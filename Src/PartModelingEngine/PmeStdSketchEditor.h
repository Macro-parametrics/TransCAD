#pragma once

#include ".\PmeStdSketchFeature.h"
#include ".\IPmeConstraintable.h"
#include ".\PmeSamePointsType.h"
#include ".\PmeReference.h"

struct IPmeDcmGeometry;
class PmeStdSketchLine;
class PmeStdSketchCenterline;
class PmeStdSketchCircle;
class PmeStdSketchCircularArc;
class PmeStdSketchControlPoint;

class PmeStdSketchCoincident;
class PmeStdSketchPerpendicular;
class PmeStdSketchParallel;
class PmeStdSketchHorizontal;
class PmeStdSketchVertical;

class PmeStdSketchEditor
{
private:
	PmeStdSketchEditor(PmeStdSketchFeature * pSketchFeature, bool activateDcm);
	~PmeStdSketchEditor(void);

public:
    static PmeStdSketchEditor * OpenSketch(PmeStdSketchFeature * pSketchFeature, bool activateDcm = false);
	void CloseSketch(void);

	dimension_system * GetDcm(void) const {return m_pDcm;}
	PmeStdSketchFeature * GetSketchFeature(void) const {return m_pSketchFeature;}	

	PmeStdSketchLine * CreateLine(double startX, double startY, double endX, double endY);
	
	PmeStdSketchCenterline * CreateCenterline(double startX, double startY, double endX, double endY);
	
	PmeStdSketchCircle * CreateCircle(double centerX, double centerY, double radius);
	
	PmeStdSketchCircularArc * CreateCircularArc(double centerX, double centerY, double radius, double startAngle, double endAngle);	
	PmeStdSketchCircularArc * CreateCircularArcFromCenterStartEnd(double centerX, double centerY, double startX, double startY, double endX, double endY);
	PmeStdSketchCircularArc * CreateCircularArcFrom3Points(double startX, double startY, double intermediateX, double intermediateY, double endX, double endY);

//	PmeStdSketchCoincident * CreateCoincident(IPmeConstraintable * pFirstGeometry, IPmeConstraintable * pSecondGeometry);
	PmeStdSketchCoincident * CreateCoincident(PmeReference * pFirstGeometry, PmeSamePointsType firstType, PmeReference * pSecondGeometry, PmeSamePointsType secondType);
	PmeStdSketchPerpendicular * CreatePerpendicular(PmeReference * pReferenceEdit, PmeReference * pTarget);
	PmeStdSketchParallel * CreateParallel(PmeReference * pReferenceEdit, PmeReference * pTarget);
	PmeStdSketchHorizontal * CreateHorizontal(PmeReference * pTarget);
	PmeStdSketchVertical * CreateVertical(PmeReference * pTarget);
	
	void DeleteItemByName(CString name);

	bool IsDcmActivated(void) const {return m_pDcm != 0;}

private:
	PmeStdSketchCircularArc * CreateInternalCircularArc(PmeStdSketchControlPoint * pCenterPoint, double radius, PmeStdSketchControlPoint * pStartPoint, PmeStdSketchControlPoint * pEndPoint);
	PmeStdSketchCircularArc * CreateInternalCircularArc(const bounded_arc & arc);

private:
	PmeStdSketchFeature * m_pSketchFeature;
	dimension_system * m_pDcm;
};