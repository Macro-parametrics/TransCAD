// PmDocument.h : PmDocument 클래스의 인터페이스
//
#pragma once

#include <map>
#include ".\PmMacro.h"
//#include ".\PmeInterOp.h"

class PmHModel;
class PmSettings;
class PmMeshManager;

class PM_API PmDocument
	: public CHoopsDoc
	, public IPmePartEventListener
{
	typedef std::map<PmeHExplicitModelObject, HC_KEY> ObjectMap;

protected: // serialization에서만 만들어집니다.
	PmDocument();
	DECLARE_DYNCREATE(PmDocument)

// 특성
public:
	PmHModel * GetHModel(void) const;
	PmSettings * GetSettings() const {return m_pSettings;}

	HC_KEY GetModelSegment(void) const {return m_hModelSegment;}
	HC_KEY GetDatumSegment(void) const {return m_hDatumSegment;}
	HC_KEY GetFitIgnoringSegment(void) const {return m_hFitIgnoringSegment;}
	
	PmeHPart GetPart(void) const {return m_hPart;}
	void UpdateAll(void);
	
	HC_KEY GetHKeyFromHExplicitModelObject(PmeHExplicitModelObject pHExplicitModelObject);

	void SetMeshManager(PmMeshManager * pManager) {m_pMeshManager = pManager;}
	PmMeshManager * GetMeshManager(void) {return m_pMeshManager;}

private:
	PmSettings * m_pSettings;
	PmeHPart m_hPart;
	ObjectMap m_mapObject;

	HC_KEY m_hModelSegment;
	HC_KEY m_hDatumSegment;
	HC_KEY m_hFitIgnoringSegment;

	BODY * m_pBody;

	PmMeshManager * m_pMeshManager;

	typedef UINT (WINAPIV *StartService)(void);
	typedef UINT (WINAPIV *Translate)(char  *argv);
	typedef UINT (WINAPIV *Terminate)(void);
	typedef UINT (WINAPIV *catiatranslate)(char* catiafilename, char* macrofilename);

// 작업
public:
	/*
	virtual void OnFeaturesAdded(PmeHFeatures hFeatures);
	virtual void OnExplicitModelAdded(PmeHExplicitModel hExplicitModel);
	*/
	virtual void OnFeaturesUpdated(PmeHUpdateInfo hInfo);
	virtual void OnExplicitModelUpdated(PmeHUpdateInfo hInfo);
	/*
	virtual void OnFeaturesDeleted(PmeHFeatures hFeatures);
	virtual void OnExplicitModelDeleted(PmeHExplicitModel hExplicitModel);
	*/

private:
	void Initialize(void);
	void ClearModel(void);
	void ClearTree(void);
	void UpdateViews(void);
	void UpdateFitView(void);
	void DeleteExistingFeatures(void);
	void DeSelectAll(void);

// 재정의
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);

// 구현
public:
	virtual ~PmDocument();
	void GenerateMesh(CString & path);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnEditUpdateAll();
	afx_msg void OnViewHoopsModelTree();

	// K 모델
	afx_msg void OnTestmodelCreateLblock();
	afx_msg void OnTestmodelCreateYmodel();
	afx_msg void OnTestmodelCreateGasspring();
	afx_msg void OnTestmodelCreateLinearsensor();
	afx_msg void OnTestmodelCreateEngineAirFilterHousing();
	afx_msg void OnTestmodelCreatePneumaticCylinder();
	afx_msg void OnTestmodelCreateChisel();
	afx_msg void OnTestmodelLastone();
	
	// C 모델
	afx_msg void OnTestmodelCreateC1Model();
	afx_msg void OnTestmodelCreateC2Model();
	afx_msg void OnTestmodelCreateC3Model();
	afx_msg void OnTestmodelCreateC4Model();
	afx_msg void OnTestmodelCreateC5Model();
	afx_msg void OnTestmodelCreateC6Model();

	// 번역기
	afx_msg void OnImportFromNX();
	afx_msg void OnExportToNX();
	afx_msg void OnImportFromSolidWorks();
	afx_msg void OnExportToSolidWorks();
	afx_msg void OnImportFromCATIA();
	afx_msg void OnExportToCATIA();
	afx_msg void OnImportFromCATIAAPI();
	afx_msg void OnExportToCATIAAPI();
	afx_msg void OnImportFromInventor();
	afx_msg void OnExportToInventor();
	afx_msg void OnExportToAvevaMarine();
	afx_msg void OnExportToX3D();
	afx_msg void OnExportToOBJ();
	afx_msg void OnExportToSTL();
	afx_msg void OnExportToPLY();
	afx_msg void OnExportToVRML();
	afx_msg void OnExportTo3DPDF();
	afx_msg void OnImportETC();
	afx_msg void OnExportETC();

	// 네이밍 선정
	afx_msg void OnNamingTopological();
	afx_msg void OnUpdateNamingTopological(CCmdUI *pCmdUI);
	afx_msg void OnNamingGeometric();
	afx_msg void OnUpdateNamingGeometric(CCmdUI *pCmdUI);

	// 추 후 구현
	afx_msg void OnUndo();
	afx_msg void OnRedo();

public:
	void ImportFromCATIA(CString & path);
	void ExportToCATIA(CString & path);
	void ImportFromNX(CString & path);
	void ExportToNX(CString & path);
	void ImportFromXML(CString & path);
	void ExportToXML(CString & path);
	void ImportFromETC(CString & path);
	void ExportToETC(CString & path);
	void ExportToMesh(CString & path);
	void ExportTo3DPDF(CString & path);
	
	void ConvertMeshToMesh(CString & source, CString & target);
	void RunScriptInterface(CString & command);
	
private:
	HINSTANCE hScriptDLL;
};