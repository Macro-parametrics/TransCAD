#pragma once
#include "SketchItem.h"

class SketchItemChamfer : public SketchItem
{
public:
	SketchItemChamfer(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemChamfer(void);

	void GetInfo(char * command);
	
	void Create(void);
	
	void Help(void);

protected:
	bool GetLineStartEnd(void);
	bool CheckMaximumLength(double dist1, double dist2);

private:
	Point2D _contactPoint[2];
	double _length;
	vector<string> _lineNames;
};