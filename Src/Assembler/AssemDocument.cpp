// AssemDocument.cpp : AssemDocument 클래스의 구현
//

#include "stdafx.h"
#include "Resource.h"
#include "AssemDocument.h"
#include "AssemView.h"
#include "AssemFrame.h"
#include "AssemHModel.h"
#include "AssemSettings.h"
#include "AssemRenderPart.h"
#include "PmMeshManager.h"
#include "AssemViewHoopsModelTreeDialog.h"
#include "PmeAssembly.h"
#include "PmeComponent.h"
#include "PmeComponentAPI.h"
#include "PmePartApi.h"
#include "PmeExplicitModelAPI.h"
#include "pmeSolidAPI.h"

#include "PmDocument.h"

#include "PmeHandleMacro.h"
#include "PmeExplicitModel.h"

#include ".\PmeTransformAPI.h"
#include ".\Pmeutility.h"

#include ".\AssemImportPartDialog.h"

// for test
#include ".\PmeStdAssemblyCoaxialAPI.h"
#include ".\PmeStdAssemblyIncidenceAPI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// AssemDocument

IMPLEMENT_DYNCREATE(AssemDocument, CHoopsDoc)

BEGIN_MESSAGE_MAP(AssemDocument, CHoopsDoc)
	ON_COMMAND(ID_EDIT_UPDATE_ALL, OnEditUpdateAll)
	ON_COMMAND(ID_VIEW_HOOPS_MODEL_TREE, OnViewHoopsModelTree)
	ON_COMMAND(ID_FILE_OPEN, &AssemDocument::OnFileOpen)
	ON_COMMAND(ID_VIEW_UPDATE_ALL, &AssemDocument::OnViewUpdateAll)
	ON_COMMAND(ID_POPUP_DEL, &AssemDocument::OnPopupDel)
	ON_COMMAND(ID_TESTMODEL_CREATE_A1, &AssemDocument::OnTestmodelCreateA1Model)
	ON_COMMAND(ID_TESTMODEL_CREATE_A2, &AssemDocument::OnTestmodelCreateA2Model)
	ON_COMMAND(ID_FILE_ADD_COMPONENT, &AssemDocument::OnAddNewComponent)
	ON_COMMAND(ID_FILE_IMPORT_PART, &AssemDocument::OnImportPart)
END_MESSAGE_MAP()


// AssemDocument 생성/소멸

AssemDocument::AssemDocument()
{
	m_pHoopsModel = 0;
	m_pSettings = 0;
	m_hAssembly = 0;

	m_hModelSegment = 0;
	m_hDatumSegment = 0;
	m_hFitIgnoringSegment = 0;

	m_pAddCompDialog = 0;
	m_pImportPartDialog = 0;
}

AssemDocument::~AssemDocument()
{
	PmeAssemblyAPI::UnregisterEventListener(m_hAssembly, this);
	PmeAssemblyAPI::Delete(m_hAssembly);
	ASSERT(!m_hAssembly);

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

	if ( m_pAddCompDialog != NULL )
	{
		m_pAddCompDialog->DestroyWindow();
		delete m_pAddCompDialog;
		m_pAddCompDialog = NULL;
	}

	if ( m_pImportPartDialog != NULL )
	{
		m_pImportPartDialog->DestroyWindow();
		delete m_pImportPartDialog;
		m_pImportPartDialog = NULL;
	}
}

void AssemDocument::Initialize(void)
{
	m_pSettings = new AssemSettings();

	// delete the HHoopsTestModel object if there is already one
	if(m_pHoopsModel)
	{
		delete m_pHoopsModel;
		m_pHoopsModel = 0;
	}
	
	// create a new AssemHModel object for this Document
	m_pHoopsModel = new AssemHModel();
	m_pHoopsModel->Init();

	//m_pMeshManager = new PmMeshManager();

	ClearModel();
	ClearTree();

	PmeAssemblyAPI::Create(m_hAssembly);
	PmeAssemblyAPI::RegisterEventListener(m_hAssembly, this);
}

void AssemDocument::ClearModel(void)
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
			HC_Set_Rendering_Options("hsra = priority");
			m_hFitIgnoringSegment = HC_KOpen_Segment("FitIgnoringSegment");
			HC_Close_Segment();
		HC_Close_Segment();
	
	HC_Close_Segment();
}

void AssemDocument::UpdateAll(void)
{
	ClearModel();
	ClearTree();
	PmeAssemblyAPI::UpdateAll(m_hAssembly);	
}

void AssemDocument::UpdateFitView( void )
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
   
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(AssemDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(AssemView)))
			{
				AssemView * pAssemView = static_cast<AssemView *>(pView);
				pAssemView->OnViewZoomAll();
			}
		}
	}
}

BOOL AssemDocument::OnNewDocument()
{
	if (!CHoopsDoc::OnNewDocument())
		return FALSE;

	Initialize();	

	// Test code here

	

	return TRUE;
}


// AssemDocument serialization
void AssemDocument::Serialize(CArchive& ar)
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


// AssemDocument 진단
#ifdef _DEBUG
void AssemDocument::AssertValid() const
{
	CHoopsDoc::AssertValid();
}

void AssemDocument::Dump(CDumpContext& dc) const
{
	CHoopsDoc::Dump(dc);
}
#endif //_DEBUG


// AssemDocument 명령
AssemHModel * AssemDocument::GetHModel(void) const
{
	return static_cast<AssemHModel *>(m_pHoopsModel);
}

void AssemDocument::OnPartUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnPartUpdated\n"));

// 	int size;
// 	PmeUpdateInfoAPI::GetSize(hInfo, size);
// 
// 	for(int i = 0; i < size; ++ i)
// 	{
// 		PmeUpdateInfoItem item;
// 		PmeUpdateInfoAPI::GetItem(hInfo, i, item);
// 
// 		switch(item.state)
// 		{
// 		case PmeUpdateState_Add:
// 			{
// 				PmeHComponent hComponent = item.hItem;
// 
// 				HC_KEY hKey = AssemRenderComponent(hComponent, this);
// 				m_mapObject[hComponent] = hKey;
// 			}
// 			break;
// 		case PmeUpdateState_Update:
// 			{
// 				PmeHPart hPart = item.hItem;		
// 
// 				HC_KEY hOldKey = m_mapObject[hPart];
// 
// 				if(hOldKey)
// 				{
// 					AssemDeleteRenderingObject(hOldKey);
// 				}
// 
// 				HC_KEY hNewKey = AssemRenderComponent(hPart, this);
// 				m_mapObject[hPart] = hNewKey;
// 			}
// 			break;
// 		case PmeUpdateState_Delete:
// 			break;
// 		}
// 	}
// 
// 	HC_Update_Display();
// 
// 	UpdateViews();
}

void AssemDocument::OnComponentUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnComponentUpdated\n"));

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
				PmeHComponent hComponent = item.hItem;

				HC_KEY hKey = AssemRenderComponent(hComponent, this);
				m_mapObject[hComponent] = hKey;
				m_keyMap[hKey]=hComponent;
				
			}
			break;

		case PmeUpdateState_Update:
			{
				PmeHComponent hComponent = item.hItem;
				
				HC_KEY hOldKey = m_mapObject[hComponent];

				if(hOldKey)
				{
					AssemDeleteRenderingObject(hComponent);
					PmeComponentAPI::SetUpdated(hComponent,TRUE);
				}

				HC_KEY hNewKey = AssemRenderComponent(hComponent, this);
				PmeComponentAPI::SetUpdated(hComponent,FALSE);
				

			}
			break;

		case PmeUpdateState_Delete:
			{
				PmeHComponent hComponent = item.hItem;

				HC_KEY hOldKey = m_mapObject[hComponent];

				if(hOldKey)
				{
					AssemDeleteRenderingObject(hComponent);
				}
			}
			break;
		}
	}

	HC_Update_Display();

	UpdateViews();
}

void AssemDocument::OnConstraintUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnConstraintUpdated\n"));

	int size;
	PmeUpdateInfoAPI::GetSize(hInfo, size);

	for (int i = 0; i < size; ++i)
	{
		PmeUpdateInfoItem item;
		PmeUpdateInfoAPI::GetItem(hInfo, i, item);

		switch(item.state)
		{
		case PmeUpdateState_Add:
			{
				// Do something
			}
			break;
			
		case PmeUpdateState_Update:
			{
				PmeHStdAssemblyConstraint hConstraint = item.hItem;

				//HC_KEY hOldKey = m_mapObject[hConstraint];

				
			}
		}
	}
}

void AssemDocument::AddObjectMapPair( PmeHComponent& hcomp, HC_KEY key )
{
	m_mapObject[hcomp] = key;
	m_keyMap[key] = hcomp;
	PmeComponentAPI::SetUpdated(hcomp,FALSE);
}

void AssemDocument::UpdateViews(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
    
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(AssemDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(AssemView)))
			{
				AssemView * pAssemView = static_cast<AssemView *>(pView);
				pAssemView->RedrawWindow();
			}
		}
	}
}

void AssemDocument::OnEditUpdateAll(void)
{
	UpdateAll();
}

void AssemDocument::OnViewHoopsModelTree(void)
{
	AssemViewHoopsModelTreeDialog dialog(this);

	dialog.DoModal();
}

void AssemDocument::ClearTree(void)
{
	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pFrame->IsKindOf(RUNTIME_CLASS(AssemFrame)) && static_cast<CDocument *>(this) == pDoc)
	{
		AssemFeatureTree * pFeatureTree = static_cast<AssemFrame *>(pFrame)->GetFeatureTree();
		pFeatureTree->Initialize();
	}
}

BOOL AssemDocument::OnSaveDocument(LPCTSTR lpszPathName)
{

	//PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);

	PmeAssemblyAPI::SaveAsXmlMacro(m_hAssembly,lpszPathName);

	// return __super::OnSaveDocument(lpszPathName);

	return TRUE;
}

void AssemDocument::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//LPCTSTR lpszPathName;
	CString strFilter;
	strFilter += _T("XML neutral format (*.xml)|*.xml|");
	strFilter += _T("SAT file (*.sat) |*.sat|");
	strFilter += _T("STEP file (*.step, *.stp) |*.stp;*.step|");
	strFilter += _T("IGES file (*.iges, *.igs) |*.igs;*.iges|");
	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter);

	if(dlg.DoModal() != IDOK)
		return;

	if(dlg.GetFileExt() == "xml")
		PmeAssemblyAPI::LoadXmlMacro(dlg.GetPathName(),m_hAssembly);

	else /*if (dlg.GetFileExt() = "sat")*/
		PmeAssemblyAPI::AddBrepPart(m_hAssembly,dlg.GetPathName());

}

PmeHComponent AssemDocument::GetComponentFromHKey( HC_KEY key )
{
	m_selectedcomp = m_keyMap[key];
	return m_selectedcomp;
}

void AssemDocument::OnViewUpdateAll()
{
	UpdateAll();
}

void AssemDocument::SelectComponent( PmeHComponent hComponent )
{
	m_selectedcomp = hComponent;

	CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
	CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());

	CDocument * pDoc = pFrame->GetActiveDocument();
	if(pDoc && pDoc->IsKindOf(RUNTIME_CLASS(AssemDocument)))
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView && pView->IsKindOf(RUNTIME_CLASS(AssemView)))
			{
				AssemView * pAssemView = static_cast<AssemView *>(pView);
				pAssemView->SelectComponent(m_mapObject[hComponent]);
			}
		}
	}
}

void AssemDocument::OnPopupDel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PmeComponentAPI::SetUpdated(m_selectedcomp,TRUE);
	PmeAssemblyAPI::DeleteComponent(m_hAssembly, m_selectedcomp);
	

	
	
	//PmeComponentAPI::Delete(m_selectedcomp);
}

void AssemDocument::DeleteExistingAssembly( void )
{
	int size;
	PmeAssemblyAPI::GetSize( m_hAssembly, size );
	
	
	for ( int i = 0; i < size; ++i )
	{	
		PmeHComponent hComponent = 0;
		PmeAssemblyAPI::GetComponent( m_hAssembly, i, hComponent );
		
		CString compName;
		PmeComponentAPI::GetName( hComponent, compName );

		if ( compName == "Default SubAssembly" )
			continue;

		PmeComponentAPI::Delete( hComponent );
	}

	UpdateAll();
}

/**
	@brief	Create a new component
*/
void AssemDocument::OnAddNewComponent()
{
	m_compName = "SubAssembly";

	int compSize;
	
	PmeAssemblyAPI::GetSize( m_hAssembly, compSize );

	int cnt = 1;		// 기본 이름을 가지는 component의 수

	for ( int i = 0; i < compSize; ++i )
	{
		PmeHComponent _hComp;
		PmeAssemblyAPI::GetComponent( m_hAssembly, i, _hComp );
		CString compName;
		PmeComponentAPI::GetName( _hComp, compName );

		if ( compName.Find( "Default" ) != -1 )
			continue;
		else if ( compName.Find( "SubAssembly" ) != -1 )
		{
			cnt++;
		}
	}

	m_compName.AppendFormat( _T( "%d" ), cnt );

	m_pAddCompDialog = new AssemAddComponentDialog( this );
	m_pAddCompDialog->Create( IDD_ADD_COMPONENT );
	m_pAddCompDialog->ShowWindow( SW_SHOW );
}

/**
	@brief Import a part in existing component
*/
void AssemDocument::OnImportPart()
{
	m_pImportPartDialog = new AssemImportPartDialog( this );
	m_pImportPartDialog->Create( IDD_IMPORT_PART );
	m_pImportPartDialog->ShowWindow( SW_SHOW );
}


/************************* A models *************************/
void AssemDocument::OnTestmodelCreateA1Model()
{
	DeleteExistingAssembly();
	
	PmeHComponent hComp = 0;

	PmeHPart m_hConstrainedPart, m_hReferencePart;
	PmePartAPI::Create( m_hConstrainedPart );
	PmePartAPI::SetName( m_hConstrainedPart, "RotationPart" );

	PmePartAPI::Create( m_hReferencePart );
	PmePartAPI::SetName( m_hReferencePart, "Body" );

	CString path;

#ifdef _DEBUG
	
	path = _T("..\\..\\RegBin\\Assembly_models\\A1\\A1_Body.xml");
	PmePartAPI::LoadXmlMacro( path, m_hReferencePart );

	path = _T( "..\\..\\RegBin\\Assembly_models\\A1\\A1_RotationPart.xml" );
	PmePartAPI::LoadXmlMacro( path, m_hConstrainedPart );

#else

	path = _T( "Assembly_models\\A1\\A1_Body.xml" );
	PmePartAPI::LoadXmlMacro( path, m_hReferencePart );

	path = _T( "Assembly_models\\A1\\A1_RotationPart.xml" );
	PmePartAPI::LoadXmlMacro( path, m_hConstrainedPart );

#endif

	//MrAxis2 currentPlacement;
	//PmePartAPI::GetPlacement( m_hConstrainedPart, currentPlacement );

	// 모델 구분을 쉽게 하기위해, 위치 이동
	MrAxis2 t = MrAxis2( MrPosition( 160.0, 50.0, 80.0 ), MrDirection( 0.0, 0.0, 1.0 ), MrDirection( 1.0, 0.0, 0.0 ) );

	PmePartAPI::SetPlacement( m_hConstrainedPart, t );

	MrAxis2 currentPlacement2;
	PmePartAPI::GetPlacement( m_hConstrainedPart, currentPlacement2 );

	PmeComponentAPI::Create( hComp );
	PmeComponentAPI::SetName( hComp, "SubAssembly1" );
	PmeComponentAPI::AddPart( hComp, m_hConstrainedPart );
	PmeComponentAPI::AddPart( hComp, m_hReferencePart );

	PmeAssemblyAPI::AddComponent( m_hAssembly, hComp );

	//UpdateAll();

	PmeHReference hConstrainedGeom, hReferenceGeom;
	PmeHStdAssemblyConstraint hConstraint;

	PmePartAPI::SelectBrepByName( m_hConstrainedPart, "SubAssembly1,RotationPart,Cut1,Sketch2,Circle1,0,0,0,ExtrudeFeature:0,0:0;0", hConstrainedGeom );
	PmePartAPI::SelectBrepByName( m_hReferencePart, "SubAssembly1,Body,Extrude2,Sketch2,Circle1,0,0,0,ExtrudeFeature:0,0:0;0", hReferenceGeom );	
	PmeStdAssemblyCoaxialAPI::ApplyCoaxial( m_hAssembly, "Coaxial", m_hConstrainedPart, hConstrainedGeom, m_hReferencePart, hReferenceGeom, hConstraint );

	PmePartAPI::SelectBrepByName( m_hConstrainedPart, "SubAssembly1,RotationPart,Extrude1,0,-1,0,0,0,ExtrudeFeature:0,0:0;0", hConstrainedGeom );
	PmePartAPI::SelectBrepByName( m_hReferencePart, "SubAssembly1,Body,Extrude1,0,-2,0,0,0,ExtrudeFeature:0,0:0;0", hReferenceGeom );	
	PmeStdAssemblyIncidenceAPI::ApplyIncidence( m_hAssembly, "Incidence", m_hConstrainedPart, hConstrainedGeom, m_hReferencePart, hReferenceGeom, PmeStdAssemblyIncidenceType::PmeStdAssemblyIncidenceType_Opposite, hConstraint );
	
	UpdateFitView();
	
	UpdateAll();
}


// A2 모델 수정해야함
void AssemDocument::OnTestmodelCreateA2Model()
{
	PmeHComponent hComp = 0;

	PmeHPart A2_plate;
	PmeHPart A2_dm;

	PmePartAPI::Create( A2_dm );
	PmePartAPI::SetName( A2_dm, "A2_dm" );

	PmePartAPI::Create( A2_plate );
	PmePartAPI::SetName( A2_plate, "A2_plate" );
	
	CString path;

	// Load models
#ifdef _DEBUG
	path = _T("..\\..\\RegBin\\Assembly_models\\A2\\A2_dm.xml");
	PmePartAPI::LoadXmlMacro( path, A2_dm );

	path = _T("..\\..\\RegBin\\Assembly_models\\A2\\A2_Plate.xml");
	PmePartAPI::LoadXmlMacro( path, A2_plate );

#else

	path = _T("RegBin\\Assembly_models\\A2\\A2_dm.xml");
	PmePartAPI::LoadXmlMacro( path, A2_dm );

	path = _T("RegBin\\Assembly_models\\A2\\A2_Plate.xml");
	PmePartAPI::LoadXmlMacro( path, A2_plate );

#endif
	PmeComponentAPI::Create( hComp );
	PmeComponentAPI::SetName( hComp, "Component1" );
	PmeComponentAPI::AddPart( hComp, A2_plate );
	PmeComponentAPI::AddPart( hComp, A2_dm );
	
	PmeAssemblyAPI::AddComponent( m_hAssembly, hComp );

	UpdateFitView();

	UpdateAll();
}
/************************************************************/


/*********************** Engine model ***********************/


/************************************************************/




