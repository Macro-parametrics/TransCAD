// StdAssemConstraintsAuto.h : CStdAssemConstraintsAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"

// CStdAssemConstraintsAuto

class ATL_NO_VTABLE CStdAssemConstraintsAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImplEx<IStdAssemConstraints, &IID_IStdAssemConstraints, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdAssemConstraintsAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDASSEMCONSTRAINTS)


BEGIN_COM_MAP(CStdAssemConstraintsAuto)
	COM_INTERFACE_ENTRY(IStdAssemConstraints)
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
	
	void Initialize( PmeHAssembly hAssembly );
	//void Initialize( PmeHStdAssemblyConstraints hStdAssemblyConstraints );
																															                                               
private:
	PmeHAssembly m_hAssembly;
	//PmeHStdAssemblyConstraints m_hStdAssemblyConstraints;

private:
	HRESULT GetIStdAssemConstraintFromHStdAssemConstraint( PmeHStdAssemblyConstraint, IStdAssemConstraint **ppVal );
public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Constraint)(long index, IStdAssemConstraint** ppVal);
	STDMETHOD(get__NewEnum)( IUnknown** ppUnk );

	STDMETHOD(SelectConstraintByName)(BSTR name, IStdAssemConstraint** ppVal);
	

	// Add methods for pre-processor
	STDMETHOD(AddNewAssemblyCoaxialConstraint)(BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, IStdAssemConstraintCoaxial** ppVal);
	STDMETHOD(AddNewAssemblyIncidenceConstraint)(BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, StdAssemblyIncidenceType incidenceType, IStdAssemConstraintIncidence** ppVal);
	STDMETHOD(AddNewAssemblyDistance)(BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, double distance, StdAssemblyIncidenceType incidenceType, IStdAssemConstraintDistance** ppVal);
	STDMETHOD(AddNewAssemblyAngle)(BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, double angle, IStdAssemConstraintAngle** ppVal);

};

//OBJECT_ENTRY_AUTO(__uuidof(StdAssemConstraints), CStdAssemConstraintsAuto)
