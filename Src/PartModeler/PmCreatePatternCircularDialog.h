#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateExtrudeDialog 대화 상자입니다.

class PmCreatePatternCircularDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreatePatternCircularDialog)

public:
	PmCreatePatternCircularDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreatePatternCircularDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSFORMATIONFEATURES_CIRCULARPATTERN };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	afx_msg void OnBnClickedSelectTargetFeatures();

public:
	CEdit m_targetFeatures;
	CEdit m_axisOrgX;
	CEdit m_axisOrgY;
	CEdit m_axisOrgZ;
	CEdit m_axisDirX;
	CEdit m_axisDirY;
	CEdit m_axisDirZ;
	CEdit m_angNumber;
	CEdit m_angIncrement;
	CEdit m_radNumber;
	CEdit m_radSpacing;
	CComboBox m_isRadiallyAligned;

	std::vector<CString> m_targetFeatureNames;

	virtual BOOL OnInitDialog();
};