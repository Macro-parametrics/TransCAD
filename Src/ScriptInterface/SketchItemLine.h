#pragma once
#include "SketchItem.h"

class SketchItemLine : public SketchItem
{
public:
	SketchItemLine(FeatureSketch* pSketch, int sketchItemType);
	SketchItemLine(FeatureSketch* pSketch, int sketchItemType, string name, Point2D startPoint, Point2D endPoint);
	virtual ~SketchItemLine(void);

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