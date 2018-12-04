/**
	@file	PmeStdAssemblyParallelAPI.h
	@class	PmeStdAssemblyParallelAPI
	@date	2017/03/23
	@author	Youngki Kim(kimyg5415@kaist.ac.kr)
*/
#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdAssemblyParallelAPI
{
public:
    static bool ApplyParallel(PmeHAssembly hAssembly, 
							  const CString & name,					
							  PmeHPart & hConstrainedPart, 
							  PmeHReference & hConstrainedGeometry, 
							  PmeHPart & hReferencePart, 
							  PmeHReference & hReferenceGeometry);

	static bool isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);
	static bool isLinearEdge(EDGE * pEdge);

};