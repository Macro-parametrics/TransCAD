#pragma once
#include "TransCADScript.h"
#include "Object.h"
#include "Part.h"
#include "Reference.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"


class Feature : public Object
{
public:
	Feature(Part * pPart, int featureType);
	virtual ~Feature(void);

	virtual void AddInfo(TransCAD::IFeaturePtr spFeature) {}	// TransCAD로부터 정보 저장
	virtual void Create(void) {}								// 정보가 존재하는 경우, 특징형상 생성
	virtual void Modify(char * command) {}						// 명령어로부터 정보 수정
	
	void Restore(void);

	bool CheckExistence(string name);
	bool IsChildOf(string name);
	bool IsAncestorAvailable(void);
	
	Reference * CopyReference(Reference * pReference);
	void CopyBasicInformation(Feature & pFeature);

	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IReferencePtr, ReferencePtr, m_spReference);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IReferencesPtr, ReferencesPtr, m_spReferences);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, Order, m_order);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, Depth, m_depth);
	int GetOriginalOrder(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(Part *, Part, m_pPart);
	VARIABLE_GET_AND_SET_FUNC_IMPL(Reference *, Reference, m_pReference);
	void AddReference(TransCAD::IReferencePtr spReference);
	void AddReference(TransCAD::IReferencesPtr spReferences);

	LIST_GET_AND_SET_FUNC_IMPL(string, ParentName, m_parentNames);

private:
	TransCAD::IReferencePtr m_spReference;
	TransCAD::IReferencesPtr m_spReferences;
	Part *	m_pPart;						// 파트 포인터
	Reference * m_pReference;				// 레퍼런스 포인터
	vector<string> m_parentNames;			// 특징형상의 부모 특징형상 이름
	int m_order;							// 특징형상의 모델링 순서
	int m_depth;
};