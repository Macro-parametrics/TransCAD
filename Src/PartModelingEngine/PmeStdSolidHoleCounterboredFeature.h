#pragma once
#include "pmestdsolidfeature.h"
//#include "PmeStdHoleCounterboredEndBlindType.h"
//#include ".\PmeStdSketchControlPoint.h"
#include "IPmePattern.h"

class PmePart;
class PmeReference;

class PmeStdSolidHoleCounterboredFeature :
	public PmeStdSolidFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)
public:
	PmeStdSolidHoleCounterboredFeature(PmePart * pPart);
	PmeStdSolidHoleCounterboredFeature(PmePart * pPart,
									PmeReference * pTargetFace,
									double centerX,
									double centerY,
									double centerZ,
									double startRadius,
									double startDepth,
									double endRadius,
									double endDepth,
									double angle);

	virtual ~PmeStdSolidHoleCounterboredFeature(void);

	PmeReference * GetTargetFace(void) const {return m_pTargetFace;}
	double GetCenterX(void) const {return m_centerX;}
	double GetCenterY(void) const {return m_centerY;}
	double GetCenterZ(void) const {return m_centerZ;}
	double GetStartRadius(void) const {return m_startRadius;}
	double GetStartDepth(void) const {return m_startDepth;}
	double GetEndRadius(void) const {return m_endRadius;}
	double GetEndDepth(void) const {return m_endDepth;}
	double GetAngle(void) const {return m_angle;}

	void SetTargetFace(PmeReference * targetFace) {m_pTargetFace = targetFace;}
	void SetCenterX(double centerX) {m_centerX = centerX;}
	void SetCenterY(double centerY) {m_centerY = centerY;}
	void SetCenterZ(double centerZ) {m_centerZ = centerZ;}
	void SetStartRadius(double startRadius) {m_startRadius = startRadius;}
	void SetStartDepth(double startDepth) {m_startDepth = startDepth;}
	void SetEndRadius(double endRadius) {m_endRadius = endRadius;}
	void SetEndDepth(double endDepth) {m_endDepth = endDepth;}
	void SetBottomAngle(double bottomAngle) {m_angle = bottomAngle;}

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidHoleCounterboredFeature;}
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
	void CreateRevolvedHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ, double startRadius, double startDepth, double endRadius, double endDepth, double angle);
	BODY * RevolveHoleBody(BODY *& pProfile, const SPAposition & location, const SPAvector & direction);
	void ResetHoleCenterPosition();

	MrAxis2 GetReferenceCoordinateSystem(PmeReference * pSketchPlane);

	PmeReference * m_pTargetFace;
	double m_centerX;
	double m_centerY;
	double m_centerZ;
	double m_startRadius;
	double m_startDepth;
	double m_endRadius;
	double m_endDepth;
	double m_angle;
};
