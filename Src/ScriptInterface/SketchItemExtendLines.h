#pragma once
#include "SketchItem.h"

class SketchItemExtendLines : public SketchItem
{
public:
	SketchItemExtendLines(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemExtendLines(void);

	void GetInfo(char * command);
	
	void Create(void);

	void Help(void);

protected:
	bool GetInterSectingPoint(void);

private:
	Point2D _contactPoint;
	vector<string> _lineNames;
};