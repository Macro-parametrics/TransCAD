// AssemDocumentAuto.h : CAssemDocumentAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include "DispatchImplEx.h"

// #if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
// #error "단일 스레드 COM 개체는 전체 DCOM 지원을 포함하지 않는 Windows Mobile 플랫폼과 같은 Windows CE 플랫폼에서 제대로 지원되지 않습니다. ATL이 단일 스레드 COM 개체의 생성을 지원하고 단일 스레드 COM 개체 구현을 사용할 수 있도록 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA를 정의하십시오. rgs 파일의 스레딩 모델은 DCOM Windows CE가 아닌 플랫폼에서 지원되는 유일한 스레딩 모델이므로 'Free'로 설정되어 있습니다."
// #endif

//using namespace ATL;


// CAssemDocumentAuto

class ATL_NO_VTABLE CAssemDocumentAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
//	public CComCoClass<CAssemDocumentAuto, &CLSID_AssemDocumentAuto>,
	public IDispatchImplEx<IAssemDocument, &IID_IAssemDocument, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAssemDocumentAuto()
			:m_pDocument(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ASSEMDOCUMENTAUTO)


BEGIN_COM_MAP(CAssemDocumentAuto)
	COM_INTERFACE_ENTRY(IAssemDocument)
	COM_INTERFACE_ENTRY(IDoc)
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

	void Initialize(AssemDocument * pDocument);

public:
	// IDoc으로 부터 상속받은 함수들 정의
	STDMETHOD(get_FullName)(BSTR* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Path)(BSTR* pVal);
	STDMETHOD(get_Saved)(VARIANT_BOOL* pVal);
	STDMETHOD(Activate)(void);
	STDMETHOD(Close)(VARIANT_BOOL saveChanges, BSTR filename);
	STDMETHOD(Save)(void);
	STDMETHOD(SaveAs)(BSTR filename);

	// IAssemDocument에서만 정의한 함수
	STDMETHOD(get_Assem)(IAssem** pVal);
	STDMETHOD(Update)(void);

	STDMETHOD(test)(void);


private:
	AssemDocument* m_pDocument;

};

//OBJECT_ENTRY_AUTO(__uuidof(AssemDocumentAuto), CAssemDocumentAuto)
