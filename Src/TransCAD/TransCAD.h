// TransCAD.h : TransCAD 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH에서 이 파일을 포함하기 전에 'stdafx.h'를 포함하십시오.
#endif

#include "resource.h"       // 주 기호
#include "TransCAD_i.h"


// TransCADApp:
// 이 클래스의 구현에 대해서는 TransCAD.cpp을 참조하십시오.
//

class TransCADApp
	: public CHoopsApp
{
public:
	TransCADApp();

	bool InitializeHoops(void);
	bool ReleaseHoops(void);

	bool InitializeAcis(void);
	bool ReleaseAcis(void);

// 재정의
public:
	virtual BOOL InitInstance();

// 구현

	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	afx_msg void OnAppAbout();
	afx_msg void OnScriptInterface();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

	
};

extern TransCADApp theApp;