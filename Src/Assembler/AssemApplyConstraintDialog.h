#pragma once

#include "afxwin.h"
#include ".\resource.h"
#include "PmeHandle.h"
#include "PmeHandleMacro.h"
#include "PmeStdAssemblyConstraints.h"
#include "PmeStdAssemblyConstraint.h"
#include "AssemView.h"
#include "AssemFrame.h"
#include <HOpCameraManipulate.h>

// AssemApplyConstraintDialog 대화 상자입니다.

class AssemView;
class AssemViewPersistentNameOperator;

class AssemApplyConstraintDialog : public CDialog
{
	DECLARE_DYNAMIC(AssemApplyConstraintDialog)

public:
	AssemApplyConstraintDialog(AssemView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~AssemApplyConstraintDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_CONSTRAINT };

// 사용자 지정 변수 및 함수 //
public:
	void UpdateAll( void );
	void DeSelectAll( void );	
	CString GetNewConstraintName( PmeStdAssemblyConstraintType type );
	virtual bool ApplyConstraint( void ) = 0;
	virtual BOOL OnInitDialog() = 0;
	void SetPersistentName( CString name );

public:
	AssemViewPersistentNameOperator * m_pOperator;
	AssemView *		m_pView;
	PmeHAssembly	m_hAssembly;
	CEdit			m_constraintName;
	CString			m_persistentName;
	PmeStdAssemblyPartType	m_partType;
	
	int			m_selectPart;	// 0 = constrained, 1 = reference
	CButton *	m_selectButton;

	CComboBox	m_constrainedGeomType;
	CEdit		m_constrainedCompName;
	CEdit		m_constrainedPartName;
	CEdit		m_constrainedGeomName;

	CComboBox	m_referenceGeomType;
	CEdit		m_referenceCompName;
	CEdit		m_referencePartName;
	CEdit		m_referenceGeomName;

	void ApplySelectionFilter( int i );

private:
	virtual afx_msg void OnBnClickedOk();
	virtual afx_msg void OnBnClickedCancel();
	virtual afx_msg void OnBnClickedSelectConstrained();
	virtual afx_msg void OnBnClickedSelectReference();
	
// 사용자 지정 변수 및 함수 마지막 //

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	
	
};
