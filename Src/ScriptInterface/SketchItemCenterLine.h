#pragma once
#include "SketchItem.h"

class SketchItemCenterLine : public SketchItem
{
public:
	SketchItemCenterLine(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemCenterLine(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem);
	
	void Create(void);
	void Modify(char * command);
	void AskInfo(void);
	void Help(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, StartPoint, _startPoint);
	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, EndPoint, _endPoint);

private:
	Point2D _startPoint;
	Point2D _endPoint;
};