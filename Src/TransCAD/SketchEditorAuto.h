// SketchEditorAuto.h : CSketchEditorAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"


// CSketchEditorAuto

class ATL_NO_VTABLE CSketchEditorAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CSketchEditorAuto, &CLSID_SketchEditor>,
	public IDispatchImpl<ISketchEditor, &IID_ISketchEditor, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSketchEditorAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SKETCHEDITOR)


BEGIN_COM_MAP(CSketchEditorAuto)
	COM_INTERFACE_ENTRY(ISketchEditor)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

	void Initialize(PmeHStdSketchEditor hEditor);

private:
	PmeHStdSketchEditor m_hEditor;

public:
	STDMETHOD(Close)(void);
	STDMETHOD(DeleteByName)(BSTR name);
	STDMETHOD(Create2DLine2Points)(BSTR name, double startX, double startY, double endX, double endY, IStdSketchLine** ppVal);
	STDMETHOD(Create2DCircleCenterPoint)(BSTR name, double centerX, double centerY, double radius, IStdSketchCircle** ppVal);
	STDMETHOD(Create2DArc)(BSTR name, double centerX, double centerY, double radius, double startAngle, double endAngle, IStdSketchCircularArc** ppVal);
	STDMETHOD(Create2DArcCenterStartEnd)(BSTR name, double centerX, double centerY, double startX, double startY, double endX, double endY, IStdSketchCircularArc** ppVal);
	STDMETHOD(Create2DArc3Points)(BSTR name, double startX, double startY, double intermediateX, double intermediateY, double endX, double endY, IStdSketchCircularArc** ppVal);
	STDMETHOD(Create2DCenterline2Points)(BSTR name, double startX, double startY, double endX, double endY, IStdSketchLine** ppVal);
	STDMETHOD(CreateCoincidentSamePoints)(BSTR name, IReference* pFirstObject, StdCoincidentSamePointsType firstType, IReference* pSecondObject, StdCoincidentSamePointsType secondType, IStdSketchCoincidentSamePoints** ppVal);
	STDMETHOD(CreatePerpendicular)(BSTR name, IReference* pReferenceEdit, IReference* pTarget, IStdSketchPerpendicular** ppVal);
	STDMETHOD(CreateParallel)(BSTR name, IReference* pReferenceEdit, IReference* pTarget, IStdSketchParallel** ppVal);
	STDMETHOD(CreateHorizontal)(BSTR name, IReference* pTarget, IStdSketchHorizontal** ppVal);
	STDMETHOD(CreateVertical)(BSTR name, IReference* pTarget, IStdSketchVertical** ppVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(SketchEditor), CSketchEditorAuto)
