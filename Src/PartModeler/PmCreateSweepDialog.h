#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateSweepDialog 대화 상자입니다.

class PmCreateSweepDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateSweepDialog)

public:
	PmCreateSweepDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateSweepDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_SKETCHBASEDFEATURES_SWEEP };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnBnClickedSelectProfileSketch();
	afx_msg void OnBnClickedSelectGuideSketch();

public:
	CEdit m_profileSketchName;
	CEdit m_guideSketchName;
	CComboBox m_boolType;

	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeBooleanType();
};
