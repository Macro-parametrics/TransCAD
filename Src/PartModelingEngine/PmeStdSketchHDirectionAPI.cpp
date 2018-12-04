#include "stdafx.h"
#include ".\PmeStdSketchHDirectionAPI.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchHDirectionAPI::GetName(PmeHStdSketchHDirection hHDirection, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hHDirection);
	PmeStdSketchHDirection * pHDirection = PME_HANDLE2STDSKETCHHDIRECTION(hHDirection);
	
	name = pHDirection->GetName();
}