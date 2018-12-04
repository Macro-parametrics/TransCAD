#pragma once


// AssemTreeView 뷰입니다.

class AssemTreeView
	: public CTreeView
{
	DECLARE_DYNCREATE(AssemTreeView)

protected:
	AssemTreeView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~AssemTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


