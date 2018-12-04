#include "stdafx.h"
#include "ReferenceExplicitModelObject.h"

ReferenceExplicitModelObject::ReferenceExplicitModelObject(Feature * pFeature, int referenceType)
	:Reference(pFeature, referenceType)
{
}

ReferenceExplicitModelObject::~ReferenceExplicitModelObject(void)
{
}

void ReferenceExplicitModelObject::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	
	if (token == "xy" || token == "XY" || token == "XYPlane")		// XY 평면
		SetName("XYPlane");
	else if (token == "yz" || token == "YZ" || token == "YZPlane")	// YZ 평면
		SetName("YZPlane");
	else if (token == "zx" || token == "ZX" || token == "ZXPlane")	// ZX 평면
		SetName("ZXPlane");
	else											// DatumPlaneOffset의 경우
		SetName(token);

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectObjectByName(GetName().c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");

	GetFeature()->GetPart()->SetCurrentReferencePtr(GetReferencePtr());
}

void ReferenceExplicitModelObject::AddInfo(TransCAD::IReferencePtr spReference)
{
	SetReferencePtr(spReference);

	string name(GetReferencePtr()->GetReferenceeName());
	SetReferenceName(name);
	SetName(name);

	SetTargetFeature(GetName());

	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceExplicitModelObject::AddInfo(TransCAD::IReferencesPtr spReferences)
{
	SetReferencesPtr(spReferences);

	for (int i = 1; i <= GetReferencesPtr()->GetCount(); ++i)
	{
		string name(GetReferencesPtr()->GetItem(i)->GetReferenceeName());
		SetReferenceName(name);
		SetName(name);

		SetTargetFeature(GetName());
	}

	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceExplicitModelObject::AskInfo(void)
{
	token = "selectplane " + GetName();
	cout << token << endl;
}

void ReferenceExplicitModelObject::Help(void)
{
	cout << " [selectplane p1]" << endl;
	cout << " -p1 : " << "Plane Name" << endl;
	cout << " [EXAMPLE] " << "selectplane xy" << endl;
	cout << " [NOTE 1] " << "To select default datum plane, you should enter one of 'xy','yz','zx'" << endl;
	cout << " [NOTE 2] " << "To select datum plane offset, you should enter the plane name" << endl;
}

void ReferenceExplicitModelObject::Restore(void)
{
	if (GetReferencesPtr())		// 요소 여러 개 일 때
	{
		SetReferencesPtr(GetFeature()->GetPart()->GetPartPtr()->CreateReferences());

		for (int i = 0; i < (int)GetReferenceNameListSize(); ++i)
		{
			SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectObjectByName(GetReferenceName(i).c_str()));
			assert(GetReferencePtr());
			GetReferencesPtr()->Add(GetReferencePtr());
		}

		SetReferencePtr(NULL);
	}
	else if (GetReferencePtr())	// 요소 1개 일 때
	{
		SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectObjectByName(GetName().c_str()));
		assert(GetReferencePtr());
	}
}
