#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"


// PmCreateOffsetDialog 대화 상자입니다.
class PmView;
class PmViewSelectionOperator;

class PmCreateOffsetDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateOffsetDialog)

public:
	PmCreateOffsetDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateOffsetDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSITIONFEATURES_OFFSET };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	PmViewSelectionOperator * m_pOperator;

public:
	CEdit m_thickness;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
