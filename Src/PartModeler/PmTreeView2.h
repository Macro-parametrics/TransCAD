#pragma once


// PmTreeView 뷰입니다.

class PmTreeView
	: public CTreeView
{
	DECLARE_DYNCREATE(PmTreeView)

protected:
	PmTreeView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~PmTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


