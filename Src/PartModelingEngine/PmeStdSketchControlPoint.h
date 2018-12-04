#pragma once

#include ".\PmeStdSketchGeometry.h"

class PmeStdSketchControlPoint
	: public PmeStdSketchGeometry
	, public IPmeDcmPoint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchControlPoint)
public:
	PmeStdSketchControlPoint(PmeStdSketchFeature * pSketchFeature, double x, double y);
	virtual ~PmeStdSketchControlPoint(void);	

	void SetPosition(double x, double y);
	double GetX(void) const {return m_x;}
	double GetY(void) const {return m_y;}

	// PmeStdSketchGeometry
	virtual PmeStdSketchGeometryType GetType(void) const {return PmeStdSketchGeometryType_ControlPoint;}

	// IPmeDcmGeometry
	virtual DCM_g_type DcmGetIdentify();
	virtual void DcmTransform(double [3][3]);
	virtual void DcmSetStatus(g_node_status status);
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// IPmeDcmPoint
	virtual void DcmGetPosition(double pt[2]);

private:
	double m_x, m_y;
};
