#include "stdafx.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeBaseList.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"

typedef PmeBaseList<PmeUpdateInfoItem> PmeUpdateInfoList;

void PmeUpdateInfoAPI::Create(PmeHUpdateInfo & hInfo)
{
	PmeUpdateInfoList * pUpdateInfoList = new PmeUpdateInfoList();
	hInfo = PME_UPDATEINFOLIST2HANDLE(pUpdateInfoList);
}

void PmeUpdateInfoAPI::Delete(PmeHUpdateInfo & hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hInfo);
	PmeUpdateInfoList * pUpdateInfoList = PME_HANDLE2UPDATEINFOLIST(hInfo);
	delete pUpdateInfoList;
	hInfo = 0;
}

void PmeUpdateInfoAPI::AddItem(PmeHUpdateInfo hInfo, PmeUpdateInfoItem infoItem)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hInfo);
	PmeUpdateInfoList * pUpdateInfoList = PME_HANDLE2UPDATEINFOLIST(hInfo);
	pUpdateInfoList->Add(infoItem);
}

void PmeUpdateInfoAPI::GetSize(PmeHUpdateInfo hInfo, int & size)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hInfo);
	PmeUpdateInfoList * pUpdateInfoList = PME_HANDLE2UPDATEINFOLIST(hInfo);
	size = pUpdateInfoList->GetSize();
}

void PmeUpdateInfoAPI::GetItem(PmeHUpdateInfo hInfo, int index, PmeUpdateInfoItem & infoItem)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hInfo);
	PmeUpdateInfoList * pUpdateInfoList = PME_HANDLE2UPDATEINFOLIST(hInfo);
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pUpdateInfoList->GetSize() <= index || index < 0);
	
    infoItem = pUpdateInfoList->GetItem(index);
}

void PmeUpdateInfoAPI::FindByItem(PmeHUpdateInfo hInfo, PmeUpdateInfoItem infoItem, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hInfo);
	PmeUpdateInfoList * pUpdateInfoList = PME_HANDLE2UPDATEINFOLIST(hInfo);
	index = pUpdateInfoList->Find(infoItem);
}