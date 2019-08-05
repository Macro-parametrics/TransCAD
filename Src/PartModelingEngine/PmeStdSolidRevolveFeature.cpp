#include "StdAfx.h"
#include <algorithm>
#include ".\PmeStdSolidRevolveFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\PmePersistentNameAPI.h"
#include ".\attr_pme_vertexname.h"
#include ".\pmepersistentname.h"
#include <vector>
#include <string>

#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\MrTolerance.h"

#include ".\PmeStdSketchLineAPI.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

#include ".\PmeStdSketchHDirectionAPI.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeStdSketchVDirectionAPI.h"
#include ".\PmeStdSketchVDirection.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidRevolveFeature, PmeStdSolidFeature)

PmeStdSolidRevolveFeature::PmeStdSolidRevolveFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidRevolveFeature::PmeStdSolidRevolveFeature(PmePart * pPart,
                                                           PmeReference * pProfileSketch,
                                                           double startAngle,
                                                           PmeStdRevolveEndType startCondition,
                                                           double endAngle,
                                                           PmeStdRevolveEndType endCondition,
														   bool isFlip) 
: PmeStdSolidFeature(pPart)
, m_pProfileSketch(pProfileSketch)
, m_startAngle(startAngle)
, m_startCondition(startCondition)
, m_endAngle(endAngle)
, m_endCondition(endCondition)
, m_isFlip(isFlip)
{
}

PmeStdSolidRevolveFeature::~PmeStdSolidRevolveFeature(void)
{
}

MrAxis1 PmeStdSolidRevolveFeature::GetInternalAxis(bool isCut)
{
	MrAxis1 axis = PmeSketchUtility::GetRevolutionAxis(GetProfileSketch());
	if(isCut)
		axis = MrMath::Reverse(axis);

	MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch());
	MrAffineTransformation trsf = MrAffineTransformation::CreateCoordinateSystemTransformation(coordinateSystem, MrAxis2::OXY());

	return MrMath::Transform(axis, trsf);
}

BODY * PmeStdSolidRevolveFeature::RevolveStartSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	MrAxis1 axis = GetInternalAxis(isCut);
	
	switch(GetInternalStartCondition())
	{
	case PmeStdRevolveEndType_Blind:
		{
			double angle = GetInternalStartAngle();
			if(angle == 0)
				break;
			pResult = RevolveWithBlind(pProfile, axis, angle);
		}
		break;
	}

	if(pResult)
    {
		if(g_bNamingType)
		{AttachName(pResult);} //Toplogy naming 
       	else 
		{AttachVertexName_pointbased(pResult);} //Point-based naming 
		
	}

	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidRevolveFeature::RevolveEndSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	MrAxis1 axis = GetInternalAxis(isCut);

	switch(GetInternalEndCondition())
	{
	case PmeStdRevolveEndType_Blind:
		{
			double angle = GetInternalEndAngle();
			if(angle == 0)
				break;
			pResult = RevolveWithBlind(pProfile, MrMath::Reverse(axis), angle);
		}
		break;
	}

	if(pResult)
	{
		if(g_bNamingType)
		{AttachName(pResult);} //Toplogy naming 
       	else 
		{AttachVertexName_pointbased(pResult);} //Point-based naming
		
	}
	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidRevolveFeature::RevolveWithBlind(BODY *& pProfile, const MrAxis1 & axis, double angle)
{
	SPAposition spaRoot(axis.Location().X(), axis.Location().Y(), axis.Location().Z());
	SPAvector spaAxis(axis.Direction().X(), axis.Direction().Y(), axis.Direction().Z());
	sweep_options options;

	BODY * pNewBody = 0;
	BODY * pTemp = 0;

	API_BEGIN

		result = api_copy_body(pProfile, pNewBody);
		check_outcome(result);

		options.set_sweep_angle(DegreeToRadian(angle));

		result = api_sweep_with_options(pNewBody, spaRoot, spaAxis, &options, pTemp);
		check_outcome(result);

		if(result.ok())
			return pNewBody;

	API_END

	return 0;
}

//TOPOLOGY-BASED Naming

void PmeStdSolidRevolveFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_SWEEP_ANNO_EDGE_LAT);

	annotationListLateral.init();

	SWEEP_ANNO_EDGE_LAT * pAnnotationEdgeLat;
	
	CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();

	while((pAnnotationEdgeLat = (SWEEP_ANNO_EDGE_LAT *)annotationListLateral.next()) != NULL)
	{
        ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);
		int count = annotationInputs.count();
		
		if(annotationInputs.count() == 1)
		{
			EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();
			
			CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
			CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,RevolveFeature:0,0:0;0";

			new ATTRIB_FACENAME(pFace, faceName);
		}
		else if(annotationInputs.count() == 0)
		{
			EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

			CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
			CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,RevolveFeature:0,0:0;0";

			new ATTRIB_FACENAME(pFace, faceName);
		}
	}

	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SWEEP_ANNO_END_CAPS);

	MrDirection sketchNormal = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).ZDirection();
	MrPosition sketchOrigin = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).Location();

	SWEEP_ANNO_END_CAPS	* pAnnotationEndCaps;
	
	annotationListEnd.init();

	while((pAnnotationEndCaps = (SWEEP_ANNO_END_CAPS *)annotationListEnd.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;

		//pAnnotationEdgeLat->inputs(annotationInputs);		

		FACE * pStartFace = pAnnotationEndCaps->start_face();
		FACE * pEndFace = pAnnotationEndCaps->end_face();

		MrDirection startNormal = PmeQueryFaceNormal(pStartFace, sketchOrigin);
		MrDirection endNormal = PmeQueryFaceNormal(pEndFace, sketchOrigin);

		bool isEndSolid = false;
		
		// StartSolid (¹Ý½Ã°è¹æÇâ È¸Àü): ½ºÄÉÄ¡ Æò¸éÀÇ Normal°ú StartFaceÀÇ NormalÀÌ µ¿ÀÏ
		// EndSolid (½Ã°è¹æÇâ È¸Àü): ½ºÄÉÄ¡ Æò¸éÀÇ Normal°ú StartFaceÀÇ NormalÀÌ ¹Ý´ë
		if(!MrMath::IsEqual(startNormal, sketchNormal)) // EndSolidÀÇ °æ¿ì ÁøÀÔ
		{
			std::swap(pStartFace, pEndFace);
			isEndSolid = true;
		}

		CString startFaceName = GetName() + ",0,-1,0,0,0,RevolveFeature:0,0:0;0";
		CString endFaceName = GetName() + ",0,-2,0,0,0,RevolveFeature:0,0:0;0";
		

		// 1. ÀÏ¹ÝÀûÀÎ °æ¿ì //
		// StartFace : ½ºÄÉÄ¡ Æò¸éÀÇ Normal°ú µ¿ÀÏ ¹æÇâÀ¸·Î È¸ÀüÇÏ¿© »ý±â´Â ¸é (½Ã°è¹æÇâ) 
		// EndFace : ½ºÄÉÄ¡ Æò¸éÀÇ Normal°ú ¹Ý´ë ¹æÇâÀ¸·Î È¸ÀüÇÏ¿© »ý±â´Â ¸é (¹Ý½Ã°è¹æÇâ)
		if (!m_isFlip) // FlipÀÌ ¾Æ´Ñ °æ¿ì
		{
			new ATTRIB_FACENAME(pStartFace, startFaceName);
			new ATTRIB_FACENAME(pEndFace, endFaceName);
		}
		else // FlipÀÎ °æ¿ì
		{
			new ATTRIB_FACENAME(pStartFace, endFaceName);
			new ATTRIB_FACENAME(pEndFace, startFaceName);
		}    

		// 2. ½ÃÀÛ¸é°ú ³¡¸éÀÌ ¿§Áö¸¦ °øÀ¯ÇÏ¸ç ÀüÃ¼ °¢µµ°¡ 180µµ ÀÎ °æ¿ì //
		// ÀÌ ¶§, µÎ ¸éÀÇ Merge°¡ ¹ß»ýÇÒ ¼ö ÀÖÀ¸¹Ç·Î ¾Æ·¡¿Í °°ÀÌ Ã³¸®
		if (IsSharingEdge(pStartFace, pEndFace))
		{	
			// StartAngle + EndEngleÀÇ ÇÕÀÌ 180ÀÏ ¶§ (´Ü, µÑ Áß ÇÏ³ª°¡ 0ÀÎ °æ¿ì Æ÷ÇÔ)
			// ÀÌ °æ¿ì ¹«Á¶°Ç StartFaceNameÀ» °¡Áöµµ·Ï Ã³¸® (CATIAÀÇ »ç·Ê¸¦ µû¸§)
			if(GetInternalStartAngle() + GetInternalEndAngle() == 180.0)
			{
				new ATTRIB_FACENAME(pStartFace, startFaceName);
				new ATTRIB_FACENAME(pEndFace, startFaceName);
			}
			// StartAngle, EndAngle µÑ Áß ÇÏ³ª¸¸ 180ÀÏ ¶§ (´Ü, µÑ ´Ù 0º¸´Ù Å« °æ¿ì)
			// ÀÌ °æ¿ì StartSolidÀÇ EndFace°¡ EndFace·Î, EndSolidÀÇ EndFace°¡ StartFace·Î ³²µµ·Ï Ã³¸® (´Ü, FlipÀÇ °æ¿ì ¹Ý´ë)
			else if (pStartFace == pEndFace)
			{	
				if (!isEndSolid)	// StartSolid¸¸ 180µµ ÀÏ ¶§
				{
					if(!m_isFlip)	// FlipÀÌ ¾Æ´Ò ¶§
						new ATTRIB_FACENAME(pEndFace, endFaceName);
					else			// FlipÀÏ ¶§
						new ATTRIB_FACENAME(pEndFace, startFaceName);
				}
				else if (isEndSolid)// EndSolid¸¸ 180µµ ÀÏ ¶§
				{
					if(!m_isFlip)	// FlipÀÌ ¾Æ´Ò ¶§
						new ATTRIB_FACENAME(pEndFace, startFaceName);
					else			// FilpÀÏ ¶§
						new ATTRIB_FACENAME(pEndFace, endFaceName);
				}	
			}
		}

	}

}

bool PmeStdSolidRevolveFeature::IsSharingEdge(FACE * pFace1, FACE * pFace2)
{
	ENTITY_LIST vertex_list1, vertex_list2;
	get_vertices(pFace1, vertex_list1);
	get_vertices(pFace2, vertex_list2);
	
	SPAposition p1,p2;

	int count = 0;

	for (int i = 0; i < vertex_list1.count(); ++i)
	{
		VERTEX* pVert1 = (VERTEX*)vertex_list1[i];
		p1 = pVert1->geometry()->coords();

		for (int j = 0; j < vertex_list2.count(); ++j)
		{
			VERTEX* pVert2 = (VERTEX*)vertex_list2[j];
			p2 = pVert2->geometry()->coords();

			if((p1.x() == p2.x()) && (p1.y() == p2.y()) && (p1.z() == p2.z()))
				count ++;
			else
				continue;
		}
	}

	if (count >= 2)
		return true;
	else
		return false;


}

// Point-based naming
void PmeStdSolidRevolveFeature::AttachVertexName_pointbased(BODY *& pBody)
{	
	AttachFeatureTag(pBody);
	
	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SWEEP_ANNO_END_CAPS);

	MrDirection sketchNormal = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).ZDirection();
	MrPosition sketchOrigin = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).Location();

	SWEEP_ANNO_END_CAPS	* pAnnotationEndCaps;
	
	annotationListEnd.init();

	while((pAnnotationEndCaps = (SWEEP_ANNO_END_CAPS *)annotationListEnd.next()) != NULL)
 {
		ENTITY_LIST annotationInputs;

		//Naming POINTS on the SKETCH side of pro-Revolve
		FACE * pStartFace = pAnnotationEndCaps->start_face();


		ENTITY_LIST edge_list; 
		get_edges(pStartFace, edge_list);


		CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();

		int a = edge_list.count();
		VERTEX * ver;	

		for (int i = 0 ; i < a; i++)

			{
						double vertexcoord[3];
						CString vertexNum[3];

						EDGE * e = (EDGE *) edge_list[i];   

						ver = e->start(); 

						SPAposition s1 = ver->geometry()->coords();
		
						vertexcoord[0] = s1.x();
						vertexcoord[1] = s1.y();
						vertexcoord[2] = s1.z();
						//vertexNum is formated vertex coordinates
						vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
						vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
						vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]); 

						ENTITY_LIST elist;
						api_get_edges(ver, elist);

						int b = elist.count();

							CString edgeName;
							CString edgeName1;
							CString edgeName2;

							if (b == 3)
								{

									EDGE* pEdge = (EDGE*)elist[0];
									edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
									
									if (edgeName != "" )
									{
										EDGE* pEdge2 = (EDGE*)elist[2];
										edgeName2 = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge2, sketchName))->value();
										
										if (edgeName2 != "" )
										{
											CString vertexName;
											vertexName = GetName() + "," + sketchName + "," + edgeName + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
											new ATTRIB_VERTEXNAME(ver, vertexName);
										}

										else 
										{
											EDGE* pEdge1 = (EDGE*)elist[1];
											edgeName1 = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge1, sketchName))->value();

											CString vertexName;
											vertexName = GetName() + "," + sketchName + "," + edgeName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
											new ATTRIB_VERTEXNAME(ver, vertexName);
										}
									}
									else
									{
							
											EDGE* pEdge1 = (EDGE*)elist[1];
											edgeName1 = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge1, sketchName))->value();
										
										
											EDGE* pEdge2 = (EDGE*)elist[2];
											edgeName2 = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge2, sketchName))->value();
										
										
											CString vertexName;
											vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
											new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								
								}

							else if (b == 1)
							{

								Attach_NewVertexNames_pointbased(pBody); //As the method to name the circular profile is same
							
							}
		
			}	
		
		//Naming POINTS on the non-SKETCH side of pro-Revolve
		FACE * pEndFace = pAnnotationEndCaps->end_face();

		ENTITY_LIST edge_list1; 
		get_edges(pEndFace, edge_list1);

		int b = edge_list1.count();
		VERTEX * ver1;	
	
		
		for (int i = 0 ; i < b; i++)
			{
						double vertexcoord[3];
						CString vertexNum[3];

						EDGE * e = (EDGE *) edge_list1[i]; 

						ver1 = e->start(); // Getting the starting vertex of all the edges

						SPAposition s2 = ver1->geometry()->coords();
		
						vertexcoord[0] = s2.x();
						vertexcoord[1] = s2.y();
						vertexcoord[2] = s2.z();
						//vertexNum is formated vertex coordinates
						vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
						vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
						vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]); 

						CString vertexName;
						// For each vertex generated by extrude feature
						vertexName = GetName() + "," + sketchName + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")"; // Replace Feature name with user selected name

						new ATTRIB_VERTEXNAME(ver1, vertexName); // Get this next!

			}

 }

	AttachRemainingVertexNames_pointbased(pBody); // Check for remaining vertices
	AttachFaceName_pointbased(pBody); // Face Names

}

//FACES of body are named after PRO/CUT REVOLVE
void PmeStdSolidRevolveFeature::AttachFaceName_pointbased(BODY *& pBody)
{

	
	FACE * ff ;
	ff = pBody->lump()->shell()->face();

	while (ff!= NULL)
	{
		CString faceName;
		ENTITY_LIST lp_list;
		
		api_get_loops(ff, lp_list); //Accounting for all LOOPS on a FACE
		
		int a = lp_list.count();
		int count=0;

		for (int b = 0; b < a; b++)
		{
			
			LOOP * lp = (LOOP *) lp_list[b];
		
			COEDGE * ce;
			ce = lp->start();
			VERTEX * ver;
			

		do{
			
			ver = ce->start();
			CString name = PmePersistentName::FindVertexName(ver);

			if (count == 0)
				faceName =  name;

			else
				faceName = faceName +","+ name;			

			count++;
			ce = ce->next();
		} while (ce != lp->start()); 
		
		}

		CString FaceName;

		FaceName = "FACE," + faceName;
		
		new ATTRIB_FACENAME(ff, FaceName);
		
		ff= ff->next();
	
		}

}


void PmeStdSolidRevolveFeature::AttachRemainingVertexNames_pointbased(BODY *& pBody)
{
	ENTITY_LIST edge_list;
	get_edges(pBody, edge_list);

	int a = edge_list.count();
	VERTEX * ver;	

	CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();

	for (int i = 0 ; i < a; i++)
	{
		double vertexcoord[3];
		CString vertexNum[3];

		EDGE * e = (EDGE *) edge_list[i];

		ver = e->start();

		CString verName = PmePersistentName::FindVertexName(ver);

		if (verName == "")  //check which points are still un-named in the final BODY and assign names
		{
			SPAposition s1 = ver->geometry()->coords();

			vertexcoord[0] = s1.x();
			vertexcoord[1] = s1.y();
			vertexcoord[2] = s1.z();

			vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
			vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
			vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);

			CString vertexName;

			vertexName = GetName() + "," + sketchName + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

			new ATTRIB_VERTEXNAME(ver, vertexName);
		}
		
	}

}


// After Bolean Operations
BODY * PmeStdSolidRevolveFeature::NamingNewVertices_ADD_BOL(BODY *& pBody, bool isCut)
{
		//BODY * pBody;

		Attach_NewVertexNames_pointbased(pBody);
	
		return pBody;
}

BODY * PmeStdSolidRevolveFeature::NamingNewVertices_SUB_BOL(BODY *& pBody, bool isCut)
{
		//BODY * pBody;

		Attach_NewVertexNames_pointbased(pBody);
	
		return pBody;
}
void PmeStdSolidRevolveFeature:: Attach_NewVertexNames_pointbased(BODY *& pBody)
{
	ENTITY_LIST edge_list;
	api_get_edges(pBody, edge_list);
	
	int b;
	b = edge_list.count();

	for (int i = 0; i < b; i++)
	{
	double vertexcoord[3];
	CString vertexNum[3];

	EDGE * pEdge = (EDGE *) edge_list[i];
	VERTEX* ver;
	ver = pEdge->start();
	CString edgeName1;
	CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();

	CString verName = PmePersistentName::FindVertexName(ver);

		if (verName == "")
		{
			SPAposition s1 = ver->geometry()->coords();
			vertexcoord[0] = s1.x();
			vertexcoord[1] = s1.y();
			vertexcoord[2] = s1.z();

			vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
			vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
			vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);

			PmeSketch * pSketch = PmeSketchUtility::GetSketch(GetProfileSketch());

			PmeFeature * pFeature = pSketch->GetCreator();
			PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

			PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
			PmeStdSketchGeometries::SizeType size = pGeometries->GetSize();

			MrAxis2 coordinateSystem = pSketchFeature->GetCoordinateSystem();
			MrDirection XDir = coordinateSystem.XDirection();
			MrDirection YDir = coordinateSystem.YDirection();
			//MrDirection ZDir = coordinateSystem.ZDirection();

			MrPosition location = coordinateSystem.Location();

			if (location.X() == vertexcoord[0] || location.Y() == vertexcoord[1] || location.Z() == vertexcoord[2]) //Unnamed POINT is on sketch plane
			{

			for(PmeStdSketchGeometries::SizeType j = 0; j < size; ++ j)
			{
				PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(j);

				
				if (pGeometry->GetType() == PmeStdSketchGeometryType_Line)
				{
					PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry);
					PmeStdSketchControlPoint * pStartPoint = pLine->GetStartPoint();

					EDGE * e1 = PmeSketchUtility::CreateEdgeFromGeometry(pGeometry);
					EDGE * e2 = CreateTransformedEdge(pEdge, coordinateSystem);
					
					VERTEX * ver1;
					ver1 = e1->start();
					SPAposition s2 = ver1->geometry()->coords();
					double vertexcoord1[3];
					vertexcoord1[0] = s2.x();
					vertexcoord1[1] = s2.y();
					vertexcoord1[2] = s2.z();

					VERTEX * ver2;
					ver2 = e2->start();
					SPAposition s3 = ver2->geometry()->coords();
					double vertexcoord2[3];
					vertexcoord2[0] = s3.x();
					vertexcoord2[1] = s3.y();
					vertexcoord2[2] = s3.z();

					if (XDir.X() == 1 && YDir.Y() == 1)
					{
						if (vertexcoord1[0] == vertexcoord2[0] && vertexcoord1[1] == vertexcoord2[1])
						{
						edgeName1 = pGeometry -> GetName();

						for(PmeStdSketchGeometries::SizeType k = 0; k < size; ++ k)
							{
								PmeStdSketchGeometry * pGeometry1 = pGeometries->GetItem(k);
				
								if (pGeometry1->GetType() == PmeStdSketchGeometryType_Line)
								{
								PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pLine->GetEndPoint();
								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();
								if (x == vertexcoord2[0] && y == vertexcoord2[1])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}
								}

								else if (pGeometry1->GetType() == PmeStdSketchGeometryType_CircularArc)
								{
								PmeStdSketchCircularArc * pCArc = static_cast<PmeStdSketchCircularArc *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pCArc->GetEndPoint();
								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();
								if (x == vertexcoord2[0] && y == vertexcoord2[1])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}
								
								}
						
							}
						
						}
					}		
					
					else if (XDir.Y() == 1 && YDir.Z() == 1)
					{
						if (vertexcoord1[0] == vertexcoord2[1] && vertexcoord1[1] == vertexcoord2[2])
						{
						edgeName1 = pGeometry -> GetName();

						for(PmeStdSketchGeometries::SizeType k = 0; k < size; ++ k)
							{
								PmeStdSketchGeometry * pGeometry1 = pGeometries->GetItem(k);

								if (pGeometry1->GetType() == PmeStdSketchGeometryType_Line)
								{
								PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pLine->GetEndPoint();
								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();
								if (x == vertexcoord2[1] && y == vertexcoord2[2])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}
								}

								else if (pGeometry1->GetType() == PmeStdSketchGeometryType_CircularArc)
								{	
								PmeStdSketchCircularArc * pCArc = static_cast<PmeStdSketchCircularArc *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pCArc->GetEndPoint();
								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();
								if (x == vertexcoord2[1] && y == vertexcoord2[2])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}

								}
						
						
							}
						}
				}
					
					
					else if (XDir.Z() == 1 && YDir.X() == 1)
					{
						if (vertexcoord1[0] == vertexcoord2[2] && vertexcoord1[1] == vertexcoord2[0])
						{
						edgeName1 = pGeometry -> GetName();
						
						for(PmeStdSketchGeometries::SizeType k = 0; k < size; ++ k)
							{
								PmeStdSketchGeometry * pGeometry1 = pGeometries->GetItem(k);

								if (pGeometry1->GetType() == PmeStdSketchGeometryType_Line)
								{
								PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pLine->GetEndPoint();
								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();

								if (x == vertexcoord2[2] && y == vertexcoord2[0])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}

								}
						
								else if (pGeometry1->GetType() == PmeStdSketchGeometryType_CircularArc)

								{
								
								PmeStdSketchCircularArc * pCArc = static_cast<PmeStdSketchCircularArc *>(pGeometry1);
								PmeStdSketchControlPoint * pEndPoint = pCArc->GetEndPoint();

								double x = pEndPoint->GetX();
								double y = pEndPoint->GetY();

								if (x == vertexcoord2[2] && y == vertexcoord2[0])
								{
									CString edgeName2 = pGeometry1 -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + "," + edgeName2 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									//break;
								}
								}
							}
						
						
						}


					}
					
					}
					else if (pGeometry->GetType() == PmeStdSketchGeometryType_Circle)
					{
					  if (size != 2 ) //Multiple Circular sketch elements
						
						{
							PmeStdSketchCircle * pCircle = static_cast<PmeStdSketchCircle *>(pGeometry);
							PmeStdSketchControlPoint * pCenterPoint = pCircle->GetCenterPoint();
							
							double circle_radius = pCircle->GetRadius();

							double x = pCenterPoint->GetX();
							double y = pCenterPoint->GetY();
							
							double local_x = vertexcoord[0] - location.X() ;
							double local_y = vertexcoord[1] - location.Y() ;
							double local_z = vertexcoord[2] - location.Z() ;


							
							if( (XDir.X() == 1 && YDir.Y() == 1) || (XDir.X() == 1 && YDir.Y() == -1) || (XDir.X() == -1 && YDir.Y() == 1) || (XDir.X() == -1 && YDir.Y() == -1) )
							{
								if (local_x == x)
								{
									if (local_y == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}

								else if (local_x == -x)
								{
									if (local_y == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_y == y )
								{
									if (local_x == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_y == -y)
								{
									if (local_x == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}



							}

							else if( (XDir.Y() == 1 && YDir.Z() == 1) || (XDir.Y() == 1 && YDir.Z() == -1) || (XDir.Y() == -1 && YDir.Z() == 1) || (XDir.Y() == -1 && YDir.Z() == -1) )
							{
								
								if (local_y == x)
								{
									if (local_z == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}

								else if (local_y == -x)
								{
									if (local_z == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_z == y )
								{
									if (local_y == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_z == -y)
								{
									if (local_y == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
							
							}

							else if( (XDir.X() == 1 && YDir.Z() == 1) || (XDir.X() == 1 && YDir.Z() == -1) || (XDir.X() == -1 && YDir.Z() == 1) || (XDir.X() == -1 && YDir.Z() == -1) )
							{
								
								if (local_x == x )
								{
									if (local_z == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}

								else if (local_x == -x)
								{
									if (local_z == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_z == y)
								{
									if (local_x == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_z == -y)
								{
									if (local_x == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
							
							}
							
							else if( (XDir.Y() == 1 && YDir.X() == 1) || (XDir.Y() == 1 && YDir.X() == -1) || (XDir.Y() == -1 && YDir.X() == 1) || (XDir.Y() == -1 && YDir.X() == -1) )
							{
								if (local_y == x )
								{
									if (local_x == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}

								else if (local_y == -x) 
								{
									if (local_x == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_x == (y + circle_radius))  
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_x == y)
								{
									if (local_y == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_x == -y)
								{
									if (local_y == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
							
							}

							else if( (XDir.Z() == 1 && YDir.Y() == 1) || (XDir.Z() == 1 && YDir.Y() == -1) || (XDir.Z() == -1 && YDir.Y() == 1) || (XDir.Z() == -1 && YDir.Y() == -1) )
							{
								if (local_z == x)
								{	
									if (local_y == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_z == -x)
								{
									if (local_y == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_y == (y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}
								else if (local_y == y)
								{
									if (local_z == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
							    }
								else if (local_y == -y)
								{
									if (local_z == (x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									else if (local_z == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
								}

							}
							
							else if( (XDir.Z() == 1 && YDir.X() == 1) || (XDir.Z() == 1 && YDir.X() == -1) || (XDir.Z() == -1 && YDir.X() == 1) || (XDir.Z() == -1 && YDir.X() == -1) )
							{
								if (local_z == x)
								{
									
									if(local_x == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}

									else if(local_x == (y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									
									/*else if(local_x == -(y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	
										
									else if(local_x == -(y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	*/
								}		
								else if (local_z == -x)
								{
									if(local_x == (y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}

									else if(local_x == (y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									
									/*else if(local_x == -(y - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	
										
									else if(local_x == -(y + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	*/
								}
								else if (local_x == y) 
								{

								    if(local_z == (x - circle_radius) )
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}

									else if( local_z == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									
									/*else if(local_z == -(x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	
										
									else if( local_z == -(x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	*/
								}
								else if (local_x == -y) 
								{
							        if(local_z == (x - circle_radius) )
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}

									else if( local_z == (x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}
									
									/*else if(local_z == -(x - circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	
										
									else if( local_z == -(x + circle_radius))
									{
									edgeName1 = pGeometry -> GetName();
									CString vertexName;
									vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
									new ATTRIB_VERTEXNAME(ver, vertexName);
									}	*/
								}
			
							}

						}

						else if (size == 2) //Single circular sketch element
						{
						edgeName1 = pGeometry -> GetName();
						CString vertexName;
						vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
						new ATTRIB_VERTEXNAME(ver, vertexName);
						}
							

					}
				}	
		}

		else //unmaed point (not on sketch plane)
		{
		CString vertexName;
		vertexName = GetName() + "," + sketchName + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";
		new ATTRIB_VERTEXNAME(ver, vertexName);
		//break;
		}

	}

	
}

	AttachRemainingVertexNames_pointbased(pBody);
	AttachFaceName_pointbased(pBody);

}
