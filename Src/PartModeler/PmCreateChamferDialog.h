#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmViewPersistentNameDialog 대화 상자입니다.
class PmViewSelectionOperator;

class PmCreateChamferDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateChamferDialog)

public:
	PmCreateChamferDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateChamferDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSITIONFEATURES_CHAMFER };

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
	CEdit m_chamferLength;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
