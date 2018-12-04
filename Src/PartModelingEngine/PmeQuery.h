#pragma once

class PmePart;

MrDirection PmeQueryFaceNormal(FACE * pFace, const MrPosition & p);
MrAxis2 PmeQueryFaceLocalCoordinate(FACE * pFace);

// 17-03-15 Added by YK for using Coaxial constraint
MrAxis2 PmeQueryEdgeLocalCoordinate(EDGE * pEdge);

// 17-03-18 Added by YK
MrAxis2	PmeQueryCylindericalFaceLocalCoordinate(PmePart* pPart, FACE * pFace);