#pragma once

#include ".\PmeStdSketchGeometry.h"

class PmeStdSketchControlPoint;
class PmeStdSketchFeature;
class PmeDcmCoincident;

class PmeStdSketchLine
	: public PmeStdSketchGeometry
	, public IPmeDcmLine
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchLine)
public:
	PmeStdSketchLine(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pStartPoint, PmeStdSketchControlPoint * pEndPoint);
	virtual ~PmeStdSketchLine(void);

	PmeStdSketchControlPoint * GetStartPoint(void) const {return m_pStartPoint;}
	PmeStdSketchControlPoint * GetEndPoint(void) const {return m_pEndPoint;}

	// PmeStdSketchGeometry
	virtual PmeStdSketchGeometryType GetType(void) const {return PmeStdSketchGeometryType_Line;}

	// IPmeDcmGeometry
	virtual DCM_g_type DcmGetIdentify();
	virtual void DcmTransform(double [3][3]);
	virtual void DcmSetStatus(g_node_status status);
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// IPmeDcmLine
	virtual void DcmGetPosition(double pt[2]);
	virtual void DcmGetDirection(double dir[2]);

private:
	PmeStdSketchControlPoint * m_pStartPoint;
	PmeStdSketchControlPoint * m_pEndPoint;
	PmeDcmCoincident * m_pStartPointOnLine;
	PmeDcmCoincident * m_pEndPointOnLine;
};
