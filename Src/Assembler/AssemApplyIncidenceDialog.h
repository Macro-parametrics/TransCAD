#pragma once

#include "afxwin.h"
#include ".\resource.h"
#include "AssemApplyConstraintDialog.h"

// AssemApplyIncidenceDialog 대화 상자입니다.

class AssemApplyIncidenceDialog : public AssemApplyConstraintDialog
{
	DECLARE_DYNAMIC(AssemApplyIncidenceDialog)

public:
	AssemApplyIncidenceDialog( AssemView * pView, CWnd* pParent = NULL );   // 표준 생성자입니다.
	virtual ~AssemApplyIncidenceDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CONSTRAINT_INCIDENCE };

// 사용자 지정 변수 및 함수 //
public:
	PmeStdAssemblyIncidenceType m_incidenceType;
	CComboBox					m_incidenceTypeComboBox;

public:
	virtual BOOL OnInitDialog();
	bool ApplyConstraint(void);

	
// 사용자 지정 변수 및 함수 마지막 //

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeConstrainedGeomType();
	afx_msg void OnCbnSelchangeReferenceGeomType();
};
