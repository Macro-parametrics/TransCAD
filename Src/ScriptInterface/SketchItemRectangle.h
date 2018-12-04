#pragma once
#include "SketchItem.h"

class SketchItemRectangle : public SketchItem
{
public:
	SketchItemRectangle(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemRectangle(void);

	void GetInfo(char * command);
	
	void Create(void);

	void Help(void);

protected:
	void SetAllPoints(void);

private:
	Point2D _points[4];
};