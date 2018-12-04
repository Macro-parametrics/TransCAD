#include "stdafx.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeReference.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeDatumPlane.h"

MrAxis2 PmeDatumPlaneUtility::GetCoordinateSystem(PmeReference * pReference)
{
	PmeExplicitModelObject * pObject = pReference->GetPart()->GetSelectionManager()->GetObjectFromReference(pReference);
	PmeThrowExceptionIf<PmeIlligalOperationException>(!pObject || (pObject->GetType() != PmeExplicitModelObjectType_DatumPlane && pObject->GetType() != PmeExplicitModelObjectType_OffsetDatumPlane) );

	PmeDatumPlane * pDatumPlane = static_cast<PmeDatumPlane *>(pObject);
			
	return pDatumPlane->GetLocation();
}