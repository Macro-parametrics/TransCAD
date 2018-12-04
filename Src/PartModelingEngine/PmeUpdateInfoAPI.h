#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

enum PmeUpdateState
{
	PmeUpdateState_Add,
	PmeUpdateState_Update,
	PmeUpdateState_Delete
};

struct PmeUpdateInfoItem
{
	PmeHandle hItem;
	PmeUpdateState state;

	bool operator==(const PmeUpdateInfoItem & rhs) const
	{
		if(hItem == rhs.hItem && state == rhs.state)
			return true;
		return false;
	}
};

class PME_API PmeUpdateInfoAPI
{
public:
	static void Create(PmeHUpdateInfo & hInfo);
	static void Delete(PmeHUpdateInfo & hInfo);
	static void AddItem(PmeHUpdateInfo hInfo, PmeUpdateInfoItem infoItem);
	static void GetSize(PmeHUpdateInfo hInfo, int & size);
	static void GetItem(PmeHUpdateInfo hInfo, int index, PmeUpdateInfoItem & infoItem);
	static void FindByItem(PmeHUpdateInfo hInfo, PmeUpdateInfoItem infoItem, int & index);
};