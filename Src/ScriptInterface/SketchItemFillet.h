#pragma once
#include "SketchItem.h"

class SketchItemFillet : public SketchItem
{
public:
	SketchItemFillet(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemFillet(void);

	void GetInfo(char * command);
	
	void Create(void);

	void Help(void);

protected:
	bool GetArcCenterStartEnd(void);
	bool CheckMaximumRadius(double dist1, double dist2, double theta);
	void GetCircleBetweenLines(double a[2], double b[2], Point2D intPoint, Direct2D uV, double radius);

private:
	Point2D _centerPoint, _contactPoint[2];
	double _radius;
	bool _isReversed;
	vector<string> _lineNames;
};