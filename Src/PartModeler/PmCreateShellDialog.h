#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmCreateFeatureDialog.h"


// PmCreateShellDialog 대화 상자입니다.
class PmView;
class PmViewSelectionOperator;

class PmCreateShellDialog : public PmCreateFeatureDialog
{
	DECLARE_DYNAMIC(PmCreateShellDialog)

public:
	PmCreateShellDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateShellDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_TRANSITIONFEATURES_SHELL };

public:
	void SetParameters(PmeFeature * pFeature);
	bool CreateFeature(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	PmViewSelectionOperator * m_pOperator;

public:
	CEdit m_innerThickness;
	CEdit m_outerThickness;
	std::vector<CString> m_selectedEntityNames;

	virtual BOOL OnInitDialog();
};
