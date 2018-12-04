#include "StdAfx.h"
#include ".\pmestddefaultdatumplanefeature.h"
#include ".\PmeDatumPlane.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdDefaultDatumPlaneFeature, PmeStdDatumPlaneFeature)

PmeStdDefaultDatumPlaneFeature::PmeStdDefaultDatumPlaneFeature(PmePart * pPart, PmeStdDefaultDatumPlaneFeatureType type)
: PmeStdDatumPlaneFeature(pPart)
, m_type(type)
{
	CString name;

	switch(type)
	{
	case PmeStdDefaultDatumPlaneFeatureType_XYPlane:
		name = _T("XYPlane");
		break;
	case PmeStdDefaultDatumPlaneFeatureType_YZPlane:
		name = _T("YZPlane");
		break;
	case PmeStdDefaultDatumPlaneFeatureType_ZXPlane:
		name = _T("ZXPlane");
		break;
	}

	SetName(name);
}

PmeStdDefaultDatumPlaneFeature::~PmeStdDefaultDatumPlaneFeature(void)
{
}

void PmeStdDefaultDatumPlaneFeature::Update(void)
{	
	MrAxis2 location;

	switch(GetType())
	{
	case PmeStdDefaultDatumPlaneFeatureType_XYPlane:
		location = MrAxis2::OXY();
		break;
	case PmeStdDefaultDatumPlaneFeatureType_YZPlane:
		location = MrAxis2::OYZ();
		break;
	case PmeStdDefaultDatumPlaneFeatureType_ZXPlane:
		location = MrAxis2::OZX();
		break;
	}

	PmeDatumPlane * pPlane = new PmeDatumPlane(location);
	pPlane->SetName(GetName());
	pPlane->SetCreator(this);
	GetPart()->GetExplicitModel()->Add(pPlane);
}