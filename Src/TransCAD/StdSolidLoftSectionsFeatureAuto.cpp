// StdSolidLoftFacesFeatureAuto.cpp : CStdSolidLoftFacesFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidLoftSectionsFeatureAuto.h"
#include ".\PartAuto.h"


// CStdSolidLoftFacesFeatureAuto

STDMETHODIMP CStdSolidLoftSectionsFeatureAuto::get_References(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hLoftSections;
	PmeStdSolidLoftSectionsFeatureAPI::GetLoftSections(m_hFeature, hLoftSections);

	return CPartAuto::GetIReferencesFromHReferences(hLoftSections, ppVal);
}

STDMETHODIMP CStdSolidLoftSectionsFeatureAuto::get_IsCut(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isCut;
	PmeStdSolidLoftSectionsFeatureAPI::IsCut(m_hFeature, isCut);

	*pVal = (isCut) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}
