// PartView.h : iPartView 클래스의 인터페이스
//


#pragma once

class PartView
	: public CView
{
protected: // serialization에서만 만들어집니다.
	PartView();
	DECLARE_DYNCREATE(PartView)

// 특성
public:
	PartDocument* GetDocument() const;

// 작업
public:

// 재정의
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현
public:
	virtual ~PartView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // PartView.cpp의 디버그 버전
inline PartDocument* PartView::GetDocument() const
   { return reinterpret_cast<PartDocument*>(m_pDocument); }
#endif