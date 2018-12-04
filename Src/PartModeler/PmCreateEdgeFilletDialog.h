#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateEdgeFilletDialog 대화 상자입니다.
class PmView;
class PmViewSelectionOperator;

class PmCreateEdgeFilletDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateEdgeFilletDialog)

public:
	PmCreateEdgeFilletDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateEdgeFilletDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSITIONFEATURES_FILLET };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	PmViewSelectionOperator * m_pOperator;
	BOOL m_isFace;
	BOOL m_isEdge;
		
	afx_msg void OnBnClickedSelectFace();
	afx_msg void OnBnClickedSelectEdge();

public:
	CEdit m_filletRadius;
	CComboBox m_propagation;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
