// PmView.cpp : PmView 클래스의 구현
//

#include "stdafx.h"

#include "PmDocument.h"
#include "PmView.h"
#include "PmePart.h"
#include "PmeFeatures.h"
#include "PmeHandle.h"
#include "PmeHandleMacro.h"

#include "PmFrame.h"
#include ".\PmView.h"
#include ".\PmHView.h"
#include ".\PmSettings.h"
#include ".\PmViewPanningOperator.h"
#include ".\PmViewRotationOperator.h"
#include ".\PmViewZoomWindowOperator.h"
#include ".\PmViewPersistentNameOperator.h"
#include ".\PmViewSelectionOperator.h"
#include ".\PmViewManipulationOperator.h"

#include ".\PmViewPersistentNameDialog.h"

#include ".\PmCreateEdgeFilletDialog.h"
#include ".\PmCreateChamferDialog.h"
#include ".\PmCreateShellDialog.h"
#include ".\PmCreateOffsetDialog.h"
#include ".\PmCreateDraftDialog.h"
#include ".\PmCreateExtrudeDialog.h"
#include ".\PmCreateRevolveDialog.h"
#include ".\PmCreateSweepDialog.h"
#include ".\PmCreateHoleDialog.h"
#include ".\PmCreatePatternRectangularDialog.h"
#include ".\PmCreatePatternCircularDialog.h"
#include ".\PmCreateDatumPlaneOffsetDialog.h"
#include ".\PmHSelectionSet.h"
#include "PmMeshManager.h"

#include ".\resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// PmView
IMPLEMENT_DYNCREATE(PmView, CHoopsView)

BEGIN_MESSAGE_MAP(PmView, CHoopsView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CHoopsView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CHoopsView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CHoopsView::OnFilePrintPreview)
	ON_WM_SIZE()
	// 화면 이동
	ON_COMMAND(ID_VIEW_MANIPULATION, OnViewManipulation)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MANIPULATION, OnUpdateViewManipulation)
	ON_COMMAND(ID_VIEW_PAN, OnViewPan)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PAN, OnUpdateViewPan)
	ON_COMMAND(ID_VIEW_ORBIT, OnViewOrbit)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ORBIT, OnUpdateViewOrbit)
	ON_COMMAND(ID_VIEW_ZOOM_IN, OnViewZoomIn)
	ON_COMMAND(ID_VIEW_ZOOM_OUT, OnViewZoomOut)
	ON_COMMAND(ID_VIEW_ZOOM_TO_WINDOW, OnViewZoomToWindow)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_TO_WINDOW, OnUpdateViewZoomToWindow)
	ON_COMMAND(ID_VIEW_FRONT, OnViewFront)
	ON_COMMAND(ID_VIEW_BACK, OnViewBack)
	ON_COMMAND(ID_VIEW_LEFT, OnViewLeft)
	ON_COMMAND(ID_VIEW_RIGHT, OnViewRight)
	ON_COMMAND(ID_VIEW_TOP, OnViewTop)
	ON_COMMAND(ID_VIEW_BOTTOM, OnViewBottom)
	ON_COMMAND(ID_VIEW_WIREFRAME, OnViewWireframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WIREFRAME, OnUpdateViewWireframe)
	ON_COMMAND(ID_VIEW_FLAT_SHADING, OnViewFlatShading)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FLAT_SHADING, OnUpdateViewFlatShading)
	ON_COMMAND(ID_VIEW_GOUROUD_SHADIHG, OnViewGouroudShadihg)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GOUROUD_SHADIHG, OnUpdateViewGouroudShadihg)
	ON_COMMAND(ID_VIEW_PHONG_SHADING, OnViewPhongShading)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PHONG_SHADING, OnUpdateViewPhongShading)
	ON_COMMAND(ID_VIEW_HIDDEN_LINE, OnViewHiddenLine)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HIDDEN_LINE, OnUpdateViewHiddenLine)
	ON_COMMAND(ID_VIEW_ACTIVE_SKETCH_VIEWPOINT, OnViewActiveSketchViewpoint)
	ON_COMMAND(ID_VIEW_DEFAULT_VIEWPOINT, OnViewDefaultViewpoint)
	ON_COMMAND(ID_VIEW_ZOOM_ALL, OnViewZoomAll)
	ON_COMMAND(ID_VIEW_PERSISTENT_NAME, OnViewPersistentName)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PERSISTENT_NAME, OnUpdateViewPersistentName)
	// 특징형상 생성
	ON_COMMAND(ID_TRANSITIONFEATURES_FILLET, OnCreateEdgeFillet)
	ON_COMMAND(ID_TRANSITIONFEATURES_CHAMFER, OnCreateChamfer)
	ON_COMMAND(ID_TRANSITIONFEATURES_SHELL, OnCreateShell)
	ON_COMMAND(ID_TRANSITIONFEATURES_DRAFT, OnCreateDraft)
	ON_COMMAND(ID_TRANSITIONFEATURES_OFFSET, OnCreateOffset)
	ON_COMMAND(ID_SKETCHBASEDFEATURES_EXTRUDE, OnCreateExtrude)
	ON_COMMAND(ID_SKETCHBASEDFEATURES_REVOLVE, OnCreateRevolve)
	ON_COMMAND(ID_SKETCHBASEDFEATURES_SWEEP, OnCreateSweep)
	ON_COMMAND(ID_SKETCHBASEDFEATURES_HOLE, OnCreateHole)
	ON_COMMAND(ID_TRANSFORMATIONFEATURES_RECTANGULARPATTERN, OnCreatePatternRectangular)
	ON_COMMAND(ID_TRANSFORMATIONFEATURES_CIRCULARPATTERN, OnCreatePatternCircular)
	ON_COMMAND(ID_DATUMPLANE_DATUMPLANEOFFSET, OnCreateDatumPlaneOffset)
	ON_WM_MBUTTONDBLCLK()
END_MESSAGE_MAP()

// PmView 생성/소멸

PmView::PmView()
{
	m_pHView = 0;

	pDialog = 0;
	pPNDialog = 0;
}

PmView::~PmView()
{
	if(m_pHView)
	{
		delete m_pHView;
		m_pHView = 0;
	}
}

// BOOL PmView::PreCreateWindow(CREATESTRUCT& cs)
// {
// 	// TODO: CREATESTRUCT cs를 수정하여 여기에서
// 	// Window 클래스 또는 스타일을 수정합니다.
// 
// return CHoopsView::PreCreateWindow(cs);
// }

// PmView 그리기
/*
void PmView::OnDraw(CDC* pDC)
{
	PmDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}
*/

// PmView 인쇄

BOOL PmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void PmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void PmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// PmView 진단

#ifdef _DEBUG
void PmView::AssertValid() const
{
	CHoopsView::AssertValid();
}

void PmView::Dump(CDumpContext& dc) const
{
	CHoopsView::Dump(dc);
}

PmDocument* PmView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(PmDocument)));
	return (PmDocument*)m_pDocument;
}
#endif //_DEBUG


// PmView 메시지 처리기

void PmView::OnInitialUpdate()
{
	CHoopsView::OnInitialUpdate();

	PmDocument * pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	PmHModel * pHModel = pDoc->GetHModel();

	// create the HOOPS ParaView object corresponding with this MFC View, passing in the 
	// Model Object, the MFC View's window handle, and palette
	m_pHView = new PmHView(
		pHModel
		, 0
		, "opengl"
		, 0
		, (void *)m_hWnd
		, (void *)(HPALETTE)*(GetPalette())
	);
	PmHView * pHView = static_cast<PmHView *>(m_pHView);

	// initialize and set the default conditions viz. operator, rendermode etc.
 	pHView->Init();
   
	// set the DEBUG_NO_WINDOWS_HOOK debug bit since the app will manage 
	// all palette and update messages
    long debug_flags = DEBUG_NO_WINDOWS_HOOK;

	// since memory on gfx cards is often limited let's use a 16 bit OpenGL z-buffer
	// (with OpenGL we're double buffering and often running on true color devices)
	if(streq(pHView->GetDriverType(), "opengl2"))				
		debug_flags |= DEBUG_16BIT_ZBUFFER;

	char options[MVO_BUFFER_SIZE];
    sprintf(options, "debug = %u", debug_flags);

	PmSettings * pSettings = GetDocument()->GetSettings();

	if(pSettings->GetBoolValue("AntiAliasing"))
		strcat(options, ", anti-alias=4 ");

	HC_Open_Segment_By_Key(pHView->GetViewKey());
		HC_Set_Driver_Options(options);

		// antialiasing needs rendering option in addition to driver option
		if(pSettings->GetBoolValue("AntiAliasing"))
			HC_Set_Rendering_Options("antialias = on");

		HC_Set_Driver_Options("special events, update interrupts");
		HC_Control_Update(".", "redraw everything");
	HC_Close_Segment();

	pHView->SetDisplayListMode(pSettings->GetBoolValue("DisplayList"));
	pHView->SetVisibilitySelectionMode(pSettings->GetBoolValue("VisualSelection"));
	pHView->SetOcclusionCullingMode(pSettings->GetBoolValue("OcclusionCulling"));
	pHView->SetSpritingMode(pSettings->GetBoolValue("Spriting"));
	pHView->SetAllowInteractiveShadows(pSettings->GetBoolValue("InteractiveShadows"));
	pHView->SetBackplaneCulling(pSettings->GetBoolValue("BackplaneCulling"));

	pHView->SetShadowRenderingMode((HShadowRenderingMode)pSettings->GetIntValue("ShadowRenderingMode"));

	pHView->SetViewMode(HViewIso);		// fit the camera to the scene extents
	pHView->SetAxisMode(((pSettings->GetBoolValue("AxisTriad")) ? AxisOn : AxisOff));
	
	SetWindowColor((COLORREF)pSettings->GetLongValue("BackgroundTopColor")
		, (COLORREF)pSettings->GetLongValue("BackgroundBottomColor"));

	pHView->SetProjMode((ProjMode)pSettings->GetIntValue("ProjectionMode"));
	pHView->SetSmoothTransition(pSettings->GetBoolValue("SmoothTransition"));
	pHView->SetSmoothTransitionDuration(pSettings->GetDoubleValue("SmoothTransitionDuration"));
 
	// continuous update allows animations to be performed seamlessly
	// while user interaction takes place
	if(pSettings->GetBoolValue("TimerBasedUpdate"))
  	    pHView->SetViewUpdateMode(Continuous);
	else
  	    pHView->SetViewUpdateMode(OnDemand);

	SetCoordinateSystemHandedness(HandednessRight, true);
	pHView->SetPolygonHandednessMode(HandednessRight);

	// set the selection color
	HSelectionSet * pSelectionSet = pHView->GetSelection();
	assert(pSelectionSet);

	HPixelRGBA selectionColor;

	int selectionAlpha = (int)(pSettings->GetDoubleValue("SelectionColorTransparency") * 2.56f);
	
	COLORREF color = (COLORREF)pSettings->GetLongValue("PolygonSelectionColor");	
	selectionColor.Set(GetRValue(color), GetGValue(color), GetBValue(color), selectionAlpha);
	pSelectionSet->SetSelectionFaceColor(selectionColor);

	color = (COLORREF)pSettings->GetLongValue("LineSelectionColor");	
	selectionColor.Set(GetRValue(color), GetGValue(color), GetBValue(color), selectionAlpha);
	pSelectionSet->SetSelectionEdgeColor(selectionColor);

	color = (COLORREF)pSettings->GetLongValue("MarkerSelectionColor");	
	selectionColor.Set(GetRValue(color), GetGValue(color), GetBValue(color), selectionAlpha);
	pSelectionSet->SetSelectionMarkerColor(selectionColor);

	// set markup color and weight
	SetMarkupColor((COLORREF)pSettings->GetLongValue("MarkupColor"));
	SetShadowColor((COLORREF)pSettings->GetLongValue("ShadowColor"));

	pHView->GetMarkupManager()->SetMarkupWeight(pSettings->GetIntValue("MarkupWeight") / 100.0f);
	pHView->SetShadowResolution(pSettings->GetIntValue("ShadowResolution"));
	pHView->SetShadowBlurring(pSettings->GetIntValue("ShadowBlur"));

	// set the rendermode
	pHView->SetRenderMode((HRenderMode)pSettings->GetIntValue("RenderMode"), true);

	SetOperator(new PmViewManipulationOperator(pHView));
	//SetOperator(new HOpCameraOrbit(pHView));
	//((HOpCameraOrbit *)GetOperator())->SetLightFollowsCamera(true);

	pHView->FitWorld();		// fit the camera to the scene extents
	SetInitialCameraPosition();
	pHView->CameraPositionChanged();

	//we need to adjust the axis window outside the mvo class as the calculation of the window
	//extents is mfc specific
 	AdjustAxisWindow();
	pHView->ForceUpdate();
}

void PmView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	PmHView * pHView = GetHView();
	if(!bActivate)
	{
		HBaseOperator * pOp = pHView->GetOperator();
		if(pOp && strcmp(pOp->GetName(),"HOpCameraOrbit") == 0)
		{
			HOpCameraOrbit * pOpCameraOrbit = static_cast<HOpCameraOrbit *>(pOp);
			pOpCameraOrbit->m_Angle1 = pOpCameraOrbit->m_Angle2 = pOpCameraOrbit->m_Angle3 = 0;
		}

		if(GetFirstUpdate())
 			pHView->Update();
	}

	CHoopsView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void PmView::SetCoordinateSystemHandedness(HandednessMode rightOrLeft, bool emitMessage)
{
	PmHView * pHView = GetHView();
	pHView->SetHandedness(rightOrLeft, emitMessage);
}

void PmView::SetWindowColor(COLORREF newTopColor, COLORREF newBottomColor, bool emitMessage)
{
	HPoint windowTopColor;
	windowTopColor.Set(
		static_cast<float>(GetRValue(newTopColor)) / 255.0f,
		static_cast<float>(GetGValue(newTopColor)) / 255.0f,
		static_cast<float>(GetBValue(newTopColor)) / 255.0f);

	HPoint windowBottomColor;
	windowBottomColor.Set(
		static_cast<float>(GetRValue(newBottomColor)) / 255.0f,
		static_cast<float>(GetGValue(newBottomColor)) / 255.0f,
		static_cast<float>(GetBValue(newBottomColor)) / 255.0f);

	GetHView()->SetWindowColor(windowTopColor, windowBottomColor, emitMessage);
}

void PmView::SetPolygonHandedness(ModelHandedness newHandedness)
{
	// now onwards (9.0) we don't set the handedness just on view.
	// we do not mess up with model segment at all - Rajesh B (13-May-03)

	PmHView * pHView = GetHView();
	if(newHandedness == HandednessSetLeft)
		pHView->SetPolygonHandednessMode(HandednessLeft);
	else if(newHandedness == HandednessSetRight)
		pHView->SetPolygonHandednessMode(HandednessRight);
	else if(newHandedness == HandednessSetNone )
		pHView->SetPolygonHandednessMode(HandednessNone);
	else if(newHandedness == HandednessNotSet)
		;
	else
		assert(0);
}

void PmView::SetMarkupColor(COLORREF newColor, bool emitMessage)
{
	PmHView * pHView = GetHView();
	HPoint color;
	color.Set(
		static_cast<float>(GetRValue(newColor)) / 255.0f,
		static_cast<float>(GetGValue(newColor)) / 255.0f,
		static_cast<float>(GetBValue(newColor)) / 255.0f);
	
	HC_Open_Segment_By_Key(pHView->GetMarkupManager()->GetMarkupKey());
 	HC_Set_Color_By_Value("everything", "RGB", color.x, color.y, color.z);
	HC_Close_Segment();
	pHView->GetMarkupManager()->SetMarkupColor(color);
}

void PmView::SetShadowColor(COLORREF newColor)
{
	PmHView * pHView = GetHView();
	HPoint color;
	color.Set(
		static_cast<float>(GetRValue(newColor)) / 255.0f,
		static_cast<float>(GetGValue(newColor)) / 255.0f,
		static_cast<float>(GetBValue(newColor)) / 255.0f);
	pHView->SetShadowColor(color);
}

PmHView * PmView::GetHView() const
{
	return static_cast<PmHView *>(m_pHView);
}

void PmView::OnSize(UINT nType, int cx, int cy)
{
	CHoopsView::OnSize(nType, cx, cy);

	PmHView * pHView = GetHView();
	if(pHView)
        pHView->ForceUpdate();
}

void PmView::SetOperator(HBaseOperator * pNewOperator)
{
	HBaseOperator * pOp = m_pHView->GetOperator();

	if(pOp)
	    delete pOp;

    m_pHView->SetOperator(pNewOperator);
}

HBaseOperator * PmView::GetOperator(void)
{
	return m_pHView->GetOperator();
}

void PmView::OnViewManipulation()
{
	SetOperator(new PmViewManipulationOperator(GetHView()));
}

void PmView::OnUpdateViewManipulation(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "PmViewManipulationOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewPan()
{
	SetOperator(new PmViewPanningOperator(GetHView()));
}

void PmView::OnUpdateViewPan(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "PmViewPanningOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewOrbit()
{
	SetOperator(new PmViewRotationOperator(GetHView()));
}

void PmView::OnUpdateViewOrbit(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "PmViewRotationOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewZoomIn()
{
	ZoomCamera(2.0);	
}

void PmView::OnViewZoomOut()
{
	ZoomCamera(0.5);	
}

void PmView::OnViewZoomToWindow()
{
	SetOperator(new PmViewZoomWindowOperator(GetHView()));
}

void PmView::OnUpdateViewZoomToWindow(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "PmViewZoomWindowOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewFront()
{
	GetHView()->SetViewMode(HViewXY);
}

void PmView::OnViewBack()
{
	GetHView()->SetViewMode(HViewYX);
}

void PmView::OnViewLeft()
{
	GetHView()->SetViewMode(HViewZY);
}

void PmView::OnViewRight()
{
	GetHView()->SetViewMode(HViewYZ);
}

void PmView::OnViewTop()
{
	GetHView()->SetViewMode(HViewZX);
}


void PmView::OnViewBottom()
{
	GetHView()->SetViewMode(HViewXZ);
}


void PmView::OnViewWireframe()
{
	PmHView * pHView = GetHView();

	pHView->RenderWireframe();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
		HC_Set_Visibility("edges = on, lines = on");
    HC_Close_Segment();

	pHView->Update();
}

void PmView::OnUpdateViewWireframe(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderWireframe)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewFlatShading()
{
	PmHView * pHView = GetHView();

	pHView->RenderFlat();	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, edges=off, lines = off");
    HC_Close_Segment();

	pHView->Update();
}

void PmView::OnUpdateViewFlatShading(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderFlat)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewGouroudShadihg()
{
 	PmHView * pHView = GetHView();
	
	pHView->RenderGouraud();	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, lines = on, edges = off");		
    HC_Close_Segment();

	pHView->Update();
}

void PmView::OnUpdateViewGouroudShadihg(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderGouraud)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewPhongShading()
{
 	PmHView * pHView = GetHView();

	pHView->RenderPhong();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, edges=off, lines = off");
    HC_Close_Segment();

	pHView->Update();
}

void PmView::OnUpdateViewPhongShading(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderPhong)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnViewHiddenLine()
{
 	PmHView * pHView = GetHView();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = off, edges=on, lines = on");
    HC_Close_Segment();

	pHView->SetRenderMode(HRenderHiddenLine, true);
	pHView->Update();
}

void PmView::OnUpdateViewHiddenLine(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderHiddenLine || m_pHView->GetRenderMode() == HRenderHiddenLineFast)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void PmView::OnViewActiveSketchViewpoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void PmView::OnViewDefaultViewpoint()
{
	PmHView * pHView = GetHView();

	if(pHView->GetSmoothTransition())
	{
		HCamera oldCamera, newCamera;
		pHView->GetCamera(&oldCamera);
		
		SetInitialCameraPosition();
		
		pHView->GetCamera(&newCamera);
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			HUtility::SmoothTransition(oldCamera, newCamera, pHView);
		HC_Close_Segment();
	}
	else
	{	
		SetInitialCameraPosition();		
		pHView->Update();
	}
    
	pHView->CameraPositionChanged(true, pHView->GetSmoothTransition());
}

void PmView::ZoomCamera(double factor)
{
	PmHView * pHView = GetHView();

	if(pHView->GetSmoothTransition())
	{
		HCamera oldCamera, newCamera;
		pHView->GetCamera(&oldCamera);
		
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			HC_Zoom_Camera(factor);
		HC_Close_Segment();
		
		m_pHView->GetCamera(&newCamera);
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			HUtility::SmoothTransition(oldCamera, newCamera, pHView);
		HC_Close_Segment();
	}
	else
	{	
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			HC_Zoom_Camera(factor);
		HC_Close_Segment();
		
		pHView->Update();
	}

	pHView->CameraPositionChanged(true, pHView->GetSmoothTransition());
}

void PmView::SetInitialCameraPosition(double distance)
{
	PmHView * pHView = GetHView();
	double width = distance / 2.5;
	double height = distance / 2.5;

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
		HC_Set_Camera_Position(distance, distance, distance);
		HC_Set_Camera_Field(width, height);
		HC_Set_Camera_Up_Vector(0.0, 0.0, 1.0);
	HC_Close_Segment();	
}

void PmView::OnViewZoomAll()
{
	PmHView * pHView = GetHView();

	if(pHView->GetSmoothTransition())
	{
		HCamera oldCamera, newCamera;
		pHView->GetCamera(&oldCamera);
		
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			pHView->FitWorld();
		HC_Close_Segment();
		
		pHView->GetCamera(&newCamera);
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			HUtility::SmoothTransition(oldCamera, newCamera, pHView);
		HC_Close_Segment();
	}
	else
	{	
		HC_Open_Segment_By_Key(pHView->GetSceneKey());
			pHView->FitWorld();
		HC_Close_Segment();
		
		pHView->Update();
	}

	pHView->CameraPositionChanged(true, pHView->GetSmoothTransition());	
}

void PmView::OnViewPersistentName()
{	
	DestroyActiveDialog();

	pPNDialog = new PmViewPersistentNameDialog(this);
	pPNDialog->Create(IDD_VIEW_PERSISTENT_NAME);
	pPNDialog->ShowWindow(SW_SHOW);
}

void PmView::OnUpdateViewPersistentName(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "PmViewPersistentNameOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void PmView::OnMeshGeneration(double normalTolerance,double surfaceTolerance)
{
	PmMeshManager * pMeshManager = GetDocument()->GetMeshManager();
	pMeshManager->SetNormalTolerance(normalTolerance);
	pMeshManager->SetSurfaceTolerance(surfaceTolerance);

	CString path;
	GetDocument()->GenerateMesh(path);
}

double PmView::GetBBDiagonal()
{
	PmMeshManager * pMeshManager = GetDocument()->GetMeshManager();
	return(pMeshManager->m_BBDiagonal);
}

PmView * PmView::GetActiveView(void)
{
	CView * pView = (static_cast<CMDIFrameWnd *>(AfxGetApp()->m_pMainWnd))->GetActiveView();

    if(!pView)
        return NULL;

    // Fail if view is of wrong kind
    if(!pView->IsKindOf(RUNTIME_CLASS(PmView)))
        return NULL;

    return static_cast<PmView *>(pView);
}

// 특징형상 하이라이트 (16-11 권순조)
void PmView::SelectFeature(PmeFeature * pFeature)
{
	PmeHPart hPart = GetDocument()->GetPart();

	PmeHExplicitModel hExplicitModel;
	PmeHExplicitModelObject hExplicitModelObject;

	PmePartAPI::GetExplicitModel(hPart, hExplicitModel);
	PmeExplicitModelAPI::GetSolid(hExplicitModel, hExplicitModelObject);
	
	PmeFeatureType featureType;
	PmeFeatureAPI::GetType(pFeature, featureType);

	// 스케치 혹은 평면인 경우
	if (featureType == PmeFeatureType_StdSketchFeature
		|| featureType == PmeFeatureType_StdDefaultDatumPlaneFeature
		|| featureType == PmeFeatureType_StdDatumPlaneOffsetFeature)
	{
		CString featureName;
		PmeFeatureAPI::GetName(pFeature, featureName);
		
		int size;
		PmeExplicitModelAPI::GetSize(hExplicitModel, size);

		for (int i = 0; i < size; ++i)
		{
			PmeHExplicitModelObject hExplicitModelObject;
			PmeExplicitModelAPI::GetItem(hExplicitModel, hExplicitModelObject, i);
			
			CString name;
			PmeExplicitModelObjectAPI::GetName(hExplicitModelObject, name);
			
			if (featureName == name)
			{
				HC_KEY key = GetDocument()->GetHKeyFromHExplicitModelObject(hExplicitModelObject);
				static_cast<PmHSelectionSet *>(GetHoopsView()->GetSelection())->Select(key, 0, 0);
			}
		}
	}
	else // 기타 특징형상의 경우
	{
		BODY * pBody = 0;
		PmeSolidAPI::GetSolid(hExplicitModelObject, pBody);
		
		ENTITY_LIST faces;

		api_get_faces(pBody, faces);

		faces.init();

		while (ENTITY * pEntity = faces.next())
		{
			PmeFeature * pFaceFeature = PmeFeatureTagMarker::FindFeature(pEntity);

			if (pFaceFeature == pFeature)
				static_cast<PmHSelectionSet *>(GetHoopsView()->GetSelection())->Select(pEntity);
		}
	}

	// 단순 하이라이트를 위한 선택이기 때문에, 저장된 엔티티 리스트는 비운다.
	static_cast<PmHSelectionSet *>(GetHoopsView()->GetSelection())->ClearSelectedList();
}

/// 특징형상 생성 다이얼로그 부분 (16-12 권순조)
void PmView::OnCreateEdgeFillet()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidFilletConstantFeature);
}

void PmView::OnCreateChamfer()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidChamferFeature);
}

void PmView::OnCreateShell()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidShellFeature);
}

void PmView::OnCreateDraft()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidDraftFeature);
}

void PmView::OnCreateOffset()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidOffsetFeature);
}

void PmView::OnCreateExtrude()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidProtrusionExtrudeFeature);
}

void PmView::OnCreateRevolve()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidProtrusionRevolveFeature);
}

void PmView::OnCreateSweep()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidProtrusionSweepFeature);
}

void PmView::OnCreateHole()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidHoleCounterboredFeature);
}

void PmView::OnCreatePatternRectangular()
{
	CreateFeatureDialog(PmeFeatureType_StdSolidOperatePatternRectangularFeature);
}

void PmView::OnCreatePatternCircular()
{	
	CreateFeatureDialog(PmeFeatureType_StdSolidOperatePatternCircularFeature);
}

 void PmView::OnCreateDatumPlaneOffset()
{
	CreateFeatureDialog(PmeFeatureType_StdDatumPlaneOffsetFeature);
}

 void PmView::CreateFeatureDialog(PmeFeatureType type)
 {
	DestroyActiveDialog();

	if (type == PmeFeatureType_StdSolidProtrusionExtrudeFeature
		|| type == PmeFeatureType_StdSolidCutExtrudeFeature)
	{
		pDialog = new PmCreateExtrudeDialog(this);
		pDialog->Create(ID_SKETCHBASEDFEATURES_EXTRUDE);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidProtrusionRevolveFeature
		|| type == PmeFeatureType_StdSolidCutRevolveFeature)
	{
		pDialog = new PmCreateRevolveDialog(this);
		pDialog->Create(ID_SKETCHBASEDFEATURES_REVOLVE);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidProtrusionSweepFeature
		|| type == PmeFeatureType_StdSolidCutSweepFeature)
	{
		pDialog = new PmCreateSweepDialog(this);
		pDialog->Create(ID_SKETCHBASEDFEATURES_SWEEP);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidHoleSimpleFeature
		|| type == PmeFeatureType_StdSolidHoleCounterboredFeature
		|| type == PmeFeatureType_StdSolidHoleCountersunkFeature)
	{
		pDialog = new PmCreateHoleDialog(this);
		pDialog->Create(ID_SKETCHBASEDFEATURES_HOLE);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidFilletConstantFeature)
	{
		pDialog = new PmCreateEdgeFilletDialog(this);
		pDialog->Create(ID_TRANSITIONFEATURES_FILLET);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidChamferFeature)
	{
		pDialog = new PmCreateChamferDialog(this);
		pDialog->Create(ID_TRANSITIONFEATURES_CHAMFER);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidOperatePatternRectangularFeature)
	{
		pDialog = new PmCreatePatternRectangularDialog(this);
		pDialog->Create(ID_TRANSFORMATIONFEATURES_RECTANGULARPATTERN);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidOperatePatternCircularFeature)
	{
		pDialog = new PmCreatePatternCircularDialog(this);
		pDialog->Create(ID_TRANSFORMATIONFEATURES_CIRCULARPATTERN);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidShellFeature)
	{
		pDialog = new PmCreateShellDialog(this);
		pDialog->Create(ID_TRANSITIONFEATURES_SHELL);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidDraftFeature)
	{
		pDialog = new PmCreateDraftDialog(this);
		pDialog->Create(ID_TRANSITIONFEATURES_DRAFT);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdSolidOffsetFeature)
	{
		pDialog = new PmCreateOffsetDialog(this);
		pDialog->Create(ID_TRANSITIONFEATURES_OFFSET);
		pDialog->ShowWindow(SW_SHOW);
	}
	else if (type == PmeFeatureType_StdDatumPlaneOffsetFeature)
	{
		pDialog = new PmCreateDatumPlaneOffsetDialog(this);
		pDialog->Create(ID_DATUMPLANE_DATUMPLANEOFFSET);
		pDialog->ShowWindow(SW_SHOW);
	}
 }

 void PmView::DestroyActiveDialog(void)
 {
	 // 특징형상 생성, 수정 다이얼로그 제거
	 if (pDialog)
	 {
		delete pDialog;
		pDialog = 0;
	 }

	 // 고유명칭보기 다이얼로그 제거
	if (pPNDialog)
	{
		delete pPNDialog;
		pPNDialog = 0;
	}
 }
 ///

// 가운데 마우스 더블 클릭 시 Fit View (17-03 권순조)
void PmView::OnMButtonDblClk(UINT nFlags, CPoint point)
{
	GetHView()->FitWorld();
	GetHView()->Update();
	
	CHoopsView::OnMButtonDblClk(nFlags, point);
}
