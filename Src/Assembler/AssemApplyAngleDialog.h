#pragma once

#include "afxwin.h"
#include ".\resource.h"
#include "AssemApplyConstraintDialog.h"

// AssemApplyAngleDialog 대화 상자입니다.

class AssemApplyAngleDialog : public AssemApplyConstraintDialog
{
	DECLARE_DYNAMIC(AssemApplyAngleDialog)

public:
	AssemApplyAngleDialog( AssemView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~AssemApplyAngleDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CONSTRAINT_ANGLE };

// 사용자 지정 변수 및 함수 //
public:
	CEdit m_angleValue;

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
