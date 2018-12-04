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

#include ".\pmepersistentname.h"
#include ".\attr_pme_vertexname.h"

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
			AttachName(pNewProfile);
		else
		{
			AttachVertexName_pointbased(pNewProfile);
			AttachFaceName_pointbased(pNewProfile);
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
			//path edge가 변합에 의해서 2개 이상 존재
			//첫번째 path edge를 사용함.

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

			CString vertexName;

			vertexName = "SWEEP1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

			new ATTRIB_VERTEXNAME(ver, vertexName);
		}

	}

}

void PmeStdSolidSweepFeature::AttachFaceName_pointbased(BODY *& pBody)
{	
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

		LOOP *lp1;
		lp1 = lp->next();

		if (lp1 != NULL)
		{	
			COEDGE * ce1;
			ce1 = lp1->start();

			do{	
				pver[edgecount] = ce1->start();
				CString name = PmePersistentName::FindVertexName(pver[edgecount]);

				faceName = faceName +","+ name;			

				edgecount++;
				ce1 = ce1->next();

			}while (ce1 != lp1 ->start());
		}

		CString strNum;
		strNum.Format(_T("%d"),edgecount) ;

		faceName = "FACE," + strNum +","+ faceName;

		new ATTRIB_FACENAME(ff, faceName);
		ff= ff->next();
	}
}
