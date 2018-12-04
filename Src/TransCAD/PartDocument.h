// PartDocument.h : PartDocument 클래스의 인터페이스
//


#pragma once

class PartHModel;
class PartModelerSettings;

class PartDocument
	: public CDocument
{
protected: // serialization에서만 만들어집니다.
	PartDocument();
	DECLARE_DYNCREATE(PartDocument)

// 특성
public:

private:

// 작업
public:
private:

// 재정의
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);

// 구현
public:
	virtual ~PartDocument();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()

};