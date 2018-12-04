#pragma once
#include "afxwin.h"
#include ".\resource.h"
#include "PmeHandle.h"
#include "PmeHandleMacro.h"
#include "PmePart.h"
#include "PmeFeature.h"
#include "PmeFeatures.h"
#include "PmHView.h"
#include "PmFrame.h"
#include <HOpCameraManipulate.h>

// PmCreateFeatureDialog 대화 상자입니다.

class PmView;

class PmCreateFeatureDialog : public CDialog
{
	DECLARE_DYNAMIC(PmCreateFeatureDialog)

public:
	PmCreateFeatureDialog(PmView * pView, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PmCreateFeatureDialog();

// 대화 상자 데이터입니다.
	enum { IDD = ID_FEATURE };
	
public:
	void DeSelectAll(void);
	void UpdateAll(void); 
	bool CheckFeatureExistence(CString pName);
	CString GetNewFeatureName(PmeFeatureType type);
	virtual bool CreateFeature(void) = 0;
	virtual void SetParameters(PmeFeature * pFeature) = 0;

public:
	PmView * m_pView;
	PmeHPart m_hPart;
	PmeHFeature m_hFeature;
	CEdit m_featureName;
	bool m_isModified;

protected:
	virtual void DoDataExchange(CDataExchange* pDX) = 0;    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	virtual afx_msg void OnBnClickedOK();
	virtual afx_msg void OnBnClickedCancel();

public:
	virtual BOOL OnInitDialog() = 0;
};
