#include "StdAfx.h"
#include <limits>
#include ".\pmeselectionmanager.h"
#include ".\PmeReference.h"
#include ".\PmeReferences.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModelObjectReference.h"
#include ".\PmeFeatureReference.h"
#include ".\PmeSketchGeometryReference.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeSketch.h"
#include ".\PmePersistentName.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeSolid.h"
#include ".\PmeBrepReference.h"
#include ".\PmeQuery.h"
#include ".\PmeFeatures.h"
#include ".\PmeFeature.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchFeature.h"

#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSolidProtrusionExtrudeFeature.h"
#include ".\pmestdsketchcontrolpoint.h"
#include ".\PmeHandleMacro.h"

//#include "wcs.hxx" //Ikjunetest 

#undef max

PmeSelectionManager::PmeSelectionManager(PmePart * pPart)
: m_pPart(pPart)
{
	m_pReferences = new PmeReferences();
}

PmeSelectionManager::~PmeSelectionManager(void)
{
	ClearReferences();

	ASSERT(m_pReferences);
	delete m_pReferences;
}

void PmeSelectionManager::ClearReferences(void)
{
	PmeReferences::SizeType size = m_pReferences->GetSize();

	for(PmeReferences::SizeType i = 0; i < size; ++ i)
	{
		PmeReference * pReference = m_pReferences->GetItem(i);
		if(pReference)
			delete pReference;
	}
}

PmeReference * PmeSelectionManager::SelectFeatureByName(const CString & name)
{
	PmeFeatures * pFeatures = GetPart()->GetFeatures();
	PmeFeature * pFeature = pFeatures->FindByName(name);

	if(!pFeature)
		return 0;

	PmeReference * pReference = new PmeFeatureReference(GetPart(), pFeature);
	GetReferences()->Add(pReference);

	return pReference;
}

// 2009.10.29, Suchul Shin
PmeReference * PmeSelectionManager::SelectSketchGeometryByName(const CString & name)
{
	PmeFeatures * pFeatures = GetPart()->GetFeatures();
	//	PmeFeature * pFeature = pFeatures->FindByName(name);

	CString sketchName, geometryName;
	PmePersistentName::GetArgumentNames(name, &sketchName, &geometryName);

	PmeStdSketchGeometry * pGeometry = 0;

	PmeFeature * pFeature = pFeatures->FindByName(sketchName);

	PmeThrowExceptionIf<PmeArgumentNullException>(!pFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature* pSketch = static_cast<PmeStdSketchFeature*>(pFeature);
	PmeStdSketchGeometries * pGeometries = pSketch->GetGeometries();

	pGeometry = pGeometries->FindByName(geometryName);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometry);

	PmeReference * pReference = new PmeSketchGeometryReference(GetPart(), pGeometry);
	GetReferences()->Add(pReference);

	return pReference;

	if(!pGeometry)
		return 0;
}

PmeReference * PmeSelectionManager::SelectObjectByName(const CString & name)
{
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	PmeExplicitModelObject * pObject = pExplicitModel->FindByName(name);
	
	if(!pObject)
		return 0;

	PmeReference * pReference = new PmeExplicitModelObjectReference(GetPart(), pObject);
	GetReferences()->Add(pReference);

	return pReference;
}

PmeFeature * PmeSelectionManager::GetFeatureFromReference(PmeReference * pReference)
{
	PmeThrowExceptionIf<PmeArgumentTypeException>(pReference->GetReferenceType() != PmeReferenceType_Feature);
	PmeFeatures * pFeatures = GetPart()->GetFeatures();
	PmeFeature * pFeature = pFeatures->FindByName(pReference->GetReferenceeName());

	return pFeature;
}

PmeExplicitModelObject * PmeSelectionManager::GetObjectFromReference(PmeReference * pReference)
{
	PmeThrowExceptionIf<PmeArgumentTypeException>(pReference->GetReferenceType() != PmeReferenceType_ExplicitModelObject);
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	PmeExplicitModelObject * pObject = pExplicitModel->FindByName(pReference->GetReferenceeName());

	return pObject;
}

// 2009.10.29, Suchul Shin
PmeStdSketchGeometry * PmeSelectionManager::GetSketchGeometryFromReference(PmeReference * pReference)
{
	PmeFeatures * pFeatures = GetPart()->GetFeatures();

	CString sketchName, geometryName;
	PmePersistentName::GetArgumentNames(pReference->GetReferenceeName(), &sketchName, &geometryName);

	PmeStdSketchGeometry * pGeometry = 0;

	PmeFeature * pFeature = pFeatures->FindByName(sketchName);

	PmeThrowExceptionIf<PmeArgumentNullException>(!pFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature* pSketch = static_cast<PmeStdSketchFeature*>(pFeature);
	PmeStdSketchGeometries * pGeometries = pSketch->GetGeometries();

	pGeometry = pGeometries->FindByName(geometryName);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometry);

	return pGeometry;
}

PmeReference * PmeSelectionManager::SelectBrepByName(const CString & persistentName)
{
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	PmeSolid * pSolid = pExplicitModel->GetSolid();

	ENTITY * pEntity = PmePersistentName::FindEntity(pSolid->GetSolid(), persistentName);

	//ASSERT(pEntity != NULL);
	if(!pEntity)
		return 0;

	PmeBrepReference * pReference = new PmeBrepReference(GetPart(), pEntity);
	GetReferences()->Add(pReference);

	return pReference;
}

ENTITY * PmeSelectionManager::GetBrepFromReference(PmeReference * pReference)
{
	PmeThrowExceptionIf<PmeArgumentTypeException>(pReference->GetReferenceType() != PmeReferenceType_Brep);
	return PmePersistentName::FindEntity(GetPart()->GetExplicitModel()->GetSolid()->GetSolid(), pReference->GetReferenceeName());
}

PmeReference * PmeSelectionManager::SelectPlaneByAxis(const MrAxis2 & axis)
{
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	int size = pExplicitModel->GetSize();

	double minNorm = std::numeric_limits<double>::max();
	PmeReference * pRetReference = 0;

	for(int i = 0; i < size; ++i)
	{
		PmeExplicitModelObject * pObject = pExplicitModel->GetItem(i);
		double norm = std::numeric_limits<double>::max();
		PmeReference * pReference = 0;

		if(pObject->GetType() == PmeExplicitModelObjectType_DatumPlane || pObject->GetType() == PmeExplicitModelObjectType_OffsetDatumPlane)
		{
			PmeDatumPlane * pPlane = static_cast<PmeDatumPlane *>(pObject);
			MrAxis2 coord = pPlane->GetLocation();
			if(MrMath::IsCoplanar(axis, coord))
			{
                norm = MrMath::Norm(axis, coord);
                pReference = new PmeExplicitModelObjectReference(GetPart(), pPlane);
			}
		}
		else if(pObject->GetType() == PmeExplicitModelObjectType_Solid)
		{
			FACE * pFace = GetNearestFace(static_cast<PmeSolid *>(pObject), axis);
			
			if(pFace)
			{
				MrAxis2 coord = PmeQueryFaceLocalCoordinate(pFace);

				if(MrMath::IsCoplanar(axis, coord))
				{
                    norm = MrMath::Norm(axis, coord);
                    pReference = new PmeBrepReference(GetPart(), pFace);
				}
			}
			else
				pReference = 0;
		}
		
		if(pReference && norm < minNorm)
		{
			minNorm = norm;
			if(pRetReference)
				delete pRetReference;

			pRetReference = pReference;
		}
		else if(pReference)
			delete pReference;
	}

	if(pRetReference)
		GetReferences()->Add(pRetReference);

	return pRetReference;
}

FACE * PmeSelectionManager::GetNearestFace(PmeSolid * pSolid, const MrAxis2 & srcAxis)
{
	BODY * pBody = pSolid->GetSolid();

	ENTITY_LIST faceList;
	api_get_faces(pBody, faceList);

	faceList.init();
	
	ENTITY * pEntity;
	
	FACE * pTarFace = NULL;
	double minNorm = std::numeric_limits<double>::max();

	while((pEntity = faceList.next()) != NULL)
	{
		FACE * pFace = (FACE *)pEntity;

		if (is_planar_face(pFace))
		{
			MrAxis2 axis = PmeQueryFaceLocalCoordinate(pFace);		

			double norm = MrMath::Norm(srcAxis, axis);
			if(MrMath::IsCoplanar(axis, srcAxis) && norm < minNorm)
			{
				pTarFace = pFace;
				minNorm = norm;
			}
		}
	}

	return pTarFace;
}

PmeReference * PmeSelectionManager::SelectCurveBy3Points(const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve)
{
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	int size = pExplicitModel->GetSize();
	
	PmeReference * pReference = 0;

	for(int i = 0; i < size; ++ i)
	{
		PmeExplicitModelObject * pObject = pExplicitModel->GetItem(i);		
		
		if(pObject->GetType() == PmeExplicitModelObjectType_Solid)
		{
			EDGE * pEdge = GetEdgesWith3Points(static_cast<PmeSolid *>(pObject), start, end, pointOnCurve);
			if(pEdge)
			{
				pReference = new PmeBrepReference(GetPart(), pEdge);
				break;
			}
		}
	}

	if(pReference)
		GetReferences()->Add(pReference);

	return pReference;
}

PmeReference * PmeSelectionManager::SelectCurveByPoint(const MrPosition & pointOnCurve)
{
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	int size = pExplicitModel->GetSize();

	PmeReference * pReference = 0;

	for(int i = 0; i < size; ++ i)
	{
		PmeExplicitModelObject * pObject = pExplicitModel->GetItem(i);		

		if(pObject->GetType() == PmeExplicitModelObjectType_Solid)
		{
			EDGE * pEdge = GetEdgesWithPoint(static_cast<PmeSolid *>(pObject), pointOnCurve);
			if(pEdge)
			{
				pReference = new PmeBrepReference(GetPart(), pEdge);
				break;
			}
		}
	}

	if(pReference)
		GetReferences()->Add(pReference);

	return pReference;
}

EDGE * PmeSelectionManager::GetEdgesWith3Points(PmeSolid * pSolid, const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve)
{
	BODY * pBody = pSolid->GetSolid();

	ENTITY_LIST edgeList;
	api_get_edges(pBody, edgeList);

	edgeList.init();
	
	ENTITY * pEntity;	
	EDGE * pEdge = NULL;
		
	SPAtransf transform;

	while((pEntity = edgeList.next()) != NULL)
	{
		EDGE * pTempEdge = (EDGE *)pEntity;

		// Import 된 Brep 모델의 요소(점, 선, 면)는 Transform 되어있지 않음
		// 따라서 Transform이 발생하는 일반적인 특징형상의 경우에만 적용 (16-11-24 권순조)
		if (pTempEdge->coedge()->loop()->face()->shell()->lump()->body()->transform())
			transform = pTempEdge->coedge()->loop()->face()->shell()->lump()->body()->transform()->transform();

		SPAposition s = pTempEdge->start_pos();
		SPAposition e = pTempEdge->end_pos();

		s *= transform;
		e *= transform;

		MrPosition edgeStart(s.x(), s.y(), s.z());
		MrPosition edgeEnd(e.x(), e.y(), e.z());

		TRACE("\nStart: %f,%f,%f",s.x(), s.y(), s.z());
		TRACE("\nEnd: %f,%f,%f\n",e.x(), e.y(), e.z());

		if((MrMath::IsEqual(start, edgeStart) && MrMath::IsEqual(end, edgeEnd))	||
		   (MrMath::IsEqual(start, edgeEnd) && MrMath::IsEqual(end, edgeStart)))
		{
			pEdge = pTempEdge;
			break;
		}
	}

	if(pEdge)
	{
		SPAinterval inter = pEdge->param_range();
		double st = inter.start_pt();
		double et = inter.end_pt();

		CURVE * pCurve = pEdge->geometry();
		const curve & c = pCurve->equation();
		
		SPAposition m(pointOnCurve.X(), pointOnCurve.Y(), pointOnCurve.Z());
		
		m *= (transform.inverse());

		double t = c.param(m);

		if((t >= st && t <= et) || (t >= et && t <= st))
		   return pEdge;
	}

	return 0;
}

// 17-02-27 권순조 수정
EDGE * PmeSelectionManager::GetEdgesWithPoint(PmeSolid * pSolid, const MrPosition & pointOnCurve)
{
	BODY * pBody = pSolid->GetSolid();

	ENTITY_LIST edgeList;
	api_get_edges(pBody, edgeList);

	edgeList.init();

	ENTITY * pEntity;
	EDGE * pEdge = NULL;

	while((pEntity = edgeList.next()) != NULL)
	{
		EDGE * pTempEdge = (EDGE *)pEntity;

		SPAtransf transform;
		
		// Import 된 Brep 모델의 요소(점, 선, 면)는 Transform 되어있지 않음
		// 따라서 Transform이 발생하는 일반적인 특징형상의 경우에만 적용 (16-11-24 권순조)
		if (pTempEdge->coedge()->loop()->face()->shell()->lump()->body()->transform())
			transform = pTempEdge->coedge()->loop()->face()->shell()->lump()->body()->transform()->transform();

		SPAposition s = pTempEdge->start_pos();
		SPAposition e = pTempEdge->end_pos();

		s *= transform;
		e *= transform;

		/// 입력 받은 포인트가 해당 edge의 curve 방정식을 만족하는지 (curve 위에 존재하는지) 확인 (17-02-27 권순조)
		SPAposition temp(pointOnCurve.X(), pointOnCurve.Y(), pointOnCurve.Z());
		const curve & c = pTempEdge->geometry()->equation();
		int isOnTheEdge = c.test_point(temp);
		///
		
		if (is_elliptical_edge(pTempEdge) ||
			((s.x() == e.x()) && (s.y() == e.y()) && (s.z() == e.z()))) // circular line
		{
			if (isOnTheEdge)
			{
				pEdge = pTempEdge;
				break;
			}

			SPAposition m = pTempEdge->mid_pos();
			m *= transform;
			
			SPAposition c;// center of circle

			c.x() = (s.x() + m.x() ) /2;
			c.y() = (s.y() + m.y() ) /2;
			c.z() = s.z();

			double rad;// radious

			rad = sqrt ( (s.x() - c.x()) * (s.x() - c.x()) + (s.y() - c.y()) * (s.y() - c.y()) );

			// 진입 조건문 검토 필요
			if ( c.x() == pointOnCurve.X() || c.y() == pointOnCurve.Y() || c.z() == pointOnCurve.Z())// same plane
			{
				double dis;// distance
				dis = sqrt ( (c.x() - pointOnCurve.X()) * (c.x() - pointOnCurve.X()) + (c.y() - pointOnCurve.Y()) * (c.y() - pointOnCurve.Y()) + (c.z() - pointOnCurve.Z()) * (c.z() - pointOnCurve.Z()) );		

				if (MrTolerance::IsZeroValue(abs(rad - dis)))
				{
					pEdge = pTempEdge;
					break;
				}
			}			
		}
		else if (is_linear_edge(pTempEdge))//normal line
		{
			if (isOnTheEdge)
			{
				if ( (pointOnCurve.X() == s.x() && pointOnCurve.X() == e.x())  && (pointOnCurve.Y() == s.y() && pointOnCurve.Y() == e.y()) &&  ((s.z() <= pointOnCurve.Z() && pointOnCurve.Z() <= e.z()) || (e.z() <= pointOnCurve.Z() && pointOnCurve.Z()<= s.z()))
					|| (pointOnCurve.X() == s.x() && pointOnCurve.X() == e.x())  && (pointOnCurve.Z() == s.z() && pointOnCurve.Z() == e.z()) &&  ((s.y() <= pointOnCurve.Y() && pointOnCurve.Y() <= e.y()) || (e.y() <= pointOnCurve.Y() && pointOnCurve.Y()<= s.y()))
					|| (pointOnCurve.Y() == s.y() && pointOnCurve.Y() == e.y())  && (pointOnCurve.Z() == s.z() && pointOnCurve.Z() == e.z()) &&  ((s.x() <= pointOnCurve.X() && pointOnCurve.X() <= e.x()) || (e.x() <= pointOnCurve.X() && pointOnCurve.X()<= s.x())) )
				{
					pEdge = pTempEdge;
					break;
				}
			}
		}
	}

	// 엣지가 선택된 경우
	if (pEdge)
	{
		//SPAinterval inter = pEdge->param_range();
		//double st = inter.start_pt();
		//double et = inter.end_pt();

		//CURVE * pCurve = pEdge->geometry();
		//const curve & c = pCurve->equation();

		//double t = c.param(SPAposition(pointOnCurve.X(), pointOnCurve.Y(), pointOnCurve.Z()));

		//if((t >= st && t <= et) ||
		//   (t >= et && t <= st))

		return pEdge;
	}

	return 0;
}

PmeReference * PmeSelectionManager::SelectPlaneByTopoName(const CString & topoName)
{
	//PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	//PmeSolid * pSolid = pExplicitModel->GetSolid();
	
	CString ExtrudeName;
	CString SketchName;
	CString LineName;

	
	int index =0;
	ExtrudeName = topoName.Tokenize(",",index);
	index ++;
	SketchName = topoName.Tokenize(",",index);
	index ++;
	SketchName = "S"+SketchName;
	//LineName = topoName.Tokenize("e",index);
	LineName = topoName.Tokenize(",",index);	
	LineName="L"+LineName;
	//int edgenum = atoi (LineName);
	
	PmeStdSolidProtrusionExtrudeFeature * pFeature_extrude= (PmeStdSolidProtrusionExtrudeFeature *) GetPart()->GetFeatures()->FindByName(ExtrudeName);
	double Extrude_depth = pFeature_extrude->GetStartDepth();

	PmeFeature * hFeature = pFeature_extrude->GetPart()->GetFeatures()->FindByName(SketchName);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);

	PmeThrowExceptionIf<PmeArgumentTypeException>(pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature);

	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);
	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
	
	PmeStdSketchLine * pLine = (PmeStdSketchLine *)pGeometries->FindByName(LineName);
	
	PmeStdSketchControlPoint * pStart = pLine->GetStartPoint();
	PmeStdSketchControlPoint * pEnd = pLine->GetEndPoint();

	double x_start = pStart->GetX();
	double y_start = pStart->GetY();
	double x_end = pEnd->GetX();
	double y_end = pEnd->GetY();

	double x_final = (x_start + x_end )/2;
	double y_final = (y_start + y_end )/2;
	double z_final = (Extrude_depth )/2;

	MrPosition pointonFace;

	pointonFace.SetX(x_final) ;
	pointonFace.SetY(y_final) ;
	pointonFace.SetZ(z_final) ;

	PmeReference * pReference = SelectPlaneByPoint(pointonFace);
	return pReference;	

	//double x_end = pEnd->GetX();
	//double y_end = pEnd->GetY();

	//PmeStdSketchFeature *  pSketch = (PmeStdSketchFeature * )GetPart()->GetExplicitModel()->FindByName(SketchName);
	//PmeStdSketchLine * pLine = (PmeStdSketchLine *) pSketch->GetGeometries()->FindByName(LineName);
	
	//PmeReference * ppp = pFeature_extrude->GetProfileSketch();

	//PmeStdSketchLine * pLine = (PmeStdSketchLine *) ppp->GetPart()->GetExplicitModel()->FindByName(LineName);	
	//PmeExplicitModel * pobject = ppp->GetPart()->GetExplicitModel();	
	
	/*
	COEDGE * pFacee = ppp->GetPart()->GetExplicitModel()->GetSolid()->GetSolid()->lump()->shell()->face()->loop()->start();
	
	for (int i = 1 ; i < edgenum ; i ++)
	{	
		VERTEX * pStart = pFacee->start();
		VERTEX * pEnd = pFacee->end();
		double x_start = pStart->geometry()->coords().x();
		double y_start = pStart->geometry()->coords().y();

		pFacee = pFacee->next();
	}*/
	/*
	VERTEX * pStart = pFacee->start();
	VERTEX * pEnd = pFacee->end();

	double x_start = pStart->geometry()->coords().x();
	double y_start = pStart->geometry()->coords().y();

	double x_end = pEnd->geometry()->coords().x();
	double y_end = pEnd->geometry()->coords().y();

	double x_final = (x_start + x_end )/2;
	double y_final = (y_start + y_end )/2;
	double z_final = (Extrude_depth )/2;*/


	//PmeStdSketchLine * pLine = (PmeStdSketchLine *)ppp->GetPart()->GetExplicitModel()->FindByName(LineName);

	//PmeStdSketchControlPoint * aaa =  pLine->GetStartPoint();

	//PmeStdSketchFeature *  pSketch = (PmeStdSketchFeature * )GetPart()->GetExplicitModel()->FindByName(SketchName);
	//PmeStdSketchLine * pLine = (PmeStdSketchLine *) pSketch->GetGeometries()->FindByName(LineName);
	//PmeStdSketchGeometries * pobject = pSketch->GetGeometries();	
	//int aaa =  pobject->GetSize();

	//ENTITY * pEntity = PmePersistentName::FindPlaneByTopoName(pSolid->GetSolid(), topoName);

	//ASSERT(pEntity != NULL);

	//PmeBrepReference * pReference = new PmeBrepReference(GetPart(), pEntity);
	//GetReferences()->Add(pReference);
	/*
	MrPosition pointonFace;

	pointonFace.SetX(x_final) ;
	pointonFace.SetY(y_final) ;
	pointonFace.SetZ(z_final) ;*/

	//PmeReference * pReference = SelectPlaneByPoint(pointonFace);
	//return pReference;
}

FACE * PmeSelectionManager::GetSelectedFaceByPoint(PmeSolid * pSolid, const MrPosition & pointOnFace)
{
	BODY * pBody = pSolid->GetSolid();

	ENTITY_LIST faceList;
	api_get_faces(pBody, faceList);

	faceList.init();

	ENTITY * pEntity;	
	FACE * pTarFace = NULL;

	while((pEntity = faceList.next()) != NULL)
	{
		FACE * pFace = (FACE *)pEntity;

		ENTITY_LIST edgeList;
		api_get_edges(pFace, edgeList);		
		
		edgeList.init();
		int edge_count= edgeList.count();
		
		ENTITY * pEdgeEntity;
		pEdgeEntity = edgeList.next();
		
		
		int i = 0; 
		double p[9],u[6],c[3];
	
		if (edge_count==1 || edge_count==2)//circular face
		{
			EDGE * pTempEdge = (EDGE *)pEdgeEntity;
			SPAposition s = pTempEdge->start_pos();//원의 한점
			
			SPAposition ss = pTempEdge->mid_pos();//원의 반대점

			p[0] = s.x();
			p[1] = s.y();
			p[2] = s.z();

			p[3] =  ss.x();
			p[4] =  ss.y();
			p[5] =  p[2];

			c[0] = (p[0] + p[3])/2; //center point x
			c[1] = (p[1] + p[4])/2; //center point y
			c[2] = p[2];			//center point z
			
			double rad; // radious of face
			rad = sqrt ((c[0]-p[0])*(c[0]-p[0]) + (c[1]-p[1])*(c[1]-p[1]) + (c[2]-p[2])*(c[2]-p[2]));
			
			p[6] =  pointOnFace.X();
			p[7] =  pointOnFace.Y();
			p[8] =  pointOnFace.Z();
			
			double radd;//distance between center of circle and point

			radd = sqrt ((c[0]-p[6])*(c[0]-p[6]) + (c[1]-p[7])*(c[1]-p[7]) + (c[2]-p[8])*(c[2]-p[8]));
			
			if ( ((c[0]==p[6]) || (c[1]==p[7]) || (c[2]==p[8])) && (radd < rad)) // selcet face is distance is smaller than radius
			{
				pTarFace = pFace;
				break;
			}
			
		}
		else//poly face
		{		

			EDGE * pTempEdge = (EDGE *)pEdgeEntity;
			SPAposition s = pTempEdge->start_pos();
			SPAposition e = pTempEdge->end_pos();

			p[0] = s.x();
			p[1] = s.y();
			p[2] = s.z();
			p[3] = e.x();
			p[4] = e.y();
			p[5] = e.z();
			
			
			pEdgeEntity = edgeList.next();
			pEdgeEntity = edgeList.next();

			EDGE * pTempEdge1 = (EDGE *)pEdgeEntity;
			SPAposition s1 = pTempEdge1->start_pos();

			p[6] = s1.x();
			p[7] = s1.y();
			p[8] = s1.z();

			/*
			while((pEdgeEntity = edgeList.next()) != NULL)
			{	
			//pEdgeEntity = edgeList.next();

			EDGE * pTempEdge = (EDGE *)pEdgeEntity;
			SPAposition e = pTempEdge->end_pos();	

			p[i] = e.x();
			p[i+1] = e.y();
			p[i+2] = e.z();

			i = i+3;			
			}
			*/

			u[0] = (p[1]-p[4])*(p[8]-p[5]) - (p[2]-p[5]) * (p[7]-p[4]);
			u[1] = (p[2]-p[5])*(p[6]-p[3]) - (p[0]-p[3]) * (p[8]-p[5]);
			u[2] = (p[0]-p[3])*(p[7]-p[4]) - (p[1]-p[4]) * (p[6]-p[3]);

			u[3] =  pointOnFace.X() - p[3];
			u[4] =  pointOnFace.Y() - p[4];
			u[5] =  pointOnFace.Z() - p[5];

			double innerPro = u[0]*u[3] + u[1]*u[4] + u[2]*u[5] ;

			//edgeList.clear();

			if(innerPro == 0)
			{	
				pTarFace = pFace;
				break;
			}	
		}
	}

	return pTarFace;	
}

PmeReference * PmeSelectionManager::SelectPlaneByPoint(const MrPosition & pointOnFace)
{	
	PmeExplicitModel * pExplicitModel = GetPart()->GetExplicitModel();
	int size = pExplicitModel->GetSize();

	PmeReference * pReference = 0;

	for(int i = 0; i < size; ++ i)
	{
		PmeExplicitModelObject * pObject = pExplicitModel->GetItem(i);

		FACE * pFace = GetSelectedFaceByPoint(static_cast<PmeSolid *>(pObject), pointOnFace);
		if(pFace)
		{
			pReference = new PmeBrepReference(GetPart(), pFace);
			break;
		}
		else
			pReference = 0;

	}

	if(pReference)
		GetReferences()->Add(pReference);

	return pReference;
}