#pragma once

#include ".\PmeMacro.h"
#include <vector>

struct PmePersistentNameData
{
	std::vector<CString> faceNames;
};

class PmePersistentName
{
public:
	static CString FindName(ENTITY * pEntity);
	static CString FindFaceName(FACE * pFace);
	static CString FindEdgeName(EDGE * pEdge);
	static ENTITY * FindEntity(BODY * pBody, CString persistentName);
	static void GetArgumentNames(CString persistentName, CString *featureID, CString *id1 = NULL, CString *id2 = NULL, CString *id3 = NULL, CString *id4 = NULL, CString *id5 = NULL);

	//Geometric Naming
	static CString FindVertexName(VERTEX * pVertex);
	//static ENTITY * FindPlaneByTopoName(BODY * pBody, CString topoName);	
	//Geometric Naming
private:
	static void SplitName(CString persistentName, PmePersistentNameData & nameData);

	static ENTITY * FindFace(BODY * pBody, const PmePersistentNameData & nameData);
	static ENTITY * FindEdge(BODY * pBody, const PmePersistentNameData & nameData);

	//Geometric Naming
	static ENTITY * FindEdge(BODY * pBody, CString persistentName);
	static ENTITY * FindFace(BODY * pBody, CString persistentName);
	//Geometric Naming


	static CString FindPersistentNameOption(CString persistentName);

	static void FindAdjacentFaces(EDGE * pEdge, FACE *& pFace1, FACE *& pFace2);
	static bool CheckPersistentFaceName(CString persistentName);
};
