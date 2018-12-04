// StdAssemConstraintIncidenceAuto.h : CStdAssemConstraintIncidenceAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdAssemConstraintImpl.h"

typedef IDispatchImplEx<IStdAssemConstraintIncidence, &IID_IStdAssemConstraintIncidence, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdAssemConstraintIncidenceType;

// CStdAssemConstraintIncidenceAuto

class ATL_NO_VTABLE CStdAssemConstraintIncidenceAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IStdAssemConstraintImpl<IStdAssemConstraintIncidenceType>	
{
public:
	CStdAssemConstraintIncidenceAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDASSEMCONSTRAINTINCIDENCE)


BEGIN_COM_MAP(CStdAssemConstraintIncidenceAuto)
	COM_INTERFACE_ENTRY(IStdAssemConstraintIncidence)
	COM_INTERFACE_ENTRY(IStdAssemConstraint)
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

public:
	STDMETHOD(get_ConstrainedPart)( IPart** ppVal);
	STDMETHOD(get_ConstrainedGeometry)( IReference** ppVal );
	STDMETHOD(get_ReferencePart)( IPart** ppVal );
	STDMETHOD(get_ReferenceGeometry)( IReference** ppVal );


};

//OBJECT_ENTRY_AUTO(__uuidof(StdAssemConstraintIncidence), CStdAssemConstraintIncidenceAuto)
