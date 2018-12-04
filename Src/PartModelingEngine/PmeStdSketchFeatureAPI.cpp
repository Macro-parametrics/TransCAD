#include "stdafx.h"
#include ".\PmeStdSketchFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmePartAPI.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeFeatures.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeSketch.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeUtility.h"

void PmeStdSketchFeatureAPI::Create(PmeHPart hPart, const CString & name, PmeHReference hSketchPlane, PmeHFeature & hFeature)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart || !hSketchPlane);

	PmePart * pPart = PME_HANDLE2PART(hPart);
	PmeFeatures * pFeatures = pPart->GetFeatures();
	PmeReference * pSketchPlaneReference = PME_HANDLE2REFERENCE(hSketchPlane);
	
	PmeStdSketchFeature * pFeature = new PmeStdSketchFeature(pPart, pSketchPlaneReference);
	if(name.IsEmpty())
		pFeature->GiveDefaultName();
	else
        pFeature->SetName(name);

	pFeatures->Add(pFeature);
	hFeature = PME_FEATURE2HANDLE(pFeature);
}

void PmeStdSketchFeatureAPI::GetSketchPlane(PmeHFeature hFeature, PmeHReference & hSketchPlane)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeReference * pSketchPlane = pSketchFeature->GetSketchPlane();

	hSketchPlane = PME_REFERENCE2HANDLE(pSketchPlane);
}

void PmeStdSketchFeatureAPI::OpenEditor(PmeHFeature hFeature, PmeHStdSketchEditor & hEditor)
{
	PmeStdSketchFeatureAPI::OpenEditor(hFeature, true, hEditor);	
}

void PmeStdSketchFeatureAPI::OpenEditor(PmeHFeature hFeature, bool activateDcm, PmeHStdSketchEditor & hEditor)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchEditor *pSketchEditor = PmeStdSketchEditor::OpenSketch(pSketchFeature, activateDcm);

	hEditor = PME_STDSKETCHEDITOR2HANDLE(pSketchEditor);
}

void PmeStdSketchFeatureAPI::SetCoordinateSystem(PmeHFeature hFeature, MrAxis2 coordinateSystem)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	pSketchFeature->SetCoordinateSystem(coordinateSystem);
}

void PmeStdSketchFeatureAPI::GetCoordinateSystem(PmeHFeature hFeature, MrAxis2 & coordinateSystem)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	coordinateSystem = pSketchFeature->GetCoordinateSystem();
}

void PmeStdSketchFeatureAPI::GetGeometries(PmeHFeature hFeature, PmeHStdSketchGeometries & hGeometries)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();

	hGeometries = PME_STDSKETCHGEOMETRIES2HANDLE(pGeometries);
}

void PmeStdSketchFeatureAPI::GetConstraints(PmeHFeature hFeature, PmeHStdSketchConstraints & hConstraints)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchConstraints * pConstraints = pSketchFeature->GetConstraints();

	hConstraints = PME_STDSKETCHCONSTRAINTS2HANDLE(pConstraints);
}

void PmeStdSketchFeatureAPI::GetOrigin(PmeHFeature hFeature, PmeHStdSketchOrigin & hOrigin)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchOrigin * pOrigin = pSketchFeature->GetOrigin();

	hOrigin = PME_STDSKETCHORIGIN2HANDLE(pOrigin);
}

void PmeStdSketchFeatureAPI::GetHDirection(PmeHFeature hFeature, PmeHStdSketchHDirection & hHDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchHDirection * pHDirection = pSketchFeature->GetHDirection();

	hHDirection = PME_STDSKETCHHDIRECTION2HANDLE(pHDirection);
}

void PmeStdSketchFeatureAPI::GetVDirection(PmeHFeature hFeature, PmeHStdSketchVDirection & hVDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchVDirection * pVDirection = pSketchFeature->GetVDirection();

	hVDirection = PME_STDSKETCHVDIRECTION2HANDLE(pVDirection);
}

void PmeStdSketchFeatureAPI::IsInversed(PmeHFeature hFeature, bool & isInversed)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	isInversed = pSketchFeature->IsInversed();
}

void PmeStdSketchFeatureAPI::HasCenterLine(PmeHFeature hFeature, bool & hasCenterLine)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	hasCenterLine = pSketchFeature->HasCenterLine();
}



void PmeStdSketchFeatureAPI::DeleteByName(PmeHFeature hFeature, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);

	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	pSketchFeature->DeleteItemByName(name);
}