#include "stdafx.h"
#include ".\PmePart.h"
#include ".\PmePartAPI.h"
#include ".\PmeFeaturesAPI.h"
#include ".\PmeFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeBaseList.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"


void PmeFeaturesAPI::GetSize(PmeHFeatures hFeatures, int & size)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);
	
	size = pFeatures->GetSize();
}

void PmeFeaturesAPI::GetItem(PmeHFeatures hFeatures, int index, PmeHFeature & hFeature)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	hFeature = 0;
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);	
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pFeatures->GetSize() <= index || index < 0);

    hFeature = pFeatures->GetItem(index);
}

void PmeFeaturesAPI::FindByItem(PmeHFeatures hFeatures, PmeHFeature hFeature, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);

	index = pFeatures->Find(PME_HANDLE2FEATURE(hFeature));
}

void PmeFeaturesAPI::FindByName(PmeHFeatures hFeatures, CString name, PmeHFeature & hFeature)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);

	for (int i = 0; i < pFeatures->GetSize(); ++i)
	{
		if (pFeatures->GetItem(i)->GetName() == name)
		{
			hFeature = pFeatures->GetItem(i);
			return;
		}
	}
}

void PmeFeaturesAPI::DeleteItem(PmeHFeatures hFeatures, int index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);

	pFeatures->Delete(index);
}

void PmeFeaturesAPI::DeleteItemByName(PmeHFeatures hFeatures, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeatures);
	PmeFeatures * pFeatures = PME_HANDLE2FEATURES(hFeatures);

	for (int i = 1; i < (int)pFeatures->GetSize(); ++i)
	{
		if(pFeatures->GetItem(i)->GetName() == name)
			pFeatures->Delete(i);
	}
}