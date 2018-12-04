#pragma once

#include ".\PmMacro.h"


class PmHModel;
class PmHSelectionSet;

class PM_API PmHView
	: public HBaseView
{
public:
	PmHView(
		PmHModel * pHModel
		, const char * alias = 0
		, const char * driver_type = 0
		, const char * instance_name = 0
		, void * window_handle = 0
		, void * colormap = 0
		);
	virtual ~PmHView(void);

	void Init(void);

    //PmHModel * GetModel(void);
	HBaseModel * GetModel(void);

	virtual void FitWorld(HPoint * center_out = 0);
	PmHSelectionSet * GetSelection(void);
};
