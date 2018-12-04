#pragma once
#include "TransCADScript.h"
#include "FeatureSketch.h"
#include "Part.h"
#include "Object.h"
#include "FeatureSketch.h"

class FeatureSketch;

class SketchItem : public Object
{
public:
	SketchItem(FeatureSketch * pSketch, int sketchItemType);
	~SketchItem(void);
	
	virtual void AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem) {}
	virtual void Create(void) {}
	virtual void Modify(char * command) {}

	bool CheckExistence(string name);
	
	void GetLineEquation(Point2D firstPoint, Point2D secondPoint, double & a, double & b);
	bool GetIntersectingPoint(double a[2], double b[2], Point2D & intPoint);
	void GetDistantPoint(Point2D org, Point2D p1, Point2D p2, Point2D & dP);
	
	bool IsDifferentPoint(Point2D p1, Point2D p2);

	VARIABLE_GET_AND_SET_FUNC_IMPL(FeatureSketch *, Sketch, m_pSketch);
	VARIABLE_IS_AND_SET_FUNC_IMPL(bool, Created, m_isCreated);

private:
	FeatureSketch * m_pSketch;
	
	bool m_isCreated;
};