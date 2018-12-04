#include "stdafx.h"
#include "PmDocument.h"
// PmDocument.cpp : PmDocument 클래스의 구현
//

#include ".\Resource.h"
#include ".\PmDocument.h"
#include ".\PmView.h"
#include ".\PmFrame.h"
#include ".\PmHModel.h"
#include ".\PmSettings.h"
#include ".\PmRenderExplicitModelObject.h"
#include "PmeHandleMacro.h"
#include "PmePart.h"
#include "PmHSelectionSet.h"

#include ".\PmViewHoopsModelTreeDialog.h"
#include "PmMeshManager.h"
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <Tlhelp32.h>

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// PmDocument

IMPLEMENT_DYNCREATE(PmDocument, CHoopsDoc)

BEGIN_MESSAGE_MAP(PmDocument, CHoopsDoc)
	ON_COMMAND(ID_EDIT_UPDATE_ALL, OnEditUpdateAll)
	ON_COMMAND(ID_VIEW_HOOPS_MODEL_TREE, OnViewHoopsModelTree)
	ON_COMMAND(ID_TESTMODEL_CREATE_LBLOCK, OnTestmodelCreateLblock)
	ON_COMMAND(ID_TESTMODEL_CREATE_YMODEL, OnTestmodelCreateYmodel)
	ON_COMMAND(ID_TESTMODEL_CREATE_GASSPRING, OnTestmodelCreateGasspring)
	ON_COMMAND(ID_TESTMODEL_CREATE_LINEARSENSOR, OnTestmodelCreateLinearsensor)
	ON_COMMAND(ID_TESTMODEL_CREATE_ENGINE_AIR_FILTER_HOUSING, OnTestmodelCreateEngineAirFilterHousing)
	ON_COMMAND(ID_TESTMODEL_CREATE_PNEUMATIC_CYLINDER, OnTestmodelCreatePneumaticCylinder)
	ON_COMMAND(ID_TESTMODEL_CREATE_CHISEL, &PmDocument::OnTestmodelCreateChisel)
	ON_COMMAND(ID_TESTMODEL_LASTONE, &PmDocument::OnTestmodelLastone)
	ON_COMMAND(ID_TESTMODEL_CREATE_C1, OnTestmodelCreateC1Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_C2, OnTestmodelCreateC2Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_C3, OnTestmodelCreateC3Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_C4, OnTestmodelCreateC4Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_C5, OnTestmodelCreateC5Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_C6, OnTestmodelCreateC6Model)
	ON_COMMAND(ID_IMPORT_FROM_NX, OnImportFromNX)
	ON_COMMAND(ID_EXPORT_TO_NX, OnExportToNX)
	ON_COMMAND(ID_IMPORT_FROM_SOLIDWORKS, OnImportFromSolidWorks)
	ON_COMMAND(ID_EXPORT_TO_SOLIDWORKS, OnExportToSolidWorks)
	ON_COMMAND(ID_IMPORT_FROM_CATIA, OnImportFromCATIA)
	ON_COMMAND(ID_EXPORT_TO_CATIA, OnExportToCATIA)
	ON_COMMAND(ID_IMPORT_FROM_CATIA_API, OnImportFromCATIAAPI)
	ON_COMMAND(ID_EXPORT_TO_CATIA_API, OnExportToCATIAAPI)
	ON_COMMAND(ID_IMPORT_FROM_INVENTOR, OnImportFromInventor)
	ON_COMMAND(ID_EXPORT_TO_INVENTOR, OnExportToInventor)
	ON_COMMAND(ID_IMPORT_FROM_ETC, &PmDocument::OnImportETC)
	ON_COMMAND(ID_EXPORT_TO_ETC, &PmDocument::OnExportETC)
	ON_COMMAND(ID_EXPORT_TO_AVEVAMARINE, OnExportToAvevaMarine)
	ON_COMMAND(ID_EXPORT_TO_X3D, &PmDocument::OnExportToX3D)
	ON_COMMAND(ID_EXPORT_TO_OBJ, &PmDocument::OnExportToOBJ)
	ON_COMMAND(ID_EXPORT_TO_STL, &PmDocument::OnExportToSTL)
	ON_COMMAND(ID_EXPORT_TO_PLY, &PmDocument::OnExportToPLY)
	ON_COMMAND(ID_EXPORT_TO_VRML, &PmDocument::OnExportToVRML)
	ON_COMMAND(ID_EXPORT_TO_3DPDF, &PmDocument::OnExportTo3DPDF)
	ON_COMMAND(ID_NAMING_TOPOLOGICAL, &PmDocument::OnNamingTopological)
	ON_UPDATE_COMMAND_UI(ID_NAMING_TOPOLOGICAL, &PmDocument::OnUpdateNamingTopological)
	ON_COMMAND(ID_NAMING_GEOMETRIC, &PmDocument::OnNamingGeometric)
	ON_UPDATE_COMMAND_UI(ID_NAMING_GEOMETRIC, &PmDocument::OnUpdateNamingGeometric)
	ON_COMMAND(ID_UNDO, &PmDocument::OnUndo)
	ON_COMMAND(ID_REDO, &PmDocument::OnRedo)
END_MESSAGE_MAP()

// PmDocument 생성/소멸

PmDocument::PmDocument()
{
	m_pHoopsModel = 0;
	m_pSettings = 0;
	m_hPart = 0;

	m_hModelSegment = 0;
	m_hDatumSegment = 0;
	m_hFitIgnoringSegment = 0;

	m_pMeshManager = 0;

	m_pBody = 0;

	hScriptDLL = NULL;
}

PmDocument::~PmDocument()
{
	PmePartAPI::UnregisterEventListener(m_hPart, this);
	PmePartAPI::Delete(m_hPart);
	ASSERT(!m_hPart);
	
	if(m_pHoopsModel)
	{
		delete m_pHoopsModel;
		m_pHoopsModel = 0;
	}

	if(m_pSettings)
	{
		delete m_pSettings;
		m_pSettings = 0;
	}

	CString command;
	command = _T("종료");
	RunScriptInterface(command);
}

void PmDocument::Initialize(void)
{
	m_pSettings = new PmSettings();

	// delete the HHoopsTestModel object if there is already one
	if(m_pHoopsModel)
	{
		delete m_pHoopsModel;
		m_pHoopsModel = 0;
	}

	// create a new PmHModel object for this Document
	m_pHoopsModel = new PmHModel();
	m_pHoopsModel->Init();
	
	m_pMeshManager = new PmMeshManager();
	ClearModel();
	ClearTree();
	PmePartAPI::Create(m_hPart);
	PmePartAPI::RegisterEventListener(m_hPart, this);	
}

void PmDocument::ClearModel(void)
{
	if(m_hModelSegment)
        HC_Delete_By_Key(m_hModelSegment);
	if(m_hDatumSegment)
        HC_Delete_By_Key(m_hDatumSegment);

	HC_Open_Segment_By_Key(GetHModel()->GetModelKey());
		HC_Set_Heuristics("polygon handedness=left");
		
		HC_Set_Color("lines = white");
		HC_Set_Color("faces = (diffuse = sky blue, specular = white, gloss = 20)");
		HC_Set_Color("markers = white");
		HC_Set_Marker_Symbol(".");

		m_hModelSegment = HC_KOpen_Segment("ModelSegment");
		HC_Close_Segment();
		m_hDatumSegment = HC_KOpen_Segment("DatumSegment");
			//HC_Set_Rendering_Options("hsra = priority");
			m_hFitIgnoringSegment = HC_KOpen_Segment("FitIgnoringSegment");
			HC_Close_Segment();
		HC_Close_Segment();
	
	HC_Close_Segment();

	PmClearSubKeyMap();
}

void PmDocument::UpdateAll(void)
{
	DeSelectAll();
	ClearModel();
	ClearTree();
	PmePartAPI::UpdateAll(m_hPart);
}

BOOL PmDocument::OnNewDocument()
{
	if (!CHoopsDoc::OnNewDocument())
		return FALSE;

	Initialize();	

	return TRUE;
}

BOOL PmDocument::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CHoopsDoc::OnOpenDocument(lpszPathName))
 		return FALSE;

	Initialize();
	             
	CString strFilename = lpszPathName;

	PmePartAPI::LoadXmlMacro(lpszPathName, m_hPart);

	return TRUE;
}

BOOL PmDocument::OnSaveDocument(LPCTSTR lpszPathName)
{
	PmePartAPI::SaveAsXmlMacro(m_hPart, lpszPathName);

	return TRUE;
}

// PmDocument serialization

void PmDocument::Serialize(CArchive& ar)
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


// PmDocument 진단

#ifdef _DEBUG
void PmDocument::AssertValid() const
{
	CHoopsDoc::AssertValid();
}

void PmDocument::Dump(CDumpContext& dc) const
{
	CHoopsDoc::Dump(dc);
}
#endif //_DEBUG


// PmDocument 명령
PmHModel * PmDocument::GetHModel(void) const
{
	return static_cast<PmHModel *>(m_pHoopsModel);
}

void PmDocument::OnFeaturesUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnFeaturesUpdated\n"));
}

void PmDocument::OnExplicitModelUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnExplicitModelUpdated\n"));

	int size;
	PmeUpdateInfoAPI::GetSize(hInfo, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeUpdateInfoItem item;
		PmeUpdateInfoAPI::GetItem(hInfo, i, item);

		switch(item.state)
		{
		case PmeUpdateState_Add:
			{
				PmeHExplicitModelObject hObject = item.hItem;

				HC_KEY hKey = PmRenderExplicitModelObject(hObject, this);
				m_mapObject[hObject] = hKey;
			}
			break;
		case PmeUpdateState_Update:
			{
				PmeHExplicitModelObject hObject = item.hItem;				

				HC_KEY hOldKey = m_mapObject[hObject];
				if(hOldKey)
				{
					PmDeleteRenderingObject(hOldKey);
				}
				
				HC_KEY hNewKey = PmRenderExplicitModelObject(hObject, this);
				m_mapObject[hObject] = hNewKey;
			}
			break;
		case PmeUpdateState_Delete:
			break;
		}
	}
	HC_Update_Display();

	UpdateViews();
}

HC_KEY PmDocument::GetHKeyFromHExplicitModelObject(PmeHExplicitModelObject pHExplicitModelObject)
{
	return m_mapObject[pHExplicitModelObject];
}

void PmDocument::UpdateViews(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
   
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(PmDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(PmView)))
			{
				PmView * pPmView = static_cast<PmView *>(pView);
				pPmView->RedrawWindow();
			}
		}
	}
}

void PmDocument::UpdateFitView(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
   
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(PmDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(PmView)))
			{
				PmView * pPmView = static_cast<PmView *>(pView);
				pPmView->OnViewZoomAll();
			}
		}
	}
}

void PmDocument::OnEditUpdateAll(void)
{
	UpdateAll();
}

void PmDocument::OnViewHoopsModelTree(void)
{
	PmViewHoopsModelTreeDialog dialog(this);

	dialog.DoModal();
}

void PmDocument::ClearTree(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
	CDocument * pDoc = pFrame->GetActiveDocument();
	
	if(pFrame->IsKindOf(RUNTIME_CLASS(PmFrame)) && static_cast<CDocument *>(this) == pDoc)
	{
		PmFeatureTree * pFeatureTree = static_cast<PmFrame *>(pFrame)->GetFeatureTree();
		pFeatureTree->Initialize();
	}
}


void PmDocument::GenerateMesh(CString & path)
{
	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);

	PmeHExplicitModelObject hSolid;
	PmeExplicitModelAPI::GetSolid(hExplicitModel, hSolid);

	BODY * pBody = 0;
	PmeSolidAPI::GetSolid(hSolid, pBody);

	if (pBody == NULL)
		pBody = m_pBody;

	if (pBody)
		m_pMeshManager->Generate(pBody, path);
}


void PmDocument::OnNamingTopological()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PmePersistentNameAPI::SelectNamingMethod(true);
}

void PmDocument::OnUpdateNamingTopological(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	bool bNaming;
	PmePersistentNameAPI::GetNamingMethod(bNaming);

	if(bNaming)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void PmDocument::OnNamingGeometric()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PmePersistentNameAPI::SelectNamingMethod(false);
}

void PmDocument::OnUpdateNamingGeometric(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	bool bNaming;
	PmePersistentNameAPI::GetNamingMethod(bNaming);

	if(bNaming)
		pCmdUI->SetCheck(0);
	else
		pCmdUI->SetCheck(1);
}


/****** 버튼 이벤트 용 변환 함수 ******/
void PmDocument::OnImportFromNX()
{
	/** NX UG 10.0 버전 전용 **/
	CString filter = _T("NX Part file (*.prt) |*.prt|");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("prt");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;
		
		if (path.Find(_T(".prt")) == -1)
			path = path + _T(".") + extension;
		
#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\UGPre_argv.exe ") + path;
#else
		path = _T("translators\\UGPre_argv.exe ") + path;
#endif

		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_SHOW);
	}
}

void PmDocument::OnExportToNX()
{
	// NX UG 10.0 버전 전용 
	CString filter = _T("NX Part file (*.prt) |*.prt|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("prt");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;
		
		if (path.Find(_T(".prt")) == -1)
			path = path + _T(".") + extension;

#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\UGPost_argv.exe ") + path;
#else
		path = _T("translators\\UGPost_argv.exe ") + path;
#endif
	
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_SHOW);
	}
	
}

void PmDocument::OnImportFromSolidWorks()
{
	HINSTANCE hDLL;               // Handle to DLL
	StartService fnStartservice;    // Function pointer
	Translate fnTranslate;

	hDLL = LoadLibrary("translators\\dllSWPre.dll");

	TRACE("%d",GetLastError());

	CString filter = _T("SolidWorks macro file (*.swb) |*.swb|");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("swb");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
		{
			FreeLibrary(hDLL);
			return;
		}

		name.Replace("\\","\\\\");
		
		if (hDLL != NULL)
		{

			fnStartservice = (StartService)GetProcAddress(hDLL, "SWPreStartService");
			fnTranslate = (Translate)GetProcAddress(hDLL, "SWPreTranslate");
			
			if (!fnStartservice && !fnTranslate)
			{
				// handle the error
				FreeLibrary(hDLL);       
				AfxMessageBox("No dll");
			}
			else
			{
				// call the function
				fnStartservice();
				fnTranslate((char *)(LPCTSTR)name);
			}
		}
	}
}

void PmDocument::OnExportToSolidWorks()
{
	HINSTANCE hDLL;               // Handle to DLL
	StartService fnStartservice;    // Function pointer
	Translate fnTranslate;

	hDLL = LoadLibrary("translators\\dllSWPost.dll");

	TRACE("%d",GetLastError());

	CString filter = _T("SolidWorks macro file (*.swb) |*.swb|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if ( dlg.DoModal() )
	{
		CString extension = _T("swb");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
		{
			FreeLibrary(hDLL);
			return;
		}

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("swb")))
				name = name + _T(".swb");
		}

		name.Replace("\\","\\\\");

		if (hDLL != NULL)
		{
			fnStartservice = (StartService)GetProcAddress(hDLL, "SWPostStartService");
			fnTranslate = (Translate)GetProcAddress(hDLL, "SWPostTranslate");

			if (!fnStartservice && !fnTranslate)
			{
				// handle the error
				FreeLibrary(hDLL);       
				AfxMessageBox("No dll");
			}
			else
			{
				// call the function
				fnStartservice();
				fnTranslate((char *)(LPCTSTR)name);
			}
		}
	}
}

void PmDocument::OnImportFromCATIA()
{
	CString filter = _T("CATIA Script file (*.CATScript) |*.CATScript|");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("CATScript");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;

		if (path.Find(_T(".CATScript")) == -1)
			path = path + _T(".") + extension;
#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\CATIA_macro_argv.exe pre ") + path;
#else
		path = _T("translators\\CATIA_macro_argv.exe pre ") + path;
#endif

		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_SHOW);

		//UpdateFitView();
	}
}

void PmDocument::OnExportToCATIA()
{
	
	CString filter = _T("CATIA Script file (*.CATScript) |*.CATScript|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("CATScript");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;
		
		if (path.Find(_T(".CATScript")) == -1)
			path = path + _T(".") + extension;

#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\CATIA_macro_argv.exe post ") + path;
#else
		path = _T("translators\\CATIA_macro_argv.exe post ") + path;
#endif

		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_SHOW);
	}
}

void PmDocument::OnImportFromCATIAAPI()
{
	CString filter = _T("CATIA Part file (*.CATPart) |*.CATPart|");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("CATPart");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;
		
		if (path.Find(_T(".CATPart")) == -1)
			path = path + _T(".") + extension;

#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\CATIA_api_argv.exe pre ") + path;
#else
		path = _T("translators\\CATIA_api_argv.exe pre ") + path;
#endif
				
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);

		//UpdateFitView();
	}
}

void PmDocument::OnExportToCATIAAPI()
{
	CString filter = _T("CATIA Part file (*.CATPart) |*.CATPart|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("CATPart");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		CString path = name;

		if (path.Find(_T(".CATPart")) == -1)
			path = path + _T(".") + extension;

#ifdef _DEBUG
		path = _T("..\\..\\RegBin\\translators\\CATIA_api_argv.exe post ") + path;
#else
		path = _T("translators\\CATIA_api_argv.exe post ") + path;
#endif
		
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);
	}
}

void PmDocument::OnImportFromInventor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString filter = _T("Inventor file (*.ipt) |*.ipt|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	CString extension = _T("ipt");
	CString name = dlg.m_ofn.lpstrFile;

	// 필터 인덱스
	name.Replace("\\","\\\\");
	WinExec("translators\\inv_pre.exe", SW_HIDE);
	name = "inv_pre.exe" + name;
	//system("C:\\Program Files\\Autodesk\\Inventor 2010\\bin\\Inventor.exe");
	//system("C:\\MACRO\\TransCAD\\Bin\\Debug\\MACRO_Inventor_to_TransCAD.exe");		
}

void PmDocument::OnExportToInventor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	WinExec("translators\\inv_post.exe", SW_SHOW);
}

void PmDocument::OnImportETC()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString filter;
	filter += _T("STEP file (*.stp) |*.stp|");
	filter += _T("SAT file (*.sat) |*.sat|");
	filter += _T("IGES file (*.igs) |*.igs|");

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);
	
	if(dlg.DoModal() != IDOK)
		return;

	if (dlg.m_ofn.lpstrFile == _T(""))
		return;

	CString extention = dlg.m_ofn.lpstrFilter;	// 현재 확장자
	CString path = dlg.GetPathName();			// 확장자 제외한 경로
	
	if (path.Find(_T(".stp")) == -1 && path.Find(_T(".sat")) == -1 && path.Find(_T(".igs")) == -1)
	{
		// 경로에 확장자 포함
		if (extention == _T("STEP file (*.stp) "))
			path = path + _T(".stp");
		else if (extention == _T("SAT file (*.sat) "))
			path = path + _T(".sat");
		else
			path = path + _T(".igs");
	}

	// 기존 특징형상 제거
	DeleteExistingFeatures();
	
	// 두 번째 방법
	PmeHFeature hImportedBrepFeature = 0;
	PmeStdSolidImportedBrepFeatureAPI::Create(m_hPart, _T("Manifold_Solid_Brep"), path, hImportedBrepFeature);
	ASSERT(hImportedBrepFeature);

	UpdateAll();
}

void PmDocument::OnExportETC()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString filter;
	filter += _T("STEP file (*.stp) |*.stp|");
	filter += _T("SAT file (*.sat) |*.sat|");
	filter += _T("IGES file (*.igs) |*.igs|");

	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if(dlg.DoModal() != IDOK)
		return;
	
	if (dlg.m_ofn.lpstrFile == _T(""))
		return;

	CString extention = dlg.m_ofn.lpstrFilter;	// 현재 확장자
	CString path = dlg.GetPathName();			// 확장자 제외한 경로

	if (path.Find(_T(".stp")) == -1 && path.Find(_T(".sat")) == -1 && path.Find(_T(".igs")) == -1)
	{
		// 경로에 확장자 포함
		if (extention == _T("STEP file (*.stp) "))
			path = path + _T(".stp");
		else if (extention == _T("SAT file (*.sat) "))
			path = path + _T(".sat");
		else
			path = path + _T(".igs");
	}

	CWaitCursor wait;

	PmeHExplicitModelObject hExplicitModelObject;
	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);
	PmeExplicitModelAPI::GetSolid(hExplicitModel, hExplicitModelObject);
	PmePartAPI::SetName(m_hPart, "Manifold_Solid_Brep");
	
	BODY * pBody = 0;
	PmeSolidAPI::GetSolid(hExplicitModelObject, pBody);

	ENTITY_LIST pEntities;
	pEntities.add((ENTITY*)pBody);

	SPAIAcisDocument source(&pEntities);
	SPAIDocument destination(path);

	SPAIConverter converter;
	SPAIResult result = converter.Convert(source, destination);
}

void PmDocument::OnExportToAvevaMarine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	HINSTANCE hDLL;               // Handle to DLL
	StartService fnStartservice;    // Function pointer
	Translate fnTranslate;

	hDLL = LoadLibrary("translators\\dllAMPost.dll");

	TRACE("%d",GetLastError());

	CString filter = _T("AM macro file (*.txt) |*.txt|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("txt");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
		{
			FreeLibrary(hDLL);
			return;
		}

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("txt")))
				name = name + _T(".txt");
		}

		name.Replace("\\","\\\\");

		if (hDLL != NULL)
		{
			fnStartservice = (StartService)GetProcAddress(hDLL, "AMPostStartService");
			fnTranslate = (Translate)GetProcAddress(hDLL, "AMPostTranslate");

			if (!fnStartservice && !fnTranslate)
			{
				// handle the error
				FreeLibrary(hDLL);
				AfxMessageBox("No dll");
			}
			else
			{
				// call the function
				fnStartservice();
				fnTranslate((char *)(LPCTSTR)name);
			}
		}
	}
}

void PmDocument::OnExportToX3D()
{
	CString filter = _T("X3D file (*.x3d) |*.x3d|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("x3d");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("x3d")))
				name = name + _T(".x3d");
		}

		GenerateMesh(name);
	}
}

void PmDocument::OnExportToOBJ()
{
	CString filter = _T("OBJ file (*.obj) |*.obj|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("obj");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("obj")))
				name = name + _T(".obj");
		}

		GenerateMesh(name);
	}
}

void PmDocument::OnExportToSTL()
{
	CString filter = _T("STL file (*.stl) |*.stl|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("stl");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("stl")))
				name = name + _T(".stl");
		}

		GenerateMesh(name);
	}
}

void PmDocument::OnExportToPLY()
{
	CString filter = _T("PLY file (*.ply) |*.ply|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("ply");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("ply")))
				name = name + _T(".ply");
		}

		GenerateMesh(name);
	}
}

void PmDocument::OnExportToVRML()
{
	CString filter = _T("VRML file (*.wrl) |*.wrl|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("wrl");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("wrl")))
				name = name + _T(".wrl");
		}

		GenerateMesh(name);
	}
}

void PmDocument::OnExportTo3DPDF()
{
	AfxMessageBox(_T("pdflatex must be installed before translating to 3D PDF.\nPlease download and install it here (32bit): https://miktex.org/download"));
	
	CString filter = _T("PDF file (*.pdf) |*.pdf|");
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, filter);

	if (dlg.DoModal())
	{
		CString extension = _T("obj");
		CString name = dlg.m_ofn.lpstrFile;
		
		if (name == _T(""))
			return;

		// 필터 인덱스
		if (dlg.m_ofn.nFileExtension == 0)
		{
			// 확장자가 없는 경우
			name = name + _T(".") + extension;
		}
		else
		{
			extension = dlg.GetFileExt();
			extension.MakeLower();

			if (extension.Compare(_T("obj")))
				name = name + _T(".obj");
		}

		ExportTo3DPDF(name);
	}
}
/*****************************/


/****** API 생성용 변환 함수 ******/
void PmDocument::ImportFromCATIA(CString & path)
{
	if (path.Find(".CATPart") != -1)
	{
		path = _T("translators\\CATIA_api_argv.exe pre ") + path;
		
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);
	}
	else
	{
		path = _T("translators\\CATIA_macro_argv.exe pre ") + path;
		
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);
		/*
		HINSTANCE hDLL;               // Handle to DLL
		StartService fnStartservice;    // Function pointer
		Translate fnTranslate;

		hDLL = LoadLibrary("translators\\CATIApre_DLL.dll");

		if (hDLL != NULL)
		{
			fnStartservice = (StartService)GetProcAddress(hDLL, "CATIAPreStartService");
			fnTranslate = (Translate)GetProcAddress(hDLL, "CATIAPreTranslate");

			// call the function
			fnStartservice();
			fnTranslate((char *)(LPCTSTR)path);
		}

		FreeLibrary(hDLL);
		*/
	}
}

void PmDocument::ExportToCATIA(CString & path)
{
	if (path.Find(".CATPart") != -1)
	{
		path = _T("translators\\CATIA_api_argv.exe post ") + path;
		
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);
	}
	else
	{
		path = _T("translators\\CATIA_macro_argv.exe post ") + path;
		
		LPCSTR command = (LPSTR)(LPCTSTR)path;

		WinExec(command, SW_HIDE);
		/*
		HINSTANCE hDLL;               // Handle to DLL
		StartService fnStartservice;    // Function pointer
		Translate fnTranslate;

		hDLL = LoadLibrary("translators\\CATIApost_DLL.dll");

		if (hDLL != NULL)
		{
			fnStartservice = (StartService)GetProcAddress(hDLL, "CATIAPostStartService");
			fnTranslate = (Translate)GetProcAddress(hDLL, "CATIAPostTranslate");

			// call the function
			fnStartservice();
			fnTranslate((char *)(LPCTSTR)path);
		}

		FreeLibrary(hDLL);
		*/
	}
}

void PmDocument::ImportFromNX(CString & path)
{
	/** NX UG 10.0 버전 전용 **/
	path = _T("translators\\UGPre_argv.exe ") + path;
	
	LPCSTR command = (LPSTR)(LPCTSTR)path;

	WinExec(command, SW_HIDE);
}

void PmDocument::ExportToNX(CString & path)
{
	/** NX UG 10.0 버전 전용 **/
	path = _T("translators\\UGPost_argv.exe ") + path;
	
	LPCSTR command = (LPSTR)(LPCTSTR)path;

	WinExec(command, SW_HIDE);
}

void PmDocument::ImportFromXML(CString & path)
{
	DeleteExistingFeatures();

	if (!CHoopsDoc::OnOpenDocument(path))
		return;
	
	PmePartAPI::LoadXmlMacro(path, m_hPart);
}

void PmDocument::ExportToXML(CString & path)
{
	PmePartAPI::SaveAsXmlMacro(m_hPart, path);
}

void PmDocument::ImportFromETC(CString & path)
{
	DeleteExistingFeatures();
	
	PmeHFeature hImportedBrepFeature = 0;
	PmeStdSolidImportedBrepFeatureAPI::Create(m_hPart, _T("Manifold_Solid_Brep"), path, hImportedBrepFeature);
	ASSERT(hImportedBrepFeature);
}

void PmDocument::ExportToETC(CString & path)
{
	PmeHExplicitModelObject hExplicitModelObject;
	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);
	PmeExplicitModelAPI::GetSolid(hExplicitModel, hExplicitModelObject);
	PmePartAPI::SetName(m_hPart, "Manifold_Solid_Brep");
	
	BODY * pBody = 0;
	PmeSolidAPI::GetSolid(hExplicitModelObject, pBody);

	ENTITY_LIST pEntities;
	pEntities.add((ENTITY*)pBody);

	SPAIAcisDocument source(&pEntities);
	SPAIDocument destination(path);

	SPAIConverter converter;
	SPAIResult result = converter.Convert(source, destination);
}

void PmDocument::ExportToMesh(CString & path)
{
	GenerateMesh(path);
}

void PmDocument::ExportTo3DPDF(CString & path)
{
	// OBJ 파일 생성
	GenerateMesh(path);
	
	CString pathname = path.Left(path.GetLength() - 4);
	CString pathonly = pathname.Left(pathname.ReverseFind('\\'));

	CString cmd;
	
	// OBJ → U3D 변환 (meshlab 사용)
	cmd = _T("meshlab\\meshlabserver_32 -i ") + path + _T(" -o ") + pathname + _T(".u3d");
	system(cmd);
	
	// U3D → 3D PDF 변환 (pdflatex 사용)
	cmd = _T("cd ") + pathonly + _T("& pdflatex ") + pathname + _T(".tex");
	system(cmd);

	// 쓸모없는 파일 지우기
	CString temp;
	temp = pathname + _T(".log");
	remove(temp);
	temp = pathname + _T(".aux");
	remove(temp);
	temp = pathname + _T(".out");
	remove(temp);
	temp = pathname + _T(".obj");
	remove(temp);
	temp = pathname + _T(".u3d");
	remove(temp);
	temp = pathname + _T(".tex");
	remove(temp);
}
/*****************************/


// 스크립트를 직접 입력받아 처리하는 함수. WebTransCAD 모듈에 사용
void PmDocument::RunScriptInterface(CString & command)
{
	StartService fnStartservice;    // Function pointer
	Translate fnTranslate;
	Terminate fnTerminate;

	if (command == "시작" || command == "startservice")
	{
		if (hScriptDLL)
			return;
		else
			hScriptDLL = LoadLibrary("ScriptInterface.dll");
		
		if (hScriptDLL != NULL)
		{
			fnStartservice = (StartService)GetProcAddress(hScriptDLL, "ScriptStartService");
			fnStartservice();
		}
	}
	else if (command == "종료" || command == "endservice")
	{
		if (hScriptDLL != NULL)
		{
			fnTerminate = (Terminate)GetProcAddress(hScriptDLL, "ScriptTerminate");
			fnTerminate();

			FreeLibrary(hScriptDLL);
			hScriptDLL = NULL;
		}
	}
	else
	{
		if (hScriptDLL != NULL)
		{
			fnTranslate = (Translate)GetProcAddress(hScriptDLL, "ScriptRun");
			fnTranslate((char *)(LPCTSTR)command);
		}
	}
}

// 매쉬 파일을 변환하는 함수. Meshlab사용
void PmDocument::ConvertMeshToMesh(CString & source, CString & target)
{
	CString cmd;
	
	// OBJ → U3D 변환 (meshlab 사용)
	cmd = _T("meshlab\\meshlabserver_32 -i ") + source + _T(" -o ") + target;
	system(cmd);
}

// 현재 특징형상을 모두 제거하는 함수
void PmDocument::DeleteExistingFeatures(void)
{
	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);
	
	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);
	
	int size;
	PmeFeaturesAPI::GetSize(hFeatures, size);

	// 가장 최근 피쳐부터 제거
	for (int i = size - 1; i >= 0; --i)
	{
		PmeHFeature hFeature;
		PmeFeaturesAPI::GetItem(hFeatures, i, hFeature);
		CString name;
		PmeFeatureAPI::GetName(hFeature, name);

		// 기본 평면이 아니면 제거
		if (!(name == _T("XYPlane") || name == _T("YZPlane") || name == _T("ZXPlane")))
		{
			PmeFeaturesAPI::DeleteItem(hFeatures, i);
			PmeExplicitModelAPI::DeleteItemByName(hExplicitModel, name);
		}
	}

	UpdateAll(); // 업데이트
}

void PmDocument::DeSelectAll(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
   
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(PmDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(PmView)))
			{
				PmView * pPmView = static_cast<PmView *>(pView);
				PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pPmView->GetHoopsView()->GetSelection());
				pSelection->DeSelectAll();
			}
		}
	}
}

/****** K 모델 생성 ******/
void PmDocument::OnTestmodelCreateLblock(void)
{
	// K1
	bool naming;
	PmePersistentNameAPI::GetNamingMethod(naming);

	if(naming)
	{
		DeleteExistingFeatures();
		
		// apply constrints or not
		bool usingConstraint = false;

		// Select a plane.
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, usingConstraint, hEditor);

		PmeHStdSketchGeometry hTemp = 0, hLine1 = 0, hLine2 = 0;
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0, 0, 100, 0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 100, 0, 100, 50, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 100, 50, 40, 50, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 40, 50, 40, 80, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 40, 80, 0, 80, hLine1);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 0, 80, 0, 0, hLine2);

		/*
		if(usingConstraint)
		{
			// coincident 1
			PmeHReference hReferenceSegement1[6];
			PmeHStdSketchConstraint hConstraint1[6];

			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line1,0,0,0,0,Sketch_Segment", hReferenceSegement1[0]);
			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line2,0,0,0,0,Sketch_Segment", hReferenceSegement1[1]);
			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line3,0,0,0,0,Sketch_Segment", hReferenceSegement1[2]);
			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line4,0,0,0,0,Sketch_Segment", hReferenceSegement1[3]);
			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line5,0,0,0,0,Sketch_Segment", hReferenceSegement1[4]);
			PmePartAPI::SelectSketchGeometryByName(m_hPart, "Sketch1,Line6,0,0,0,0,Sketch_Segment", hReferenceSegement1[5]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident1", hReferenceSegement1[0], PmeSamePointsType_EndPoint, hReferenceSegement1[1], PmeSamePointsType_StartPoint, hConstraint1[0]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident2", hReferenceSegement1[1], PmeSamePointsType_EndPoint, hReferenceSegement1[2], PmeSamePointsType_StartPoint, hConstraint1[1]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident3", hReferenceSegement1[2], PmeSamePointsType_EndPoint, hReferenceSegement1[3], PmeSamePointsType_StartPoint, hConstraint1[2]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident4", hReferenceSegement1[3], PmeSamePointsType_EndPoint, hReferenceSegement1[4], PmeSamePointsType_StartPoint, hConstraint1[3]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident5", hReferenceSegement1[4], PmeSamePointsType_EndPoint, hReferenceSegement1[5], PmeSamePointsType_StartPoint, hConstraint1[4]);
			PmeStdSketchEditorAPI::CreateCoincident(hEditor, "Coincident6", hReferenceSegement1[5], PmeSamePointsType_EndPoint, hReferenceSegement1[0], PmeSamePointsType_StartPoint, hConstraint1[5]);

			// horizontal & vertical 1
			PmeHStdSketchConstraint hHorizontal[3], hVertical[3];
			PmeStdSketchEditorAPI::CreateHorizontal(hEditor, "Horizontal1", hReferenceSegement1[0], hHorizontal[0]);
			PmeStdSketchEditorAPI::CreateHorizontal(hEditor, "Horizontal2", hReferenceSegement1[2], hHorizontal[1]);
			PmeStdSketchEditorAPI::CreateHorizontal(hEditor, "Horizontal3", hReferenceSegement1[4], hHorizontal[2]);
			PmeStdSketchEditorAPI::CreateVertical(hEditor, "Vertical1", hReferenceSegement1[1], hVertical[0]);
			PmeStdSketchEditorAPI::CreateVertical(hEditor, "Vertical2", hReferenceSegement1[3], hVertical[1]);
			PmeStdSketchEditorAPI::CreateVertical(hEditor, "Vertical3", hReferenceSegement1[5], hVertical[2]);

			// perpendicular 1
			PmeHStdSketchConstraint hPerpendicular[6];
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular1", hReferenceSegement1[0], hReferenceSegement1[1], hPerpendicular[0]);
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular2", hReferenceSegement1[1], hReferenceSegement1[2], hPerpendicular[1]);
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular3", hReferenceSegement1[2], hReferenceSegement1[3], hPerpendicular[2]);
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular4", hReferenceSegement1[3], hReferenceSegement1[4], hPerpendicular[3]);
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular5", hReferenceSegement1[4], hReferenceSegement1[5], hPerpendicular[4]);
			PmeStdSketchEditorAPI::CreatePerpendicular(hEditor, "Perpendicular61", hReferenceSegement1[5], hReferenceSegement1[0], hPerpendicular[5]);

		}
		*/
		PmeStdSketchEditorAPI::Close(hEditor);
	
		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Extrude the base sketch.
		PmeHFeature hProtrusionExtrudeFeature = 0;
		PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 80, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
		ASSERT(hProtrusionExtrudeFeature);

		// 	Select one of faces on the L-block.
		PmeHReference hReferenceFace = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line3,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);
		ASSERT(hReferenceFace);

		// Create a hole sketch.
		PmeHFeature hHoleSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReferenceFace, hHoleSketchFeature);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hHoleSketchFeature, MrAxis2(MrPosition(70, 50.0, 40), MrDirection(0.0, 1.0, 0.0), MrDirection(1.0, 0.0, 0.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hHoleSketchFeature, usingConstraint, hEditor);

		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 0.0, 15.0, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the hole sketch.
		PmeFeatureAPI::GetName(hHoleSketchFeature, sketchName);
		PmeHReference hHoleSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hHoleSketch);
		ASSERT(hHoleSketch);

		// Cut the hole sketch.
		PmeHFeature hCutExtrudeFeature = 0;
		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hHoleSketch, 30.0, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
		ASSERT(hCutExtrudeFeature);

		// Select one of the edges to fillet
		PmeHReference hReferenceEdge = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line3,0,0,0,ExtrudeFeature:0,0:0;0#Extrude1,Sketch1,Line4,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceEdge);
		ASSERT(hReferenceEdge);
	
		PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge);

		// Fillet
		PmeHFeature hFilletFeature = 0;
		PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, _T("Fillet1"), hReferenceEdges, 5.0, PmePropagationType_Minimal, hFilletFeature);
		ASSERT(hFilletFeature);
		
		//PmePartAPI::Undo(m_hPart);
		//PmePartAPI::Redo(m_hPart);

		UpdateFitView();
	}
	else
	{
		AfxMessageBox("No testModel for Pointbased method");
	}

}

void PmDocument::OnTestmodelCreateYmodel(void)
{
	// K2
	DeleteExistingFeatures();

	bool naming;
	PmePersistentNameAPI::GetNamingMethod(naming);
	
	if(naming)
	{// Select a plane.
		
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hTemp = 0;

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -237.5, 0, 237.5, 0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 237.5, 0, 237.5, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 237.5, 300, 210, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 210, 300, 0, 125, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 0, 125, -210, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), -210, 300, -237.5, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), -237.5, 300, -237.5, 0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Extrude the base sketch.
		PmeHFeature hProtrusionExtrudeFeature = 0;
		PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 152.5, PmeStdExtrudeEndType_Blind,0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);
		ASSERT(hProtrusionExtrudeFeature);
	
		// Create a base sketch.
		PmeHReference hReferenceFace3 = 0;
 		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace3);
 		ASSERT(hReferenceFace3);

		PmeHFeature hBaseSketchFeature11 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReferenceFace3, hBaseSketchFeature11);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hBaseSketchFeature11, MrAxis2(MrPosition(0.0, 0.0, 152.5), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature11, false, hEditor);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line9"), 104.167, 101.667, 187.5, 185, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line10"), 157.5, 215, 74.167, 131.667, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc3"), 172.5, 200, 187.5, 185, 157.5, 215, hTemp);	
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc4"), 89.167, 116.667, 74.167, 131.667, 104.167, 101.667, hTemp);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line11"), -104.167, 101.667, -187.5, 185, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line12"), -157.5, 215, -74.167, 131.667, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc5"), -172.5, 200, -157.5, 215, -187.5, 185, hTemp);	
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc6"), -89.167, 116.667, -104.167, 101.667, -74.167, 131.667, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		PmeFeatureAPI::GetName(hBaseSketchFeature11, sketchName);
		hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Extrude the base sketch.
		PmeHFeature hCutExtrudeFeature0 = 0;
		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hBaseSketch, 0.0, PmeStdExtrudeEndType_ThroughAll, 0.0, PmeStdExtrudeEndType_ThroughAll, true, hCutExtrudeFeature0);
		ASSERT(hCutExtrudeFeature0);
 
 		PmeHReference hReferenceFace = 0;
 		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line1,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);
 		ASSERT(hReferenceFace);
 
 		// Create a H sketch.
 		PmeHFeature hHSketchFeature = 0;
 		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hReferenceFace, hHSketchFeature);
 		PmeStdSketchFeatureAPI::SetCoordinateSystem(hHSketchFeature, MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, -1.0, 0.0), MrDirection(1.0, 0.0, 0.0)));
 
 		PmeStdSketchFeatureAPI::OpenEditor(hHSketchFeature, false, hEditor);
 
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -37.5, 52.5, 37.5, 52.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 37.5, 52.5, 37.5, 72.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 37.5, 72.5, 10.0, 72.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 10.0, 72.5, 10.0, 132.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 10.0, 132.5, 37.5, 132.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 37.5, 132.5, 37.5, 152.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 37.5, 152.5, -37.5, 152.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), -37.5, 152.5, -37.5, 132.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line9"), -37.5, 132.5, -10.0, 132.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line10"), -10.0, 132.5, -10.0, 72.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line11"), -10.0, 72.5, -37.5, 72.5, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line12"), -37.5, 72.5, -37.5, 52.5, hTemp);
 
 		PmeStdSketchEditorAPI::Close(hEditor);
 
 		PmeHReference hYZPlane = 0;
 		PmePartAPI::SelectObjectByName(m_hPart, _T("YZPlane"), hYZPlane);	
 		ASSERT(hYZPlane);
 
 		// Create a guide sketch.
 		PmeHFeature hGuideSketchFeature = 0;
 		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hYZPlane, hGuideSketchFeature);
 		PmeStdSketchFeatureAPI::SetCoordinateSystem(hGuideSketchFeature, MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(1.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0)));
 
 		PmeStdSketchFeatureAPI::OpenEditor(hGuideSketchFeature, false, hEditor);
 
 		PmeHStdSketchGeometry hLine1;
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0.0, 152.5, -120.0, 152.5, hLine1);
 		PmeHStdSketchGeometry hArc1;
 		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc1"), -120, -62.5, -120, 152.5, -283.16814783, 77.50412684, hArc1);
 		PmeHStdSketchGeometry hLine2;
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), -283.16814783, 77.50412684, -399.10780871, -57.61816414, hLine2);
		 PmeHStdSketchGeometry hArc2;
 		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc2"), -475, 7.5, -475, -92.5, -399.10780871, -57.61816414, hArc2);
 		PmeHStdSketchGeometry hLine3;
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), -475, -92.5, -700, -92.5, hLine3);
 
 		PmeStdSketchEditorAPI::Close(hEditor);
 
 		// Select the H sketch.
 		PmeFeatureAPI::GetName(hHSketchFeature, sketchName);
 		PmeHReference hHSketch = 0;
 		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hHSketch);
 		ASSERT(hHSketch);
 
 		PmeFeatureAPI::GetName(hGuideSketchFeature, sketchName);
 		PmeHReference hGuideSketch = 0;
 		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hGuideSketch);
 		ASSERT(hGuideSketch);
 
 		PmeHFeature hHSweepFeature = 0;
 		PmeStdSolidProtrusionSweepFeatureAPI::Create(m_hPart, _T("Sweep1"), hHSketch, hGuideSketch, hHSweepFeature);
 		ASSERT(hHSweepFeature);
 
 		PmeHFeature hRevolvingSketchFeature = 0;
 		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hYZPlane, hRevolvingSketchFeature);
 		PmeStdSketchFeatureAPI::SetCoordinateSystem(hRevolvingSketchFeature, MrAxis2(MrPosition(0.0, -700, -92.5 -100.0), MrDirection(1.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0)));
 
 		PmeStdSketchFeatureAPI::OpenEditor(hRevolvingSketchFeature, false, hEditor);
 
 		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
 
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0.0, -10.0, 80.0, -10.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 80.0, -10.0, 80.0, 20.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 80.0, 20.0, 80.0 - 27.5, 20.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 80.0 - 27.5, 20.0, 80.0 - 27.5, 80.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 80.0 - 27.5, 80.0, 80.0, 80.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 80.0, 80.0, 80.0, 100.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 80.0, 100.0, 0.0, 100.0, hTemp);
 		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), 0.0, 100.0, 0.0, -10.0, hTemp);
 	
 		PmeStdSketchEditorAPI::Close(hEditor);
 
 		// Select the sketch.
 		PmeFeatureAPI::GetName(hRevolvingSketchFeature, sketchName);
 		PmeHReference hRevolvingSketch = 0;
 		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hRevolvingSketch);
 		ASSERT(hRevolvingSketch);
 
 		// Revolution
 		PmeHFeature hRevolveFeature = 0;
 		PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _T("Revolve1"), hRevolvingSketch, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature);
 		ASSERT(hRevolveFeature);
 
 		PmeHReference hReferenceFace2 = 0;
 		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch5,Line7,0,0,0,RevolveFeature:0,0:0;0"), hReferenceFace2);
 		ASSERT(hReferenceFace2);
 	
 		PmeHFeature hCircularSketchFeature = 0;
 		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch6"), hReferenceFace2, hCircularSketchFeature);
 		PmeStdSketchFeatureAPI::SetCoordinateSystem(hCircularSketchFeature, MrAxis2(MrPosition(0.0, -700, -92.5), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));
 
 		PmeStdSketchFeatureAPI::OpenEditor(hCircularSketchFeature, false, hEditor);
 
 		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 0.0, 35.0, hTemp);	
 	
 		PmeStdSketchEditorAPI::Close(hEditor);
 
 		// Select the sketch.
 		PmeFeatureAPI::GetName(hCircularSketchFeature, sketchName);
 		PmeHReference hCircularSketch = 0;
 		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hCircularSketch);
 		ASSERT(hCircularSketch);
 
 		// Cut the hole sketch.
 		PmeHFeature hCutExtrudeFeature = 0;
 		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut2"), hCircularSketch, 0.0, PmeStdExtrudeEndType_ThroughAll, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
 		ASSERT(hCutExtrudeFeature);

		// Select one of the edges to fillet
		PmeHReference hReferenceEdge = 0; 
		PmeHReference hReferenceEdge1 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line1,0,0,0,ExtrudeFeature:0,0:0;0#Extrude1,Sketch1,Line2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceEdge);
		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line1,0,0,0,ExtrudeFeature:0,0:0;0#Extrude1,Sketch1,Line7,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceEdge1);
		ASSERT(hReferenceEdge);
		ASSERT(hReferenceEdge1);
	
		PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge1);

		// Fillet
		PmeHFeature hFilletFeature = 0;
		PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, _T("Fillet1"), hReferenceEdges, 132.5, PmePropagationType_Minimal, hFilletFeature);
		ASSERT(hFilletFeature);

		UpdateFitView();
	}
	else
	{	// Select a plane.
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hTemp = 0;

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -237.5, 0, 237.5, 0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 237.5, 0, 237.5, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 237.5, 300, 210, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 210, 300, 0, 125, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 0, 125, -210, 300, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), -210, 300, -237.5, 300, hTemp);	
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), -237.5, 300, -237.5, 0, hTemp);	

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), 104.167, 101.667, 187.5, 185, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc1"), 172.5, 200, 187.5, 185, 157.5, 215, hTemp);	
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line9"), 157.5, 215, 74.167, 131.667, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc2"), 89.167, 116.667, 74.167, 131.667, 104.167, 101.667, hTemp);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line10"), -104.167, 101.667, -187.5, 185, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc3"), -172.5, 200, -157.5, 215, -187.5, 185, hTemp);	
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line11"), -157.5, 215, -74.167, 131.667, hTemp);
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc4"), -89.167, 116.667, -104.167, 101.667, -74.167, 131.667, hTemp);


		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Extrude the base sketch.
		PmeHFeature hProtrusionExtrudeFeature = 0;
		PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 152.5, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
		ASSERT(hProtrusionExtrudeFeature);


		// Select one edge for fillet
		PmeHReference hReferenceEdge = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("EDGE,Pad1,(237.50,0.00,0.00),Pad1,(237.50,0.00,152.50)"), hReferenceEdge);
		ASSERT(hReferenceEdge);

		PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge);

		// Fillet
		PmeHFeature hFilletFeature = 0;
		PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, _T("Fillet1"), hReferenceEdges, 132.5, PmePropagationType_Minimal, hFilletFeature);
		ASSERT(hFilletFeature);


		// Select one more edge for fillet2
		PmePartAPI::SelectBrepByName(m_hPart, _T("EDGE,Pad1,(-237.50,0.00,0.00),Pad1,(-237.50,0.00,152.50)"), hReferenceEdge);
		ASSERT(hReferenceEdge);

		//PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge);

		// Fillet
		//PmeHFeature hFilletFeature = 0;
		PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, _T("Fillet2"), hReferenceEdges, 132.5, PmePropagationType_Minimal, hFilletFeature);
		ASSERT(hFilletFeature);	


		PmeHReference hReferenceFace = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("FACE,4,Fillet1,(-105.00,0.00,152.50),Fillet1,(-105.00,0.00,0.00),Fillet1,(105.00,0.00,0.00),Fillet1,(105.00,0.00,152.50)"), hReferenceFace);
		ASSERT(hReferenceFace);	

		// Create a H sketch.
		PmeHFeature hHSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReferenceFace, hHSketchFeature);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hHSketchFeature, MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, -1.0, 0.0), MrDirection(1.0, 0.0, 0.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hHSketchFeature, false, hEditor);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -37.5, 52.5, 37.5, 52.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 37.5, 52.5, 37.5, 72.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 37.5, 72.5, 10.0, 72.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 10.0, 72.5, 10.0, 132.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 10.0, 132.5, 37.5, 132.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 37.5, 132.5, 37.5, 152.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 37.5, 152.5, -37.5, 152.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), -37.5, 152.5, -37.5, 132.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line9"), -37.5, 132.5, -10.0, 132.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line10"), -10.0, 132.5, -10.0, 72.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line11"), -10.0, 72.5, -37.5, 72.5, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line12"), -37.5, 72.5, -37.5, 52.5, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		PmeHReference hYZPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("YZPlane"), hYZPlane);	
		ASSERT(hYZPlane);

		// Create a guide sketch.
		PmeHFeature hGuideSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hYZPlane, hGuideSketchFeature);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hGuideSketchFeature, MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0), MrDirection(0.0, 0.0, 1.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hGuideSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hLine1;
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0.0, 152.5, -120.0, 152.5, hLine1);
		PmeHStdSketchGeometry hArc1;
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc1"), -120, -62.5, -120, 152.5, -283.16814783, 77.50412684, hArc1);
		PmeHStdSketchGeometry hLine2;
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), -283.16814783, 77.50412684, -399.10780871, -57.61816414, hLine2);
		PmeHStdSketchGeometry hArc2;
		PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(hEditor, _T("Arc2"), -475, 7.5, -475, -92.5, -399.10780871, -57.61816414, hArc2);
		PmeHStdSketchGeometry hLine3;
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), -475, -92.5, -700, -92.5, hLine3);
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the H sketch.
		PmeFeatureAPI::GetName(hHSketchFeature, sketchName);
		PmeHReference hHSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hHSketch);
		ASSERT(hHSketch);

		PmeFeatureAPI::GetName(hGuideSketchFeature, sketchName);
		PmeHReference hGuideSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hGuideSketch);
		ASSERT(hGuideSketch);

		PmeHFeature hHSweepFeature = 0;
		PmeStdSolidProtrusionSweepFeatureAPI::Create(m_hPart, _T("Sweep1"), hHSketch, hGuideSketch, hHSweepFeature);
		ASSERT(hHSweepFeature);


		PmeHFeature hRevolvingSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hYZPlane, hRevolvingSketchFeature);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hRevolvingSketchFeature, MrAxis2(MrPosition(0.0, -700, -192.5 ), MrDirection(1.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hRevolvingSketchFeature, false, hEditor);

		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0.0, 0.0, 80.0, 0.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 80.0, 0.0, 80.0, 20.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 80.0, 20.0, 80.0 - 27.5, 20.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 80.0 - 27.5, 20.0, 80.0 - 27.5, 80.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 80.0 - 27.5, 80.0, 80.0, 80.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 80.0, 80.0, 80.0, 100.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 80.0, 100.0, 0.0, 100.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), 0.0, 100.0, 0.0, 0.0, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the sketch.
		PmeFeatureAPI::GetName(hRevolvingSketchFeature, sketchName);
		PmeHReference hRevolvingSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hRevolvingSketch);
		ASSERT(hRevolvingSketch);

		// Revolution
		PmeHFeature hRevolveFeature = 0;
		PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _T("Revolve1"), hRevolvingSketch, 365.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature);
		ASSERT(hRevolveFeature);


		PmeHReference hReferenceFace2 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("FACE,4,SWEEP1,(-37.50,-92.50,700.00),SWEEP1,(37.50,-92.50,700.00),SWEEP1,(37.50,-92.50,475.00),SWEEP1,(-37.50,-92.50,475.00)"), hReferenceFace2);
		ASSERT(hReferenceFace2);

		PmeHFeature hCircularSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hReferenceFace2, hCircularSketchFeature);
		PmeStdSketchFeatureAPI::SetCoordinateSystem(hCircularSketchFeature, MrAxis2(MrPosition(0.0, -700.0, -92.5), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));
		PmeStdSketchFeatureAPI::OpenEditor(hCircularSketchFeature, false, hEditor);

		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 0.0, 35.0, hTemp);	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the sketch.
		PmeFeatureAPI::GetName(hCircularSketchFeature, sketchName);
		PmeHReference hCircularSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hCircularSketch);
		ASSERT(hCircularSketch);

		// Cut the hole sketch.
		PmeHFeature hCutExtrudeFeature = 0;
		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hCircularSketch, 0.0, PmeStdExtrudeEndType_ThroughAll, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
		ASSERT(hCutExtrudeFeature);
	}
}

void PmDocument::OnTestmodelCreateGasspring(void)
{
	// K3
	DeleteExistingFeatures();
	bool naming;
	PmePersistentNameAPI::GetNamingMethod(naming);
	
	if(naming)
	{
		// Select a plane.
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hTemp = 0;

		const double C = 150.0;
		const double STROKE = 30.0;

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0, 0, 75.0 * 0.5, 0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 75.0 * 0.5, 0, 75.0 * 0.5, C, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 75.0 * 0.5, C, 36.0 * 0.5, C, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 36.0 * 0.5, C, 36.0 * 0.5, C + STROKE, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 36.0 * 0.5, C + STROKE, 0.0, C + STROKE, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 0.0, C + STROKE, 0.0, 0.0, hTemp);

		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Revolution
		PmeHFeature hRevolveFeature = 0;
		PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _T("Revolve1"), hBaseSketch, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature);
		ASSERT(hRevolveFeature);

		// Create a cut sketch.
		PmeHReference hReference = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line5,0,0,0,RevolveFeature:0,0:0;0"), hReference);
		ASSERT(hReference);

		PmeHFeature hSketchFeature5 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReference, hSketchFeature5);

		PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature5, false, hEditor);
		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), -9, 0, 10, hTemp);
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName5;
		PmeFeatureAPI::GetName(hSketchFeature5, sketchName5);
		PmeHReference hSketch5 = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName5, hSketch5);
		ASSERT(hSketch5);

		PmeHFeature hCutExtrudeFeature1 = 0;
		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hSketch5, 10.0, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature1);
		ASSERT(hCutExtrudeFeature1);

		// Chamfer1
		PmeHReference hReferenceEdge1 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line5,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line4,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge1);
		ASSERT(hReferenceEdge1);

		PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge1);

		PmeHFeature hChamferFeature1 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer1"), hReferenceEdges, 2.5, hChamferFeature1);
		ASSERT(hChamferFeature1);

		PmeReferencesAPI::Delete(hReferenceEdges);

		// Chamfer2
		PmeHReference hReferenceEdge2 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line3,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line2,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge2);
		ASSERT(hReferenceEdge2);
	
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge2);

		PmeHFeature hChamferFeature2 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer2"), hReferenceEdges, 2.5, hChamferFeature2);
		ASSERT(hChamferFeature2);
		
		PmeReferencesAPI::Delete(hReferenceEdges);

		//// Chamfer3
		PmeHReference hReferenceEdge3 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line2,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line1,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge3);
		ASSERT(hReferenceEdge3);
	
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge3);

		PmeHFeature hChamferFeature3 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer3"), hReferenceEdges, 2.5, hChamferFeature3);
		ASSERT(hChamferFeature3);
		
		PmeReferencesAPI::Delete(hReferenceEdges);
				
		// Create a revolve cut sketch.
		PmeHFeature hSketchFeature2 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hXYPlane, hSketchFeature2);

		PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature2, false, hEditor);

		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 75.0 * 0.5, C - 21.0, 2.5, hTemp);
		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName2;
		PmeFeatureAPI::GetName(hSketchFeature2, sketchName2);
		PmeHReference hSketch2 = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName2, hSketch2);
		ASSERT(hSketch2);

		PmeHFeature hRevolveFeature2 = 0;
		PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, _T("Revolve2"), hSketch2, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature2);
		ASSERT(hRevolveFeature2);

		// Create a revolve cut sketch.
		PmeHFeature hSketchFeature3 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hXYPlane, hSketchFeature3);

		PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature3, false, hEditor);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 75.0 * 0.5, 8.0, 75.0 * 0.5, 8.0 + 7.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 75.0 * 0.5, 8.0 + 7.0, 75.0 * 0.5 - 4.0, 8.0 + 7.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 75.0 * 0.5 - 4.0, 8.0 + 7.0, 75.0 * 0.5 - 4.0, 8.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 75.0 * 0.5 - 4.0, 8.0, 75.0 * 0.5, 8.0, hTemp);	
	
		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName3;
		PmeFeatureAPI::GetName(hSketchFeature3, sketchName3);
		PmeHReference hSketch3 = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName3, hSketch3);
		ASSERT(hSketch3);

		PmeHFeature hRevolveFeature3 = 0;
		PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, _T("Revolve3"), hSketch3, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature3);
		ASSERT(hRevolveFeature3);


		PmeHFeature hMyPlane = 0;
		//PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane"), MrAxis2(MrPosition(0, 0, 0), MrDirection(0.0, 1.0, 0.0), MrDirection(1.0, 0.0, 1.0)), hMyPlane);
		
		PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane1"), hXYPlane, 37.5, false, hMyPlane);
		ASSERT(hMyPlane);

		PmeHReference hNewPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("MyPlane1"), hNewPlane);	
		ASSERT(hNewPlane);


		// Create a hole sketch.
		PmeHFeature hHoleSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hNewPlane, hHoleSketchFeature);
		//PmeStdSketchFeatureAPI::SetCoordinateSystem(hHoleSketchFeature, MrAxis2(MrPosition(70.0, 50.0, 40), MrDirection(0.0, 1.0, 0.0), MrDirection(1.0, 0.0, 0.0)));

		PmeStdSketchFeatureAPI::OpenEditor(hHoleSketchFeature, false, hEditor);

		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 11.5, 8.0, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the hole sketch.
		CString sketchName4;
		PmeFeatureAPI::GetName(hHoleSketchFeature, sketchName4);
		PmeHReference hHoleSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName4, hHoleSketch);
		ASSERT(hHoleSketch);

		// Cut the hole sketch.
		PmeHFeature hCutExtrudeFeature = 0;
		PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut2"), hHoleSketch, 10.0, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
		ASSERT(hCutExtrudeFeature);
	}
	else
	{
		// Select a plane.
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);
		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hTemp = 0;

		const double C = 150.0;
		const double STROKE = 30.0;

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0, 0, 75.0 * 0.5, 0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 75.0 * 0.5, 0, 75.0 * 0.5, C, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 75.0 * 0.5, C, 36.0 * 0.5, C, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 36.0 * 0.5, C, 36.0 * 0.5, C + STROKE, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 36.0 * 0.5, C + STROKE, 0.0, C + STROKE, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 0.0, C + STROKE, 0.0, 0.0, hTemp);

		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		// Revolution
		PmeHFeature hRevolveFeature = 0;
		PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _T("Revolve1"), hBaseSketch, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature);
		ASSERT(hRevolveFeature);
	
	
		// Chamfer1
		PmeHReference hReferenceEdge1 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line5,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line4,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge1);
		ASSERT(hReferenceEdge1);

		PmeHReferences hReferenceEdges = 0;
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge1);

		PmeHFeature hChamferFeature1 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer1"), hReferenceEdges, 2.5, hChamferFeature1);
		ASSERT(hChamferFeature1);

		PmeReferencesAPI::Delete(hReferenceEdges);

		// Chamfer2
		PmeHReference hReferenceEdge2 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line3,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line2,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge2);
		ASSERT(hReferenceEdge2);
	
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge2);

		PmeHFeature hChamferFeature2 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer2"), hReferenceEdges, 2.5, hChamferFeature2);
		ASSERT(hChamferFeature2);
		
		PmeReferencesAPI::Delete(hReferenceEdges);

		//// Chamfer3
		PmeHReference hReferenceEdge3 = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line2,0,0,0,RevolveFeature:0,0:0;0#Revolve1,Sketch1,Line1,0,0,0,RevolveFeature:0,0:0;0"), hReferenceEdge3);
		ASSERT(hReferenceEdge3);
	
		PmeReferencesAPI::Create(hReferenceEdges);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge3);

		PmeHFeature hChamferFeature3 = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer3"), hReferenceEdges, 2.5, hChamferFeature3);
		ASSERT(hChamferFeature3);
		
		PmeReferencesAPI::Delete(hReferenceEdges);

		// Create a revolve cut sketch.
		PmeHFeature hSketchFeature2 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hXYPlane, hSketchFeature2);

		PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature2, false, hEditor);

		PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 75.0 * 0.5, C - 21.0, 2.5, hTemp);
		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName2;
		PmeFeatureAPI::GetName(hSketchFeature2, sketchName2);
		PmeHReference hSketch2 = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName2, hSketch2);
		ASSERT(hSketch2);

		PmeHFeature hRevolveFeature2 = 0;
		PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, _T("Revolve2"), hSketch2, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature2);
		ASSERT(hRevolveFeature2);
	
		// Create a revolve cut sketch.
		PmeHFeature hSketchFeature3 = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hXYPlane, hSketchFeature3);

		PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature3, false, hEditor);

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 75.0 * 0.5, 8.0, 75.0 * 0.5, 8.0 + 7.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 75.0 * 0.5, 8.0 + 7.0, 75.0 * 0.5 - 4.0, 8.0 + 7.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 75.0 * 0.5 - 4.0, 8.0 + 7.0, 75.0 * 0.5 - 4.0, 8.0, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 75.0 * 0.5 - 4.0, 8.0, 75.0 * 0.5, 8.0, hTemp);	
	
		PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);
	
		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName3;
		PmeFeatureAPI::GetName(hSketchFeature3, sketchName3);
		PmeHReference hSketch3 = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName3, hSketch3);
		ASSERT(hSketch3);

		PmeHFeature hRevolveFeature3 = 0;
		PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, _T("Revolve3"), hSketch3, 360.0, PmeStdRevolveEndType_Blind, 0.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature3);
		ASSERT(hRevolveFeature3);
	}

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateLinearsensor(void)
{
	// K4
	DeleteExistingFeatures();
	
	const double width = 150;
	const double length = 50;
	const double height = 45;

	const double width2 = 40;
	const double height2 = 20;
	
	const double width3 = 20;
	const double height3 = 20;

	const double radius = 10;
	
	const double width4 = 7.5;
	const double height4 = 3;

	PmeHReference hReference1 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("YZPlane"), hReference1);
	ASSERT(hReference1);

	PmeHFeature hSketchFeature1 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hReference1, hSketchFeature1);

	PmeHStdSketchEditor hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature1, false, hEditor);

	PmeHStdSketchGeometry hGeometry = 0;

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -length, 0, length, 0, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), length, 0, length, height, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), length, height, -length, height, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -length, height, -length, 0, hGeometry);	
	
	PmeStdSketchEditorAPI::Close(hEditor);

	CString sketchName;
	PmeFeatureAPI::GetName(hSketchFeature1, sketchName);
	PmeHReference hReference2 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference2);
	ASSERT(hReference2);

	PmeHFeature hProtrusionExtrudeFeature1 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hReference2, width, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature1);
	ASSERT(hProtrusionExtrudeFeature1);
	
	PmeHReference hReference112 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line2,0,0,0,ExtrudeFeature:0,0:0;0"), hReference112);
	ASSERT(hReference112);

	PmeHFeature hSketchFeature11 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReference112, hSketchFeature11);

	PmeHStdSketchEditor hEditor11 = 0;
	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature11, MrAxis2(MrPosition(width*0.5, length, 0), MrDirection(0.0, 1.0, 0.0), MrDirection(-1.0, 0.0, 0.0)));
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature11, false, hEditor11);

	PmeHStdSketchGeometry hGeometry11 = 0;
	
	PmeStdSketchEditorAPI::CreateLine(hEditor11, _T("Line1"), -width*0.5 + 3, 3, width*0.5 - 3, 3, hGeometry11);
	PmeStdSketchEditorAPI::CreateLine(hEditor11, _T("Line2"), width*0.5 - 3, 3, width*0.5 - 3, height - 3, hGeometry11);
	PmeStdSketchEditorAPI::CreateLine(hEditor11, _T("Line3"), width*0.5 - 3, height - 3, -width*0.5 + 3, height - 3, hGeometry11);
	PmeStdSketchEditorAPI::CreateLine(hEditor11, _T("Line4"), -width*0.5 + 3, height - 3, -width*0.5 + 3, 3, hGeometry11);	

	PmeStdSketchEditorAPI::Close(hEditor11);

	PmeFeatureAPI::GetName(hSketchFeature11, sketchName);
	PmeHReference hReference111 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference111);
	ASSERT(hReference111);

	PmeHFeature hCutExtrudeFeature11 = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hReference111, 150, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature11);
	ASSERT(hCutExtrudeFeature11);	

	PmeHReference hReference3 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line3,0,0,0,ExtrudeFeature:0,0:0;0"), hReference3);
	ASSERT(hReference3);

	PmeHFeature hSketchFeature2 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hReference3, hSketchFeature2);
	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature2, MrAxis2(MrPosition(width * 0.5, 0, height), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));

	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature2, false, hEditor);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -width2, -height2, width2, -height2, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), width2, -height2, width2, height2, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), width2, height2, -width2, height2, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -width2, height2, -width2, -height2, hGeometry);
	
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature2, sketchName);
	PmeHReference hReference4 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference4);
	ASSERT(hReference4);

	PmeHFeature hCutExtrudeFeature1 = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut2"), hReference4, 25, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature1);
	ASSERT(hCutExtrudeFeature1);	

	PmeHReference hReference5 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Cut1,Sketch2,Line1,0,0,0,ExtrudeFeature:0,0:0;0"), hReference5);
	ASSERT(hReference5);

	PmeHFeature hSketchFeature3 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hReference5, hSketchFeature3);
	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature3, MrAxis2(MrPosition(width * 0.5, 0, 3), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));

	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature3, false, hEditor);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -width3, -height3, width3, -height3, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), width3, -height3, width3, height3, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), width3, height3, -width3, height3, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -width3, height3, -width3, -height3, hGeometry);
	
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature3, sketchName);
	PmeHReference hReference6 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference6);
	ASSERT(hReference6);

	PmeHFeature hProtrusionExtrudeFeature2 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude2"), hReference6, 38, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature2);
	ASSERT(hProtrusionExtrudeFeature2);

	PmeHReference hReference7 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude2,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReference7);
	ASSERT(hReference7);

	PmeHFeature hSketchFeature4 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hReference7, hSketchFeature4);
	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature4, MrAxis2(MrPosition(width * 0.5, 0, 41), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0)));

	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature4, false, hEditor);

	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 0.0, radius, hGeometry);	
	
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature4, sketchName);
	PmeHReference hReference8 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference8);
	ASSERT(hReference8);

	PmeHFeature hProtrusionExtrudeFeature3 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude3"), hReference8, 40, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature3);
	ASSERT(hProtrusionExtrudeFeature3);

	// Chamfer 특징형상
	PmeHReference hReference9 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude3,Sketch5,Circle1,0,0,0,ExtrudeFeature:0,0:0;0#Extrude3,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReference9);
	ASSERT(hReference9);
	
	PmeHReferences hReferenceEdges = 0;
	PmeReferencesAPI::Create(hReferenceEdges);
	PmeReferencesAPI::AddItem(hReferenceEdges, hReference9);

	PmeHFeature hChamferFeature1 = 0;
	PmeStdSolidChamferFeatureAPI::Create(m_hPart, _T("Chamfer1"), hReferenceEdges, 3, hChamferFeature1);
	ASSERT(hChamferFeature1);

	PmeReferencesAPI::Delete(hReferenceEdges);
	//

	PmeHReference hReference10 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,Sketch1,Line1,0,0,0,ExtrudeFeature:0,0:0;0"), hReference10);
	ASSERT(hReference10);

	PmeHFeature hSketchFeature5 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch6"), hReference10, hSketchFeature5);
	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature5, MrAxis2(MrPosition(18.5, 25, 0), MrDirection(0.0, 0.0, -1.0), MrDirection(-1.0, 0.0, 0.0)));

	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature5, false, hEditor);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -width4, -height4, width4, -height4, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), width4, -height4, width4, height4, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), width4, height4, -width4, height4, hGeometry);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -width4, height4, -width4, -height4, hGeometry);
	
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature5, sketchName);
	PmeHReference hReference11 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hReference11);
	ASSERT(hReference11);

	PmeHFeature hProtrusionExtrudeFeature4 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude4"), hReference11, 38, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature4);
	ASSERT(hProtrusionExtrudeFeature4);

	CString featureName;
	PmeFeatureAPI::GetName(hProtrusionExtrudeFeature4, featureName);
	PmeHReference hReference12 = 0;
	PmePartAPI::SelectFeatureByName(m_hPart, featureName, hReference12);
	ASSERT(hReference12);
	
	PmeHReferences hReferenceFeatures = 0;
	PmeReferencesAPI::Create(hReferenceFeatures);
	PmeReferencesAPI::AddItem(hReferenceFeatures, hReference12);

    PmeHFeature hPatternFeature1 = 0;
	PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, _T("Pattern1"), hReferenceFeatures,
		25, MrDirection(1.0, 0.0, 0.0), 2,
		25, MrDirection(0.0, -1.0, 0.0), 3,
		hPatternFeature1);
	ASSERT(hPatternFeature1);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateEngineAirFilterHousing(void)
{
	// K5
	DeleteExistingFeatures();

	MrAxis2 coordinateSystem;
	MrAxis1 axis;
	MrDirection coord;

	// Select a plane.
	PmeHReference hXYPlane = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
	ASSERT(hXYPlane);

	// Create a base sketch.
	PmeHFeature hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

	PmeHStdSketchEditor hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	PmeHStdSketchGeometry hTemp = 0;

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 0, 0, 100, 0, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 100, 0, 100, 5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 100, 5, 80, 5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 80, 5, 80, 95, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), 80, 95,100,95, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 100, 95,100,100, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 100, 100,0,100, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), 0, 100,0,0, hTemp);
	PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("Centerline1"), 0.0, 0.0, 0.0, 100.0, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	// Select the base sketch.
	CString sketchName;
	PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
	PmeHReference hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
	ASSERT(hBaseSketch);
	// Revolution
	PmeHFeature hRevolveFeature = 0;
	PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _T("Revolve1"), hBaseSketch, 0.0, PmeStdRevolveEndType_Blind, 360.0, PmeStdRevolveEndType_Blind, false, hRevolveFeature);
	ASSERT(hRevolveFeature);

	PmeHReference hReferenceFace = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("ZXPlane"), hReferenceFace);	
	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), 90, 90, -90, 90, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), -90, 90, -90, -90, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), -90, -90, 90, -90, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 90,-90, 90, 90, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	// Select the base sketch.
	sketchName="Sketch2";
	PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
	hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
	ASSERT(hBaseSketch);

	// Extrude the base sketch.
	PmeHFeature hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 5, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);

	hReferenceFace = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("ZXPlane"), hReferenceFace);	
	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 80.0, 80.0, 5, hTemp);	
	PmeStdSketchEditorAPI::Close(hEditor);
	
	PmeHFeature hHoleSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch3"), hHoleSketch);
	ASSERT(hHoleSketch);

	PmeHFeature hCutExtrudeFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hHoleSketch, 5, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, true, hCutExtrudeFeature);
	ASSERT(hCutExtrudeFeature);

	PmeHReference hReferencepatt1= 0;
	PmePartAPI::SelectFeatureByName(m_hPart, "Cut1", hReferencepatt1);
	ASSERT(hReferencepatt1);

	PmeHReferences hReferenceFeatures = 0;
	PmeReferencesAPI::Create(hReferenceFeatures);
	PmeReferencesAPI::AddItem(hReferenceFeatures, hReferencepatt1);

	PmeHFeature hPatternFeature1 = 0;
	PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, _T("Pattern1"), hReferenceFeatures,
		160, MrDirection(-1.0, 0.0, 0.0), 2,
		160, MrDirection(0.0, 0.0, -1.0), 2,
		hPatternFeature1);
	ASSERT(hPatternFeature1);

	hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line7,0,0,0,RevolveFeature:0,0:0;0"), hReferenceFace);
	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 15, 65, 5, hTemp);	
	PmeStdSketchEditorAPI::Close(hEditor);
	hHoleSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch4"), hHoleSketch);
	ASSERT(hHoleSketch);

	hCutExtrudeFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut2"), hHoleSketch, 5, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
	ASSERT(hCutExtrudeFeature);

	PmeHReference hReferencepatt2 = 0;
	PmePartAPI::SelectFeatureByName(m_hPart, "Cut2", hReferencepatt2);
	ASSERT(hReferencepatt2);
	
	PmeHReferences hReferenceFeatures1 = 0;
	PmeReferencesAPI::Create(hReferenceFeatures1);
	PmeReferencesAPI::AddItem(hReferenceFeatures1, hReferencepatt2);

	PmeHFeature hPatternFeature2 = 0;
	PmeStdSolidOperatePatternCircularFeatureAPI::Create(m_hPart, _T("Pattern2"), hReferenceFeatures1, MrAxis1(MrPosition(0, 0, 0), MrDirection(0, 1, 0)), 4, 90, 1, 0, true, hPatternFeature2);
	ASSERT(hPatternFeature2);

	hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Revolve1,Sketch1,Line7,0,0,0,RevolveFeature:0,0:0;0"), hReferenceFace);
	ASSERT(hReferenceFace);
	
	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;

	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), -50.0, 0.0, 75, hTemp);	
	PmeStdSketchEditorAPI::Close(hEditor);

	hHoleSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch5"), hHoleSketch);
	ASSERT(hHoleSketch);

	// Cut the hole sketch.
	hCutExtrudeFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut3"), hHoleSketch, 95.0, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
	ASSERT(hCutExtrudeFeature);

	hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Cut3,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);

	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch6"), hReferenceFace, hBaseSketchFeature);
	
	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0,0,60, hTemp);	

	PmeStdSketchEditorAPI::Close(hEditor);

	hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch6"), hBaseSketch);
	ASSERT(hBaseSketch);
	hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude2"), hBaseSketch, 20, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);

	hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude2,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);

	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch7"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0,0,25, hTemp);	
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle2"), 0,0,20, hTemp);	

	PmeStdSketchEditorAPI::Close(hEditor);

	hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch7"), hBaseSketch);
	ASSERT(hBaseSketch);
	hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude3"), hBaseSketch, 20, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);

	hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude2,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);

	ASSERT(hReferenceFace);

	// Create a base sketch.
	hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch8"), hReferenceFace, hBaseSketchFeature);

	hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	hTemp = 0;
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0,0,10, hTemp);	
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle2"), 0,0,5, hTemp);	

	PmeStdSketchEditorAPI::Close(hEditor);

	hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch8"), hBaseSketch);
	ASSERT(hBaseSketch);
	hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude4"), hBaseSketch, 20, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);

	UpdateFitView();	
}

void PmDocument::OnTestmodelCreatePneumaticCylinder(void)
{
	// K6
	DeleteExistingFeatures();

	// Select a plane.
	PmeHReference hXYPlane = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
	ASSERT(hXYPlane);

	// Create a base sketch.
	PmeHFeature hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

	PmeHStdSketchEditor hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

	PmeHStdSketchGeometry hTemp = 0;
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -62.5, -62.5, 62.5, -62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 62.5, -62.5, 62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 62.5, 62.5, -62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -62.5, 62.5, -62.5, -62.5, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	// Select the base sketch.
	CString sketchName;
	PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
	PmeHReference hBaseSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
	ASSERT(hBaseSketch);

	// Extrude the base sketch.
	PmeHFeature hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 42.18, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);

	// Select one of faces on the block.
	PmeHReference hReferenceFace = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace);
	ASSERT(hReferenceFace);

	// Create a cylinder sketch.
	PmeHFeature hCylinderSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hReferenceFace, hCylinderSketchFeature);
	
	PmeStdSketchFeatureAPI::OpenEditor(hCylinderSketchFeature, false, hEditor);

	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle1"), 0.0, 0.0, 40.5, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	// Select the cylinder sketch.
	PmeFeatureAPI::GetName(hCylinderSketchFeature, sketchName);
	PmeHReference hCylinderSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hCylinderSketch);
	ASSERT(hCylinderSketch);

	// Extrude the cylinder sketch.
	PmeHFeature hCylinderExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude2"), hCylinderSketch, 190.64, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCylinderExtrudeFeature);
	ASSERT(hCylinderExtrudeFeature);

	// Select the face on top of the cylinder
	PmeHReference hReferenceFace2 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude2,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace2);

	// Create a block sketch
	PmeHFeature hBlockSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hReferenceFace2, hBlockSketchFeature);
	PmeStdSketchFeatureAPI::OpenEditor(hBlockSketchFeature, false, hEditor);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -62.5, -62.5, 62.5, -62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 62.5, -62.5, 62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 62.5, 62.5, -62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -62.5, 62.5, -62.5, -62.5, hTemp);
	PmeStdSketchEditorAPI::Close(hEditor);

	// Select the block sketch.
	PmeFeatureAPI::GetName(hBlockSketchFeature, sketchName);
	PmeHReference hBlockSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBlockSketch);
	ASSERT(hBaseSketch);

	// Extrude the block sketch.
	PmeHFeature hBlockExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude3"), hBlockSketch, 42.18, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hBlockExtrudeFeature);	
	ASSERT(hBlockExtrudeFeature);

	PmeHReference hReferenceFace3 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace3);

	PmeHFeature hSketchFeature3 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hReferenceFace3, hSketchFeature3);
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature3, false, hEditor);
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle2"), 48.25, 12.05, 5.175, hTemp);
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature3, sketchName);
	PmeHReference hSketch3 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hSketch3);
	ASSERT(hSketch3);

	PmeHFeature hExtrudeFeature3 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude4"), hSketch3, 190.64, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hExtrudeFeature3);
	ASSERT(hExtrudeFeature3);

	// patter circular
	CString featureName;
	PmeFeatureAPI::GetName(hExtrudeFeature3, featureName);
	
	PmeHReference hReference3 = 0;
	PmePartAPI::SelectFeatureByName(m_hPart, featureName, hReference3);
	ASSERT(hReference3);

	PmeHReferences hReferenceFeatures = 0;
	PmeReferencesAPI::Create(hReferenceFeatures);
	PmeReferencesAPI::AddItem(hReferenceFeatures, hReference3);

	PmeHFeature hPatternFeature1 = 0;
	PmeStdSolidOperatePatternCircularFeatureAPI::Create(m_hPart, _T("Pattern1"), hReferenceFeatures,
		MrAxis1(MrPosition(0, 0, 0), MrDirection(0, 0, 1)), 4, 90,  1, 0, true,
		hPatternFeature1);
	ASSERT(hPatternFeature1);

	PmeHReference hReferenceFace4 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude3,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace4);

	PmeHFeature hSketchFeature4 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hReferenceFace4, hSketchFeature4);
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature4, false, hEditor);
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle3"), 0.0, 0.0, 15.625, hTemp);
	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature4, sketchName);
	PmeHReference hSketch4 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hSketch4);
	ASSERT(hSketch4);

	PmeHFeature hExtrudeFeature4 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude5"), hSketch4, 50, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hExtrudeFeature4);
	ASSERT(hExtrudeFeature4);

	PmeHReference hReferenceFace5 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude5,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace5);

	PmeHFeature hSketchFeature5 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch6"), hReferenceFace5, hSketchFeature5);
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature5, false, hEditor);

	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle4"), 0.0, 0.0, 10, hTemp);
	PmeStdSketchEditorAPI::CreateCircle(hEditor, _T("Circle5"), 0.0, 0.0, 5, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature5, sketchName);
	PmeHReference hSketch5 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hSketch5);
	ASSERT(hSketch5);

	PmeHFeature hExtrudeFeature5 = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude6"), hSketch5, 37.50, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hExtrudeFeature5);
	ASSERT(hExtrudeFeature5);

	PmeHReference hReferenceFace6 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,0,-1,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace6);

	PmeHFeature hSketchFeature6 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch7"), hReferenceFace6, hSketchFeature6);
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature6, false, hEditor);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -45, -35, -45, 35, hTemp);
	PmeStdSketchEditorAPI::CreateCircularArc(hEditor, _T("Arc1"), -35, 35, 10, 90, 180, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), -35, 45, 35, 45, hTemp);
	PmeStdSketchEditorAPI::CreateCircularArc(hEditor, _T("Arc2"), 35, 35, 10, 0, 90, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 45, 35, 45, -35, hTemp);
	PmeStdSketchEditorAPI::CreateCircularArc(hEditor, _T("Arc3"), 35, -35, 10, 270, 360, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), 35, -45, -35, -45, hTemp);
	PmeStdSketchEditorAPI::CreateCircularArc(hEditor, _T("Arc4"), -35, -35, 10, 180, 270, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature6, sketchName);
	PmeHReference hSketch6 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hSketch6);
	ASSERT(hSketch6);

	PmeHFeature hCutExtrudeFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut1"), hSketch6, 20, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature);
	ASSERT(hCutExtrudeFeature);

	PmeHReference hReferenceFace7 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude3,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace7);

	PmeHFeature hSketchFeature7 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch8"), hReferenceFace7, hSketchFeature7);
	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature7, false, hEditor);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -62.5, -62.5, 62.5, -62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 62.5, -62.5, 62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 62.5, 62.5, -62.5, 62.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -62.5, 62.5, -62.5, -62.5, hTemp);

	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line5"), -52.5, 52.5, -52.5, -52.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line6"), 52.5, 52.5, -52.5, 52.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line7"), 52.5, -52.5, 52.5, 52.5, hTemp);
	PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line8"), -52.5, -52.5, 52.5, -52.5, hTemp);

	PmeStdSketchEditorAPI::Close(hEditor);

	PmeFeatureAPI::GetName(hSketchFeature7, sketchName);
	PmeHReference hSketch7 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, sketchName, hSketch7);
	ASSERT(hSketch7);

	PmeHFeature hCutExtrudeFeature2 = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _T("Cut2"), hSketch7, 10, PmeStdExtrudeEndType_Blind, 0.0, PmeStdExtrudeEndType_Blind, false, hCutExtrudeFeature2);
	ASSERT(hCutExtrudeFeature2);

	// Counterbored Hole
	PmeHReference hReferenceFace8 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Cut1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace8);

	PmeHFeature hHoleCounterboredFeature = 0;
	PmeStdSolidHoleCounterboredFeatureAPI::Create(m_hPart, _T("HoleCounterbored1"), hReferenceFace8, 0.0, 0.0, 20, 7.03, 4.40, 3.50, 95.6, 118, hHoleCounterboredFeature);
	ASSERT(hHoleCounterboredFeature);

	// Countersunk Hole
	PmeHReference hReferenceFace9 = 0;
	PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude3,Sketch3,Line3,0,0,0,ExtrudeFeature:0,0:0;0"), hReferenceFace9);

	PmeHFeature hHoleCountersunkFeature = 0;
	PmeStdSolidHoleCountersunkFeatureAPI::Create(m_hPart, _T("HoleCountersunk1"), hReferenceFace9, 0, 62.50, 245, 3.50, 100, 5.95, 90, 180, hHoleCountersunkFeature); //0.1609, -0.6250, 0.0350, 1.0, 0.0595, 100, hHoleCountersunkFeature);
	ASSERT(hHoleCountersunkFeature);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateChisel(void)
{
	// K7
	DeleteExistingFeatures();

	// 여기에 추가
	// apply constrints or not
	bool usingConstraint = false;
	
	// Select XYplane.
	PmeHReference hXYPlane = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
	ASSERT(hXYPlane);

	// Create a sketch on XYPlane
	PmeHFeature hBaseSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);

	PmeHStdSketchEditor hEditor = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, usingConstraint, hEditor);

	PmeHStdSketchGeometry hTemp = 0;
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -30, -30, 30, -30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 30, -30, 30, 30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 30, 30, -30, 30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -30, 30, -30, -30, hTemp);
	PmeStdSketchEditorAPI::Close(hEditor);

	// Create a datum plane1
	PmeHFeature hMyPlane1 = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane1"), hXYPlane, 200, true, hMyPlane1);
	ASSERT(hMyPlane1);

	// Select the datum plane1
	PmeHReference hNewPlane1 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("MyPlane1"), hNewPlane1);	
	ASSERT(hNewPlane1);

	// Create a sketch on the datum plane1
	PmeHFeature hBaseSketchFeature1 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch2"), hNewPlane1, hBaseSketchFeature1);

	PmeHStdSketchEditor hEditor1 = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature1, usingConstraint, hEditor1);

	PmeHStdSketchGeometry hTemp1 = 0;
		PmeStdSketchEditorAPI::CreateLine(hEditor1, _T("Line1"), -75, -2.5, 75, -2.5, hTemp1);
		PmeStdSketchEditorAPI::CreateLine(hEditor1, _T("Line2"), 75, -2.5, 75, 2.5, hTemp1);
		PmeStdSketchEditorAPI::CreateLine(hEditor1, _T("Line3"), 75, 2.5, -75, 2.5, hTemp1);
		PmeStdSketchEditorAPI::CreateLine(hEditor1, _T("Line4"), -75, 2.5, -75, -2.5, hTemp1);
	PmeStdSketchEditorAPI::Close(hEditor1);

	// Create a datum plane2
	PmeHFeature hMyPlane2 = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane2"), hXYPlane, 25, false, hMyPlane2);
	ASSERT(hMyPlane2);

	// Select the datum plane2
	PmeHReference hNewPlane2 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("MyPlane2"), hNewPlane2);	
	ASSERT(hNewPlane2);

	// Create a sketch on the datum plane2
	PmeHFeature hBaseSketchFeature2 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch3"), hNewPlane2, hBaseSketchFeature2);

	PmeHStdSketchEditor hEditor2 = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature2, usingConstraint, hEditor2);

	PmeHStdSketchGeometry hTemp2 = 0;
		PmeStdSketchEditorAPI::CreateCircle(hEditor2,_T("Circle1"),0,0,25,hTemp2);
	PmeStdSketchEditorAPI::Close(hEditor2);

	// Create a datum plane3
	PmeHFeature hMyPlane3 = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane3"), hXYPlane, 50, false, hMyPlane3);
	ASSERT(hMyPlane3);

	// Select the datum plane3
	PmeHReference hNewPlane3 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("MyPlane3"), hNewPlane3);	
	ASSERT(hNewPlane3);

	// Create a sketch on the datum plane3
	PmeHFeature hBaseSketchFeature3 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch4"), hNewPlane3, hBaseSketchFeature3);

	PmeHStdSketchEditor hEditor3 = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature3, usingConstraint, hEditor3);

	PmeHStdSketchGeometry hTemp3 = 0;
		PmeStdSketchEditorAPI::CreateCircle(hEditor3,_T("Circle1"),0,0,40,hTemp3);
	PmeStdSketchEditorAPI::Close(hEditor3);

	// Create a datum plane4
	PmeHFeature hMyPlane4 = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _T("MyPlane4"), hXYPlane, 90, false, hMyPlane4);
	ASSERT(hMyPlane4);
	
	// Select the datum plane4
	PmeHReference hNewPlane4 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("MyPlane4"), hNewPlane4);	
	ASSERT(hNewPlane4);
	
	// Create a sketch on the datum plane4
	PmeHFeature hBaseSketchFeature4 = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch5"), hNewPlane4, hBaseSketchFeature4);

	PmeHStdSketchEditor hEditor4 = 0;
	PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature4, usingConstraint, hEditor4);

	PmeHStdSketchGeometry hTemp4 = 0;
		PmeStdSketchEditorAPI::CreateCircle(hEditor4,_T("Circle1"),0,0,40,hTemp4);
	PmeStdSketchEditorAPI::Close(hEditor4);

	// Make a reference for the sketches
	PmeHReference hRef1 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch1"), hRef1);
	ASSERT(hRef1);

	PmeHReference hRef2 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch2"), hRef2);
	ASSERT(hRef2);

	PmeHReference hRef3 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch3"), hRef3);
	ASSERT(hRef3);

	PmeHReference hRef4 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch4"), hRef4);
	ASSERT(hRef4);

	PmeHReference hRef5 = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _T("Sketch5"), hRef5);
	ASSERT(hRef5);

	// Make references for loft feature1
	PmeHReferences hSections = 0;
	PmeReferencesAPI::Create(hSections);
	PmeReferencesAPI::AddItem(hSections, hRef1);
	PmeReferencesAPI::AddItem(hSections, hRef3);
	PmeReferencesAPI::AddItem(hSections, hRef4);
	PmeReferencesAPI::AddItem(hSections, hRef5);

	// Create a loft feature1
	PmeHFeature hLoftFeature1 =0;
	PmeStdSolidLoftSectionsFeatureAPI::Create(m_hPart, "Loft1", hSections, false, hLoftFeature1);
	ASSERT(hLoftFeature1);

	// Make references for loft feature2
	PmeHReferences hSections2 = 0;
	PmeReferencesAPI::Create(hSections2);
	PmeReferencesAPI::AddItem(hSections2, hRef1);
	PmeReferencesAPI::AddItem(hSections2, hRef2);

	// Create a loft feature2
	PmeHFeature hLoftFeature2 =0;
	PmeStdSolidLoftSectionsFeatureAPI::Create(m_hPart, "Loft2", hSections2,  false, hLoftFeature2);
	ASSERT(hLoftFeature2);

	UpdateFitView();
}

void PmDocument::OnTestmodelLastone(void)
{
	// 테스트용
	DeleteExistingFeatures();

	bool naming;
	PmePersistentNameAPI::GetNamingMethod(naming);
	if(naming)
	{
		PmeHReference hXYPlane = 0;
		PmePartAPI::SelectObjectByName(m_hPart, _T("XYPlane"), hXYPlane);	
		ASSERT(hXYPlane);

		// Create a base sketch.
		PmeHFeature hBaseSketchFeature = 0;
		PmeStdSketchFeatureAPI::Create(m_hPart, _T("Sketch1"), hXYPlane, hBaseSketchFeature);
	
		PmeHStdSketchEditor hEditor = 0;
		PmeStdSketchFeatureAPI::OpenEditor(hBaseSketchFeature, false, hEditor);

		PmeHStdSketchGeometry hTemp = 0;

		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line1"), -25, -30, 25, -30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line2"), 25, -30, 25, 30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line3"), 25, 30, -25, 30, hTemp);
		PmeStdSketchEditorAPI::CreateLine(hEditor, _T("Line4"), -25, 30, -25, -30, hTemp);
		//PmeStdSketchEditorAPI::CreateCenterline(hEditor, _T("CenterLine"), 0, 0, 0, 100, hTemp);

		PmeStdSketchEditorAPI::Close(hEditor);

		// Select the base sketch.
		CString sketchName;
		PmeFeatureAPI::GetName(hBaseSketchFeature, sketchName);
		PmeHReference hBaseSketch = 0;
		PmePartAPI::SelectObjectByName(m_hPart, sketchName, hBaseSketch);
		ASSERT(hBaseSketch);

		PmeHFeature hProtrusionExtrudeFeature = 0;
		PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _T("Extrude1"), hBaseSketch, 50, PmeStdExtrudeEndType_Blind,0, PmeStdExtrudeEndType_Blind, false, hProtrusionExtrudeFeature);
		ASSERT(hProtrusionExtrudeFeature);

		//

		PmeHReference hReference = 0;
		PmePartAPI::SelectBrepByName(m_hPart, _T("Extrude1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0"), hReference);	
		ASSERT(hReference);

		PmeHFeature hHoleFeature = 0;
		PmeStdSolidHoleSimpleFeatureAPI::Create(m_hPart, _T("Hole1"), hReference, 0, -20, 50, 3, 10, hHoleFeature);
		ASSERT(hHoleFeature);
		
		CString featureName;
		PmeFeatureAPI::GetName(hHoleFeature, featureName);
		PmeHReference hReference2 = 0;
		PmePartAPI::SelectFeatureByName(m_hPart, featureName, hReference2);
		ASSERT(hReference2);
		
		PmeHReferences hReferenceFeatures = 0;
		PmeReferencesAPI::Create(hReferenceFeatures);
		PmeReferencesAPI::AddItem(hReferenceFeatures, hReference2);

		PmeHFeature hPatternFeature1 = 0;
		PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, _T("Pattern1"), hReferenceFeatures, 0, MrDirection(1,0,0), 1, 10, MrDirection(0,1,0), 3, hPatternFeature1);
		ASSERT(hPatternFeature1);
	}
	
}
/*****************************/


/****** C 모델 생성 ******/
void PmDocument::OnTestmodelCreateC1Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C1.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateC2Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C2.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateC3Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C3.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateC4Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C4.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateC5Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C5.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}

void PmDocument::OnTestmodelCreateC6Model()
{
	DeleteExistingFeatures();
	
	CString path = _T("chaps models\\C6.xml");

	PmePartAPI::LoadXmlMacro(path, m_hPart);

	UpdateFitView();
}
/*****************************/


void PmDocument::OnUndo()
{
	//CString command;
	//command = _T("undo");
	//RunScriptInterface(command);
}

void PmDocument::OnRedo()
{
	//CString command;
	//command = _T("redo");
	//RunScriptInterface(command);
}