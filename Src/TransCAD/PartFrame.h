// PartFrame.h : PartFrame 클래스의 인터페이스
//


#pragma once


class PartFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(PartFrame)
public:
	PartFrame();

// 특성
public:

// 작업
public:

// 재정의
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현
public:
	virtual ~PartFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()
};
