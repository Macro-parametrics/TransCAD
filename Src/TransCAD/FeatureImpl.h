#pragma once

#include ".\PartAuto.h"
#include ".\FeaturesAuto.h"

template <class T>
class IFeatureImpl : public T
{
public:
	IFeatureImpl(void)
		: m_hFeature(0)
	{
	}

	void Initialize(PmeHFeature hFeature) {m_hFeature = hFeature;}

	// IFeature

	STDMETHODIMP get_Type(FeatureType* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		PmeFeatureType type;
		PmeFeatureAPI::GetType(m_hFeature, type);
		
		*pVal = ConvertPmeFeatureTypeToFeatureType(type);

		return S_OK;
	}

	STDMETHODIMP get_Name(BSTR* pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		CString name;
		PmeFeatureAPI::GetName(m_hFeature, name);

		name.SetSysString(pVal);

		return S_OK;
	}
	
	STDMETHODIMP SetName(BSTR pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		CString name(pVal);
		PmeFeatureAPI::SetName(m_hFeature, name);

		return S_OK;
	}

	/*
	STDMETHODIMP get_Part(IPart** ppVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		HRESULT hr;
		CComObject<CPartAuto> * pPartObject = NULL;
		hr = CComObject<CPartAuto>::CreateInstance(&pPartObject);
		if(FAILED(hr))
			return hr;
		
		IDispatch * pParent = m_pParent;
		CFeaturesAuto * pFeaturesAuto = static_cast<CFeaturesAuto *>(pParent);
		
		IDispatch * pPart = 0;
		hr = pFeaturesAuto->get_Parent(&pPart);
		if(FAILED(hr))
			return hr;

		pPart->QueryInterface(IID_IPart, (void **)ppVal);

		pPart->Release();
		
		return S_OK;
	}
	*/

private:

	FeatureType ConvertPmeFeatureTypeToFeatureType(PmeFeatureType type)
	{
		return (FeatureType)type;
	}

public:
	PmeHFeature m_hFeature;
};