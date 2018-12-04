#include "StdAfx.h"
#include ".\PmeStdSolidCutExtrudeFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketch.h"
#include ".\PmeSketchUtility.h"

#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\attr_pme_vertexname.h"
#include ".\pmepersistentname.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature, PmeStdSolidExtrudeFeature)

PmeStdSolidCutExtrudeFeature::PmeStdSolidCutExtrudeFeature(PmePart * pPart)
: PmeStdSolidExtrudeFeature(pPart)
{
}

PmeStdSolidCutExtrudeFeature::PmeStdSolidCutExtrudeFeature(PmePart * pPart,
                                                                  PmeReference * pProfileSketch,
                                                                  double startDepth,
                                                                  PmeStdExtrudeEndType startCondition,
                                                                  double endDepth,
                                                                  PmeStdExtrudeEndType endCondition,
                                                                  bool isFlip)
: PmeStdSolidExtrudeFeature(pPart, pProfileSketch, startDepth, startCondition, endDepth, endCondition, isFlip)
{
}

PmeStdSolidCutExtrudeFeature::~PmeStdSolidCutExtrudeFeature(void)
{
}

void PmeStdSolidCutExtrudeFeature::Update(void)
{
	SetParentName(GetProfileSketch());
	
	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
	
	BODY * pOldBody = pSolid->GetSolid();

	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);

	ASSERT(pNewBody);

	//
	ENTITY_LIST old_face_list1, old_face_list2, old_face_list3;
	get_faces((ENTITY*) pOldBody, old_face_list1);
	get_faces((ENTITY*) pNewBody, old_face_list2);
	
	CopyFaces(old_face_list2, old_face_list3);
	//

	API_BEGIN
		if(pOldBody)
		{
			result = api_boolean(pNewBody, pOldBody, SUBTRACTION);
			check_outcome(result);
		}
	
		if(result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			pSolid->UpdateSolid(pOldBody);
			SetSolid(pSolid);
		}
	API_END	

	//
	SplitCheck(pOldBody, old_face_list1);
	SplitCheck(pOldBody, old_face_list2);
	MergeCheck(pOldBody, old_face_list2, old_face_list3);
	//
}

void PmeStdSolidCutExtrudeFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
{
	pBody = 0;

	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);

	ASSERT(pNewBody);

	API_BEGIN
        result = api_apply_transf(pNewBody, transformation);
		
		if(result.ok())
			pBody = pNewBody;
		
	API_END
}

bool PmeStdSolidCutExtrudeFeature::IsCut(void)
{
	return true;
}

void PmeStdSolidCutExtrudeFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * pProfile = CreateShellFromSketch(GetProfileSketch());
	PmeThrowExceptionIf<PmeIlligalOperationException>(pProfile == 0);

	BODY * pStartBody = ExtrudeStartSolid(pProfile, true);
	BODY * pEndBody = ExtrudeEndSolid(pProfile, true);

	PmeThrowExceptionIf<PmeIlligalOperationException>(pStartBody == 0 && pEndBody == 0);
	
	API_BEGIN

		if(pStartBody && pEndBody)
		{
			result = api_boolean(pEndBody, pStartBody, UNION);
		}
		else if(pEndBody)
			pStartBody = pEndBody;

		pBody = pStartBody;
	
	API_END
}


void PmeStdSolidCutExtrudeFeature::AttachVertexName_pointbased(BODY *& pBody)
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

			vertexName = "Cut1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

			new ATTRIB_VERTEXNAME(ver, vertexName);
		}
		
	}

}

void PmeStdSolidCutExtrudeFeature::AttachFaceName_pointbased(BODY *& pBody)
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