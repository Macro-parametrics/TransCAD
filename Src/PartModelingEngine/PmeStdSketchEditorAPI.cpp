#include "stdafx.h"
#include <cmath>
#include ".\PmeStdSketchEditorAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmePart.h"
#include ".\PmePartAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeUtility.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeSketch.h"
#include ".\PmeStdSketchOrigin.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeStdSketchVDirection.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\PmeStdSketchCoincident.h"
#include ".\PmeStdSketchPerpendicular.h"
#include ".\PmeStdSketchParallel.h"
#include ".\PmeStdSketchHorizontal.h"
#include ".\PmeStdSketchVertical.h"
#include ".\PmeStdSketchControlPoint.h"

#define DISTANCE_TOLERANCE 1.0e-12
#define ANGLE_TOLERANCE 1.0e-8

IPmeConstraintable * GetIPmeConstraintable(PmeHandle hHandle);

void PmeStdSketchEditorAPI::Close(PmeHStdSketchEditor & hEditor)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchFeature * pSketchFeature = pEditor->GetSketchFeature();
	pEditor->CloseSketch();

	PmePart * pPart = pSketchFeature->GetPart();
	PmeHPart hPart = PME_PART2HANDLE(pPart);
	
	// 수정되는 경우를 고려하지 않았으므로 닫히는 스케치는 가장 마지막 피쳐이다.
	pPart->UpdateLast();
	
	hEditor = 0;

	PmeHFeature hFeature = PME_FEATURE2HANDLE(pSketchFeature);
	PME_UPDATE_FEATURE(hPart, hFeature, PmeUpdateState_Add);

	PmeHExplicitModelObject hSketch = PME_EXPLICITMODELOBJECT2HANDLE(pSketchFeature->GetSketch());
	PME_UPDATE_EXPLICITMODELOBJECT(hPart, hSketch, PmeUpdateState_Add);
}

void PmeStdSketchEditorAPI::CreateLine(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hLine)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(std::abs(startX - endX) < DISTANCE_TOLERANCE &&
											  std::abs(startY - endY) < DISTANCE_TOLERANCE);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchLine * pLine = pEditor->CreateLine(startX, startY, endX, endY);

	if(!name.IsEmpty())
		pLine->SetName(name);

	hLine = PME_STDSKETCHGEOMETRY2HANDLE(pLine);
}

void PmeStdSketchEditorAPI::CreateCenterline(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hCenterline)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(std::abs(startX - endX) < DISTANCE_TOLERANCE &&
											  std::abs(startY - endY) < DISTANCE_TOLERANCE);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCenterline * pCenterline = pEditor->CreateCenterline(startX, startY, endX, endY);

	if(!name.IsEmpty())
		pCenterline->SetName(name);

	hCenterline = PME_STDSKETCHGEOMETRY2HANDLE(pCenterline);
}

void PmeStdSketchEditorAPI::CreateCircle(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double radius, PmeHStdSketchGeometry & hCircle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(radius <= 0.0);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCircle * pCircle = pEditor->CreateCircle(centerX, centerY, radius);

	if(!name.IsEmpty())
		pCircle->SetName(name);

	hCircle = PME_STDSKETCHGEOMETRY2HANDLE(pCircle);
}

void PmeStdSketchEditorAPI::CreateCircularArc(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double radius, double startAngle, double endAngle, PmeHStdSketchGeometry & hArc)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(radius <= 0.0);
	PmeThrowExceptionIf<PmeArgumentException>(abs(startAngle - endAngle) <= ANGLE_TOLERANCE);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCircularArc * pArc = pEditor->CreateCircularArc(centerX, centerY, radius, startAngle, endAngle);

	if(!name.IsEmpty())
		pArc->SetName(name);

	hArc = PME_STDSKETCHGEOMETRY2HANDLE(pArc);
}

void PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hArc)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(abs(centerX - startX) <= DISTANCE_TOLERANCE && abs(centerY - startY) <= DISTANCE_TOLERANCE);
	PmeThrowExceptionIf<PmeArgumentException>(abs(startX - endX) <= DISTANCE_TOLERANCE && abs(startY - endY) <= DISTANCE_TOLERANCE);
	PmeThrowExceptionIf<PmeArgumentException>(abs(endX - centerX) <= DISTANCE_TOLERANCE && abs(endY - centerY) <= DISTANCE_TOLERANCE);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCircularArc * pArc = pEditor->CreateCircularArcFromCenterStartEnd(centerX, centerY, startX, startY, endX, endY);

	if(!name.IsEmpty())
		pArc->SetName(name);

	hArc = PME_STDSKETCHGEOMETRY2HANDLE(pArc);
}

void PmeStdSketchEditorAPI::CreateCircularArcFrom3Points(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double intermediateX, double intermediateY, double endX, double endY, PmeHStdSketchGeometry & hArc)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentException>(abs(intermediateX - startX) <= DISTANCE_TOLERANCE && abs(intermediateY - startY) <= DISTANCE_TOLERANCE);
	PmeThrowExceptionIf<PmeArgumentException>(abs(startX - endX) <= DISTANCE_TOLERANCE && abs(startY - endY) <= DISTANCE_TOLERANCE);
	PmeThrowExceptionIf<PmeArgumentException>(abs(endX - intermediateX) <= DISTANCE_TOLERANCE && abs(endY - intermediateY) <= DISTANCE_TOLERANCE);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCircularArc * pArc = pEditor->CreateCircularArcFrom3Points(startX, startY, intermediateX, intermediateY, endX, endY);

	if(!name.IsEmpty())
		pArc->SetName(name);

	hArc = PME_STDSKETCHGEOMETRY2HANDLE(pArc);
}

void PmeStdSketchEditorAPI::GetPoints(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hStartPoint, PmeHStdSketchGeometry & hEndPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hLine);

	PmeStdSketchLine* pLine = (PmeStdSketchLine*)PME_HANDLE2STDSKETCHGEOMETRY(hLine);
	PmeStdSketchControlPoint* pStartPoint = pLine->GetStartPoint();
	PmeStdSketchControlPoint* pEndPoint = pLine->GetEndPoint();

	hStartPoint = PME_STDSKETCHGEOMETRY2HANDLE(pStartPoint);
	hEndPoint = PME_STDSKETCHGEOMETRY2HANDLE(pEndPoint);

	hLine = PME_STDSKETCHGEOMETRY2HANDLE(pLine);
}

void PmeStdSketchEditorAPI::CreateCoincident(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hFirstGeometry, PmeSamePointsType firstType, PmeHReference hSecondGeometry, PmeSamePointsType secondType, PmeHStdSketchConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFirstGeometry);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSecondGeometry);

// 	IPmeConstraintable * pFirstGeometry = GetIPmeConstraintable(hFirstGeometry);
// 	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFirstGeometry);
// 
// 	IPmeConstraintable * pSecondGeometry = GetIPmeConstraintable(hSecondGeometry);
// 	PmeThrowExceptionIf<PmeArgumentTypeException>(!pSecondGeometry);
// 	
// 	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
// 	PmeStdSketchCoincident * pCoincident = pEditor->CreateCoincident(pFirstGeometry, pSecondGeometry);

	PmeReference * pFirstGeometry = PME_HANDLE2REFERENCE(hFirstGeometry);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFirstGeometry);

	PmeReference * pSecondGeometry = PME_HANDLE2REFERENCE(hSecondGeometry);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pSecondGeometry);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchCoincident * pCoincident = pEditor->CreateCoincident(pFirstGeometry, firstType, pSecondGeometry, secondType);

	if(!name.IsEmpty())
		pCoincident->SetName(name);

	hConstraint = PME_STDSKETCHCONSTRAINT2HANDLE(pCoincident);
}

void PmeStdSketchEditorAPI::CreatePerpendicular(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hReferenceEdit, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferenceEdit);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hTarget);

	PmeReference * pReferenceEdit = PME_HANDLE2REFERENCE(hReferenceEdit);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pReferenceEdit);

	PmeReference * pTarget = PME_HANDLE2REFERENCE(hTarget);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pTarget);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchPerpendicular * pPerpendicular = pEditor->CreatePerpendicular(pReferenceEdit, pTarget);

	if(!name.IsEmpty())
		pPerpendicular->SetName(name);

	hConstraint = PME_STDSKETCHCONSTRAINT2HANDLE(pPerpendicular);
}

void PmeStdSketchEditorAPI::CreateParallel(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hReferenceEdit, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferenceEdit);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hTarget);

	PmeReference * pReferenceEdit = PME_HANDLE2REFERENCE(hReferenceEdit);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pReferenceEdit);

	PmeReference * pTarget = PME_HANDLE2REFERENCE(hTarget);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pTarget);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchParallel * pParallel = pEditor->CreateParallel(pReferenceEdit, pTarget);

	if(!name.IsEmpty())
		pParallel->SetName(name);

	hConstraint = PME_STDSKETCHCONSTRAINT2HANDLE(pParallel);
}

void PmeStdSketchEditorAPI::CreateHorizontal(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hTarget);

	PmeReference * pTarget = PME_HANDLE2REFERENCE(hTarget);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pTarget);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchHorizontal * pHorizontal = pEditor->CreateHorizontal(pTarget);

	if(!name.IsEmpty())
		pHorizontal->SetName(name);

	hConstraint = PME_STDSKETCHCONSTRAINT2HANDLE(pHorizontal);
}

void PmeStdSketchEditorAPI::CreateVertical(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hTarget);

	PmeReference * pTarget = PME_HANDLE2REFERENCE(hTarget);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pTarget);

	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);
	PmeStdSketchVertical * pVertical = pEditor->CreateVertical(pTarget);

	if(!name.IsEmpty())
		pVertical->SetName(name);

	hConstraint = PME_STDSKETCHCONSTRAINT2HANDLE(pVertical);
}

IPmeConstraintable * GetIPmeConstraintable(PmeHandle hHandle)
{
	PmeObject * pObject = static_cast<PmeObject *>(hHandle);

	if(pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchGeometry)))
	{
		PmeStdSketchGeometry * pGeometry = static_cast<PmeStdSketchGeometry *>(pObject);
		return pGeometry;
	}
	else if(pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchOrigin)))
	{
		PmeStdSketchOrigin * pOrigin = static_cast<PmeStdSketchOrigin *>(pObject);
		return pOrigin;
	}
	else if(pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchHDirection)))
	{
		PmeStdSketchHDirection * pHDir = static_cast<PmeStdSketchHDirection *>(pObject);
		return pHDir;
	}
	else if(pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchVDirection)))
	{
		PmeStdSketchVDirection * pVDir = static_cast<PmeStdSketchVDirection *>(pObject);
		return pVDir;
	}

	return 0;
}

void PmeStdSketchEditorAPI::DeleteItemByName(PmeHStdSketchEditor hEditor, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEditor);
	PmeStdSketchEditor * pEditor = PME_HANDLE2STDSKETCHEDITOR(hEditor);

	pEditor->DeleteItemByName(name);
}