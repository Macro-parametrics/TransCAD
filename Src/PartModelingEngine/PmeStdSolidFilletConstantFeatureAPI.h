#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmePropagationType.h"

class PME_API PmeStdSolidFilletConstantFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReferences hFilletEdges,
		double radius,
		PmePropagationType propagation,    
		PmeHFeature & hFeature
	);

	static void GetFilletEdges(PmeHFeature hFeature, PmeHReferences & hFilletEdges);
	static void GetRadius(PmeHFeature hFeature, double & radius);
	static void GetPropagationType(PmeHFeature hFeature, PmePropagationType & propagation);
	static void GetStartPoint(PmeHFeature hFeature, SPAposition & position);
	static void GetEndPoint(PmeHFeature hFeature, SPAposition & position);
	static void GetStartPointAt(PmeHFeature hFeature, int index, SPAposition & position);
	static void GetEndPointAt(PmeHFeature hFeature, int index, SPAposition & position);

	static void SetFilletEdges(PmeHFeature hFeature, PmeHReferences hFilletEdges);
	static void SetRadius(PmeHFeature hFeature, double radius);
	static void SetPropagationType(PmeHFeature hFeature, PmePropagationType propagation);
};