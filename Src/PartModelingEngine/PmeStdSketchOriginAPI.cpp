#include "stdafx.h"
#include ".\PmeStdSketchOriginAPI.h"
#include ".\PmeStdSketchOrigin.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchOriginAPI::GetName(PmeHStdSketchOrigin hOrigin, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hOrigin);
	PmeStdSketchOrigin * pOrigin = PME_HANDLE2STDSKETCHORIGIN(hOrigin);
	
	name = pOrigin->GetName();
}