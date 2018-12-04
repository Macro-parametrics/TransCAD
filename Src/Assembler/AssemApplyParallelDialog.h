#pragma once

#include "afxwin.h"
#include ".\resource.h"
#include "AssemApplyConstraintDialog.h"

// AssemApplyParallelDialog 대화 상자입니다.

class AssemApplyParallelDialog : public AssemApplyConstraintDialog
{
	DECLARE_DYNAMIC(AssemApplyParallelDialog)

public:
	AssemApplyParallelDialog( AssemView * pView, CWnd* pParent = NULL );   // 표준 생성자입니다.
	virtual ~AssemApplyParallelDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CONSTRAINT_PARALLEL };

// 사용자 지정 변수 및 함수 //
public:


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
