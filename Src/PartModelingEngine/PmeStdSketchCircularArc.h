#pragma once
#include "pmestdsketchgeometry.h"

class PmeStdSketchControlPoint;
class PmeStdSketchFeature;
class PmeDcmCoincident;
class PmeDcmConcentric;

class PmeStdSketchCircularArc
	: public PmeStdSketchGeometry
	, public IPmeDcmCircle
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchCircularArc)
public:
	PmeStdSketchCircularArc(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pCenterPoint, double radius, PmeStdSketchControlPoint * pStartPoint, PmeStdSketchControlPoint * pEndPoint);
	virtual ~PmeStdSketchCircularArc(void);

	PmeStdSketchControlPoint * GetCenterPoint(void) const {return m_pCenterPoint;}
	PmeStdSketchControlPoint * GetStartPoint(void) const {return m_pStartPoint;}
	PmeStdSketchControlPoint * GetEndPoint(void) const {return m_pEndPoint;}
	double GetRadius(void) const {return m_radius;}
	double GetStartAngle(void) const;
	double GetEndAngle(void) const;

	// PmeStdSketchGeometry
	virtual PmeStdSketchGeometryType GetType(void) const {return PmeStdSketchGeometryType_CircularArc;}

	// IPmeDcmGeometry
	virtual DCM_g_type DcmGetIdentify();
	virtual void DcmTransform(double [3][3]);
	virtual void DcmSetStatus(g_node_status status);
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// IPmeDcmCircle
	virtual void DcmGetCenter(double pt[2]);
	virtual double DcmGetRadius();
	virtual void DcmSetRadius(double radius);

private:
	PmeStdSketchControlPoint * m_pCenterPoint;	
	double m_radius;
	PmeStdSketchControlPoint * m_pStartPoint;
	PmeStdSketchControlPoint * m_pEndPoint;

	PmeDcmConcentric * m_pConcentricCenterPoint;
	PmeDcmCoincident * m_pStartPointOnArc;
	PmeDcmCoincident * m_pEndPointOnArc;
};