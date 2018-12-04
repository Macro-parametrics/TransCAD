#pragma once
#include "pmestdsolidfeature.h"
//#include "PmeStdHoleCountersunkEndBlindType.h"
//#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeReference.h"
#include "IPmePattern.h"

//class PmePart;
class PmeReference;

class PmeStdSolidHoleSimpleFeature :
	public PmeStdSolidFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)
public:
	PmeStdSolidHoleSimpleFeature(PmePart * pPart);
	PmeStdSolidHoleSimpleFeature(PmePart * pPart,
									PmeReference * pTargetFace,
									double centerX,
									double centerY,
									double centerZ,
									double radius,
									double depth);

	virtual ~PmeStdSolidHoleSimpleFeature(void);

	PmeReference * GetTargetFace(void) const {return m_pTargetFace;}
	double GetCenterX(void) const {return m_centerX;}
	double GetCenterY(void) const {return m_centerY;}
	double GetCenterZ(void) const {return m_centerZ;}
	double GetRadius(void) const {return m_radius;}
	double GetDepth(void) const {return m_depth;}

	void SetTargetFace(PmeReference * targetFace) {m_pTargetFace = targetFace;}
	void SetCenterX(double centerX) {m_centerX = centerX;}
	void SetCenterY(double centerY) {m_centerY = centerY;}
	void SetCenterZ(double centerZ) {m_centerZ = centerZ;}
	void SetRadius(double radius) {m_radius = radius;}
	void SetDepth(double depth) {m_depth = depth;}

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidHoleSimpleFeature;}
	virtual void Update(void);
	
	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

protected:
	void AttachName(BODY *& pBody);

private:
	EDGE * CreateCircleEdge(double centerX, double centerY, double radius);
	void CreateSolidBody(BODY *& pBody);
	void CreateSolidHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ, double radius, double depth);
	MrAxis2 GetReferenceCoordinateSystem(PmeReference * pSketchPlane);
	void ResetHoleCenterPosition();

	PmeReference * m_pTargetFace;
	double m_centerX;
	double m_centerY;
	double m_centerZ;
	double m_radius;
	double m_depth;
};
