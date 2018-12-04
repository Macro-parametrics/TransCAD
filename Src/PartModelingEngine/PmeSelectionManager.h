#pragma once

class PmePart;
class PmeReferences;
class PmeReference;
class PmeExplicitModelObject;
class PmeSolid;
class PmeFeature;
class PmeStdSketchGeometry;

class PmeSelectionManager
{
public:
	PmeSelectionManager(PmePart * pPart);
	~PmeSelectionManager(void);

	PmePart * GetPart(void) const {return m_pPart;}
	PmeReferences * GetReferences(void) const {return m_pReferences;}

	PmeReference * SelectFeatureByName(const CString & name);
	PmeReference * SelectSketchGeometryByName(const CString & name);	// 2009.10.29, Suchul Shin
	PmeReference * SelectObjectByName(const CString & name);
	PmeReference * SelectBrepByName(const CString & persistentName);
	PmeReference * SelectPlaneByAxis(const MrAxis2 & axis);
	PmeReference * SelectCurveBy3Points(const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve);
	PmeReference * SelectCurveByPoint(const MrPosition & pointOnCurve);


	PmeFeature * GetFeatureFromReference(PmeReference * pReference);
	PmeExplicitModelObject * GetObjectFromReference(PmeReference * pReference);
	ENTITY * GetBrepFromReference(PmeReference * pReference);
	PmeStdSketchGeometry * GetSketchGeometryFromReference(PmeReference * pReference);	// 2009.10.29, Suchul Shin

	//Pointbased
	PmeReference * SelectPlaneByPoint(const MrPosition & pointOnFace);
	PmeReference * SelectPlaneByTopoName(const CString & topoName);
	FACE * GetSelectedFaceByPoint(PmeSolid * pSolid, const MrPosition & pointOnFace); 
	//Pointbased

private:
	void ClearReferences(void);	
	FACE * GetNearestFace(PmeSolid * pSolid, const MrAxis2 & srcAxis);
	EDGE * PmeSelectionManager::GetEdgesWith3Points(PmeSolid * pSolid, const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve);
	EDGE * PmeSelectionManager::GetEdgesWithPoint(PmeSolid * pSolid, const MrPosition & pointOnCurve);
private:
	PmePart * m_pPart;
	PmeReferences * m_pReferences;
};
