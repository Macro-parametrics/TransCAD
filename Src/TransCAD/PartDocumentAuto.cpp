// PartDocumentAuto.cpp : CPartDocumentAuto의 구현입니다.

#include "stdafx.h"
#include "PartDocumentAuto.h"
#include ".\PartAuto.h"

// CPartDocumentAuto

void CPartDocumentAuto::Initialize(PmDocument * pDocument)
{
	m_pDocument = pDocument;
}

STDMETHODIMP CPartDocumentAuto::get_FullName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString fullname = m_pDocument->GetPathName();
	fullname.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name = m_pDocument->GetPathName();
	name = name.Right(name.GetLength() - name.ReverseFind('\\') - 1);
	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::get_Path(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString path = m_pDocument->GetPathName();
	path = path.Left(path.ReverseFind('\\'));
	path.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::get_Saved(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::Activate(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::Close(VARIANT_BOOL saveChanges, BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::Save(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return (m_pDocument->DoFileSave() == TRUE) ? S_OK : E_FAIL;
}

STDMETHODIMP CPartDocumentAuto::SaveAs(BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strFilename(filename);
	
	return (m_pDocument->DoSave(strFilename) == TRUE) ? S_OK : E_FAIL;
}

STDMETHODIMP CPartDocumentAuto::get_Part(IPart** pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());	

	HRESULT hr;
	CComObject<CPartAuto> * pPartObject = NULL;
	hr = CComObject<CPartAuto>::CreateInstance(&pPartObject);
	if(FAILED(hr))
		return hr;

	pPartObject->InitializeDispatchImplEx(m_pApplication, this);
	pPartObject->Initialize(m_pDocument->GetPart());

	hr = pPartObject->QueryInterface(__uuidof(IPart), (void **)pVal);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::Update(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	m_pDocument->UpdateAll();

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::get_Title(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString title = m_pDocument->GetTitle();
	*pVal = title.AllocSysString();

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::DoMeshGeneration(double normalTolerance,double surfaceTolerance)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	if(pFrame == NULL) return E_FAIL;

	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	if(pChild == NULL) return E_FAIL;

	PmView * pPmView = static_cast<PmView *>(pChild->GetActiveView());
	if(pPmView == NULL) return E_FAIL;

	pPmView->OnMeshGeneration(normalTolerance,surfaceTolerance);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::GetBBDiagonal(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	if(pFrame == NULL) return E_FAIL;

	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	if(pChild == NULL) return E_FAIL;

	PmView * pPmView = static_cast<PmView *>(pChild->GetActiveView());
	if(pPmView == NULL) return E_FAIL;

	return(pPmView->GetBBDiagonal());
}


STDMETHODIMP CPartDocumentAuto::ImportFromCATIA(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ImportFromCATIA(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ExportToCATIA(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ExportToCATIA(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ImportFromUG(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ImportFromNX(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ExportToUG(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ExportToNX(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ImportFromXML(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ImportFromXML(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ExportToXML(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ExportToXML(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ImportFromBrep(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ImportFromETC(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ExportToBrep(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);
	m_pDocument->ExportToETC(filePath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ExportToMesh(BSTR path)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString filePath(path);

	if (filePath.Find(_T(".pdf")) == -1)
		m_pDocument->ExportToMesh(filePath);
	else
	{
		filePath.Replace(_T(".pdf"),_T(".obj"));
		
		m_pDocument->ExportTo3DPDF(filePath);
	}

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::ConvertMesh(BSTR source, BSTR target)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString sourcePath(source);
	CString targetPath(target);

	m_pDocument->ConvertMeshToMesh(sourcePath, targetPath);

	return S_OK;
}

STDMETHODIMP CPartDocumentAuto::RunScriptInterface(BSTR command)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString _command(command);
	m_pDocument->RunScriptInterface(_command);

	return S_OK;
}