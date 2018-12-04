#pragma once
#include "SketchItem.h"

class SketchItemPolyLine : public SketchItem
{
public:
	SketchItemPolyLine(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemPolyLine(void);

	void GetInfo(char * command);
	
	void Create(void);

	void Help(void);

protected:
	void SetAllPoints(void);

private:
	vector<double> _pointArray;
	vector<Point2D> _points;
	int _pointNumber;
};