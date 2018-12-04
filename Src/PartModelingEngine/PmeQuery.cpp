#include "stdafx.h"
#include ".\PmeQuery.h"
#include ".\PmePart.h"

MrDirection PmeQueryFaceNormal(FACE * pFace, const MrPosition & p)
{
	SPAtransf transform;
	
	// Import 된 Brep 모델의 요소(점, 선, 면)는 Transform 되어있지 않음
	// 따라서 Transform이 발생하는 일반적인 특징형상의 경우에만 적용 (16-11-24 권순조)
	if (pFace->shell()->lump()->body()->transform())
		transform = pFace->shell()->lump()->body()->transform()->transform();
	
	SURFACE * pSurface = pFace->geometry();
	const surface & surfaceEquation = pSurface->equation();
	
	SPAunit_vector surfaceNormal = surfaceEquation.point_normal(SPAposition(p.X(), p.Y(), p.Z()));

	surfaceNormal *= transform;
	
	MrDirection normal = MrDirection(surfaceNormal.x(), surfaceNormal.y(), surfaceNormal.z());

	if(pFace->sense() == REVERSED)
		return MrMath::Reverse(normal);
	else
        return normal;
}

MrAxis2 PmeQueryFaceLocalCoordinate(FACE * pFace)
{
	SPAtransf transform;

	// Import 된 Brep 모델의 요소(점, 선, 면)는 Transform 되어있지 않음
	// 따라서 Transform이 발생하는 일반적인 특징형상의 경우에만 적용 (16-11-24 권순조)
	if (pFace->shell()->lump()->body()->transform())
		transform = pFace->shell()->lump()->body()->transform()->transform();

	SURFACE * pSurface = pFace->geometry();
	const surface & surfaceEquation = pSurface->equation();
	
	SPAposition origin = surfaceEquation.eval_position(SPApar_pos(0.0, 0.0));
	SPAposition xpos = surfaceEquation.eval_position(SPApar_pos(1.0, 0.0));
	SPAunit_vector normal = surfaceEquation.eval_normal(SPApar_pos(0.0, 0.0));

	origin *= transform;
	xpos *= transform;
	normal *= transform;

	MrAxis2 axis = MrAxis2(MrPosition(origin.x(), origin.y(), origin.z()), MrDirection(normal.x(), normal.y(), normal.z()), MrDirection(xpos.x(), xpos.y(), xpos.z()));

	if(pFace->sense() == REVERSED)
		return MrMath::Reverse(axis);
	else
		return axis;
}

/**
 * 17-03-18 Added by YK
 * Set local coordinates of face for cylinderical face
 * @param pPart
 * initially normal vector of face is same to part's
 * @param pFace
 * target geometry
**/
MrAxis2 PmeQueryCylindericalFaceLocalCoordinate(PmePart * pPart, FACE * pFace)
{
	MrAxis2 lc;

	// Get centroid of cylinderical face

	SPAposition centre;					// centroid return
	
	API_BEGIN
		double area;					// area returned
		double req_rel_accy = 0;		// relative precision desired
		double moment_a;				// first principal moment
		double moment_b;				// second principal moment
		SPAunit_vector axis_a;			// first principal axis
		SPAunit_vector axis_b;			// second principal axis
		double est_rel_accy_achieved;	// estimate of relative accuracy achieved
		AcisOptions* ao = NULL;
		
		result = api_planar_face_pr(pFace, req_rel_accy, area, centre, moment_a, moment_b, axis_a, axis_b, est_rel_accy_achieved, ao);

		check_outcome(result);
	API_END


	for(int i = 0; i < 3; ++i)
	{
		double t = 1e-6;	// tolerance

		if ( centre.coordinate(i) < t )
			centre.coordinate(i) = 0.0;
	}
	
	lc.SetLocation(MrPosition(centre.x(), centre.y(), centre.z()));

	// Part의 coordinate system
	MrAxis2 partCSYS = pPart->GetPlacement();

	lc.XDirection() = partCSYS.XDirection();
	lc.YDirection() = partCSYS.YDirection();
	lc.ZDirection() = partCSYS.ZDirection();
	
	return lc;
	
}

// 17-03-19 Added by YK
MrAxis2 PmeQueryEdgeLocalCoordinate(EDGE * pEdge)
{
	SPAtransf transform;

	if (pEdge->coedge()->loop()->face()->shell()->lump()->body()->transform())
		transform = pEdge->coedge()->loop()->face()->shell()->lump()->body()->transform()->transform();

	SPAposition    center;			// center point
	SPAunit_vector normal;			// normal vector
	SPAvector      major_axis;		// major axis

	API_BEGIN

		double         radius_ratio;	// radius ratio
		double         start_angle;		// start angle
		double         end_angle;		// end angle

		api_get_ellipse_parameters(pEdge, center, normal, major_axis, radius_ratio, start_angle, end_angle);

	API_END


	center *= transform;
	normal *= transform;

	MrPosition origin = MrPosition(center.x(), center.y(), center.z());
	MrDirection XDirection = MrDirection(major_axis.x(), major_axis.y(), major_axis.z());
	MrDirection ZDirection = MrDirection(normal.x(), normal.y(), normal.z());
		
		
	MrAxis2 axis = MrAxis2(origin, ZDirection, XDirection);

	return axis;

	
}