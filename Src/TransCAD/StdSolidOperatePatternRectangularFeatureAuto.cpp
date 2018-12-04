// StdSolidOperatePatternRectangularFeatureAuto.cpp : CStdSolidOperatePatternRectangularFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidOperatePatternRectangularFeatureAuto.h"


// CStdSolidOperatePatternRectangularFeatureAuto

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_TargetFeatures(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hReferences;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetTargetFeatures(m_hFeature, hReferences);

	return CPartAuto::GetIReferencesFromHReferences(hReferences, ppVal);
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_ColumnSpacing(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double columnSpacing;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnSpacing(m_hFeature, columnSpacing);

	*pVal = columnSpacing;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_ColumnDirection(double* x, double* y, double* z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection columnDirection;

	PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnDirection(m_hFeature, columnDirection);

	*x = columnDirection.X();
	*y = columnDirection.Y();
	*z = columnDirection.Z();

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_ColumnNumber(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int columnNumber;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnNumber(m_hFeature, columnNumber);

	*pVal = columnNumber;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_RowSpacing(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double rowSpacing;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowSpacing(m_hFeature, rowSpacing);

	*pVal = rowSpacing;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_RowDirection(double* x, double* y, double* z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection rowDirection;

	PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowDirection(m_hFeature, rowDirection);

	*x = rowDirection.X();
	*y = rowDirection.Y();
	*z = rowDirection.Z();

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::get_RowNumber(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int rowNumber;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowNumber(m_hFeature, rowNumber);

	*pVal = rowNumber;

	return S_OK;
}


STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::put_TargetFeatures(IReferences* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hReferences = 0;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hReferences);
	PmeStdSolidOperatePatternRectangularFeatureAPI::SetTargetFeatures(m_hFeature, hReferences);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::put_ColumnSpacing(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double columnSpacing = pVal;
	PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnSpacing(m_hFeature, columnSpacing);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::PutColumnDirection(double x, double y, double z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection columnDirection(x, y, z);

	PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnDirection(m_hFeature, columnDirection);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::put_ColumnNumber(int pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int columnNumber = pVal;
	PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnNumber(m_hFeature, columnNumber);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::put_RowSpacing(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double rowSpacing = pVal;
	PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowSpacing(m_hFeature, rowSpacing);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::put_RowNumber(int pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int rowNumber = pVal;
	PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowNumber(m_hFeature, rowNumber);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternRectangularFeatureAuto::PutRowDirection(double x, double y, double z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection rowDirection(x, y, z);

	PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowDirection(m_hFeature, rowDirection);

	return S_OK;
}