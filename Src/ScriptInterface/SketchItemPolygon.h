#pragma once
#include "SketchItem.h"

class SketchItemPolygon : public SketchItem
{
public:
	SketchItemPolygon(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemPolygon(void);

	void GetInfo(char * command);
	
	void Create(void);
	
	void Help(void);

protected:
	void SetAllPoints(void);

private:
	vector<Point2D> _points;
	double _length;
	int _edgeNumber;
};