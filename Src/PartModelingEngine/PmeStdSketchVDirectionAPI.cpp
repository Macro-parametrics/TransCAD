#include "stdafx.h"
#include ".\PmeStdSketchVDirectionAPI.h"
#include ".\PmeStdSketchVDirection.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchVDirectionAPI::GetName(PmeHStdSketchVDirection hVDirection, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVDirection);
	PmeStdSketchVDirection * pVDirection = PME_HANDLE2STDSKETCHVDIRECTION(hVDirection);
	
	name = pVDirection->GetName();
}