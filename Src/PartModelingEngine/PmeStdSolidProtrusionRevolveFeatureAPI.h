#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdRevolveEndType.h"

class PME_API PmeStdSolidProtrusionRevolveFeatureAPI
{
public:
	static void PmeStdSolidProtrusionRevolveFeatureAPI::Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hProfileSketch,
		double startAngle,
		PmeStdRevolveEndType startCondition,
		double endAngle,
		PmeStdRevolveEndType endCondition,
		bool isFlip,
		PmeHFeature & hFeature
	);

	static void PmeStdSolidProtrusionRevolveFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch);
	static void PmeStdSolidProtrusionRevolveFeatureAPI::GetStartAngle(PmeHFeature hFeature, double & startAngle);
	static void PmeStdSolidProtrusionRevolveFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdRevolveEndType & startCondition);
	static void PmeStdSolidProtrusionRevolveFeatureAPI::GetEndAngle(PmeHFeature hFeature, double & endAngle);
	static void PmeStdSolidProtrusionRevolveFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdRevolveEndType & endCondition);
	static void PmeStdSolidProtrusionRevolveFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip);

	static void SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch);
	static void SetStartAngle(PmeHFeature hFeature, double startAngle);
	static void SetEndAngle(PmeHFeature hFeature, double endAngle);
	static void SetFlip(PmeHFeature hFeature, bool isFlip);
};