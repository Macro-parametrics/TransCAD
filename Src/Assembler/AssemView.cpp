// AssemView.cpp : AssemView 클래스의 구현
//

#include "stdafx.h"

#include "AssemDocument.h"
#include "AssemView.h"
#include "AssemHView.h"
#include "AssemSettings.h"
#include "AssemViewPanningOperator.h"
#include "AssemViewRotationOperator.h"
#include "AssemViewZoomWindowOperator.h"
#include "AssemHSelectionSet.h"
#include "PmMeshManager.h"

#include "AssemFrame.h"
#include "AssemFeatureTree.h"

#include "PmViewPersistentNameOperator.h"
#include "PmViewPersistentNameDialog.h"

#include "HUtilityGeomHandle.h"
#include "AssemOpMoveHandle.h"
#include "HOpCameraManipulate.h"
#include "HEventManager.h"
#include "AssemViewManipulationOperator.h"
#include "resource.h"


// for assembly constraint dialog
#include ".\AssemApplyCoaxialDialog.h"
#include ".\AssemApplyIncidenceDialog.h"
#include ".\AssemApplyParallelDialog.h"
#include ".\AssemApplyPerpendicularDialog.h"
#include ".\AssemApplyDistanceDialog.h"
#include ".\AssemApplyAngleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// AssemView
IMPLEMENT_DYNCREATE(AssemView, CHoopsView)

BEGIN_MESSAGE_MAP(AssemView, CHoopsView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CHoopsView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CHoopsView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CHoopsView::OnFilePrintPreview)
	ON_WM_SIZE()
	// 화면 이동
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

	//ON_UPDATE_COMMAND_UI(ID_MESH_GEN, OnUpdateMeshGeneration)
	
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_ASSEMBLY_COAXIAL, &AssemView::OnApplyCoaxial)
	ON_COMMAND(ID_ASSEMBLY_INCIDENCE, &AssemView::OnApplyIncidence)
	ON_COMMAND(ID_ASSEMBLY_PARALLEL, &AssemView::OnAppyParallel)
	ON_COMMAND(ID_ASSEMBLY_PERPENDICULAR, &AssemView::OnApplyPerpendicular)
	ON_COMMAND(ID_ASSEMBLY_DISTANCE, &AssemView::OnApplyDistance)
	ON_COMMAND(ID_ASSEMBLY_ANGLE, &AssemView::OnApplyAngle)
END_MESSAGE_MAP()

// AssemView 생성/소멸

AssemView::AssemView()
{
	m_pHView = 0;
	m_pDialog = 0;
}

AssemView::~AssemView()
{
	if(m_pHView)
	{
		delete m_pHView;
		m_pHView = 0;
	}

	if ( m_pDialog != NULL )
	{
		m_pDialog->DestroyWindow();
		delete m_pDialog;
		m_pDialog = NULL;
	}
}

BOOL AssemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CHoopsView::PreCreateWindow(cs);
}

// AssemView 그리기
/*
void AssemView::OnDraw(CDC* pDC)
{
	AssemDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}
*/

// AssemView 인쇄

BOOL AssemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void AssemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void AssemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// AssemView 진단

#ifdef _DEBUG
void AssemView::AssertValid() const
{
	CHoopsView::AssertValid();
}

void AssemView::Dump(CDumpContext& dc) const
{
	CHoopsView::Dump(dc);
}

AssemDocument* AssemView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(AssemDocument)));
	return (AssemDocument*)m_pDocument;
}
#endif //_DEBUG


// AssemView 메시지 처리기

void AssemView::OnInitialUpdate()
{
	CHoopsView::OnInitialUpdate();

	AssemDocument * pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	AssemHModel * pHModel = pDoc->GetHModel();

	// create the HOOPS ParaView object corresponding with this MFC View, passing in the 
	// Model Object, the MFC View's window handle, and palette
	m_pHView = new AssemHView(
		pHModel
		, 0
		, "opengl"
		, 0
		, (void *)m_hWnd
		, (void *)(HPALETTE)*(GetPalette())
	);
	AssemHView * pHView = static_cast<AssemHView *>(m_pHView);

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

	AssemSettings * pSettings = GetDocument()->GetSettings();

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

	SetOperator(new HOpCameraManipulate(pHView, 0,1, new AssemViewRotationOperator(pHView), new AssemViewPanningOperator(pHView),
		new AssemViewZoomWindowOperator(pHView),0,false));	

	pHView->SetAxisManipulateOperator(new HOpCameraManipulate(pHView, 0,1, new AssemViewRotationOperator(pHView), new AssemViewPanningOperator(pHView),
		new AssemViewZoomWindowOperator(pHView),0, false));

	AssemOpMoveHandle *handleoperator = new AssemOpMoveHandle(m_pHView, this, GetDocument(), false);

	pHView->SetHandleOperator(handleoperator);
	
//	pHView->GetEventManager()->RegisterHandler((HObjectManipulationListener *)handleoperator, HObjectManipulationListener::GetType(), HLISTENER_PRIORITY_NORMAL);

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
	pHView->SetPolygonHandednessMode(HandednessLeft);

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

	SetOperator(new AssemViewManipulationOperator(pHView));	
	//((HOpCameraOrbit *)GetOperator())->SetLightFollowsCamera(true);

	pHView->FitWorld();		// fit the camera to the scene extents
	SetInitialCameraPosition();
	pHView->CameraPositionChanged();

	OnGeomHandle = FALSE;
	//we need to adjust the axis window outside the mvo class as the calculation of the window
	//extents is mfc specific
 	AdjustAxisWindow();
	pHView->ForceUpdate();
}

void AssemView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	AssemHView * pHView = GetHView();
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

void AssemView::SetCoordinateSystemHandedness(HandednessMode rightOrLeft, bool emitMessage)
{
	AssemHView * pHView = GetHView();
	pHView->SetHandedness(rightOrLeft, emitMessage);
}

void AssemView::SetWindowColor(COLORREF newTopColor, COLORREF newBottomColor, bool emitMessage)
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

void AssemView::SetPolygonHandedness(AssemModelHandedness newHandedness)
{
	// now onwards (9.0) we don't set the handedness just on view.
	// we do not mess up with model segment at all - Rajesh B (13-May-03)

	AssemHView * pHView = GetHView();
	if(newHandedness == AssemHandednessSetLeft)
		pHView->SetPolygonHandednessMode(HandednessLeft);
	else if(newHandedness == AssemHandednessSetRight)
		pHView->SetPolygonHandednessMode(HandednessRight);
	else if(newHandedness == AssemHandednessSetNone )
		pHView->SetPolygonHandednessMode(HandednessNone);
	else if(newHandedness == AssemHandednessNotSet)
		;
	else
		assert(0);
}

void AssemView::SetMarkupColor(COLORREF newColor, bool emitMessage)
{
	AssemHView * pHView = GetHView();
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

void AssemView::SetShadowColor(COLORREF newColor)
{
	AssemHView * pHView = GetHView();
	HPoint color;
	color.Set(
		static_cast<float>(GetRValue(newColor)) / 255.0f,
		static_cast<float>(GetGValue(newColor)) / 255.0f,
		static_cast<float>(GetBValue(newColor)) / 255.0f);
	pHView->SetShadowColor(color);
}

AssemHView * AssemView::GetHView() const
{
	return static_cast<AssemHView *>(m_pHView);
}

void AssemView::OnSize(UINT nType, int cx, int cy)
{
	CHoopsView::OnSize(nType, cx, cy);

	AssemHView * pHView = GetHView();
	if(pHView)
        pHView->ForceUpdate();
}

void AssemView::SetOperator(HBaseOperator * pNewOperator)
{
	HBaseOperator * pOp = m_pHView->GetOperator();

	if(pOp)
	    delete pOp;
	
	((AssemHView *)m_pHView)->SetSnap(false);

    m_pHView->SetOperator(pNewOperator);
}

HBaseOperator * AssemView::GetOperator(void)
{
	return m_pHView->GetOperator();
}

void AssemView::OnViewPan()
{
	SetOperator(new AssemViewPanningOperator(GetHView()));
}

void AssemView::OnUpdateViewPan(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "AssemViewPanningOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewOrbit()
{
	SetOperator(new AssemViewRotationOperator(GetHView()));
}

void AssemView::OnUpdateViewOrbit(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "AssemViewRotationOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewZoomIn()
{
	ZoomCamera(2.0);	
}

void AssemView::OnViewZoomOut()
{
	ZoomCamera(0.5);	
}

void AssemView::OnViewZoomToWindow()
{
	SetOperator(new AssemViewZoomWindowOperator(GetHView()));
}

void AssemView::OnUpdateViewZoomToWindow(CCmdUI *pCmdUI)
{
	if(strcmp(GetOperator()->GetName(), "AssemViewZoomWindowOperator") == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewFront()
{
	GetHView()->SetViewMode(HViewXY);
}

void AssemView::OnViewBack()
{
	GetHView()->SetViewMode(HViewYX);
}

void AssemView::OnViewLeft()
{
	GetHView()->SetViewMode(HViewZY);
}

void AssemView::OnViewRight()
{
	GetHView()->SetViewMode(HViewYZ);
}

void AssemView::OnViewTop()
{
	GetHView()->SetViewMode(HViewZX);
}


void AssemView::OnViewBottom()
{
	GetHView()->SetViewMode(HViewXZ);
}


void AssemView::OnViewWireframe()
{
	AssemHView * pHView = GetHView();

	pHView->RenderWireframe();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
		HC_Set_Visibility("edges = on, lines = on");
    HC_Close_Segment();

	pHView->Update();
}

void AssemView::OnUpdateViewWireframe(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderWireframe)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewFlatShading()
{
	AssemHView * pHView = GetHView();

	pHView->RenderFlat();	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, edges=off, lines = off");
    HC_Close_Segment();

	pHView->Update();
}

void AssemView::OnUpdateViewFlatShading(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderFlat)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewGouroudShadihg()
{
 	AssemHView * pHView = GetHView();
	
	pHView->RenderGouraud();	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, lines = on, edges = off");		
    HC_Close_Segment();

	pHView->Update();
}

void AssemView::OnUpdateViewGouroudShadihg(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderGouraud)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewPhongShading()
{
 	AssemHView * pHView = GetHView();

	pHView->RenderPhong();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = on, edges=off, lines = off");
    HC_Close_Segment();

	pHView->Update();
}

void AssemView::OnUpdateViewPhongShading(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderPhong)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void AssemView::OnViewHiddenLine()
{
 	AssemHView * pHView = GetHView();

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
        HC_Set_Visibility("faces = off, edges=on, lines = on");
    HC_Close_Segment();

	pHView->SetRenderMode(HRenderHiddenLine, true);
	pHView->Update();
}

void AssemView::OnUpdateViewHiddenLine(CCmdUI *pCmdUI)
{
	if(GetHView()->GetRenderMode() == HRenderHiddenLine || m_pHView->GetRenderMode() == HRenderHiddenLineFast)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void AssemView::OnViewActiveSketchViewpoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void AssemView::OnViewDefaultViewpoint()
{
	AssemHView * pHView = GetHView();

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

void AssemView::ZoomCamera(double factor)
{
	AssemHView * pHView = GetHView();

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

void AssemView::SetInitialCameraPosition(double distance)
{
	AssemHView * pHView = GetHView();
	double width = distance / 2.5;
	double height = distance / 2.5;

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
		HC_Set_Camera_Position(distance, distance, distance);
		HC_Set_Camera_Field(width, height);
		HC_Set_Camera_Up_Vector(0.0, 0.0, 1.0);
	HC_Close_Segment();	
}

void AssemView::OnViewZoomAll()
{
	AssemHView * pHView = GetHView();

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


void AssemView::OnUpdateMeshGeneration(CCmdUI *pCmdUI)
{
	//pCmdUI->Enable(GetDocument()->GetMeshManager()->IsEmpty());
}

void AssemView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	HC_KEY key = -1;
	int offset1= -1 ;
	int offset2= -1 ;
	int offset3= -1 ;

	HPoint localpixels, localwindow;
	localpixels.Set((float)point.x,(float) point.y, 0);

	HC_Open_Segment_By_Key(m_pHView->GetSceneKey());
		HC_Compute_Coordinates(".", "local pixels", &localpixels, "local window", &localwindow);
	HC_Close_Segment();
	
	HC_Open_Segment_By_Key(m_pHView->GetViewKey());
		if ( HC_Compute_Selection(".","./scene/overwrite","v", localwindow.x, localwindow.y))
		{	
			HC_Show_Selection_Element (&key, &offset1, &offset2, &offset3);
		}
	HC_Close_Segment();

	if (key != -1)
	{
		char type[MVO_BUFFER_SIZE];
		HC_Show_Key_Type(key, type);
		if (strcmp(type,"segment") != 0)
		{	//To grab a component	
			key = HC_KShow_Owner_By_Key(key);
			key = HC_KShow_Owner_By_Key(key);
			key = HC_KShow_Owner_By_Key(key);
			key = HC_KShow_Owner_By_Key(key);
		}	

		PmeHComponent hSelectedComponent = GetDocument()->GetComponentFromHKey(key);

		if(hSelectedComponent)
		{
			SelectComponent(key);
			CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
			CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());
		
			if(pFrame->IsKindOf(RUNTIME_CLASS(AssemFrame)))
			{
				AssemFeatureTree * pFeatureTree = static_cast<AssemFrame *>(pFrame)->GetFeatureTree();
			
				pFeatureTree->SelectComponent(hSelectedComponent);
			}

			//key = HUtility::GrabSegment(key);
		
	 		m_selected_key = key;
			MrAxis2 placement;

			PmeComponentAPI::GetPlacement(hSelectedComponent, placement);

			//HPoint mid_point(placement.Location().X(),placement.Location().Y(),placement.Location().Z());

			HPoint mid_point(0,0,0);
			
			HUtilityGeomHandle ghandle;
			
			ghandle.SetupManipulator(key,GetHView(),&mid_point,false,false,false,true,true,false);

			OnGeomHandle = TRUE;
		}
		
	}
	
	CHoopsView::OnLButtonDblClk(nFlags, point);
	Invalidate(FALSE);
}

void AssemView::SelectComponent( HC_KEY hKey )
{
	GetHView()->GetSelection()->DeSelectAll();
	GetHView()->GetSelection()->Select(hKey,0,0);
	Invalidate(FALSE);
}

/*
void AssemView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(!OnGeomHandle)
	{
		HC_KEY key = -1;
		int offset1= -1 ;
		int offset2= -1 ;
		int offset3= -1 ;

		HPoint localpixels, localwindow;
		localpixels.Set((float)point.x,(float) point.y, 0);

		HC_Open_Segment_By_Key(m_pHView->GetSceneKey());
		HC_Compute_Coordinates(".", "local pixels", &localpixels, "local window", &localwindow);
		HC_Close_Segment();

		HC_Open_Segment_By_Key(m_pHView->GetViewKey());
		if ( HC_Compute_Selection(".","./scene/overwrite","v", localwindow.x, localwindow.y))
		{	
			HC_Show_Selection_Element (&key, &offset1, &offset2, &offset3);
		}
		HC_Close_Segment();

		if (key != -1)
		{
			char type[MVO_BUFFER_SIZE];
			HC_Show_Key_Type(key, type);
			if (strcmp(type,"segment") != 0)
			{	//To grab a component	
				key = HC_KShow_Owner_By_Key(key);
 				key = HC_KShow_Owner_By_Key(key);
				key = HC_KShow_Owner_By_Key(key);
				key = HC_KShow_Owner_By_Key(key);
			}	
			PmeHComponent hSelectedComponent = GetDocument()->GetComponentFromHKey(key);
			if(hSelectedComponent)
			{
				SelectComponent(key);

				CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
				CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());

				if(pFrame->IsKindOf(RUNTIME_CLASS(AssemFrame)))
				{
					AssemFeatureTree * pFeatureTree = static_cast<AssemFrame *>(pFrame)->GetFeatureTree();

					pFeatureTree->SelectComponent(hSelectedComponent);
				}
			}
		}
		else
		{
			GetHView()->GetSelection()->DeSelectAll();
		}
	
	}
	CHoopsView::OnMouseMove(nFlags, point);
	Invalidate(FALSE);
	
}
*/


void AssemView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	if(!OnGeomHandle)
	{
		HC_KEY key = -1;
		int offset1= -1 ;
		int offset2= -1 ;
		int offset3= -1 ;

		HPoint localpixels, localwindow;
		localpixels.Set((float)point.x,(float) point.y, 0);

		HC_Open_Segment_By_Key(m_pHView->GetSceneKey());
		HC_Compute_Coordinates(".", "local pixels", &localpixels, "local window", &localwindow);
		HC_Close_Segment();

		HC_Open_Segment_By_Key(m_pHView->GetViewKey());
		if ( HC_Compute_Selection(".","./scene/overwrite","v", localwindow.x, localwindow.y))
		{	
			HC_Show_Selection_Element (&key, &offset1, &offset2, &offset3);
		}
		HC_Close_Segment();

		if (key != -1)
		{
			char type[MVO_BUFFER_SIZE];
			HC_Show_Key_Type(key, type);
			if (strcmp(type,"segment") != 0)
			{	//To grab a component	
				key = HC_KShow_Owner_By_Key(key);
				key = HC_KShow_Owner_By_Key(key);
				key = HC_KShow_Owner_By_Key(key);
				key = HC_KShow_Owner_By_Key(key);
			}	
			PmeHComponent hSelectedComponent = GetDocument()->GetComponentFromHKey(key);
			if(hSelectedComponent)
			{
				SelectComponent(key);

				CMDIFrameWnd * pMainFrame = static_cast<CMDIFrameWnd *>(AfxGetMainWnd());
				CMDIChildWnd * pFrame = static_cast<CMDIChildWnd *>(pMainFrame->GetActiveFrame());

				if(pFrame->IsKindOf(RUNTIME_CLASS(AssemFrame)))
				{
					AssemFeatureTree * pFeatureTree = static_cast<AssemFrame *>(pFrame)->GetFeatureTree();

					pFeatureTree->SelectComponent(hSelectedComponent);
				}
				
				CMenu parent_menu;	
				CMenu * popup_menu;
				CRect   rect;
				CPoint  new_menu_position;

				int pos;
				(void) pos;


				parent_menu.LoadMenu (IDR_POPUP_MENU);
				// Get a pointer to the menu
				popup_menu = parent_menu.GetSubMenu (0);

				GetWindowRect(&rect);

				// Transform the screen coordinate point to a window-relative point.
				new_menu_position = CPoint (rect.left + point.x, rect.top + point.y);

				popup_menu->TrackPopupMenu( TPM_LEFTALIGN , 
					new_menu_position.x, 
					new_menu_position.y, 
					(CWnd *)this);  


			}
		}
		else
		{
			GetHView()->GetSelection()->DeSelectAll();
		}

	}
	
	CHoopsView::OnRButtonDown(nFlags, point);
}

void AssemView::DestroyActiveDialog( void )
{
	if ( m_pDialog )
	{
		delete m_pDialog;
		m_pDialog = 0;
	}
}

void AssemView::CreateConstraintDialog( PmeStdAssemblyConstraintType type )
{
	DestroyActiveDialog();

	if ( type == PmeStdAssemblyConstraintType_Coaxial )
	{
		m_pDialog = new AssemApplyCoaxialDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_COAXIAL );

		m_pDialog->ShowWindow( SW_SHOW );
	}

	else if ( type == PmeStdAssemblyConstraintType_Incidence )
	{
		m_pDialog = new AssemApplyIncidenceDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_INCIDENCE );

		m_pDialog->ShowWindow( SW_SHOW );
	}

	else if ( type == PmeStdAssemblyConstraintType_Parallel )
	{
		m_pDialog = new AssemApplyParallelDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_PARALLEL );

		m_pDialog->ShowWindow( SW_SHOW );
	}

	else if ( type == PmeStdAssemblyConstraintType_Perpendicular )
	{
		m_pDialog = new AssemApplyPerpendicularDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_PERPENDICULAR );

		m_pDialog->ShowWindow( SW_SHOW );
	}

	else if ( type == PmeStdAssemblyConstraintType_Distance )
	{
		m_pDialog = new AssemApplyDistanceDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_DISTANCE );

		m_pDialog->ShowWindow( SW_SHOW );
	}

	else if ( type == PmeStdAssemblyConstraintType_Angle )
	{
		m_pDialog = new AssemApplyAngleDialog( this );
		
		m_pDialog->Create( IDD_CONSTRAINT_ANGLE );

		m_pDialog->ShowWindow( SW_SHOW );
	}

}

void AssemView::OnApplyCoaxial()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Coaxial );
}


void AssemView::OnApplyIncidence()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Incidence );
}


void AssemView::OnAppyParallel()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Parallel );
}


void AssemView::OnApplyPerpendicular()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Perpendicular );
}


void AssemView::OnApplyDistance()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Distance );
}


void AssemView::OnApplyAngle()
{
	CreateConstraintDialog( PmeStdAssemblyConstraintType_Angle );
}
