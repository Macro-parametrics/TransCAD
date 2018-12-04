#pragma once
#include "pmestdsolidfeature.h"
#include ".\PmeReferences.h"
#include ".\PmePropagationType.h"
//#include "IPmePattern.h"

class PmeReference;

class PmeStdSolidFilletConstantFeature :
	public PmeStdSolidFeature
	//,public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)
public:

	PmeStdSolidFilletConstantFeature(PmePart * pPart);
	PmeStdSolidFilletConstantFeature(PmePart * pPart,
								PmeReferences * pFilletEdges,
								double radius,
                                PmePropagationType propagation);
	virtual ~PmeStdSolidFilletConstantFeature(void);

	PmeReferences * GetFilletEdges(void) const {return m_pFilletEdges;}
	double GetRadius(void) const {return m_radius;}
	PmePropagationType GetPropagation(void) const {return m_propagation;}

	SPAposition GetStartPoint(void) const {return m_EdgePoint[0];}
	SPAposition GetEndPoint(void) const {return m_EdgePoint[1];}

	SPAposition GetStartPointAt(int index) const {return m_startPoints[index];}
	SPAposition GetEndPointAt(int index) const {return m_endPoints[index];}


	void SetFilletEdges(PmeReferences * pFilletEdges) {m_pFilletEdges = pFilletEdges->Clone();}
	void SetRadius(double radius) {m_radius = radius;}
	void SetPropagation(PmePropagationType propagation) {m_propagation = propagation;}
	void GetFilletFeatureNamefromEdge(CString & tempFilletFeatureName, int order);
	void GetElementsfromFaceName(CString faceName, CString & tempElementsName);


	bool IsFacesSame(FACE* pFace1, FACE* pFace2);
	bool IsEdgesSame(EDGE* pEdge1, EDGE* pEdge2);
	bool IsVerticesSame(VERTEX* pVertex1, VERTEX* pVertex2);
	bool IsFaceContainEdge(FACE* pFace, EDGE* pEdge);
	bool IsFaceContainVertex(FACE* pFace, VERTEX* pVertex);
	void InsertFace(FACE* pCurrentFace, FACE* pInsertedFace, ENTITY_LIST & face_list);
	void GetSurroundindFacesofFace(FACE* pFace, BODY* pBody, ENTITY_LIST & face_list);
	void InsertFace(FACE* pInsertedFace, ENTITY_LIST& face_list);
	void GetSurroundindFacesofVertex(VERTEX* pVertex, ENTITY_LIST entire_face_list, ENTITY_LIST & face_list);
	void GetSurroundingFaceofEdge(EDGE* pEdge, BODY* pBody, ENTITY_LIST & face_list);
	void FindFaceNamefromOldFaceList(FACE* pFace, ENTITY_LIST old_face_list, CString & faceName);
	void FindFaceNamefromOldFaceList2(FACE* pFace, ENTITY_LIST old_face_list, CString & faceName);
	void RecoverOriginalFaceName(ENTITY_LIST face_list, ENTITY_LIST old_face_list);


	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidFilletConstantFeature;}
	virtual void Update(void);	
	
	// IPmePattern
	//virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	//virtual bool IsCut(void);
	//void CreateSolidBody(BODY *& pBody);

protected:
	void AttachName(BODY *& pBody,  ENTITY_LIST old_face_list);
	void AttachAdditionalName(BODY *& pBody);
	void AttachVertexName_pointbased(BODY *& pBody);
	void AttachFaceName_pointbased(BODY *& pBody);

private:
	PmeReferences * m_pFilletEdges;
	double m_radius;
	PmePropagationType m_propagation;
	SPAposition m_EdgePoint[2];
	vector<SPAposition> m_startPoints;
	vector<SPAposition> m_endPoints;

	CString m_FilletEdgeName[100];
	int m_edgeNumber;

};