#include "StdAfx.h"
#include ".\pmestdsketchconstraints.h"
#include ".\PmeStdSketchConstraint.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchConstraints, PmeObject)

PmeStdSketchConstraints::PmeStdSketchConstraints(void)
{
}

PmeStdSketchConstraints::~PmeStdSketchConstraints(void)
{
}

PmeStdSketchConstraint * PmeStdSketchConstraints::FindByName(const CString & name) const
{
	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchConstraint * pConstraint = GetItem(i);
		if(pConstraint->GetName() == name)
			return pConstraint;
	}

	return 0;
}