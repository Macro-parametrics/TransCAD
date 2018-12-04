#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeTransformAPI
{
public:
	
//     static void Rotate
// 		(
// 		PmeHAssembly hPmeAssembly,
// 		PmeHComponent& hComponent,
// 		float x,
// 		float y,
// 		float z,
// 		float radianAngle
// 		);
//     static void Rotate2
// 		(
// 		PmeHAssembly hPmeAssembly,
// 		PmeHComponent& hComponent,
// 		float x,
// 		float y,
// 		float z,
// 		float radianAngle
// 		);
	static void Rotate
		(
		PmeHAssembly hPmeAssembly,
		PmeHComponent& hComponent,
		double x,
		double y,
		double z,
		float radianAngle
		);

	static void Translate
		(
		PmeHAssembly hPmeAssembly,
		PmeHComponent& hComponent,
		float dx,
		float dy,
		float dz
			);

	static MrTransformation CalcModelingMatrix(PmeHComponent hComponent, BOOL UpToParent = TRUE);
	//static MrTransformation CalcModelingMatrix2(PmeHPart hPart, BOOL UpToParent = TRUE);

private:	

};