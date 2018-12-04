#pragma once
#include "pmestdsketchgeometry.h"

class PmeStdSketchControlPoint;
class PmeStdSketchFeature;
class PmeDcmConcentric;

class PmeStdSketchCircle
	: public PmeStdSketchGeometry
	, public IPmeDcmCircle
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchCircle)
public:
	PmeStdSketchCircle(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pCenterPoint, double radius);
	virtual ~PmeStdSketchCircle(void);

	PmeStdSketchControlPoint * GetCenterPoint(void) const {return m_pCenterPoint;}
	double GetRadius(void) const {return m_radius;}

	// PmeStdSketchGeometry
	virtual PmeStdSketchGeometryType GetType(void) const {return PmeStdSketchGeometryType_Circle;}

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
	PmeDcmConcentric * m_pConcentricCenterPoint;
};
