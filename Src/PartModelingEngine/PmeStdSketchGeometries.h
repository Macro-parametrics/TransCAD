#pragma once

#include ".\PmeObject.h"
#include ".\PmeBaseList.h"

class PmeStdSketchGeometry;

class PmeStdSketchGeometries
	: public PmeObject
	, public PmeBaseList<PmeStdSketchGeometry *>
{
	typedef PmeBaseList<PmeStdSketchGeometry *> BaseList;

	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchGeometries)
public:
	PmeStdSketchGeometries(void);
	virtual ~PmeStdSketchGeometries(void);

	PmeStdSketchGeometry * FindByName(const CString & name) const;
};