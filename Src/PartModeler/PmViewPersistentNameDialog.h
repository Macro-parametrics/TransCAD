#pragma once
#include "afxwin.h"
#include ".\resource.h"

// PmViewPersistentNameDialog 대화 상자입니다.
class PmView;
class PmViewPersistentNameOperator;

class PmViewPersistentNameDialog : public CDialog
{
	DECLARE_DYNAMIC(PmViewPersistentNameDialog)

public:
	PmViewPersistentNameDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmViewPersistentNameDialog();

	void OnCancel();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_VIEW_PERSISTENT_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	PmViewPersistentNameOperator * m_pOperator;
	PmView * m_pView;
	BOOL m_isFace;
	BOOL m_isEdge;
	BOOL m_isVertex;
	CEdit m_persistentName;

	afx_msg void OnBnClickedViewPersistentNameFace();
	afx_msg void OnBnClickedViewPersistentNameEdge();
	afx_msg void OnBnClickedViewPersistentNameVertex();	

public:
	void SetPersistentName(CString name) {m_persistentName.SetWindowText(name);}
	//CEdit GetPersistentNameEditControl(void) {return m_persistentName;}
	virtual BOOL OnInitDialog();
};
