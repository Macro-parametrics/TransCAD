// PartView.cpp : PartView 클래스의 구현
//

#include "stdafx.h"
#include "TransCAD.h"

#include ".\PartDocument.h"
#include ".\PartView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// PartView

IMPLEMENT_DYNCREATE(PartView, CView)

BEGIN_MESSAGE_MAP(PartView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// PartView 생성/소멸

PartView::PartView()
{
}

PartView::~PartView()
{
}

BOOL PartView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// PartView 그리기

void PartView::OnDraw(CDC* pDC)
{
	PartDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}

// PartView 인쇄

BOOL PartView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void PartView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void PartView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// PartView 진단

#ifdef _DEBUG
void PartView::AssertValid() const
{
	CView::AssertValid();
}

void PartView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

PartDocument* PartView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(PartDocument)));
	return (PartDocument*)m_pDocument;
}
#endif //_DEBUG


// PartView 메시지 처리기

void PartView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	PartDocument * pDoc = GetDocument();
	ASSERT_VALID(pDoc);

}