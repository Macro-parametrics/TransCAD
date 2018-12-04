#pragma once
#include "SketchItem.h"

class SketchItemRotate : public SketchItem
{
public:
	SketchItemRotate(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemRotate(void);

	void GetInfo(char * command);
	
	void Create(void);
	
	void Help(void);

protected:
	void RotateAllPoints(void);

private:
	Point2D _rotCenter;
	double _rotAngle;
	Matrix2D _rotMatrix;
};