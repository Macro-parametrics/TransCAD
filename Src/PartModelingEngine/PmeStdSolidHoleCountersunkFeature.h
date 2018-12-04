#pragma once
#include "pmestdsolidfeature.h"
//#include "PmeStdHoleCountersunkEndBlindType.h"
//#include ".\PmeStdSketchControlPoint.h"
#include "IPmePattern.h"

class PmePart;
class PmeReference;

class PmeStdSolidHoleCountersunkFeature :
	public PmeStdSolidFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)
public:
	PmeStdSolidHoleCountersunkFeature(PmePart * pPart);
	PmeStdSolidHoleCountersunkFeature(PmePart * pPart,
									PmeReference * pTargetFace,
									double centerX,
									double centerY,
									double centerZ,
									double radius,
									double depth,
									double sinkRadius,
									double sinkAngle,
									double bottomAngle);

	virtual ~PmeStdSolidHoleCountersunkFeature(void);

	PmeReference * GetTargetFace(void) const {return m_pTargetFace;}
	double GetCenterX(void) const {return m_centerX;}
	double GetCenterY(void) const {return m_centerY;}
	double GetCenterZ(void) const {return m_centerZ;}
	double GetRadius(void) const {return m_radius;}
	double GetDepth(void) const {return m_depth;}
	double GetSinkRadius(void) const {return m_sinkRadius;}
	double GetSinkAngle(void) const {return m_sinkAngle;}
	double GetBottomAngle(void) const {return m_bottomAngle;}

	void SetTargetFace(PmeReference * targetFace) {m_pTargetFace = targetFace;}
	void SetCenterX(double centerX) {m_centerX = centerX;}
	void SetCenterY(double centerY) {m_centerY = centerY;}
	void SetCenterZ(double centerZ) {m_centerZ = centerZ;}
	void SetRadius(double radius) {m_radius = radius;}
	void SetDepth(double depth) {m_depth = depth;}
	void SetSinkRadius(double sinkRadius) {m_sinkRadius = sinkRadius;}
	void SetSinkAngle(double sinkAngle) {m_sinkAngle = sinkAngle;}
	void SetBottomAngle(double bottomAngle) {m_bottomAngle = bottomAngle;}

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidHoleCountersunkFeature;}
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
	void CreateSolidConicBody(BODY *& pBody, double centerX, double centerY, double centerZ, double radius, double angle);
	void CreateRevolvedHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ, double radius, double depth, double sinkRadius, double sinkAngle, double bottomAngle);
	BODY * RevolveHoleBody(BODY *& pProfile, const SPAposition & location, const SPAvector & direction);
	void ResetHoleCenterPosition();
	
	MrAxis2 GetReferenceCoordinateSystem(PmeReference * pSketchPlane);

	PmeReference * m_pTargetFace;
	double m_centerX;
	double m_centerY;
	double m_centerZ;
	double m_radius;
	double m_depth;
	double m_sinkRadius;
	double m_sinkAngle;
	double m_bottomAngle;
};
