// AssemAuto.h : CAssemAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include "DispatchImplEx.h"

// CAssemAuto

class ATL_NO_VTABLE CAssemAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
//	public CComCoClass<CAssemAuto, &CLSID_AssemAuto>,
	public IDispatchImplEx<IAssem, &IID_IAssem, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAssemAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ASSEMAUTO)


BEGIN_COM_MAP(CAssemAuto)
	COM_INTERFACE_ENTRY(IAssem)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		ReleaseDispatchImplEx();
	}

	void Initialize(PmeHAssembly hAssem);

	static HRESULT GetICompFromHComp(PmeHComponent hComp, IComp** ppVal);
	static HRESULT GetIPartFromHPart(PmeHPart hPart, IPart** ppVal);
	static HRESULT GetIReferenceFromHReference( PmeHReference hReference, IReference** ppVal );
	static HRESULT GetIStdAssemConstraintsFromHStdAssemConstraints( PmeHStdAssemblyConstraints hStdAssemConstraints, IStdAssemConstraints** ppVal );
	

private:
	PmeHAssembly m_hAssem;
	PmeHAssembly GetHAssem(void) {return m_hAssem;}

public:
	// Test func
	STDMETHOD(get_Name)(BSTR* pVal);

	STDMETHOD(CreatePart)(IPart** ppVal);
	STDMETHOD(CreateComponent)(IComp** ppVal);
	
	STDMETHOD(GetComponent)(int index, IComp** ppVal);
	STDMETHOD(GetSize)(/*PmeHComponent hItem,*/ int * pVal);

	//STDMETHOD(AddBooleanPart)(BSTR pVal,IPart* pTool,IPart* pBlank);
	//STDMETHOD(AddBooleanPart2)(BSTR pVal,IPart* pTool, VARIANT_BOOL type);
	STDMETHOD(AddComponent)(/*PmeHComponent& hItem,*/ IComp* pVal);

	STDMETHOD(get_Constraints)( IStdAssemConstraints** ppVal );
};

//OBJECT_ENTRY_AUTO(__uuidof(AssemAuto), CAssemAuto)
