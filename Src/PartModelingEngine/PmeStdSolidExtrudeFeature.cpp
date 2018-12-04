#include "StdAfx.h"
#include <algorithm>
#include ".\PmeStdSolidExtrudeFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\attr_pme_facename.h"
#include ".\attr_pme_vertexname.h"
#include ".\PmeQuery.h"
#include ".\pmepersistentname.h"
#include ".\PmePersistentNameAPI.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidExtrudeFeature, PmeStdSolidFeature)

PmeStdSolidExtrudeFeature::PmeStdSolidExtrudeFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidExtrudeFeature::PmeStdSolidExtrudeFeature(PmePart * pPart,
                                                           PmeReference * pProfileSketch,
                                                           double startDepth,
                                                           PmeStdExtrudeEndType startCondition,
                                                           double endDepth,
                                                           PmeStdExtrudeEndType endCondition,
														   bool isFlip) 
: PmeStdSolidFeature(pPart)
, m_pProfileSketch(pProfileSketch)
, m_startDepth(startDepth)
, m_startCondition(startCondition)
, m_endDepth(endDepth)
, m_endCondition(endCondition)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
, m_isFlip(isFlip)
{
}

PmeStdSolidExtrudeFeature::~PmeStdSolidExtrudeFeature(void)
{
}

MrDirection PmeStdSolidExtrudeFeature::GetInternalDirection(bool isCut)
{
	MrDirection zDir = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).ZDirection();
	if(isCut)
		zDir = -zDir;

	return zDir;
}

BODY * PmeStdSolidExtrudeFeature::ExtrudeStartSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	switch(GetInternalStartCondition())
	{
	case PmeStdExtrudeEndType_Blind:
		{
			double depth = GetInternalStartDepth();
			if(depth > 0.0)
			{
                MrVector vector = GetInternalDirection(isCut) * depth;
				pResult = ExtrudeWithBlind(pProfile, vector);
			}
		}
		break;
	case PmeStdExtrudeEndType_ThroughAll:
		{
			pResult = ExtrudeWithThroughAll(pProfile, GetInternalDirection(isCut));
		}
		break;
	}

	if(pResult)
	{
		if(g_bNamingType)
			AttachName(pResult); //Topology naming 

		else
		{
			if (isCut == false)
			{
				AttachName_pointbased_1(pResult);
			}
			else
			{
				AttachName_pointbased_2(pResult);
			}
		}
	}

	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidExtrudeFeature::ExtrudeEndSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	switch(GetInternalEndCondition())
	{
	case PmeStdExtrudeEndType_Blind:
		{
			double depth = GetInternalEndDepth();
			if(depth > 0.0)
			{
                MrVector vector = GetInternalDirection(isCut) * depth;
                pResult = ExtrudeWithBlind(pProfile, -vector);
			}
		}
		break;
	case PmeStdExtrudeEndType_ThroughAll:
		{
			pResult = ExtrudeWithThroughAll(pProfile, -GetInternalDirection(isCut));
		}
		break;
	}

	if(pResult)
	{
		if(g_bNamingType)
			AttachName(pResult); //Toplogy naming 
       	else
		{
			if (isCut == false)
			{
				AttachName_pointbased_1(pResult);
			}
			else
			{
				AttachName_pointbased_2(pResult);
			}
		}
	}

	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidExtrudeFeature::ExtrudeWithBlind(BODY *& pProfile, const MrVector & vector)
{
	SPAvector spaVector(vector.X(), vector.Y(), vector.Z());
	sweep_options options;

	BODY * pNewBody = 0;
	BODY * pTemp = 0;

	API_BEGIN

		result = api_copy_body(pProfile, pNewBody);
		check_outcome(result);

		result = api_sweep_with_options(pNewBody, spaVector, &options, pTemp);
		check_outcome(result);

		if(result.ok())
			return pNewBody;

	API_END

	return 0;
}

BODY * PmeStdSolidExtrudeFeature::ExtrudeWithThroughAll(BODY *& pProfile, const MrDirection & direction)
{
	const double infinite = 1.0e7;

	SPAvector spaVector(direction.X(), direction.Y(), direction.Z());
	spaVector *= infinite;
	sweep_options options;

	BODY * pNewBody = 0;
	BODY * pTemp = 0;

	API_BEGIN

		result = api_copy_body(pProfile, pNewBody);
		check_outcome(result);

		result = api_sweep_with_options(pNewBody, spaVector, &options, pTemp);
		check_outcome(result);

		if(result.ok())
			return pNewBody;

	API_END

	return 0;
}

void PmeStdSolidExtrudeFeature::AttachName(BODY *& pBody)
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
		
		// 컷면과 대상면이 정확히 일치할 때 count가 2인 경우가 발생... (16-07-08 권순조)
		if (count != 1)
			continue;
		//ASSERT(annotationInputs.count() == 1);

 		EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
		FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

		CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
		CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,ExtrudeFeature:0,0:0;0";

		new ATTRIB_FACENAME(pFace, faceName);
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

		if(GetFeatureType() == PmeFeatureType_StdSolidProtrusionExtrudeFeature)
		{
			if(MrMath::IsEqual(startNormal, sketchNormal))
				std::swap(pStartFace, pEndFace);
		}
		else
		{
			if(!MrMath::IsEqual(startNormal, sketchNormal))
				std::swap(pStartFace, pEndFace);
		}

		CString startFaceName = GetName() + ",0,-1,0,0,0,ExtrudeFeature:0,0:0;0";
		CString endFaceName = GetName() + ",0,-2,0,0,0,ExtrudeFeature:0,0:0;0";

		if (!m_isFlip) 
		{
			new ATTRIB_FACENAME(pStartFace, startFaceName);
			new ATTRIB_FACENAME(pEndFace, endFaceName);        
		}
		else
		{
			new ATTRIB_FACENAME(pStartFace, endFaceName);
			new ATTRIB_FACENAME(pEndFace, startFaceName);
		}
	}
}


void PmeStdSolidExtrudeFeature::AttachName_pointbased_2(BODY *& pBody)
{	
	// 각 vertex에 이름 주기. 이름 형식 : 피쳐 + 좌표

	ENTITY_LIST edge_list;
	get_edges(pBody, edge_list);

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

		vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
		vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
		vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);

		CString vertexName;

		vertexName = "Cut1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

		new ATTRIB_VERTEXNAME(ver, vertexName);
	}

	// face에 이름 주기 , 점이름 나열.

	FACE * ff ;
	CString faceName;

	ff = pBody->lump()->shell()->face();

	while (ff!= NULL)
	{
		LOOP *lp;
		lp = ff->loop();

		COEDGE * ce;
		ce = lp->start();

		int edgecount=0;
		VERTEX * pver[20];

		do{	
			pver[edgecount] = ce->start();
			CString name = PmePersistentName::FindVertexName(pver[edgecount]);

			if (edgecount == 0 )
				faceName =  name;

			else
				faceName = faceName +","+ name;			

			edgecount++;
			ce = ce->next();

		}while (ce != lp ->start());

		CString strNum;
		strNum.Format(_T("%d"),edgecount) ;

		faceName = "FACE," + strNum +","+ faceName;
		
		new ATTRIB_FACENAME(ff, faceName);
		ff= ff->next();
	}
}

void PmeStdSolidExtrudeFeature::AttachName_pointbased_1(BODY *& pBody)
{	
	// 각 vertex에 이름 주기. 이름 형식 : 피쳐 + 좌표

	ENTITY_LIST edge_list;
	get_edges(pBody, edge_list);
	
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

		vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
		vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
		vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);

		CString vertexName;

		vertexName = "Pad1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

		new ATTRIB_VERTEXNAME(ver, vertexName);
	}
	
	// face에 이름 주기 , 점이름 나열.

	FACE * ff ;
	CString faceName;
	
	ff = pBody->lump()->shell()->face();
	
	while (ff!= NULL)
	{
		LOOP *lp;
		lp = ff->loop();
			
		COEDGE * ce;
		ce = lp->start();

		int edgecount=0;
		VERTEX * pver[20];

		do{	
			pver[edgecount] = ce->start();
			CString name = PmePersistentName::FindVertexName(pver[edgecount]);
			
			if (edgecount == 0 )
				faceName =  name;

			else
				faceName = faceName +","+ name;			

			edgecount++;
			ce = ce->next();

		}while (ce != lp ->start());
		
		CString strNum;
		strNum.Format(_T("%d"),edgecount) ;

		faceName = "FACE," + strNum +","+ faceName;

		
		/*
		do{
			SPAposition s1 = ce ->start_pos();			

			p[3*edgecount] = s1.x();
			p[3*edgecount+1] = s1.y();
			p[3*edgecount+2] = s1.z();

			strNum[3*edgecount].Format(_T("%3.2f"), p[3*edgecount]);
			strNum[3*edgecount+1].Format(_T("%3.2f"), p[3*edgecount+1]);
			strNum[3*edgecount+2].Format(_T("%3.2f"), p[3*edgecount+2]);

			edgecount++;

			ce = ce->next();

		}while (ce != lp ->start());
	
		int a =11;

		if (edgecount == 4)
		{
			faceName =  "FACE ,4, (" + strNum[0] +","+ strNum[1] +","+ strNum[2] +"), ("+ strNum[3] +","+ strNum[4]+","+ strNum[5] +"), ("+
				strNum[6] +","+ strNum[7]+","+ strNum[8] +"), (" + strNum[9] +","+ strNum[10]+","+ strNum[11] +")";
		}

		else if (edgecount == 6)
		{
			faceName =  "FACE ,6, (" + strNum[0] +","+ strNum[1] +","+ strNum[2] +"), ("+ strNum[3] +","+ strNum[4]+","+ strNum[5] +"), ("+
				strNum[6] +","+ strNum[7]+","+ strNum[8] +"), (" + strNum[9] +","+ strNum[10]+","+ strNum[11] +"), ("
				+ strNum[12] +","+ strNum[13]+","+ strNum[14] +"), ("+ strNum[15] +","+ strNum[16]+","+ strNum[17]+")";
		}

		else if (edgecount == 8)
		{
			faceName =  "FACE ,8, (" + strNum[0] +","+ strNum[1] +","+ strNum[2] +"), ("+ strNum[3] +","+ strNum[4]+","+ strNum[5] +"), ("+
				strNum[6] +","+ strNum[7]+","+ strNum[8] +"), (" + strNum[9] +","+ strNum[10]+","+ strNum[11] +"), ("
				+ strNum[12] +","+ strNum[13]+","+ strNum[14] +"), ("+ strNum[15] +","+ strNum[16]+","+ strNum[17]+"), ("
				+ strNum[18] +","+ strNum[19]+","+ strNum[20] +"), ("+ strNum[21] +","+ strNum[22]+","+ strNum[23]+")";
		}		

		else
		{
		
		}*/
		
		new ATTRIB_FACENAME(ff, faceName);
		ff= ff->next();
	}
	

	
	
	/*
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

		ASSERT(annotationInputs.count() == 1);

		EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
		FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

		int Edgenum =0 ;
		
		COEDGE * ce ;
		
		ce = pFace ->loop() ->start();

		while( ce->next() != NULL)
		{
			Edgenum++;
		}

		EDGE * pEdge1 = pFace ->loop() ->start() ->edge(); 
		EDGE * pEdge2 = pFace ->loop() ->start() ->next() ->next() ->edge();

		SPAposition s1 = pEdge1 ->start_pos();
		SPAposition e1 = pEdge1 ->end_pos();

		SPAposition s2 = pEdge2 ->start_pos();
		SPAposition e2 = pEdge2 ->end_pos();


		double p[18];

		p[0] = s1.x();
		p[1] = s1.y();
		p[2] = s1.z();
		p[3] = e1.x();
		p[4] = e1.y();
		p[5] = e1.z();

		p[6] = s2.x();
		p[7] = s2.y();
		p[8] = s2.z();
		p[9] = e2.x();
		p[10] = e2.y();
		p[11] = e2.z();


		//p[12] = (p[0] + p[6]) /2;
		//p[13] = (p[1] + p[7]) /2;
		//p[14] = (p[2] + p[8]) /2;


		CString strNum1;
		strNum1.Format(_T("%3.2f"), p[0]);

		CString strNum2;
		strNum2.Format(_T("%3.2f"), p[1]);

		CString strNum3;
		strNum3.Format(_T("%3.2f"), p[2]);

		CString strNum4;
		strNum4.Format(_T("%3.2f"), p[3]);

		CString strNum5;
		strNum5.Format(_T("%3.2f"), p[4]);

		CString strNum6;
		strNum6.Format(_T("%3.2f"), p[5]);

		CString strNum7;
		strNum7.Format(_T("%3.2f"), p[6]);

		CString strNum8;
		strNum8.Format(_T("%3.2f"), p[7]);

		CString strNum9;
		strNum9.Format(_T("%3.2f"), p[8]);

		CString strNum10;
		strNum10.Format(_T("%3.2f"), p[9]);

		CString strNum11;
		strNum11.Format(_T("%3.2f"), p[10]);

		CString strNum12;
		strNum12.Format(_T("%3.2f"), p[11]);


		CString faceName =  "FACE ,((" + strNum1 +","+ strNum2 +","+ strNum3 +"), ("+ strNum4 +","+ strNum5+","+ strNum6 +"), ("+
			strNum7 +","+ strNum8+","+ strNum9 +"), (" + strNum10 +","+ strNum11+","+ strNum12 +"))";


		//CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
		//CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,ExtrudeFeature:0,0:0;0";

		new ATTRIB_FACENAME(pFace, faceName);
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

		EDGE * pEdge1 = pStartFace ->loop() ->start() ->edge(); 
		EDGE * pEdge2 = pStartFace ->loop() ->start() ->next() ->next() ->edge();

		EDGE * pEdge3 = pEndFace ->loop() ->start() ->edge(); 
		EDGE * pEdge4 = pEndFace ->loop() ->start() ->next() ->next() ->edge();


		SPAposition ss1 = pEdge1 ->start_pos();
		SPAposition se1 = pEdge1 ->end_pos();

		SPAposition ss2 = pEdge2 ->start_pos();
		SPAposition se2 = pEdge2 ->end_pos();


		SPAposition es1 = pEdge3 ->start_pos();
		SPAposition ee1 = pEdge3 ->end_pos();

		SPAposition es2 = pEdge4 ->start_pos();
		SPAposition ee2 = pEdge4 ->end_pos();


		//MrDirection startNormal = PmeQueryFaceNormal(pStartFace, sketchOrigin);
		//MrDirection endNormal = PmeQueryFaceNormal(pEndFace, sketchOrigin);

		//if(MrMath::IsEqual(startNormal, sketchNormal))
		//{
			//std::swap(pStartFace, pEndFace);
		//}


		double sp[18];
		double ep[18];
		

		sp[0] = ss1.x();
		sp[1] = ss1.y();
		sp[2] = ss1.z();
		sp[3] = se1.x();
		sp[4] = se1.y();
		sp[5] = se1.z();

		sp[6] = ss2.x();
		sp[7] = ss2.y();
		sp[8] = ss2.z();
		sp[9] = se2.x();
		sp[10] = se2.y();
		sp[11] = se2.z();


		sp[12] = (sp[0] + sp[6]) /2;
		sp[13] = (sp[1] + sp[7]) /2;
		sp[14] = (sp[2] + sp[8]) /2;

		ep[0] = es1.x();
		ep[1] = es1.y();
		ep[2] = es1.z();
		ep[3] = ee1.x();
		ep[4] = ee1.y();
		ep[5] = ee1.z();

		ep[6] = es2.x();
		ep[7] = es2.y();
		ep[8] = es2.z();
		ep[9] = ee2.x();
		ep[10] = ee2.y();
		ep[11] = ee2.z();


		ep[12] = (ep[0] + ep[6]) /2;
		ep[13] = (ep[1] + ep[7]) /2;
		ep[14] = (ep[2] + ep[8]) /2;
		

		CString strNum4;
		strNum4.Format(_T("%f"), sp[12]);

		CString strNum5;
		strNum5.Format(_T("%f"), sp[13]);

		CString strNum6;
		strNum6.Format(_T("%f"), sp[14]);

		CString strNum7;
		strNum7.Format(_T("%f"), ep[12]);

		CString strNum8;
		strNum8.Format(_T("%f"), ep[13]);

		CString strNum9;
		strNum9.Format(_T("%f"), ep[14]);


		//CString startFaceName = GetName() + ",0,-1,0,0,0,ExtrudeFeature:0,0:0;0";
		CString startFaceName = "FACE ,(" + strNum4 +","+ strNum5 +","+ strNum6 +")";
		CString endFaceName = "FACE ,(" + strNum7 +","+ strNum8 +","+ strNum9 +")";

		new ATTRIB_FACENAME(pStartFace, startFaceName);
		new ATTRIB_FACENAME(pEndFace, endFaceName);        
	}*/
}