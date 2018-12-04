// AssemView.h : iAssemView 클래스의 인터페이스


#pragma once

#include "AssemMacro.h"
#include ".\CHoopsView.h"

#include ".\AssemApplyConstraintDialog.h"

enum AssemModelHandedness
{
	AssemHandednessSetLeft,
	AssemHandednessSetRight,
	AssemHandednessSetNone,
	AssemHandednessNotSet
};

enum AssemModelView
{
	AssemPartView,
	AssemMeshView
};

class AssemHView;
class AssemDocument;
class PmeAssembly;
class AssemApplyConstraintDialog;

class ASSEM_API AssemView
	: public CHoopsView
{
protected: // serialization에서만 만들어집니다.
	AssemView();
	DECLARE_DYNCREATE(AssemView)

// 특성
public:
	AssemDocument* GetDocument() const;
	AssemHView * GetHView() const;

	void SetCoordinateSystemHandedness(HandednessMode rightOrLeft, bool emitMessage = true);
	void SetWindowColor(COLORREF newTopColor, COLORREF newBottomColor, bool emitMessage = true);
	void SetPolygonHandedness(AssemModelHandedness newHandedness);
	void SetMarkupColor(COLORREF newColor, bool emitMessage = true);
	void SetShadowColor(COLORREF newColor);

// 작업
private:
	void ZoomCamera(double factor);
	void SetInitialCameraPosition(double distance = 1000.0);
	AssemModelView m_currentView;

	HC_KEY m_selected_key;
	BOOL OnGeomHandle;
	

public:
	virtual void SetOperator(HBaseOperator * pNewOperator);
	virtual HBaseOperator * GetOperator(void);

	void FitWorld(void);

	HC_KEY Selected_key() const { return m_selected_key; }
	
	void SelectComponent(HC_KEY hKey);
	void SetGeomHandleStatus(BOOL val) { OnGeomHandle = val; }
// 재정의
public:
	// virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현
public:
	virtual ~AssemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnViewPan();
	afx_msg void OnUpdateViewPan(CCmdUI *pCmdUI);
	afx_msg void OnViewOrbit();
	afx_msg void OnUpdateViewOrbit(CCmdUI *pCmdUI);
	afx_msg void OnViewZoomIn();
	afx_msg void OnViewZoomOut();
	afx_msg void OnViewZoomToWindow();
	afx_msg void OnUpdateViewZoomToWindow(CCmdUI *pCmdUI);
	afx_msg void OnViewFront();
	afx_msg void OnViewBack();
	afx_msg void OnViewLeft();
	afx_msg void OnViewRight();
	afx_msg void OnViewTop();
	afx_msg void OnViewBottom();
	afx_msg void OnViewWireframe();
	afx_msg void OnUpdateViewWireframe(CCmdUI *pCmdUI);
	afx_msg void OnViewFlatShading();
	afx_msg void OnUpdateViewFlatShading(CCmdUI *pCmdUI);
	afx_msg void OnViewGouroudShadihg();
	afx_msg void OnUpdateViewGouroudShadihg(CCmdUI *pCmdUI);
	afx_msg void OnViewPhongShading();
	afx_msg void OnUpdateViewPhongShading(CCmdUI *pCmdUI);
	afx_msg void OnViewHiddenLine();
	afx_msg void OnUpdateViewHiddenLine(CCmdUI *pCmdUI);
	afx_msg void OnViewActiveSketchViewpoint();
	afx_msg void OnViewDefaultViewpoint();
	afx_msg void OnViewZoomAll();	

	afx_msg void OnUpdateMeshGeneration(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

// Added by YK
protected:
	AssemApplyConstraintDialog * m_pDialog;

public:
	void CreateConstraintDialog( PmeStdAssemblyConstraintType type );
	void DestroyActiveDialog( void );
	

	
	afx_msg void OnApplyCoaxial();
	afx_msg void OnApplyIncidence();
	afx_msg void OnAppyParallel();
	afx_msg void OnApplyPerpendicular();
	afx_msg void OnApplyDistance();
	afx_msg void OnApplyAngle();
};

#ifndef _DEBUG  // AssemView.cpp의 디버그 버전
inline AssemDocument* AssemView::GetDocument() const
   { return reinterpret_cast<AssemDocument*>(m_pDocument); }
#endif

