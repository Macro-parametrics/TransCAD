#pragma once

#include ".\PartAuto.h"
#include ".\StdSketchConstraintsAuto.h"

template <class T>
class IStdSketchConstraintImpl : public T
{
public:
	IStdSketchConstraintImpl(void)
		: m_hStdSketchConstraint(0)
	{
	}

	void Initialize(PmeHStdSketchConstraint hStdSketchConstraint) {m_hStdSketchConstraint = hStdSketchConstraint;}

	// IStdSketchConstraint

	STDMETHODIMP get_Type(StdSketchConstraintType* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		PmeStdSketchConstraintType type;
		PmeStdSketchConstraintAPI::GetType(m_hStdSketchConstraint, type);

		*pVal = ConvertPmeStdSketchConstraintTypeToStdSketchConstraintType(type);

		return S_OK;
	}

	STDMETHODIMP get_Name(BSTR* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		CString name;
		PmeStdSketchConstraintAPI::GetName(m_hStdSketchConstraint, name);

		name.SetSysString(pVal);

		return S_OK;
	}

	STDMETHODIMP get_SketchFeature(IStdSketchFeature** ppVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		return S_OK;
	}

	HRESULT GetIStdSketchGeometryFromHStdSketchGeometry(PmeHStdSketchGeometry hGeometry, IStdSketchGeometry** ppVal)
	{
		*ppVal = NULL;
		HRESULT hr = S_OK;

		if(hGeometry == 0)
			return S_OK;

		CComObject<CStdSketchGeometryAuto> * pObj = NULL;
		hr = CComObject<CStdSketchGeometryAuto>::CreateInstance(&pObj);
		if(FAILED(hr))
			return hr;

		pObj->Initialize(hGeometry);

		hr = pObj->QueryInterface(__uuidof(IStdSketchGeometry), (void **)ppVal);

		return hr;
	}

private:

	StdSketchConstraintType ConvertPmeStdSketchConstraintTypeToStdSketchConstraintType(PmeStdSketchConstraintType type)
	{
		return (StdSketchConstraintType)type;
	}

public:
	PmeHStdSketchConstraint m_hStdSketchConstraint;
};