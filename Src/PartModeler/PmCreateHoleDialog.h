#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateHoleDialog 대화 상자입니다.
class PmViewSelectionOperator;

class PmCreateHoleDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateHoleDialog)

public:
	PmCreateHoleDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateHoleDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_SKETCHBASEDFEATURES_HOLE };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	PmViewSelectionOperator * m_pOperator;
	afx_msg void OnCbnSelchangeHoleType();

public:
	CEdit m_holeDepth;
	CEdit m_holeRadius;
	CEdit m_holeBottomAngle;
	CEdit m_holeSinkRadius;
	CEdit m_holeSinkAngle;
	CEdit m_holeHeadDepth;
	CEdit m_holeHeadRadius;
	CEdit m_holeCenterX;
	CEdit m_holeCenterY;
	CEdit m_holeCenterZ;
	CComboBox m_holeType;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
