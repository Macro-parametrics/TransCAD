#pragma once

#include "afxwin.h"
#include ".\resource.h"
#include "PmeHandle.h"
#include "PmeHandleMacro.h"

#include "AssemDocument.h"

// AssemAddComponentDialog 대화 상자입니다.

class AssemDocument;

class AssemAddComponentDialog : public CDialog
{
	DECLARE_DYNAMIC(AssemAddComponentDialog)

public:
	AssemAddComponentDialog( AssemDocument * pDoc, CWnd* pParent = NULL );   // 표준 생성자입니다.
	virtual ~AssemAddComponentDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ADD_COMPONENT };

public:
	AssemDocument *	m_pDoc;
	PmeHAssembly	m_hAssembly;
	CEdit			m_compName;

	BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
