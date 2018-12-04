#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"

// PmCreateDraftDialog 대화 상자입니다.
class PmView;
class PmViewSelectionOperator;

class PmCreateDraftDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateDraftDialog)

public:
	PmCreateDraftDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateDraftDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSITIONFEATURES_DRAFT };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	PmViewSelectionOperator * m_pOperator;

public:
	CEdit m_draftAngle;
	CEdit m_pullingOrgX;
	CEdit m_pullingOrgY;
	CEdit m_pullingOrgZ;
	CEdit m_pullingDirX;
	CEdit m_pullingDirY;
	CEdit m_pullingDirZ;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
