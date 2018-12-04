#include "stdafx.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeDcmInterface.h"
#include ".\PmeDcmFrustum.h"
#include ".\PmeStdSketchOrigin.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeStdSketchVDirection.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchConstraints.h"
#include ".\PmeStdSketchCoincident.h"
#include ".\PmeStdSketchPerpendicular.h"
#include ".\PmeStdSketchParallel.h"
#include ".\PmeStdSketchHorizontal.h"
#include ".\PmeStdSketchVertical.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"

#define DISTANCE_TOLERANCE 1.0e-12
#define ANGLE_TOLERANCE 1.0e-8

PmeStdSketchEditor::PmeStdSketchEditor(PmeStdSketchFeature * pSketchFeature, bool activateDcm)
: m_pSketchFeature(pSketchFeature)
{
	if(activateDcm)
	{
        // m_pDcm = new dimension_system();
		// 2009-03-11, Suchul Shin, Set the tolerances into the DCM
		m_pDcm = new dimension_system(DISTANCE_TOLERANCE, DISTANCE_TOLERANCE/ANGLE_TOLERANCE);
        PmeDcmRegisterFrustum(m_pDcm);

		pSketchFeature->GetOrigin()->UpdateDcmInfo(this);
		pSketchFeature->GetHDirection()->UpdateDcmInfo(this);
		pSketchFeature->GetVDirection()->UpdateDcmInfo(this);
	}
	else
		m_pDcm = 0;
}

PmeStdSketchEditor::~PmeStdSketchEditor(void)
{
	if(IsDcmActivated())
	{
		PmeStdSketchFeature * pSketchFeature = GetSketchFeature();
		
		PmeStdSketchConstraints * pConstraints = pSketchFeature->GetConstraints();

		for(PmeStdSketchConstraints::SizeType i = 0; i < pConstraints->GetSize(); ++ i)
		{
			PmeStdSketchConstraint * pConstraint = pConstraints->GetItem(i);
			pConstraint->CleanDcmInfo(this);
		}

		PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();

		for(PmeStdSketchGeometries::SizeType i = 0; i < pGeometries->GetSize(); ++ i)
		{
			PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(i);
			IPmeConstraintable * pConstraintable = static_cast<IPmeConstraintable *>(pGeometry);
			pConstraintable->CleanDcmInfo(this);
		}

		pSketchFeature->GetVDirection()->CleanDcmInfo(this);
		pSketchFeature->GetHDirection()->CleanDcmInfo(this);
		pSketchFeature->GetOrigin()->CleanDcmInfo(this);	
		
		delete m_pDcm;
	}
}

PmeStdSketchEditor * PmeStdSketchEditor::OpenSketch(PmeStdSketchFeature * pSketchFeature, bool activateDcm)
{
	return new PmeStdSketchEditor(pSketchFeature, activateDcm);
}

void PmeStdSketchEditor::CloseSketch(void)
{
	if(IsDcmActivated())
	{
        GetDcm()->re_evaluate();
	}

	PmeStdSketchFeature * pSketchFeature = GetSketchFeature();
	pSketchFeature->GetPart()->GetFeatures()->MustUpdate(pSketchFeature);
	delete this;
}

PmeStdSketchLine * PmeStdSketchEditor::CreateLine(double startX, double startY, double endX, double endY)
{
	PmeStdSketchControlPoint * pStartPoint = new PmeStdSketchControlPoint(GetSketchFeature(), startX, startY);	
	PmeStdSketchControlPoint * pEndPoint = new PmeStdSketchControlPoint(GetSketchFeature(), endX, endY);	
	PmeStdSketchLine * pLine = new PmeStdSketchLine(GetSketchFeature(), pStartPoint, pEndPoint);
	
	PmeStdSketchGeometries * pGeometries = GetSketchFeature()->GetGeometries();

	pStartPoint->GiveDefaultName();
	pGeometries->Add(pStartPoint);
	pEndPoint->GiveDefaultName();
	pGeometries->Add(pEndPoint);
	pLine->GiveDefaultName();
	pGeometries->Add(pLine);

	if(IsDcmActivated())
	{
		pStartPoint->UpdateDcmInfo(this);
		pEndPoint->UpdateDcmInfo(this);
		pLine->UpdateDcmInfo(this);
		
		GetDcm()->evaluate();
	}	

	return pLine;
}

PmeStdSketchCenterline * PmeStdSketchEditor::CreateCenterline(double startX, double startY, double endX, double endY)
{
	PmeStdSketchControlPoint * pStartPoint = new PmeStdSketchControlPoint(GetSketchFeature(), startX, startY);	
	PmeStdSketchControlPoint * pEndPoint = new PmeStdSketchControlPoint(GetSketchFeature(), endX, endY);	
	PmeStdSketchCenterline * pCenterline = new PmeStdSketchCenterline(GetSketchFeature(), pStartPoint, pEndPoint);
	
	PmeStdSketchGeometries * pGeometries = GetSketchFeature()->GetGeometries();

	pStartPoint->GiveDefaultName();
	pGeometries->Add(pStartPoint);
	pEndPoint->GiveDefaultName();
	pGeometries->Add(pEndPoint);
	pCenterline->GiveDefaultName();
	pGeometries->Add(pCenterline);

	if(IsDcmActivated())
	{
		pStartPoint->UpdateDcmInfo(this);
		pEndPoint->UpdateDcmInfo(this);
		pCenterline->UpdateDcmInfo(this);
		
		GetDcm()->evaluate();
	}	

	return pCenterline;
}

PmeStdSketchCircle * PmeStdSketchEditor::CreateCircle(double centerX, double centerY, double radius)
{
	PmeStdSketchControlPoint * pCenterPoint = new PmeStdSketchControlPoint(GetSketchFeature(), centerX, centerY);	
	PmeStdSketchCircle * pCircle = new PmeStdSketchCircle(GetSketchFeature(), pCenterPoint, radius);

	PmeStdSketchGeometries * pGeometries = GetSketchFeature()->GetGeometries();

	pCenterPoint->GiveDefaultName();
	pGeometries->Add(pCenterPoint);
	pCircle->GiveDefaultName();
	pGeometries->Add(pCircle);

	if(IsDcmActivated())
	{
		pCenterPoint->UpdateDcmInfo(this);
		pCircle->UpdateDcmInfo(this);

        GetDcm()->evaluate();
	}

	return pCircle;
}

PmeStdSketchCircularArc * PmeStdSketchEditor::CreateCircularArc(double centerX, double centerY, double radius, double startAngle, double endAngle)
{
	startAngle = 2 * M_PI / 360.0 * startAngle;
	endAngle = 2 * M_PI / 360.0 * endAngle;

	bounded_arc arc(SPAposition(centerX, centerY, 0.0), SPAunit_vector(0.0, 0.0, 1.0), SPAvector(radius, 0.0, 0.0), startAngle, endAngle, 1.0);

	return CreateInternalCircularArc(arc);
}

PmeStdSketchCircularArc * PmeStdSketchEditor::CreateCircularArcFromCenterStartEnd(double centerX, double centerY, double startX, double startY, double endX, double endY)
{
	bounded_arc arc(SPAposition(centerX, centerY, 0.0), SPAposition(startX, startY, 0.0), SPAposition(endX, endY, 0.0), SPAunit_vector(0.0, 0.0, 1.0));

	return CreateInternalCircularArc(arc);
}

PmeStdSketchCircularArc * PmeStdSketchEditor::CreateCircularArcFrom3Points(double startX, double startY, double intermediateX, double intermediateY, double endX, double endY)
{
	bounded_arc arc(SPAposition(startX, startY, 0.0), SPAposition(intermediateX, intermediateY, 0.0), SPAposition(endX, endY, 0.0), FALSE);

	return CreateInternalCircularArc(arc);
}

PmeStdSketchCircularArc * PmeStdSketchEditor::CreateInternalCircularArc(const bounded_arc & arc)
{
	PmeStdSketchControlPoint * pStartPoint = new PmeStdSketchControlPoint(GetSketchFeature(), arc.get_start_pt().x(), arc.get_start_pt().y());
	PmeStdSketchControlPoint * pEndPoint = new PmeStdSketchControlPoint(GetSketchFeature(), arc.get_end_pt().x(), arc.get_end_pt().y());
	PmeStdSketchControlPoint * pCenterPoint = new PmeStdSketchControlPoint(GetSketchFeature(), arc.get_center().x(), arc.get_center().y());

	PmeStdSketchCircularArc * pArc = new PmeStdSketchCircularArc(GetSketchFeature(), pCenterPoint, arc.get_radius(), pStartPoint, pEndPoint);

	PmeStdSketchGeometries * pGeometries = GetSketchFeature()->GetGeometries();

	pCenterPoint->GiveDefaultName();
	pGeometries->Add(pCenterPoint);
	pStartPoint->GiveDefaultName();
	pGeometries->Add(pStartPoint);
	pEndPoint->GiveDefaultName();
	pGeometries->Add(pEndPoint);
	pArc->GiveDefaultName();
	pGeometries->Add(pArc);

	if(IsDcmActivated())
	{
		pCenterPoint->UpdateDcmInfo(this);
		pStartPoint->UpdateDcmInfo(this);
		pEndPoint->UpdateDcmInfo(this);
		pArc->UpdateDcmInfo(this);
        
		GetDcm()->evaluate();
	}

	return pArc;
}
/*
PmeStdSketchCoincident * PmeStdSketchEditor::CreateCoincident(IPmeConstraintable * pFirstGeometry, IPmeConstraintable * pSecondGeometry)
{
	PmeStdSketchCoincident * pCoincident = new PmeStdSketchCoincident(GetSketchFeature(), pFirstGeometry, pSecondGeometry);

	pCoincident->GiveDefaultName();

	if(IsDcmActivated())
	{
		pCoincident->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pCoincident);

	if(IsDcmActivated())
	{
        GetDcm()->evaluate();
	}

	return pCoincident;
}
*/

PmeStdSketchCoincident * PmeStdSketchEditor::CreateCoincident(PmeReference * pFirstGeometry, PmeSamePointsType firstType, PmeReference * pSecondGeometry, PmeSamePointsType secondType)
{
	PmeStdSketchCoincident * pCoincident = new PmeStdSketchCoincident(GetSketchFeature(), pFirstGeometry, firstType, pSecondGeometry, secondType);

	pCoincident->GiveDefaultName();

	if(IsDcmActivated())
	{
		pCoincident->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pCoincident);

	if(IsDcmActivated())
	{
		GetDcm()->evaluate();
	}

	return pCoincident;
}

PmeStdSketchPerpendicular * PmeStdSketchEditor::CreatePerpendicular(PmeReference * pReferenceEdit, PmeReference * pTarget)
{
	PmeStdSketchPerpendicular * pPerpendicular = new PmeStdSketchPerpendicular(GetSketchFeature(), pReferenceEdit, pTarget);

	pPerpendicular->GiveDefaultName();

	if(IsDcmActivated())
	{
		pPerpendicular->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pPerpendicular);

	if(IsDcmActivated())
	{
		GetDcm()->evaluate();
	}

	return pPerpendicular;
}

PmeStdSketchParallel * PmeStdSketchEditor::CreateParallel(PmeReference * pReferenceEdit, PmeReference * pTarget)
{
	PmeStdSketchParallel * pParallel = new PmeStdSketchParallel(GetSketchFeature(), pReferenceEdit, pTarget);

	pParallel->GiveDefaultName();

	if(IsDcmActivated())
	{
		pParallel->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pParallel);

	if(IsDcmActivated())
	{
		GetDcm()->evaluate();
	}

	return pParallel;
}

PmeStdSketchHorizontal * PmeStdSketchEditor::CreateHorizontal(PmeReference * pTarget)
{
	PmeStdSketchHorizontal * pHorizontal = new PmeStdSketchHorizontal(GetSketchFeature(), pTarget);

	pHorizontal->GiveDefaultName();

	if(IsDcmActivated())
	{
		pHorizontal->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pHorizontal);

	if(IsDcmActivated())
	{
		GetDcm()->evaluate();
	}

	return pHorizontal;
}

PmeStdSketchVertical * PmeStdSketchEditor::CreateVertical(PmeReference * pTarget)
{
	PmeStdSketchVertical * pVertical = new PmeStdSketchVertical(GetSketchFeature(), pTarget);

	pVertical->GiveDefaultName();

	if(IsDcmActivated())
	{
		pVertical->UpdateDcmInfo(this);
	}

	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();

	pConstraints->Add(pVertical);

	if(IsDcmActivated())
	{
		GetDcm()->evaluate();
	}

	return pVertical;
}


void PmeStdSketchEditor::DeleteItemByName(CString name)
{
	for (int i = 1; i <= (int)GetSketchFeature()->GetGeometries()->GetSize(); ++i)
	{
		if (name == GetSketchFeature()->GetGeometries()->GetItem(i)->GetName())
			GetSketchFeature()->GetGeometries()->Delete(i);
	}
}