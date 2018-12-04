#pragma once
#include "SketchItem.h"

class SketchItemTranslate : public SketchItem
{
public:
	SketchItemTranslate(FeatureSketch* pSketch, int sketchItemType);
	virtual ~SketchItemTranslate(void);

	void GetInfo(char * command);
	
	void Create(void);
	
	void Help(void);

protected:
	void TranslateAllPoints(void);

private:
	Vector2D _translation;
};