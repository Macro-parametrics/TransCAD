#include "stdafx.h"
#include "Feature.h"

#include "ReferenceExplicitModelObject.h"
#include "ReferenceBrep.h"
#include "ReferenceFeature.h"

Feature::Feature(Part * pPart, int featureType)
	:Object(featureType)
{
	SetPart(pPart);
	SetReference(NULL);
}

Feature::~Feature(void)
{
	delete m_pReference;
}

// 입력 된 이름의 특징형상의 존재 여부 판별
bool Feature::CheckExistence(string name)
{
	if (GetPart()->GetFeatureByName(name))
		return false;
	else
		return true;
}

// 입력 특징형상이 부모인지 판별
bool Feature::IsChildOf(string name)
{
	for (int i = 0; i < GetParentNameListSize(); ++i)
	{
		if (GetParentName(i) == name)
			return true;
	}

	return false;
}

// 부모 특징형상이 현재 모델 상에 존재하는지 판별
bool Feature::IsAncestorAvailable()
{
	int count = 0;

	// 부모 피쳐가 현재 TransCAD에 생성되어 있는지 검색
	for (int i = 0; i < GetParentNameListSize(); ++i)
	{
		if (GetPart()->GetFeatureByName(GetParentName(i)))
			count++;
		else
		{
			// 부모가 좌표평면인 경우에는 OK
			if (GetParentName(i) == "XYPlane"
				|| GetParentName(i) == "YZPlane"
				|| GetParentName(i) == "ZXPlane"
				|| GetParentName(i) == "N/A")
				count++;
			else
				continue;
		}
	}

	// 모든 부모가 생성되어 있는 경우
	if (count == GetParentNameListSize())
		return true;
	else
		return false;
}

// 초기 모델링 순서 리턴
int Feature::GetOriginalOrder(void)
{
	int _originalOrder = 0;

	// 같은 이름의 특징형상이 제거 후 다시 생겼을 경우, 나중에 생긴 특징형상의 Order를 리턴해야 한다.
	int _CreateCnt = 0;
	int _DeleteCnt = 0;
	int _ModifyCnt = 0;

	for (int i = 0; i < GetPart()->GetCurrentState(); ++i)
	{
		if (GetName() == GetPart()->GetHistoryFeature(i)->GetName())
		{
			if (GetPart()->GetHistoryFeature(i)->IsModified())
				_ModifyCnt++;
			else if (GetPart()->GetHistoryFeature(i)->IsDeleted())
				_DeleteCnt++;
			else
				_CreateCnt++;
		}
	}

	// 한 번 이상 제거 되었으며, 제거 된 횟수보다 많이 생성 된 경우
	if (_DeleteCnt >= 1 && _CreateCnt > _DeleteCnt)
	{
		// 뒤에서부터 검색해서 같은 이름을 가지며, 맨 처음 생성된 특징형상의 순서를 리턴
		for (int i = GetPart()->GetCurrentState() - 1; i > 0; --i)
		{
			if (GetName() == GetPart()->GetHistoryFeature(i)->GetName()
				&& !GetPart()->GetHistoryFeature(i)->IsModified()
				&& !GetPart()->GetHistoryFeature(i)->IsDeleted())
			{
				_originalOrder = GetPart()->GetHistoryFeature(i)->GetOrder();
				break;
			}
		}
	}
	else
	{
		// 앞에서부터 검색해서 같은 이름을 가지며, 맨 처음 생성된 특징형상의 순서를 리턴
		for (int i = 0; i < GetPart()->GetCurrentState(); ++i)
		{
			if (GetName() == GetPart()->GetHistoryFeature(i)->GetName()
				&& !GetPart()->GetHistoryFeature(i)->IsModified()
				&& !GetPart()->GetHistoryFeature(i)->IsDeleted())
			{
				_originalOrder = GetPart()->GetHistoryFeature(i)->GetOrder();
				break;
			}
		}
	}

	return _originalOrder;
}

// Reference를 복구
void Feature::Restore(void)
{
	if (GetReference())
		GetReference()->Restore();
}

// Reference에 ReferencePtr추가. 각각의 특징형상에서 호출됨
void Feature::AddReference(TransCAD::IReferencePtr spReference)
{
	Reference * pReference = 0;

	switch(spReference->GetType())
	{
	case TransCAD::ExplicitModelObject:
		pReference = new ReferenceExplicitModelObject(this, 0);
		break;
	case TransCAD::Brep:
		pReference = new ReferenceBrep(this, 1);
		break;
	case TransCAD::Feature:
		pReference = new ReferenceFeature(this, 6);
		break;
	}
	
	if (pReference)
	{
		pReference->AddInfo(spReference);
		pReference->SetDepth();
		SetReference(pReference);
	}
}

// Reference에 ReferencesPtr추가. 각각의 특징형상에서 호출됨
void Feature::AddReference(TransCAD::IReferencesPtr spReferences)
{
	Reference * pReference = 0;
	
	m_spReference = spReferences->GetItem(1);

	switch(m_spReference->GetType())
	{
	case TransCAD::ExplicitModelObject:
		pReference = new ReferenceExplicitModelObject(this, 0);
		break;
	case TransCAD::Brep:
		pReference = new ReferenceBrep(this, 2);
		break;
	case TransCAD::Feature:
		pReference = new ReferenceFeature(this, 7);
		break;
	}

	if (pReference)
	{
		pReference->AddInfo(spReferences);
		pReference->SetDepth();
		SetReference(pReference);
	}
}

// 기본 정보 복사
void Feature::CopyBasicInformation(Feature & pFeature)
{
	SetName(pFeature.GetName());
	SetOrder(pFeature.GetOrder());
	SetDepth(pFeature.GetDepth());
	SetModified(pFeature.IsModified());
	SetDeleted(pFeature.IsDeleted());

	if (pFeature.GetReference())
		SetReference(CopyReference(pFeature.GetReference()));
	
	m_parentNames = pFeature.m_parentNames;
}

// 레퍼런스 복사
Reference * Feature::CopyReference(Reference * pReference)
{
	Reference * pCopiedReference = 0;
	
	if (pReference->GetType() == 0)
		pCopiedReference = new ReferenceExplicitModelObject(*(ReferenceExplicitModelObject*)pReference);
	else if (pReference->GetType() == 6 || pReference->GetType() == 7)
		pCopiedReference = new ReferenceFeature(*(ReferenceFeature*)pReference);
	else
		pCopiedReference = new ReferenceBrep(*(ReferenceBrep*)pReference);
	
	pCopiedReference->SetFeature(this);

	return pCopiedReference;
}
