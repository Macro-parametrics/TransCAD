#pragma once
#include "SketchItem.h"

class SketchItemArc : public SketchItem
{
public:
	SketchItemArc(FeatureSketch* pSketch, int sketchItemType);
	SketchItemArc(FeatureSketch* pSketch, int sketchItemType, string name, Point2D center, Point2D startPoint, Point2D endPoint);
	virtual ~SketchItemArc(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem);

	void Create(void);
	void Modify(char * command);
	void AskInfo(void);
	void Help(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, CenterPoint, _center);
	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, StartPoint, _startPoint);
	VARIABLE_GET_AND_SET_FUNC_IMPL(Point2D, EndPoint, _endPoint);

private:
	Point2D _center;
	Point2D _startPoint;
	Point2D _endPoint;
};