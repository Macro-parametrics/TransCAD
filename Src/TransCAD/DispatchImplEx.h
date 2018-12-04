#pragma once

template <class T, const IID* piid = &__uuidof(T), const GUID* plibid = &CAtlModule::m_libid, WORD wMajor = 1,
WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class IDispatchImplEx : public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
	IDispatchImplEx()
		: m_pApplication(0)
		, m_pParent(0)
	{
	}

	void InitializeDispatchImplEx(IApplication * pApp, IDispatch * pParent)
	{
		m_pApplication = pApp;
		m_pApplication->AddRef();
		 
		m_pParent = pParent;
		m_pParent->AddRef();
	}

	void ReleaseDispatchImplEx()
	{
		m_pApplication->Release();
		m_pParent->Release();
	}

	STDMETHODIMP get_Application(IApplication** pVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		*pVal = m_pApplication;
		m_pApplication->AddRef();

		return S_OK;
	}

	STDMETHODIMP get_Parent(IDispatch** ppVal)
	{
		AFX_MANAGE_STATE(AfxGetAppModuleState());

		*ppVal = m_pParent;
		m_pParent->AddRef();

		return S_OK;
	}
public:
	IApplication * m_pApplication;
	IDispatch * m_pParent;
};