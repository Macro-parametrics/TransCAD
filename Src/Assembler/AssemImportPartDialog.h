#pragma once

#include "afxwin.h"
#include ".\resource.h"

#include "AssemDocument.h"

// AssemImportPartDialog 대화 상자입니다.

class AssemDocument;

class AssemImportPartDialog : public CDialog
{
	DECLARE_DYNAMIC(AssemImportPartDialog)

public:
	AssemImportPartDialog( AssemDocument * pDoc, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~AssemImportPartDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMPORT_PART };

public:
	AssemDocument * m_pDoc;
	PmeHAssembly	m_hAssembly;
	CListBox		m_compList;
	CEdit			m_filePath;
	CEdit			m_partName;
	CEdit			m_partOriginX;
	CEdit			m_partOriginY;
	CEdit			m_partOriginZ;
	CEdit			m_partNormalX;
	CEdit			m_partNormalY;
	CEdit			m_partNormalZ;

	BOOL OnInitDialog();
	bool ImportPart();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonImportPart();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
