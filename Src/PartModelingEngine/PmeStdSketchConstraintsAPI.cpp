#include "stdafx.h"
#include ".\PmeStdSketchConstraintsAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"
#include ".\PmeStdSketchConstraints.h"

void PmeStdSketchConstraintsAPI::GetSize(PmeHStdSketchConstraints & hConstraints, int & size)
{
	PmeStdSketchConstraints * pConstraints = PME_HANDLE2STDSKETCHCONSTRAINTS(hConstraints);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pConstraints);
	size = pConstraints->GetSize();
}

void PmeStdSketchConstraintsAPI::GetItem(PmeHStdSketchConstraints & hConstraints, int index, PmeHStdSketchConstraint & hConstraint)
{
	PmeStdSketchConstraints * pConstraints = PME_HANDLE2STDSKETCHCONSTRAINTS(hConstraints);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pConstraints);

	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pConstraints->GetSize() <= index || index < 0);
    hConstraint = pConstraints->GetItem(index);
}

void PmeStdSketchConstraintsAPI::FindByItem(PmeHStdSketchConstraints & hConstraints, PmeHStdSketchConstraint hConstraint, int & index)
{
	PmeStdSketchConstraints * pConstraints = PME_HANDLE2STDSKETCHCONSTRAINTS(hConstraints);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pConstraints);
	index = pConstraints->Find(PME_HANDLE2STDSKETCHCONSTRAINT(hConstraint));
}