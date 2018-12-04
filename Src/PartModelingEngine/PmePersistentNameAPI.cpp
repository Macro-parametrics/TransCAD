#include "stdafx.h"
#include ".\PmePersistentNameAPI.h"
#include ".\PmePersistentName.h"

void PmePersistentNameAPI::FindFaceName(FACE * pFace, CString & faceName)
{
	faceName = PmePersistentName::FindFaceName(pFace);
}

void PmePersistentNameAPI::FindEdgeName(EDGE * pEdge, CString & edgeName)
{
	edgeName = PmePersistentName::FindEdgeName(pEdge);
}

void PmePersistentNameAPI::FindVertexName(VERTEX * pVertex, CString & vertexName)
{
	vertexName = PmePersistentName::FindVertexName(pVertex);
}

void PmePersistentNameAPI::SelectNamingMethod(bool bMethod)
{
	g_bNamingType = bMethod;
}

void PmePersistentNameAPI::GetNamingMethod(bool & bMethod)
{
	bMethod = g_bNamingType;
}
