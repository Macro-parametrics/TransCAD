#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdAssemblyConstraintType.h"

class PmePart;
class PmeReference;

class PME_API PmeStdAssemblyIncidenceAPI
{
public:
    static void ApplyIncidence( PmeHAssembly hAssembly, 
							    const CString & name,					
							    PmeHPart & hConstrainedPart, 
							    PmeHReference & hConstrainedCoGeometry, 
							    PmeHPart & hReferencePart, 
							    PmeHReference & hReferenceGeometry,
							    PmeStdAssemblyIncidenceType hIncidenceType,
								PmeHStdAssemblyConstraint & hConstraint);

	static bool isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);
	static bool isLinearEdge(EDGE * pEdge);

	static void GetConstrainedPart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hConstrainedPart );
	static void GetReferencePart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hReferencePart );

	static void GetConstrainedGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hConstrainedGeometry );
	static void GetReferenceGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hReferenceGeometry );
};