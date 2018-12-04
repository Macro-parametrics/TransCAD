#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateExtrudeDialog 대화 상자입니다.

class PmCreateExtrudeDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateExtrudeDialog)

public:
	PmCreateExtrudeDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateExtrudeDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_SKETCHBASEDFEATURES_EXTRUDE };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnBnClickedSelectProfileSketch();

public:
	CEdit m_sketchName;
	CEdit m_startDepth;
	CEdit m_endDepth;
	CComboBox m_boolType;
	CComboBox m_startCondition;
	CComboBox m_endCondition;
	CComboBox m_isFlip;

	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeBooleanType();
};
