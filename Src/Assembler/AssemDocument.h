// AssemDocument.h : AssemDocument 클래스의 인터페이스
//


#pragma once

#include <vector>
#include <map>
#include "AssemMacro.h"

#include ".\AssemAddComponentDialog.h"


class AssemHModel;
class AssemSettings;
class PmMeshManager;
class AssemAddComponentDialog;
class AssemImportPartDialog;

class ASSEM_API AssemDocument
	: public CHoopsDoc
	, public IPmeAssemblyEventListener
{
protected:
	typedef std::map<PmeHComponent, HC_KEY> ObjectMap;
	typedef std::map<HC_KEY,PmeHComponent> KeyMap;
	typedef std::vector<MrPosition> PositionList;

 // serialization에서만 만들어집니다.
	AssemDocument();
	virtual ~AssemDocument();
	DECLARE_DYNCREATE(AssemDocument)

// 특성
public:
	AssemHModel * GetHModel(void) const;
	AssemSettings * GetSettings() const {return m_pSettings;}

	HC_KEY GetModelSegment(void) const {return m_hModelSegment;}
	HC_KEY GetDatumSegment(void) const {return m_hDatumSegment;}
	HC_KEY GetFitIgnoringSegment(void) const {return m_hFitIgnoringSegment;}
	PmeHAssembly GetAssembly(void) const {return m_hAssembly;}
	
	void AddObjectMapPair(PmeHComponent& hcomp, HC_KEY key);

	void UpdateAll(void);
	void UpdateFitView( void );
	PmeHComponent GetComponentFromHKey(HC_KEY key);
	
	PmeHComponent GetSelectedcomp() const { return m_selectedcomp; }
	void SetSelectedcomp(PmeHComponent val) { m_selectedcomp = val; }

	void SelectComponent(PmeHComponent hComponent);


private:
	AssemSettings * m_pSettings;
	PmeHAssembly m_hAssembly;
	PmeHComponent m_selectedcomp;

	AssemAddComponentDialog *	m_pAddCompDialog;
	AssemImportPartDialog *		m_pImportPartDialog;
	CString						m_compName;

	ObjectMap m_mapObject;
	KeyMap m_keyMap;
	HC_KEY m_hModelSegment;
	HC_KEY m_hDatumSegment;
	HC_KEY m_hFitIgnoringSegment;

	void Initialize(void);
	void ClearModel(void);
	void ClearTree(void);
	void UpdateViews(void);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	afx_msg void OnEditUpdateAll();
	afx_msg void OnViewHoopsModelTree();
	afx_msg void OnTestmodelCreateLblock();
	afx_msg void OnFileOpen();

// 구현
	void DeleteExistingAssembly( void );
	CString GetComponentName() { return m_compName; }


//재정의
	virtual void OnPartUpdated(PmeHUpdateInfo hInfo);
	virtual void OnComponentUpdated(PmeHUpdateInfo hInfo);
	virtual void OnConstraintUpdated(PmeHUpdateInfo hInfo);

	virtual BOOL OnNewDocument();
	//	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);

	afx_msg void OnViewUpdateAll();
	afx_msg void OnPopupDel();
	afx_msg void OnTestmodelCreateA1Model();
	afx_msg void OnTestmodelCreateA2Model();
	afx_msg void OnAddNewComponent();
	afx_msg void OnImportPart();
};