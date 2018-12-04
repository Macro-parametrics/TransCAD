#include "StdAfx.h"
#include <algorithm>
#include ".\PmeStdSolidFilletConstantFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmePersistentNameAPI.h"
#include <acistype.hxx>

#include ".\attr_pme_vertexname.h"
#include ".\pmepersistentname.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature, PmeStdSolidFeature)

PmeStdSolidFilletConstantFeature::PmeStdSolidFilletConstantFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidFilletConstantFeature::PmeStdSolidFilletConstantFeature(
	PmePart * pPart,
    PmeReferences * pFilletEdges,
	double radius,
    PmePropagationType propagation) 
: PmeStdSolidFeature(pPart)
, m_radius(radius)
, m_propagation(propagation)
{
	m_pFilletEdges = pFilletEdges->Clone();
	ENTITY_LIST filletEdges = m_pFilletEdges->CreateEdgeList();

	m_edgeNumber = filletEdges.count();
	
	for (int i = 0; i < filletEdges.count(); ++i)
	{
		//// 엣지를 Transform 한 후 저장 (16-11-23 권순조 최종)
		EDGE * filletEdge = (EDGE*)filletEdges[i];

		SPAposition sP = filletEdge->start_pos();
		SPAposition eP = filletEdge->end_pos();

		// Transform 이 발생한 경우 진입
		if (filletEdge->coedge()->loop()->face()->shell()->lump()->body()->transform())
		{
			SPAtransf transform = filletEdge->coedge()->loop()->face()->shell()->lump()->body()->transform()->transform();
			sP *= transform;
			eP *= transform;
		}
		////

		PmePersistentNameAPI::FindEdgeName(filletEdge, m_FilletEdgeName[i]);

		if (i == 0)
		{
			m_EdgePoint[0] = sP;
			m_EdgePoint[1] = eP;		
		}

		m_startPoints.push_back(sP);
		m_endPoints.push_back(eP);
	}
}

PmeStdSolidFilletConstantFeature::~PmeStdSolidFilletConstantFeature(void)
{
	if(m_pFilletEdges)
		delete m_pFilletEdges;
	
	m_pFilletEdges = 0;
}

void PmeStdSolidFilletConstantFeature::Update(void)
{
	SetParentName(m_pFilletEdges);
	
	api_set_int_option("annotations", TRUE);
	
	ENTITY_LIST filletEdges = m_pFilletEdges->CreateEdgeList();

	double radius = GetRadius();

	PmeThrowExceptionIf<PmeIlligalOperationException>(filletEdges.count() == 0);
	PmeThrowExceptionIf<PmeIlligalOperationException>(radius <= 0);	
	
	PmePart * pPart = GetPart();
	BODY * pBody = pPart->GetExplicitModel()->GetSolid()->GetSolid();
	
	ENTITY_LIST face_list;

	for (int i = 0; i < filletEdges.count(); ++i)
	{
		EDGE* filletEdge = (EDGE*) filletEdges[i];
		GetSurroundingFaceofEdge((EDGE*) filletEdge, pBody, face_list);
	}
	
	API_BEGIN
		result = api_blend_edges(filletEdges, radius);
		
		if (!result.ok())
			TRACE(result.get_error_info()->error_message());
		
		check_outcome(result);
		
		if(result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			SetSolid(pSolid);
		}

	API_END
		
	if(g_bNamingType)
		AttachName(pBody, face_list);
	else
	{
		AttachVertexName_pointbased(pBody);
		AttachFaceName_pointbased(pBody);
	}
	
	api_clear_annotations();
}

/*
void PmeStdSolidFilletConstantFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
{
	ENTITY_LIST edges;
	ENTITY_LIST filletEdges;

	api_get_edges(pBody, edges);

	for (int i = 0; i < edges.count(); ++i)
	{
		EDGE * pEdge = (EDGE *)edges[i];

		for (int j = 0; j < m_pFilletEdges->GetSize(); ++j)
		{
			if (pEdge->start_pos() == m_startPoints[j] && pEdge->end_pos() == m_endPoints[j])
				filletEdges.add(pEdge);
		}
	}

	if (filletEdges.count() > 0)
	{
		api_set_int_option("annotations", TRUE);

		ENTITY_LIST face_list;

		for (int i = 0; i < filletEdges.count(); ++i)
		{
			EDGE * filletEdge = (EDGE *)filletEdges[i];
			GetSurroundingFaceofEdge((EDGE *)filletEdge, pBody, face_list);
		}
	
		API_BEGIN
			result = api_blend_edges(filletEdges, GetRadius());
		
			if (!result.ok())
				TRACE(result.get_error_info()->error_message());
		
			check_outcome(result);
		API_END
		
		if(g_bNamingType)
			AttachName(pBody, face_list);
		else
		{
			AttachVertexName_pointbased(pBody);
			AttachFaceName_pointbased(pBody);
		}

		api_clear_annotations();
	}
}
*/

// 권순조 수정
void PmeStdSolidFilletConstantFeature::AttachName(BODY *& pBody, ENTITY_LIST old_face_list) 
{
	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_BLEND_ANNO_EDGE);

	annotationListLateral.init();

	BLEND_ANNO_EDGE * pAnnotationEdge;

	ENTITY_LIST filletedFaces;

	while((pAnnotationEdge = (BLEND_ANNO_EDGE *)annotationListLateral.next()) != NULL)
	{
		FACE * pFilletFace = (FACE *)pAnnotationEdge->blend_face();

		CString faceName;
        PmePersistentNameAPI::FindFaceName(pFilletFace, faceName);

		if (faceName == "")
		{
			ENTITY_LIST face_list;
			GetSurroundindFacesofFace(pFilletFace, pBody, face_list);
			RecoverOriginalFaceName(face_list, old_face_list);

			CString pFilletFeatureName;
			
			if (m_edgeNumber == 1)
			{
				GetFilletFeatureNamefromEdge(pFilletFeatureName, 0);
				pFilletFeatureName = GetName() + "," + pFilletFeatureName + "FilletFeature:0,0:0;0";
				
				new ATTRIB_FACENAME(pFilletFace, pFilletFeatureName);
			}
			else
			{
				for (int i = 0; i < m_edgeNumber; ++i)
				{
					int count = 0;

					for (int j = 0; j < face_list.count(); ++j)
					{
						FACE * pFace = (FACE *)face_list[j];
						
						CString faceName;
						PmePersistentNameAPI::FindFaceName(pFace, faceName);
						
						if (faceName == "")
							continue;
						else
						{
							if (m_FilletEdgeName[i].Find(faceName) != -1)
								count ++;
						}
					}

					if (count == 2)
					{
						GetFilletFeatureNamefromEdge(pFilletFeatureName, i);
						pFilletFeatureName = GetName() + "," + pFilletFeatureName + "FilletFeature:0,0:0;0";
						
						new ATTRIB_FACENAME(pFilletFace, pFilletFeatureName);
					}
				}
			}
		}

		filletedFaces.add(pFilletFace);
	}

	AttachAdditionalName(pBody);

	for (int i = 0; i < filletedFaces.count(); ++i)
		PmeFeatureTagMarker::Attach((FACE*)filletedFaces[i], this);
}

// 3개 이상 필렛이 겹쳐진 곳에 생기는 면의 네이밍 (16-08-05 권순조 추가)
void PmeStdSolidFilletConstantFeature::AttachAdditionalName(BODY *& pBody)
{
	ENTITY_LIST face_list;
	get_faces(pBody, face_list);

	for (int i = 0; i < face_list.count(); ++i)
	{
		FACE * pFace = (FACE *)face_list[i];

		CString faceName;
        PmePersistentNameAPI::FindFaceName(pFace, faceName);

		if (faceName == "")
		{
			ENTITY_LIST surr_face_list;
			GetSurroundindFacesofFace(pFace, pBody, surr_face_list);
			
			vector<CString> elementNames;

			for (int j = 0; j < surr_face_list.count(); ++j)
			{
				FACE * pSurrFace = (FACE *)surr_face_list[j];

				CString surrFaceName;
				PmePersistentNameAPI::FindFaceName(pSurrFace, surrFaceName);
				
				if (surrFaceName != "")
				{
					int prev, next;
					CString s1, s2, temp;

					prev = 0;
					next = surrFaceName.Find(_T(','), prev);

					for (int k = 0; k < 2; ++k)
					{
						prev = next + 1;
						next = surrFaceName.Find(_T(','), prev);
						s1 = surrFaceName.Mid(prev, next - prev);

						prev = next + 1;
						next = surrFaceName.Find(_T(','), prev);
						s2 = surrFaceName.Mid(prev, next - prev);
						temp = s1 + "," + s2;
								
						int count = 0;
						for (int l = 0; l < (int)elementNames.size(); ++l)
						{
							if (elementNames[l] == temp)
								count++;
						}

						if (count == 0)
							elementNames.push_back(temp);
					}
				}
			}
			
			CString name;

			for (int j = 0; j < (int)elementNames.size(); ++j)
				name = name + elementNames[j] + ",";

			name = GetName() + ","+ name + "FilletFeature:0,0:0;0";
			new ATTRIB_FACENAME(pFace, name);

			PmeFeatureTagMarker::Attach(pFace, this);
		}
	}
}

// 권순조 추가
void PmeStdSolidFilletConstantFeature::RecoverOriginalFaceName(ENTITY_LIST face_list, ENTITY_LIST old_face_list)
{
	// 필렛 후에 이름을 소실한 주변 면들의 이름 복원
	for(int i = 0; i < face_list.count(); ++i)
	{
		FACE * pFace = (FACE *)face_list[i];
		
		CString faceName;
		PmePersistentNameAPI::FindFaceName(pFace, faceName);
		
		if(faceName == "")
		{
			//FindFaceNamefromOldFaceList(pFace, old_face_list, faceName); //이전 방법. 코디네이트를 활용
			FindFaceNamefromOldFaceList2(pFace, old_face_list, faceName); //업데이트. ACIS 내부 자료구조 활용. 정확.
			new ATTRIB_FACENAME(pFace, faceName);
		}
	}
}

void PmeStdSolidFilletConstantFeature::GetFilletFeatureNamefromEdge(CString & tempFilletFeatureName, int order)
{
	int prev = 0;
	int next = 0;
	next = m_FilletEdgeName[order].Find(_T('#'), prev);

	CString faceName1 = m_FilletEdgeName[order].Mid(prev, next - prev);

	prev = next+1;
	next = m_FilletEdgeName[order].GetLength();        ///// number of # is 2
	//next = m_FilletEdgeName.Find(_T('#'),prev);      ///// number of # is 3

	CString faceName2 = m_FilletEdgeName[order].Mid(prev, next - prev);

	TRACE("face1 : %s \n", faceName1);
	TRACE("face2 : %s \n", faceName2);

	CString tempElementsName1, tempElementsName2;
	GetElementsfromFaceName(faceName1, tempElementsName1);
	GetElementsfromFaceName(faceName2, tempElementsName2);

	tempFilletFeatureName = tempElementsName1 + "," + tempElementsName2 + ",0,";
}

void PmeStdSolidFilletConstantFeature::GetElementsfromFaceName(CString faceName, CString & tempElementsName)
{
	int prev = 0;
	int next = 0;
	next = faceName.Find(_T(','), prev);

	CString s1 = faceName.Mid(prev, next - prev);

	prev = next+1;
	next = faceName.Find(_T(','), prev);
	prev = next+1;
	next = faceName.Find(_T(','), prev);
	CString s2 = faceName.Mid(prev, next - prev);

	tempElementsName = s1 + "," + s2;

	TRACE("333: %s \n", tempElementsName);
}

void PmeStdSolidFilletConstantFeature::GetSurroundindFacesofFace(FACE * pFace, BODY * pBody, ENTITY_LIST & face_list)
{
	ENTITY_LIST f_list;
	ENTITY_LIST e_list;
	ENTITY_LIST tmp_face_list;
	get_faces(pBody, f_list);
	get_edges(pFace, e_list);

	for(int i = 0; i < e_list.count(); i++)
	{
		EDGE * pE = (EDGE *)e_list[i];
		
		for(int j = 0; j < f_list.count(); j++)
		{
			FACE * pF = (FACE *)f_list[j];
			
			bool flag = false;
			flag = IsFaceContainEdge(pF, pE);

			if(flag == true)
				InsertFace(pFace, pF, tmp_face_list);
		}
	}

	for(int k = 0; k < tmp_face_list.count(); k++)
	{
		face_list.add(tmp_face_list[k]);
	}

	TRACE("Surrounding Faces of FACE are : %d \n", tmp_face_list.count());
}

void PmeStdSolidFilletConstantFeature::GetSurroundingFaceofEdge(EDGE * pEdge, BODY * pBody, ENTITY_LIST & face_list)
{
	VERTEX * startVertex = pEdge->start();
	VERTEX * endVertex = pEdge->end();

	ENTITY_LIST f_list;
	get_faces(pBody, f_list);

	ENTITY_LIST tmp_face_list;

	if(IsVerticesSame(startVertex, endVertex))
	{
		GetSurroundindFacesofVertex(startVertex,f_list, tmp_face_list);
	}
	else
	{
		GetSurroundindFacesofVertex(startVertex, f_list, tmp_face_list);
		GetSurroundindFacesofVertex(endVertex, f_list, tmp_face_list);
	}

	for(int i = 0; i < tmp_face_list.count(); i++)
	{
		face_list.add(tmp_face_list[i]);
	}

    TRACE("Surrounding Faces of EDGE are : %d \n", tmp_face_list.count());
}

void PmeStdSolidFilletConstantFeature::GetSurroundindFacesofVertex(VERTEX * pVertex, ENTITY_LIST entire_face_list, ENTITY_LIST & face_list)
{
	for(int i = 0; i < entire_face_list.count(); i++)
	{
		FACE * pFace = (FACE *)entire_face_list[i];
		
		if(IsFaceContainVertex(pFace, pVertex))
			InsertFace(pFace, face_list);
	}
}

bool PmeStdSolidFilletConstantFeature::IsFaceContainVertex(FACE * pFace, VERTEX * pVertex)
{
	ENTITY_LIST vertex_list;
	get_vertices(pFace, vertex_list);

	bool flag = false;
	
	for (int i = 0; i < vertex_list.count(); i++)
	{
		VERTEX * pV = (VERTEX *)vertex_list[i];
		
		if(IsVerticesSame(pV, pVertex))
			flag = true;
	}

	if(flag == true)
		return true;
	else
		return false;
}

void PmeStdSolidFilletConstantFeature::InsertFace(FACE * pInsertedFace, ENTITY_LIST& face_list)
{
	if(face_list.count() == 0)
	{
		face_list.add(pInsertedFace);
	}
	else
	{
		bool flag = false;

		for(int i = 0; i < face_list.count(); i++)
		{
			FACE * pFace = (FACE *)face_list[i];
			
			if (IsFacesSame(pFace, pInsertedFace))
				flag = true;
		}

		if(flag == false)
			face_list.add(pInsertedFace);
	}
}


bool PmeStdSolidFilletConstantFeature::IsFaceContainEdge(FACE * pFace, EDGE * pEdge)
{
	ENTITY_LIST e_list;

	get_edges(pFace, e_list);

	bool flag = false;

	for(int i = 0; i < e_list.count(); i++)
	{
		EDGE * pE = (EDGE *)e_list[i];
		
		if(IsEdgesSame(pEdge, pE))		
		{
			flag = true;
		}
	}

	if(flag == true)
		return true;
	else
		return false;
}

bool PmeStdSolidFilletConstantFeature::IsEdgesSame(EDGE * pEdge1, EDGE * pEdge2)
{
	if(pEdge1->start_pos().x() == pEdge2->start_pos().x() 
		&& pEdge1->start_pos().y() == pEdge2->start_pos().y() 
		&& pEdge1->start_pos().z() == pEdge2->start_pos().z() 
		&& pEdge1->end_pos().x() == pEdge2->end_pos().x() 
		&& pEdge1->end_pos().y() == pEdge2->end_pos().y() 
		&& pEdge1->end_pos().z() == pEdge2->end_pos().z() 
		)
	{  
		return true;
	}
	else if(pEdge1->start_pos().x() == pEdge2->end_pos().x() && 
		pEdge1->start_pos().y() == pEdge2->end_pos().y() &&
		pEdge1->start_pos().z() == pEdge2->end_pos().z() &&
		pEdge1->end_pos().x() == pEdge2->start_pos().x() &&
		pEdge1->end_pos().y() == pEdge2->start_pos().y() &&
		pEdge1->end_pos().z() == pEdge2->start_pos().z())
	{  
		return true;
	}
	else 
	{
		return false;
	}
}

bool PmeStdSolidFilletConstantFeature::IsVerticesSame(VERTEX * pVertex1, VERTEX * pVertex2)
{
	SPAposition p1,p2;
	p1 = pVertex1->geometry()->coords();
	p2 = pVertex2->geometry()->coords();

	if((p1.x() == p2.x()) && (p1.y() == p2.y()) && (p1.z() == p2.z()))
		return true;
	else
		return false;
}

void PmeStdSolidFilletConstantFeature::InsertFace(FACE * pCurrentFace, FACE * pInsertedFace, ENTITY_LIST & face_list)
{
	bool flag = false;

	flag = IsFacesSame(pCurrentFace, pInsertedFace);

	for(int i = 0; i < face_list.count(); i++)
	{
		FACE * pFace = (FACE *)face_list[i];
		
		if(IsFacesSame(pFace, pInsertedFace))
			flag = true;
	}
	
	if (flag == true)
		return;
	else if (flag == false)
		face_list.add(pInsertedFace);
}

bool PmeStdSolidFilletConstantFeature::IsFacesSame(FACE * pFace1, FACE * pFace2)
{
	ENTITY_LIST edge_list1;
	ENTITY_LIST edge_list2;

	get_edges(pFace1, edge_list1);
	get_edges(pFace2, edge_list2);

	int num_edges_face1 = edge_list1.count();
	int num_edges_face2 = edge_list2.count();

	int num_sameEdge = 0;

	if (num_edges_face1 != num_edges_face2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < num_edges_face1; i++)
		{
			EDGE * pEdge1 =  (EDGE *)edge_list1[i];

			for (int j = 0; j < num_edges_face2; j++)
			{
				EDGE * pEdge2 =  (EDGE *)edge_list2[j];

				if (IsEdgesSame(pEdge1, pEdge2))
					num_sameEdge++;
			}
		}

		if(num_sameEdge == num_edges_face1)
			return true;
		else 
			return false;
	}
}

void PmeStdSolidFilletConstantFeature::FindFaceNamefromOldFaceList(FACE * pFace, ENTITY_LIST old_face_list, CString & faceName)
{
	ENTITY_LIST filletEdges = m_pFilletEdges->CreateEntityList();
	EDGE * filletEdge = (EDGE *)filletEdges.first();

	if(is_linear_edge((ENTITY *)filletEdge))
	{
		ENTITY_LIST vertex_list1;
		get_vertices(pFace, vertex_list1);
		
		for(int i = 0; i < old_face_list.count(); i++)
		{
			FACE * pF = (FACE *)old_face_list[i];

			int num = 0;
			ENTITY_LIST vertex_list2;
			get_vertices(pF, vertex_list2);
			
			for(int j = 0; j < vertex_list2.count(); j++)
			{
				VERTEX * pV2 = (VERTEX *)vertex_list2[j];
				
				for(int k = 0; k < vertex_list1.count(); k++)
				{
					VERTEX * pV1 = (VERTEX *)vertex_list1[k];
					
					if(IsVerticesSame(pV1, pV2))
						num++;
				}
			}

			if(num > 2)
				PmePersistentNameAPI::FindFaceName(pF, faceName);
		}
	}
	else 
	{
		if(is_planar_face(pFace))
		{
			for(int i = 0; i < old_face_list.count(); i++)
			{
				FACE * pF = (FACE *)old_face_list[i];
	
				if(is_planar_face(pF))
				{  
					PmePersistentNameAPI::FindFaceName(pF, faceName);
					break;
				}
			}
		}
		else if(is_cylindrical_face(pFace))
		{
			for(int i = 0; i < old_face_list.count(); i++)
			{
				FACE * pF = (FACE *)old_face_list[i];

				if(is_cylindrical_face(pF))
				{  
					PmePersistentNameAPI::FindFaceName(pF, faceName);
					break;
				}
			}
		}
	}
}

// 권순조 추가
void PmeStdSolidFilletConstantFeature::FindFaceNamefromOldFaceList2(FACE * pFace, ENTITY_LIST old_face_list, CString & faceName)
{
	for (int j = 0; j < old_face_list.count(); j++) 
	{
		FACE * oldface = (FACE*)old_face_list[j];
				
		// New face (post-edit) and old face (pre-edit) should have the same owner of geomtery pointer.
		if(pFace->geometry()->owner() == oldface->geometry()->owner()){

			PmePersistentNameAPI::FindFaceName(oldface, faceName);
			break;
		}
	}
}

void PmeStdSolidFilletConstantFeature::AttachVertexName_pointbased(BODY *& pBody)
{	
	ENTITY_LIST edge_list;
	get_edges(pBody, edge_list);

	int a = edge_list.count();
	VERTEX * ver;
	
	for (int i = 0; i < a; i++)
	{
		double vertexcoord[3];
		CString vertexNum[3];

		EDGE * e = (EDGE *)edge_list[i];

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

			vertexName = "Fillet1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] + ")";

			new ATTRIB_VERTEXNAME(ver, vertexName);
		}
	}	
}

void PmeStdSolidFilletConstantFeature::AttachFaceName_pointbased(BODY *& pBody)
{	
	FACE * ff;
	CString faceName;

	ff = pBody->lump()->shell()->face();
	
	while (ff != NULL)
	{
		LOOP * lptest;
		lptest = ff->loop() ->next();

		if (lptest == NULL)
		{	
			LOOP * lp;
			lp = ff->loop();

			COEDGE * ce;
			ce = lp->start();
			
			int edgecount=0;
			VERTEX * pver[20];

			do
			{	
				pver[edgecount] = ce->start();
				CString name = PmePersistentName::FindVertexName(pver[edgecount]);

				if (edgecount == 0)
					faceName = name;
				else
					faceName = faceName +","+ name;			

				edgecount++;
				ce = ce->next();

			}while (ce != lp->start());	

			CString strNum;
			strNum.Format(_T("%d"),edgecount) ;

			faceName = "FACE," + strNum +","+ faceName;

			new ATTRIB_FACENAME(ff, faceName);
		}

		ff= ff->next();
	}
}