// ComponentAuto.h : CComponentAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"



//#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
//#error "단일 스레드 COM 개체는 전체 DCOM 지원을 포함하지 않는 Windows Mobile 플랫폼과 같은 Windows CE 플랫폼에서 제대로 지원되지 않습니다. ATL이 단일 스레드 COM 개체의 생성을 지원하고 단일 스레드 COM 개체 구현을 사용할 수 있도록 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA를 정의하십시오. rgs 파일의 스레딩 모델은 DCOM Windows CE가 아닌 플랫폼에서 지원되는 유일한 스레딩 모델이므로 'Free'로 설정되어 있습니다."
//#endif

//using namespace ATL;


// CComponentAuto

class ATL_NO_VTABLE CComponentAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	//public CComCoClass<CComponentAuto, &CLSID_ComponentAuto>,
	public IDispatchImplEx<IComp, &IID_IComp, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CComponentAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMPONENTAUTO)


BEGIN_COM_MAP(CComponentAuto)
	COM_INTERFACE_ENTRY(IComp)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		//ReleaseDispatchImplEx();
	}
	void Initialize(PmeHComponent hComponent);

	PmeHComponent GetHComponent(void) {return m_hComponent;}

	static HRESULT GetICompFromHComp(PmeHComponent hComp, IComp** ppVal);
	static HRESULT GetIPartFromHPart(PmeHPart hPart, IPart** ppVal);
private:
	PmeHComponent m_hComponent;

public:
	STDMETHOD(set_Name)(BSTR pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(set_ParentName)(BSTR pVal);
	STDMETHOD(get_ParentName)(BSTR* pVal);
	
	STDMETHOD(GetPart)(/*PmeHComponent& hComp,*/ int i, IPart** ppVal);
	STDMETHOD(GetComponent)(/*PmeHComponent& hComp,*/ int i, IComp** ppVal);
	STDMETHOD(IsPart)( /*PmeHComponent& hComp,*/ int i,  VARIANT_BOOL* pVal);
	STDMETHOD(IsComponent)(/* PmeHComponent& hComp,*/ int i, VARIANT_BOOL* pVal);

	STDMETHOD(GetPlacement)(/*PmeHComponent hComponent,*/ double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz);
	STDMETHOD(SetPlacement)(/*PmeHComponent hComponent,*/ double ox, double oy, double oz, double zx, double zy, double zz, double xx, double xy, double xz);

	STDMETHOD(AddPart)(/*PmeHComponent& hItem,*/ IPart* pVal);
	STDMETHOD(AddComponent)(/*PmeHComponent& hItem,*/ IComp* pVal);

	STDMETHOD(GetSize)(/*PmeHComponent hItem,*/ int * pVal);

	STDMETHOD(SaveAsMesh)(int i, BSTR name);

	// for test
	STDMETHOD(CreatePart)( BSTR naem, IPart** ppVal );
	STDMETHOD(ImportPartFromXML)( BSTR path, IPart* pVal, IPart** ppVal );
	STDMETHOD(SetPartPlacement)( IPart* pVal, double ox, double oy, double oz, double zx, double zy, double zz, double xx, double xy, double xz );

};

//OBJECT_ENTRY_AUTO(__uuidof(ComponentAuto), CComponentAuto)
