#include "StdAfx.h"
#include ".\pmestdsolidspherefeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidSphereFeature, PmeStdSolidFeature)

PmeStdSolidSphereFeature::PmeStdSolidSphereFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
, m_location(MrPosition::O())
, m_radius(100.0)
{
}

PmeStdSolidSphereFeature::PmeStdSolidSphereFeature(PmePart * pPart, const MrPosition & location, double radius)
: PmeStdSolidFeature(pPart)
, m_location(location)
, m_radius(radius)
{
}

PmeStdSolidSphereFeature::~PmeStdSolidSphereFeature(void)
{
}

void PmeStdSolidSphereFeature::Update(void)
{
	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();

	MrPosition pos = GetLocation();
	BODY * pOldBody = pSolid->GetSolid();
	BODY * pAddedBody = 0;
	
	API_BEGIN
		
        result = api_solid_sphere(SPAposition(pos.X(), pos.Y(), pos.Z()), GetRadius(), pAddedBody);

		check_outcome(result);
	
		if(pOldBody)
		{
			result = api_boolean(pAddedBody, pOldBody, UNION);
			check_outcome(result);
		}
		else
			pOldBody = pAddedBody;

		if(result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			pSolid->UpdateSolid(pOldBody);
			SetSolid(pSolid);
		}
	API_END	
}