#pragma once

#include ".\Resource.h"
#include "afxcmn.h"

// PmViewHoopsModelTreeDialog 대화 상자입니다.

class PmDocument;

class PmViewHoopsModelTreeDialog
	: public CDialog
{
	DECLARE_DYNAMIC(PmViewHoopsModelTreeDialog)

public:
	PmViewHoopsModelTreeDialog(PmDocument * pDocument, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmViewHoopsModelTreeDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_VIEW_HOOPS_MODEL_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

private:
	void AddSegmentToTree(char * segmentName, HTREEITEM hParent);

	DECLARE_MESSAGE_MAP()
private:
	PmDocument * m_pDocument;
	CTreeCtrl m_tree;	
};
