// PartDocument.cpp : PartDocument 클래스의 구현
//

#include "stdafx.h"
#include "TransCAD.h"

#include ".\PartDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// PartDocument

IMPLEMENT_DYNCREATE(PartDocument, CDocument)

BEGIN_MESSAGE_MAP(PartDocument, CDocument)
END_MESSAGE_MAP()


// PartDocument 생성/소멸

PartDocument::PartDocument()
{
}

PartDocument::~PartDocument()
{
}

BOOL PartDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

BOOL PartDocument::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return TRUE;
}

// PartDocument serialization

void PartDocument::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// PartDocument 진단

#ifdef _DEBUG
void PartDocument::AssertValid() const
{
	CDocument::AssertValid();
}

void PartDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// PartDocument 명령