#pragma once
#include "pmereference.h"

class PmeStdSketchGeometry;

class PmeSketchGeometryReference :
	public PmeReference
{
	PME_DECLARE_RUNTIME_TYPE(PmeSketchGeometryReference)
public:
	PmeSketchGeometryReference(PmePart * pPart, PmeStdSketchGeometry * pGeometry);
	virtual ~PmeSketchGeometryReference(void);

	// PmeReference
	virtual PmeReferenceType GetReferenceType(void) const { return PmeReferenceType_SketchGeometry; }
};
