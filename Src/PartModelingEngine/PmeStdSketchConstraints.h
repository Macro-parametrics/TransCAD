#pragma once

#include ".\PmeObject.h"
#include ".\PmeBaseList.h"

class PmeStdSketchConstraint;


class PmeStdSketchConstraints
	: public PmeObject
	, public PmeBaseList<PmeStdSketchConstraint *>
{
	typedef PmeBaseList<PmeStdSketchConstraint *> BaseList;

	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchConstraints)
public:
	PmeStdSketchConstraints(void);
	virtual ~PmeStdSketchConstraints(void);

	PmeStdSketchConstraint * FindByName(const CString & name) const;
};