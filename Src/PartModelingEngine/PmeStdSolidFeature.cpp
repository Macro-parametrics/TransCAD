#include "StdAfx.h"
#include ".\pmestdsolidfeature.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeSketchUtility.h"
#include ".\attr_pme_facename.h"
#include ".\attr_pme_vertexname.h"
#include ".\PmeQuery.h"
#include ".\pmepersistentname.h"
#include ".\PmePersistentNameAPI.h"
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#include ".\PmeSketch.h"
#include ".\PmeStdSketchFeature.h"
	
struct FaceBoxPair
{
	FACE * pFace;
	SPAbox pBox;
};

bool UDgreater (FaceBoxPair &elem1, FaceBoxPair &elem2);
double GetHigher(double v1, double v2);


PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidFeature, PmeStdFeature)

PmeStdSolidFeature::PmeStdSolidFeature(PmePart * pPart)
: PmeStdFeature(pPart)
, m_pSolid(0)
{
}

PmeStdSolidFeature::PmeStdSolidFeature(PmePart * pPart, const CString & name)
: PmeStdFeature(pPart, name)
, m_pSolid(0)
{
}

PmeStdSolidFeature::~PmeStdSolidFeature(void)
{
}

BODY * PmeStdSolidFeature::CreateShellFromSketch(PmeReference * pSketch)
{
	BODY ** ppWires = NULL;
	int nWires = 0;

	PmeSketchUtility::CreateWire(pSketch, ppWires, nWires);

	PmeThrowExceptionIf<PmeIlligalOperationException>(nWires == 0);

	ENTITY_LIST wlist;

	for(int i = 0; i < nWires; ++ i)
	{
		outcome isClosed = api_closed_wire(ppWires[i]);

		PmeThrowExceptionIf<PmeIlligalOperationException>(!isClosed.ok());

		wlist.add(ppWires[i]);		
	}

	ACIS_DELETE [] STD_CAST ppWires;

	BODY * pShell = 0;
	ENTITY_LIST outWires;	
	
	MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(pSketch);

	API_BEGIN
		result = api_cover_planar_wires(wlist, pShell, outWires);
		check_outcome(result);

		MrPosition origin = coordinateSystem.Location();
		MrDirection xDir = coordinateSystem.XDirection();
		MrDirection yDir = coordinateSystem.YDirection();		

		SPAtransf spaTransf = coordinate_transf(SPAposition(origin.X(), origin.Y(), origin.Z()),
											  SPAunit_vector(xDir.X(), xDir.Y(), xDir.Z()),
											  SPAunit_vector(yDir.X(), yDir.Y(), yDir.Z()));

		result = api_apply_transf(pShell, spaTransf);
		check_outcome(result);

		// 스케치 요소 이름 체크
		RecoverSketchElementName(pSketch, pShell);

		if(result.ok() && outWires.count() == 0)
			return pShell;

	API_END

	return 0;
}

BODY * PmeStdSolidFeature::CreateWireFromSketch(PmeReference * pSketch)
{
	BODY * pWire = NULL;
	PmeSketchUtility::CreateWire(pSketch, pWire);

	MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(pSketch);

	API_BEGIN
		MrPosition origin = coordinateSystem.Location();
		MrDirection xDir = coordinateSystem.XDirection();
		MrDirection yDir = coordinateSystem.YDirection();		

		SPAtransf spaTransf = coordinate_transf(SPAposition(origin.X(), origin.Y(), origin.Z()),
											  SPAunit_vector(xDir.X(), xDir.Y(), xDir.Z()),
											  SPAunit_vector(yDir.X(), yDir.Y(), yDir.Z()));
		//spaTransf = spaTransf.inverse();

		result = api_apply_transf(pWire, spaTransf);
		check_outcome(result);

		if(result.ok())
			return pWire;

	API_END

	return 0;
}



// Split을 체크하는 부분 (16-07-10 권순조 수정)
void PmeStdSolidFeature::SplitCheck(BODY *& pBody, ENTITY_LIST & old_face_list)
{
	// Get new face list after the operation
	ENTITY_LIST new_face_list;
	get_faces((ENTITY*) pBody, new_face_list);

	// Container for the order of faces which can be candidates of the split faces.
	vector <int> faceOrder;

	// 1. 이름이 소실된 면들의 원래 이름을 복원
	for (int i = 0; i < new_face_list.count(); ++i) 
	{
		FACE * new_f = (FACE*)new_face_list[i];
		ATTRIB_FACENAME * new_att = (ATTRIB_FACENAME*)find_attrib(new_f, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);

		// If a face is geometrically deformed by an operation, it loses its attribute.
		// Therefore, we should find the original face name and add it to the deformed face.
		if (new_att == NULL)
		{
			for (int j = 0; j < old_face_list.count(); j++) 
			{
				FACE * old_f = (FACE*)old_face_list[j];
				
				CString faceName;
				PmePersistentNameAPI::FindFaceName(old_f, faceName);
				
				if (!faceName.IsEmpty())
				{
					// New face (post-edit) and old face (pre-edit) should have the same owner of geomtery pointer.
					if(new_f->geometry()->owner() == old_f->geometry()->owner())
					{
						new ATTRIB_FACENAME(new_f, faceName);
						faceOrder.push_back(i);
						break;
					}

				}
			}
		}		
	}

	// 2. 같은 이름을 갖는 면들을 찾아 Split 정보 추가
	for (int i = 0; i < (int)faceOrder.size(); ++i) 
	{
		ENTITY_LIST split_face_list;
		
		// Candidate face
		// If it has more than two faces with the same name, bounding boxes for the faces will be computed
		FACE * split_f = (FACE*)new_face_list[faceOrder[i]];
	
		CString splitFaceName;
		PmePersistentNameAPI::FindFaceName(split_f, splitFaceName);
		
		int _colon = splitFaceName.Find(":");
		splitFaceName = splitFaceName.Left(_colon); // Basic face name of the split face candidate
		
		for (int j = 0; j < new_face_list.count(); ++j)
		{
			CString faceName;
			PmePersistentNameAPI::FindFaceName((FACE*)new_face_list[j], faceName);

			_colon = faceName.Find(":");
			faceName = faceName.Left(_colon); // Basic face name of a face in new_face_list
	
			if (splitFaceName == faceName)
				split_face_list.add((FACE*)new_face_list[j]);

		}

		// If two or more faces have the same name,
		// Compute bounding boxes for the faces and rename the faces applying SFI(split face information)
		if (split_face_list.count() >= 2)
		{
			ComputeFaceBoundingBox(split_face_list);
		}

	} 

	// 3. 하나의 스케치의 여러 개의 Profile이 있는 경우 구분
	for (int i = 0; i < new_face_list.count(); ++i) 
	{
		ENTITY_LIST split_face_list;
		
		FACE * face1 = (FACE*)new_face_list[i];
		CString faceName1;
		PmePersistentNameAPI::FindFaceName(face1, faceName1);
		
		if (faceName1 != "")
			split_face_list.add(face1);
		else
			continue;

		for (int j = 0; j < new_face_list.count(); ++j) 
		{
			if (i == j)
				continue;
			
			FACE * face2 = (FACE*)new_face_list[j];
			CString faceName2;
			PmePersistentNameAPI::FindFaceName(face2, faceName2);

			if (faceName1 == faceName2)
				split_face_list.add(face2);
		}

		if (split_face_list.count() > 1)
			ComputeFaceBoundingBox(split_face_list);
	}
}

// Merge를 체크하는 부분 (16-07-10 권순조 추가)
void PmeStdSolidFeature::MergeCheck(BODY *& pBody, ENTITY_LIST & face_list1, ENTITY_LIST & face_list2)
{
	// Get new face list after the operation
	ENTITY_LIST new_face_list;
	get_faces((ENTITY*) pBody, new_face_list); 

	vector <int> faceOrder;
	vector <CString> old_face_name_list;

	// Merge된 면을 찾아서 추가
	for (int i = 0; i < face_list1.count(); ++i)
	{
		FACE * old_f = (FACE*)face_list1[i];
		
		// Merge된 면의 경우 새로운 Body에 geometry owner가 없다. 이를 체크하여 추가.
		if (!old_f->geometry()->get_owners(new_face_list))
		{
			faceOrder.push_back(i);
			
			CString faceName;
			PmePersistentNameAPI::FindFaceName(old_f, faceName);
			old_face_name_list.push_back(faceName);
		}
	}
			
	for( int i = 0; i < (int)faceOrder.size(); ++i)
	{
		CString mfaceName = old_face_name_list[i];
		CString mBasicFaceName = mfaceName.Left(mfaceName.Find(":"));
		
		FACE * old_f = (FACE*)face_list2[faceOrder[i]];

		for (int j = 0; j < new_face_list.count(); ++j)
		{
			FACE * new_f = (FACE*)new_face_list[j];

			// Clash test between two faces.
			entity_clash_type clashResult;
			face_clash_options * clashOptions = 0;
			AcisOptions * options = 0;
			outcome result = api_clash_faces(old_f, new_f, clashResult, options);
			//

			// 두 면이 겹치는 경우 Merge로 판단
			if (clashResult == ENTITY_CLASH_COI_INSIDE || clashResult == ENTITY_CLASH_COI_OUTSIDE)
			{
				CString faceName;
				PmePersistentNameAPI::FindFaceName(new_f, faceName);
				
				if (faceName == "")
					continue;

				// Rename the faces according to the MFI
				int _secondColon = faceName.Find(":", faceName.Find(":") + 1);
				
				CString basicFaceNameWithSFI, MFI;
				basicFaceNameWithSFI = faceName.Left(_secondColon);	// Basic Naming with SFI
				
				// Merged Face Information
				char pre_merged_face = faceName.GetAt(_secondColon + 1);
				int pre_merged_face_number = pre_merged_face - '0';

				if (pre_merged_face_number != 0) 
				{
					CString pre_merged_face_name = faceName.Right(faceName.GetLength() - faceName.Find(";"));
					MFI.Format(_T(":%d%s;%s"), pre_merged_face_number + 1, pre_merged_face_name, mBasicFaceName);
				}
				else
					MFI.Format(_T(":%d;%s"), 1, mBasicFaceName);

				CString finalFaceName = basicFaceNameWithSFI + MFI;

				new ATTRIB_FACENAME(new_f, finalFaceName);
			}
		}
	}
}

void PmeStdSolidFeature::CopyFaces(ENTITY_LIST & face_list1, ENTITY_LIST & face_list2)
{
	for (int i = 0; i < face_list1.count(); ++i)
	{
		ENTITY * pCopiedEntity = 0;
		ENTITY * pOriginalEntity = face_list1[i];
		
		api_copy_entity(pOriginalEntity, pCopiedEntity);
		face_list2.add((FACE*)pCopiedEntity);
	}
}

bool PmeStdSolidFeature::CompareEdges(ENTITY_LIST & old_edge_list, ENTITY_LIST & new_edge_list)
{
	// Check if two edge lists contain exactly the same edges
	int count = 0;
	for (int i = 0; i < old_edge_list.count(); ++i)
	{
		EDGE * oldEdge = ((COEDGE*)old_edge_list[i])->edge();
		
		for (int j = 0; j < new_edge_list.count(); ++j)
		{
			EDGE * newEdge = ((COEDGE*)new_edge_list[j])->edge();

			if (oldEdge == newEdge)
			{
				count++;
				break;
			}
		}
	}

	// Return true if the two edge lists are the same
	if (count == old_edge_list.count())
		return true;
	else
		return false;
}

void PmeStdSolidFeature::ComputeFaceBoundingBox(ENTITY_LIST & split_face_list)
{
	// Container for pairs of splt faces and corresponding bounding boxes
	vector <FaceBoxPair> faceBoxes;

	for (int i = 0; i < split_face_list.count(); ++i)
	{
		FACE * pFace = (FACE*)split_face_list[i];
		SPAtransf _tform;
		SPAbox pbox = get_face_box(pFace, & _tform);
		
		FaceBoxPair pair;
		pair.pFace = pFace;
		pair.pBox = pbox;
		
		faceBoxes.push_back(pair);
	}

	// Sort the FaceBoxPair according to the result of comparison.
	sort( faceBoxes.begin(), faceBoxes.end(), UDgreater );


	// Rename the faces according to the SFI
	int current_number = 1;
	int total_number = faceBoxes.size();

	vector<FaceBoxPair>::iterator iter = faceBoxes.begin();
	while(iter != faceBoxes.end())
	{
		FACE * _face = (*iter).pFace;
		ATTRIB_FACENAME * att = (ATTRIB_FACENAME*)find_attrib(_face, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);
		
		int _firstColon = att->GetFaceName().Find(":");
		int _secondColon = att->GetFaceName().Find(":", _firstColon + 1);

		CString basicFaceName, SFI, MFI;
		basicFaceName = att->GetFaceName().Left(_firstColon);		// Basic Naming
		SFI.Format(_T(":%d,%d"), current_number, total_number);	// Split Face Information
		MFI = att->GetFaceName().Right(att->GetFaceName().GetLength() - _secondColon);				// Merged Face Information
		
		CString finalFaceName = basicFaceName + SFI + MFI;

		// Reset the name of face
		att->SetFaceName(finalFaceName);

		iter ++;
		current_number ++;
	}

	faceBoxes.clear();
}

bool UDgreater(FaceBoxPair &elem1, FaceBoxPair &elem2)
{
	double elem1_x, elem2_x, elem1_y, elem2_y,elem1_z, elem2_z;
	elem1_x = GetHigher(elem1.pBox.high().x(), elem1.pBox.low().x());
	elem2_x = GetHigher(elem2.pBox.high().x(), elem2.pBox.low().x());	

	elem1_y = GetHigher(elem1.pBox.high().y(), elem1.pBox.low().y());
	elem2_y = GetHigher(elem2.pBox.high().y(), elem2.pBox.low().y());	

	elem1_z = GetHigher(elem1.pBox.high().z(), elem1.pBox.low().z());
	elem2_z = GetHigher(elem2.pBox.high().z(), elem2.pBox.low().z());	

	// Compare X => Compare Y => Compare Z => Warning
	if(is_greater_than( elem1_x, elem2_x))
		return true;
	else if(is_less_than( elem1_x, elem2_x))
		return false;
	else
	{
		if(is_greater_than( elem1_y, elem2_y))
			return true;
		else if(is_less_than( elem1_y, elem2_y))
			return false;
		else
		{
			if(is_greater_than( elem1_z, elem2_z))
				return true;
			else if(is_less_than( elem1_z, elem2_z))
				return false;
			else
			{
				//cerr<<"\n Bounding Box Comparing Error!! Check\n"; 
				return 0;
			}
		}
	}
}

double GetHigher(double v1, double v2)
{
	if(v1 >= v2) 
		return v1;
	else 
		return v2;
}

// 입력된 pEdge를, 입력받은 coordinateSystem을 기준으로 이동한 후 리턴. 
EDGE * PmeStdSolidFeature::CreateTransformedEdge(EDGE *& pEdge, MrAxis2 & coordinateSystem)
{
	MrPosition origin = coordinateSystem.Location();
	MrDirection XDir = coordinateSystem.XDirection();
	MrDirection YDir = coordinateSystem.YDirection();
	MrDirection ZDir = coordinateSystem.ZDirection();
	
	// 스케치 평면 좌표계로 Edge의 좌표이동
	double sP[3], eP[3];
	
	sP[0] = pEdge->start_pos().x()*(XDir.X()+YDir.X()+ZDir.X()) - origin.X();
	sP[1] = pEdge->start_pos().y()*(XDir.Y()+YDir.Y()+ZDir.Y()) - origin.Y();
	sP[2] = pEdge->start_pos().z()*(XDir.Z()+YDir.Z()+ZDir.Z()) - origin.Z();
	
	eP[0] = pEdge->end_pos().x()*(XDir.X()+YDir.X()+ZDir.X()) - origin.X();
	eP[1] = pEdge->end_pos().y()*(XDir.Y()+YDir.Y()+ZDir.Y()) - origin.Y();
	eP[2] = pEdge->end_pos().z()*(XDir.Z()+YDir.Z()+ZDir.Z()) - origin.Z();
	
	// 구해진 시작점, 끝점을 소수점 14번째에서 반올림한다.
	double digit = pow(10.0, 14);

	for (int i = 0; i < 3; ++i)
	{
		sP[i] = sP[i] * digit;
		eP[i] = eP[i] * digit;
		
		double spRest = sP[i] - floor(sP[i]);
		double epRest = eP[i] - floor(eP[i]);

		if(spRest >= 0.5)
			sP[i] = ceil(sP[i]);
		else
			sP[i] = floor(sP[i]);
		
		if(epRest >= 0.5)
			eP[i] = ceil(eP[i]);
		else
			eP[i] = floor(eP[i]);

		sP[i] /= digit;
		eP[i] /= digit;
	}

	EDGE* pEdge1 = 0;
	api_mk_ed_line(SPAposition(sP[0],sP[1],sP[2]), SPAposition(eP[0],eP[1],eP[2]), pEdge1);

	return pEdge1;
}

// 스케치 요소들이 서로 겹치는 경우 (ex. 겹치는 두 원), Shell 생성 후 Shell을 구성하는 Edge에 부여된 스케치 요소 이름이 소실됨.
// 따라서 Shell을 구성하는 Edge와 매칭되는 기존의 스케치 요소를 찾아 이름을 다시 부여함. (17-02-27 권순조 추가)
void PmeStdSolidFeature::RecoverSketchElementName(PmeReference * pSketch, BODY *& pShell)
{
	// 스케치 특징형상
	PmeSketch * sketch = PmeSketchUtility::GetSketch(pSketch);
	PmeFeature * pFeature = sketch->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);

	// 스케치 이름
	CString sketchName = pSketchFeature->GetName();

	// Shell을 구성하는 Coedge의 시작
	COEDGE * start = pShell->lump()->shell()->face()->loop()->start();
	COEDGE * temp = start;

	do
	{
		int count = 0;

		EDGE * edge = temp->edge();
		
		// 스케치 요소간에 겹치는 부분이 없다면, count는 반드시 1이 됨
		for (int i = 0; i < pSketchFeature->GetEdgeGeometrySize(); ++i)
		{
			if (pSketchFeature->GetEdgeGeometry(i) == edge)
				count ++;
		}

		// count가 1이 아니면 스케치 요소가 겹치는 부분이 발생한 것임
		if (count != 1)
		{
			for (int i = 0; i < pSketchFeature->GetEdgeGeometrySize(); ++i)
			{
				// geometry의 owner가 동일한 edge를 찾아서 해당 이름을 새로운 edge에 다시 부여
				if (pSketchFeature->GetEdgeGeometry(i)->geometry()->owner() == edge->geometry()->owner())
				{
					CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pSketchFeature->GetEdgeGeometry(i), sketchName))->value();
					
					new ATTRIB_GEN_STRING(edge, sketchName, edgeName);
				}
			}
		}

		// 다음 Coedge로 이동
		temp = temp->next();

	}while (temp != start);

	// 체크가 완료되면 목록 비우기
	pSketchFeature->ClearEdgeGeometry();
}