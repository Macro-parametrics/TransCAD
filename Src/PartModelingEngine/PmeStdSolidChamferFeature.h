#pragma once
#include "pmestdsolidfeature.h"
#include ".\PmeReferences.h"
#include ".\PmeChamferType.h"

class PmeReference;

class PmeStdSolidChamferFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidChamferFeature)
public:
	PmeStdSolidChamferFeature(PmePart * pPart);
	PmeStdSolidChamferFeature(PmePart * pPart,
								PmeChamferType chamferType,
								PmeReferences * pSelectedEdges,
								PmeReference * pSelectedFace,
								double length,
								double value
                                );
	virtual ~PmeStdSolidChamferFeature(void);

	PmeChamferType GetChamferType(void) const {return m_chamferType;}
	PmeReferences * GetSelectedEdges(void) const {return m_pSelectedEdges;}
	PmeReference * GetSelectedFace(void) const {return m_pSelectedFace;}
	double GetLength(void) const {return m_length;}
	double GetValue(void) const {return m_value;}

	SPAposition GetStartPoint(void) const {return m_EdgePoint[0];}
	SPAposition GetEndPoint(void) const {return m_EdgePoint[1];}
	
	SPAposition GetStartPointAt(int index) const {return m_startPoints[index];}
	SPAposition GetEndPointAt(int index) const {return m_endPoints[index];}

	void SetChamferType(PmeChamferType chamferType) {m_chamferType = chamferType;}
	void SetSelectedEdges(PmeReferences * pSelectedEdges) {m_pSelectedEdges = pSelectedEdges->Clone();}
	void SetSelectedFace(PmeReference * pSelectedFace) {m_pSelectedFace = pSelectedFace;}
	void SetLength(double length) {m_length = length;}
	void SetValue(double value) {m_value = value;}	
	void GetChamferFeatureNamefromEdge(CString & tempChamferFeatureName, int order);
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

	void PrintFaceName(ENTITY_LIST face_list);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidChamferFeature;}
	virtual void Update(void);	

protected:
	void AttachName(BODY *& pBody, ENTITY_LIST face_list);
	void AttachAdditionalName(BODY *& pBody);
	void AttachVertexName_pointbased(BODY *& pBody);
	void AttachFaceName_pointbased(BODY *& pBody);
private:
	PmeChamferType m_chamferType;
	PmeReferences * m_pSelectedEdges;
	PmeReference * m_pSelectedFace;
	CString m_ChamferEdgeName[100];
	double m_length;
	double m_value;	
	SPAposition m_EdgePoint[2];
	vector<SPAposition> m_startPoints;
	vector<SPAposition> m_endPoints;
	ENTITY * m_pChamferEdge;
	int m_edgeNumber;
};