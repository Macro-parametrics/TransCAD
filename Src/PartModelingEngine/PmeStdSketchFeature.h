#pragma once
#include ".\PmeStdFeature.h"

class PmeStdSketchGeometries;
class PmeStdSketchConstraints;
class PmeStdSketchOrigin;
class PmeStdSketchHDirection;
class PmeStdSketchVDirection;
class PmeStdSketchGeometry;
class PmeStdSketchConstraint;
class PmePart;
class PmeReference;
class PmeSketch;

class PmeStdSketchFeature
	: public PmeStdFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchFeature)
public:
	PmeStdSketchFeature(PmePart * pPart, PmeReference * pSketchPlane);
	virtual ~PmeStdSketchFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSketchFeature; }
	virtual void Update(void);

	PmeStdSketchOrigin * GetOrigin(void) const {return m_pOrigin;}
	PmeStdSketchHDirection * GetHDirection(void) const {return m_pHDirection;}
	PmeStdSketchVDirection * GetVDirection(void) const {return m_pVDirection;}
	PmeStdSketchGeometries * GetGeometries(void) const {return m_pGeometries;}
	PmeStdSketchConstraints * GetConstraints(void) const {return m_pConstraints;}

	PmeSketch * GetSketch(void) const {return m_pSketch;}

	void SetCoordinateSystem(const MrAxis2 & coordinateSystem) {m_coordinateSystem = coordinateSystem;}
	MrAxis2 GetCoordinateSystem() const {return m_coordinateSystem;}

	PmeReference * GetSketchPlane(void) const {return m_pSketchPlane;}

	void DeleteItemByName(CString name);

	// 17-02-24 권순조
	bool IsInversed(void);
	bool HasCenterLine(void);
	
	// 17-02-27 권순조
	void SaveEdgeGeometry(EDGE * pEdge) {edges.push_back(pEdge);}
	void ClearEdgeGeometry() {edges.clear();}
	EDGE * GetEdgeGeometry(int i) {return edges[i];}
	int GetEdgeGeometrySize() {return (int)edges.size();}

private:
	// 17-02-27 권순조	
	std::vector<EDGE *> edges; 

private:
	void Initialize(void);
	void Uninitialize(void);
	void ClearGeometries(void);
	void ClearConstraints(void);

	MrAxis2 GetReferenceCoordinateSystem(PmeReference * pSketchPlane);

private:
	PmeStdSketchOrigin * m_pOrigin;
	PmeStdSketchHDirection * m_pHDirection;
	PmeStdSketchVDirection * m_pVDirection;
	PmeStdSketchGeometries * m_pGeometries;
	PmeStdSketchConstraints * m_pConstraints;

	PmeReference * m_pSketchPlane;

	PmeSketch * m_pSketch;

	MrAxis2 m_coordinateSystem;
};