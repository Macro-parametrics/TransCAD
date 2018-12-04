#pragma once
#include "SketchItem.h"

class SketchItemCircle : public SketchItem
{
public:
	SketchItemCircle(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemCircle(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem);
	
	void Create(void);
	void Modify(char * command);
	void AskInfo(void);
	void Help(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, CenterPoint, _center);

private:
	double _radius;
	Point2D _center;
};