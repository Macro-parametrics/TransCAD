#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeChamferType.h"

class PME_API PmeStdSolidChamferFeatureAPI
{
public:
    static void Create
		(
			PmeHPart hPart,
			const CString & name,
			PmeChamferType chamferType,
			PmeHReferences hSelectedEdges,
			PmeHReference hSelectedFace,
			double length,
			double value,
			PmeHFeature & hFeature
		);

	static void Create
		(
			PmeHPart hPart,
			const CString & name,
			PmeHReferences hSelectedEdges,
			double length,
			PmeHFeature & hFeature
		);

	static void GetChamferType(PmeHFeature hFeature, PmeChamferType & chamferType);
	static void GetSelectedEdges(PmeHFeature hFeature, PmeHReferences & hSelectedEdges);
	static void GetSelectedFace(PmeHFeature hFeature, PmeHReference & hSelectedFace);
	static void GetLength(PmeHFeature hFeature, double & length);
	static void GetValue(PmeHFeature hFeature, double & value);

	static void GetStartPoint(PmeHFeature hFeature, SPAposition & position);
	static void GetEndPoint(PmeHFeature hFeature, SPAposition & position);
	
	static void GetStartPointAt(PmeHFeature hFeature, int index, SPAposition & position);
	static void GetEndPointAt(PmeHFeature hFeature, int index, SPAposition & position);

	static void SetChamferType(PmeHFeature hFeature, PmeChamferType chamferType);
	static void SetSelectedEdges(PmeHFeature hFeature, PmeHReferences hSelectedEdges);
	static void SetLength(PmeHFeature hFeature, double length);
};