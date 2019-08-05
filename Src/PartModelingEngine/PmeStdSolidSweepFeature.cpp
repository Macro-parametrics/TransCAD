#include "StdAfx.h"
#include <algorithm>
#include ".\PmeStdSolidSweepFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\PmePersistentNameAPI.h"
#include ".\pmepersistentname.h"
#include ".\attr_pme_vertexname.h"

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

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidSweepFeature, PmeStdSolidFeature)

PmeStdSolidSweepFeature::PmeStdSolidSweepFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidSweepFeature::PmeStdSolidSweepFeature(PmePart * pPart,
                                                           PmeReference * pProfileSketch,
                                                           PmeReference * pGuideCurve) 
: PmeStdSolidFeature(pPart)
, m_pProfileSketch(pProfileSketch)
, m_pGuideCurve(pGuideCurve)
{
}

PmeStdSolidSweepFeature::~PmeStdSolidSweepFeature(void)
{
}

BODY * PmeStdSolidSweepFeature::SweepSolid(BODY *& pProfile, BODY *& pGuideCurve)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	sweep_options options;

	BODY * pNewProfile = 0;
	BODY * pNewGuideCurve = 0;

	BODY * pTemp = 0;

	API_BEGIN

		result = api_copy_body(pProfile, pNewProfile);
		check_outcome(result);

		result = api_copy_body(pGuideCurve, pNewGuideCurve);
		check_outcome(result);

		result = api_sweep_with_options(pNewProfile, pNewGuideCurve, &options, pTemp);
		check_outcome(result);

		if(!result.ok())
			return 0;

	API_END

		if(g_bNamingType)       
		{
		
		if(g_bNamingType)
		{AttachName(pResult);} //Toplogy naming 
       	else 
		{AttachVertexName_pointbased(pResult);} //Point-based naming 

		}
	

	api_clear_annotations();

	return pNewProfile;
}

void PmeStdSolidSweepFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);

	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_SWEEP_ANNO_EDGE_LAT);

	annotationListLateral.init();

	SWEEP_ANNO_EDGE_LAT * pAnnotationEdgeLat;

	CString profileSketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();
	CString pathSketchName = PmeSketchUtility::GetSketch(GetGuideCurve())->GetName();

	while((pAnnotationEdgeLat = (SWEEP_ANNO_EDGE_LAT *)annotationListLateral.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);

		if(annotationInputs.count() == 2)
		{            
			EDGE * pProfileEdge = pAnnotationEdgeLat->profile_edge();
			EDGE * pPathEdge = pAnnotationEdgeLat->path_edge();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();
			
			CString profileEdgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pProfileEdge, profileSketchName))->value();
			CString pathEdgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pPathEdge, pathSketchName))->value();
			
			CString faceName = GetName() + "," + profileSketchName + "," + profileEdgeName + "," + pathSketchName + "," + pathEdgeName + ",0,SweepFeature:0,0:0;0";
			new ATTRIB_FACENAME(pFace, faceName);
		}
		else if(annotationInputs.count() > 2)
		{
			//path edge°¡ º¯ÇÕ¿¡ ÀÇÇØ¼­ 2°³ ÀÌ»ó Á¸Àç
			//Ã¹¹øÂ° path edge¸¦ »ç¿ëÇÔ.

			annotationInputs.init();

			EDGE * pProfileEdge = (EDGE *)annotationInputs.next();
			EDGE * pPathEdge = (EDGE *)annotationInputs.next();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

			CString profileEdgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pProfileEdge, profileSketchName))->value();
			CString pathEdgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pPathEdge, pathSketchName))->value();
			
			CString faceName = GetName() + "," + profileSketchName + "," + profileEdgeName + "," + pathSketchName + "," + pathEdgeName + ",0,SweepFeature:0,0:0;0";
			new ATTRIB_FACENAME(pFace, faceName);
		}
	}

	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SWEEP_ANNO_END_CAPS);

	SWEEP_ANNO_END_CAPS	* pAnnotationEndCaps;
	
	annotationListEnd.init();

	while((pAnnotationEndCaps = (SWEEP_ANNO_END_CAPS *)annotationListEnd.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;
		pAnnotationEndCaps->inputs(annotationInputs);		

		ASSERT(annotationInputs.count() == 0);

		FACE * pStartFace = pAnnotationEndCaps->start_face();
		FACE * pEndFace = pAnnotationEndCaps->end_face();

		CString startFaceName = GetName() + ",0,-1,0,0,0,SweepFeature:0,0:0;0";
		CString endFaceName = GetName() + ",0,-2,0,0,0,SweepFeature:0,0:0;0";

		new ATTRIB_FACENAME(pStartFace, startFaceName);
		new ATTRIB_FACENAME(pEndFace, endFaceName);        
	}
}


void PmeStdSolidSweepFeature::AttachVertexName_pointbased(BODY *& pBody)
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

		//Naming POINTS on the SKETCH side of pro-SWEEP
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

						EDGE * e = (EDGE *) edge_list[i]; // ?  

						ver = e->start(); // Getting the starting vertex of all the edges

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
		
		//Naming POINTS on the non-SKETCH side of pro-SWEEP
		FACE * pEndFace = pAnnotationEndCaps->end_face();

		ENTITY_LIST edge_list1; 
		get_edges(pEndFace, edge_list1);

		int b = edge_list1.count();
		VERTEX * ver1;	
	
		
		for (int i = 0 ; i < b; i++)
			{
						double vertexcoord[3];
						CString vertexNum[3];

						EDGE * e = (EDGE *) edge_list1[i]; // ?  

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
	AttachFaceName_pointbased(pBody); // FACE names

}


void PmeStdSolidSweepFeature::AttachRemainingVertexNames_pointbased(BODY *& pBody)
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


//FACES of body are named after PRO/CUT SWEEP
void PmeStdSolidSweepFeature::AttachFaceName_pointbased(BODY *& pBody)
{	
	FACE * ff ;
	ff = pBody->lump()->shell()->face();

	while (ff!= NULL)
	{
		CString faceName;
		ENTITY_LIST lp_list;
		
		api_get_loops(ff, lp_list);
		
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

//After Bolean Operations
BODY * PmeStdSolidSweepFeature::NameNewVertices_ADD_BOL(BODY *& pBody, bool isCut)
{

		Attach_NewVertexNames_pointbased(pBody);
		return pBody;
}

BODY * PmeStdSolidSweepFeature::NameNewVertices_SUB_BOL(BODY *& pBody, bool isCut)
{

		Attach_NewVertexNames_pointbased(pBody);
		return pBody;
}

// Check for newly generated vertices
void PmeStdSolidSweepFeature:: Attach_NewVertexNames_pointbased(BODY *& pBody)

{
	
	ENTITY_LIST edge_list;
	api_get_edges(pBody, edge_list);
	//VERTEX* ver;

	int b;
	b = edge_list.count();
	

	for (int i = 0; i < b; i++)
	{
	//int edgecount=0;
	//CString edgeName[50];


	double vertexcoord[3];
	CString vertexNum[3];

	EDGE * pEdge = (EDGE *) edge_list[i];
	VERTEX* ver;
	ver = pEdge->start();

	//CString edgeName;
	CString edgeName1;
	//CString edgeName2;
	CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();
	//int count = 0;
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

			//int Circular_Element_Count = 0;

			if (location.X() == vertexcoord[0] || location.Y() == vertexcoord[1] || location.Z() == vertexcoord[2])
			{
			
			//PmeStdSketchHDirection * pHDirection = pSketchFeature->GetHDirection();
			//PmeStdSketchVDirection * pVDirection = pSketchFeature->GetVDirection();

			//CString name1 = pHDirection->GetName();
			//CString name2 = pVDirection->GetName();

			//PmeReference Reference = pSketchFeature->GetHDirection();

			for(PmeStdSketchGeometries::SizeType j = 0; j < size; ++ j)
			{
				PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(j);

				
				if (pGeometry->GetType() == PmeStdSketchGeometryType_Line)
				{
					
					//CString edgeName[edgecount] = pGeometry -> GetName();
					//PmeStdSketchLine * pLine = pGeometry->GetType();

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

					//double x = pStartPoint->GetX();
					//double y = pStartPoint->GetY();


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
						if (size != 2 ) //Multiple close-loop/Circular sketch elements
						
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

						else if (size == 2)
						{
						edgeName1 = pGeometry -> GetName();
							
						CString vertexName;

						vertexName = GetName() + "," + sketchName + "," + edgeName1 + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

						new ATTRIB_VERTEXNAME(ver, vertexName);
						}
					}

					

				}
	
			
		}

		else 
		{
		
		CString vertexName;

		vertexName = GetName() + "," + sketchName + ",(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

		new ATTRIB_VERTEXNAME(ver, vertexName);
		//break;
		}

	//count
	}

}
	
	AttachRemainingVertexNames_pointbased(pBody);
	AttachFaceName_pointbased(pBody);
}
