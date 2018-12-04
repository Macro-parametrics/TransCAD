#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PmePart;
class PmeReference;

class PME_API PmeStdAssemblyPerpendicularAPI
{
public:
    static bool ApplyPerpendicular(PmeHAssembly hAssembly, 
								   const CString & name,					
								   PmeHPart & hConstrainedPart, 
								   PmeHReference & hConstrainedGeometry, 
								   PmeHPart & hReferencePart, 
								   PmeHReference & hReferenceGeometry);
	
	// 17-03-21 Added by YK
	static bool isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);
	static bool isLinearEdge(EDGE * pEdge);
};