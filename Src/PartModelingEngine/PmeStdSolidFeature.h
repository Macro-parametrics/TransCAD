#pragma once
#include "pmestdfeature.h"
#include <vector>

using namespace std;

class PmeSolid;
class PmeReference;

class PmeStdSolidFeature : 
	public PmeStdFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidFeature)
public:
	PmeStdSolidFeature(PmePart * pPart);
	PmeStdSolidFeature(PmePart * pPart, const CString & name);
	virtual ~PmeStdSolidFeature(void);

	PmeSolid * GetSolid(void) const {return m_pSolid;}
	void SetSolid(PmeSolid * pSolid) {m_pSolid = pSolid;}

protected:
	BODY * CreateShellFromSketch(PmeReference * pSketch);
	BODY * CreateWireFromSketch(PmeReference * pSketch);
	
	void SplitCheck(BODY *& pBody, ENTITY_LIST & old_face_list);
	//void MergeCheckBeforeOperation(BODY *& pBody, ENTITY_LIST & old_face_list);
	//void MergeCheckAfterOperation(BODY *& pBody, ENTITY_LIST & old_face_list);
	void MergeCheck(BODY *& pBody, ENTITY_LIST & face_list1, ENTITY_LIST & face_list2);
	void CopyFaces(ENTITY_LIST & face_list1, ENTITY_LIST & face_list2);

	void ComputeFaceBoundingBox(ENTITY_LIST & split_face_list);
	bool CompareEdges(ENTITY_LIST & old_edge_list, ENTITY_LIST & new_edge_list);

	EDGE * CreateTransformedEdge(EDGE *& pEdge, MrAxis2 & coordinateSystem);

	void RecoverSketchElementName(PmeReference * pSketch, BODY *& pShell);

private:
    PmeSolid * m_pSolid;
};
