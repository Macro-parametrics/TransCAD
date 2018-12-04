#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdExtrudeEndType.h"

class PME_API PmeStdSolidProtrusionExtrudeFeatureAPI
{
public:
	static void Create
	(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hProfileSketch,
	double startDepth,
	PmeStdExtrudeEndType startCondition,
	double endDepth,
	PmeStdExtrudeEndType endCondition,
	bool isFlip,
	PmeHFeature & hFeature
	);

	static void GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch);
	static void GetStartDepth(PmeHFeature hFeature, double & startDepth);
	static void GetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & startCondition);
	static void GetEndDepth(PmeHFeature hFeature, double & endDepth);
	static void GetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & endCondition);
	static void IsFlip(PmeHFeature hFeature, bool & isFlip);

	static void SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch);
	static void SetStartDepth(PmeHFeature hFeature, double startDepth);
	static void SetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType startCondition);
	static void SetEndDepth(PmeHFeature hFeature, double endDepth);
	static void SetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType endCondition);
	static void SetFlip(PmeHFeature hFeature, bool isFlip);
};