#pragma once

#include ".\PartAuto.h"
#include ".\StdSketchGeometriesAuto.h"

template <class T>
class IStdSketchGeometryImpl : public T
{
public:
	IStdSketchGeometryImpl(void)
		: m_hStdSketchGeometry(0)
	{
	}

	void Initialize(PmeHStdSketchGeometry hStdSketchGeometry) {m_hStdSketchGeometry = hStdSketchGeometry;}

	// IStdSketchGeometry

	STDMETHODIMP get_Type(StdSketchGeometryType* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		PmeStdSketchGeometryType type;
		PmeStdSketchGeometryAPI::GetType(m_hStdSketchGeometry, type);

		*pVal = ConvertPmeStdSketchGeometryTypeToStdSketchGeometryType(type);

		return S_OK;
	}

	STDMETHODIMP get_Name(BSTR* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		CString name;
		PmeStdSketchGeometryAPI::GetName(m_hStdSketchGeometry, name);

		name.SetSysString(pVal);

		return S_OK;
	}

	STDMETHODIMP get_SketchFeature(IStdSketchFeature** ppVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		return S_OK;
	}

private:

	StdSketchGeometryType ConvertPmeStdSketchGeometryTypeToStdSketchGeometryType(PmeStdSketchGeometryType type)
	{
		return (StdSketchGeometryType)type;
	}

public:
	PmeHStdSketchGeometry m_hStdSketchGeometry;
};