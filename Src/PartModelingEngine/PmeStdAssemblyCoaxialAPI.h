#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PmePart;
class PmeReference;

class PME_API PmeStdAssemblyCoaxialAPI
{
public:
    static void ApplyCoaxial(
		PmeHAssembly hAssembly, 
		const CString & name,					
		PmeHPart & hConstrainedPart, 
		PmeHReference & hConstrainedGeometry, 
		PmeHPart & hReferencePart, 
		PmeHReference & hReferenceGeometry,
		PmeHStdAssemblyConstraint & hConstraint );

	// 17-03-21 Added by YK
	static bool isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);
	static bool isCircularEdge(EDGE * pEdge);
	static bool isCylindericalFace(FACE * pFace);

	static void GetConstrainedPart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hConstrainedPart );
	static void GetReferencePart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hReferencePart );

	static void GetConstrainedGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hConstrainedGeometry );
	static void GetReferenceGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hReferenceGeometry );
};