#include "stdafx.h"
#include <map>
#include ".\PmRenderExplicitModelObject.h"
#include ".\PmDocument.h"
#include ".\PmeExplicitModelObjectAPI.h"
#include ".\PmeDatumPlaneAPI.h"
#include ".\PmeSketchAPI.h"

typedef std::map<HC_KEY, HC_KEY> SubKeyMap;
SubKeyMap g_subKeyMap;

int sketchCount = 1;
int planeCount = 1;
int centerLineCount = 1;

HC_KEY PmRenderExplicitModelObject(PmeHExplicitModelObject hObject, PmDocument * pDocument)
{
	PmeExplicitModelObjectType type;
	HC_KEY hKey = 0;
	
	PmeExplicitModelObjectAPI::GetType(hObject, type);

	switch(type)
	{
	case PmeExplicitModelObjectType_Solid:
		HC_Open_Segment_By_Key(pDocument->GetModelSegment());
			hKey = PmRenderSolid(hObject);
		HC_Close_Segment();
		break;
	case PmeExplicitModelObjectType_DatumPlane:
		HC_Open_Segment_By_Key(pDocument->GetFitIgnoringSegment());
			hKey = PmRenderDatumPlane(hObject);
		HC_Close_Segment();
		break;
	case PmeExplicitModelObjectType_OffsetDatumPlane:
		HC_Open_Segment_By_Key(pDocument->GetFitIgnoringSegment());
			hKey = PmRenderOffsetDatumPlane(hObject);
		HC_Close_Segment();
		break;
	case PmeExplicitModelObjectType_Sketch:
		HC_Open_Segment_By_Key(pDocument->GetModelSegment());
			hKey = PmRenderSketch(hObject);
		HC_Close_Segment();
		break;
	}

	return hKey;
}

HC_KEY PmRenderSolid(PmeHExplicitModelObject hObject)
{
	BODY * pBody = 0;
	PmeSolidAPI::GetSolid(hObject, pBody);

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);

	HC_KEY hKey = HC_KOpen_Segment(name);
		HC_Set_Visibility("lines = on, markers = on");
		HC_KEY hSubKey = HA_Render_Entity((ENTITY *)pBody);
		g_subKeyMap[hKey] = hSubKey;
	HC_Close_Segment();

	return hKey;
}

void PmDeleteRenderingObject(HC_KEY hKey)
{
	SubKeyMap::iterator i = g_subKeyMap.find(hKey);
	if(i != g_subKeyMap.end())
	{
		HC_KEY hSubKey = i->second;
		if(hSubKey)
		{
            ENTITY * pEntity = HA_Compute_Entity_Pointer(hSubKey);
            HA_Delete_Entity_Geometry((ENTITY *)pEntity);
		}
	}

	HC_Delete_By_Key(hKey);

	g_subKeyMap.erase(i);
}

void PmClearSubKeyMap(void)
{
	g_subKeyMap.clear();
}

HC_KEY PmRenderDatumPlane(PmeHExplicitModelObject hObject)
{
	static const double size = 1;
	HPoint hPoints[5];

	MrPosition points[5] = {
		MrPosition(-size, -size, 0.0)
        , MrPosition(size, -size, 0.0)
		, MrPosition(size, size, 0.0)
		, MrPosition(-size, size, 0.0)
		, MrPosition(-size, -size, 0.0)
	};	

	MrAxis2 source;
		MrDirection xdir(1,0,0);
		MrDirection ydir(0,1,0);
		MrDirection zdir(0,0,1);
 
		source.SetXDirection(xdir);
		source.SetYDirection(ydir);
		source.SetZDirection(zdir);
	
	MrAxis2 location;
	PmeDatumPlaneAPI::GetLocation(hObject, location);
		
	MrTransformation transf = MrTransformation::CreateCoordinateSystemTransformation(location, source);

	for(int i = 0; i < 5; i ++)
	{
		MrPosition tPoint = transf.Transform(points[i]);
		hPoints[i] = HPoint(tPoint.X(), tPoint.Y(), tPoint.Z());
	}

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);
	
	HC_KEY hKey = HC_KOpen_Segment(name);
		HC_Set_Visibility("lines = on");
		HC_Insert_Polyline(5, hPoints);
		// DatumPlane이 camera scaling에 영향을 받지 않게 하려면 아래 내용을 첨부해야 한다.
		HImSetCallback("draw segment tree"/*HOOPS Callback type*/, "PmImUtility_DatumPlaneCallback");	
	HC_Close_Segment();

	return hKey;
}

HC_KEY PmRenderOffsetDatumPlane(PmeHExplicitModelObject hObject)
{
	static const double size = 30;
	HPoint hPoints[5];

	MrPosition points[5] = {
		MrPosition(-size, -size, 0.0)
		, MrPosition(size, -size, 0.0)
		, MrPosition(size, size, 0.0)
		, MrPosition(-size, size, 0.0)
		, MrPosition(-size, -size, 0.0)
	};	

	MrAxis2 source;
	MrDirection xdir(1,0,0);
	MrDirection ydir(0,1,0);
	MrDirection zdir(0,0,1);

	source.SetXDirection(xdir);
	source.SetYDirection(ydir);
	source.SetZDirection(zdir);

	MrAxis2 location;
	PmeDatumPlaneAPI::GetLocation(hObject, location);

	MrTransformation transf = MrTransformation::CreateCoordinateSystemTransformation(location, source);

	for(int i = 0; i < 5; i ++)
	{
		MrPosition tPoint = transf.Transform(points[i]);
		hPoints[i] = HPoint(tPoint.X(), tPoint.Y(), tPoint.Z());
	}

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);

	// 한글 입력이 안되기 때문에 임시로 평면 이름을 생성하여 삽입
	CString _planeName;
	_planeName = _T("Plane");
	_planeName.AppendFormat(_T("%d"), planeCount);
	planeCount ++;

	HC_KEY hKey = HC_KOpen_Segment(_planeName);
		
		HC_Set_Visibility("lines = on");

		HC_Insert_Polyline(5, hPoints);

	HC_Close_Segment();

	return hKey;
}

HC_KEY PmRenderSketch(PmeHExplicitModelObject hObject)
{
	PmeHFeature hFeature;
	PmeExplicitModelObjectAPI::GetCreator(hObject, hFeature);

	MrAxis2 coordinateSystem;
	PmeStdSketchFeatureAPI::GetCoordinateSystem(hFeature, coordinateSystem);

	PmeHStdSketchGeometries hGeometries;
	PmeStdSketchFeatureAPI::GetGeometries(hFeature, hGeometries);

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);
	
	// 한글 입력이 안되기 때문에 임시로 스케치 이름을 생성하여 삽입
	CString _sketchName;
	_sketchName = _T("Sketch");
	_sketchName.AppendFormat(_T("%d"), sketchCount);
	sketchCount ++;

	HC_KEY hKey = HC_KOpen_Segment(_sketchName);
		//HC_Set_Rendering_Options("hsra = priority");		
		HC_Set_Visibility("lines = on");

		MrTransformation mrTrsf = MrTransformation::CreateCoordinateSystemTransformation(coordinateSystem, MrAxis2::OXY());

		float transform[16];
		transform[0] = mrTrsf(0, 0); transform[1] = mrTrsf(1, 0); transform[2] = mrTrsf(2, 0); transform[3] = 0.0f;
		transform[4] = mrTrsf(0, 1); transform[5] = mrTrsf(1, 1); transform[6] = mrTrsf(2, 1); transform[7] = 0.0f;
		transform[8] = mrTrsf(0, 2); transform[9] = mrTrsf(1, 2); transform[10] = mrTrsf(2, 2); transform[11] = 0.0f;
		transform[12] = mrTrsf(0, 3); transform[13] = mrTrsf(1, 3); transform[14] = mrTrsf(2, 3); transform[15] = 1.0f;

		HC_Set_Modelling_Matrix(transform);

		int size;
		PmeStdSketchGeometriesAPI::GetSize(hGeometries, size);

		for(int i = 0; i < size; ++ i)
		{
			PmeHStdSketchGeometry hGeometry;
			PmeStdSketchGeometriesAPI::GetItem(hGeometries, i, hGeometry);

			PmeStdSketchGeometryType type;
			PmeStdSketchGeometryAPI::GetType(hGeometry, type);

			switch(type)
			{
			case PmeStdSketchGeometryType_Centerline:
				PmRenderSketchCenterline(hGeometry);
				break;
			case PmeStdSketchGeometryType_Line:
				PmRenderSketchLine(hGeometry);
				break;
			case PmeStdSketchGeometryType_Circle:
				PmRenderSketchCircle(hGeometry);
				break;
			case PmeStdSketchGeometryType_CircularArc:
				PmRenderSketchCircularArc(hGeometry);
				break;
			}
		}
		
	HC_Close_Segment();

	return hKey;
}

void PmRenderSketchLine(PmeHStdSketchGeometry hGeometry)
{
	PmeHStdSketchGeometry hStartPoint, hEndPoint;

	PmeStdSketchLineAPI::GetStartPoint(hGeometry, hStartPoint);
	PmeStdSketchLineAPI::GetEndPoint(hGeometry, hEndPoint);

	double startX, startY;
	double endX, endY;

	PmeStdSketchControlPointAPI::GetPosition(hStartPoint, startX, startY);
	PmeStdSketchControlPointAPI::GetPosition(hEndPoint, endX, endY);

	// 센터라인 쪽 참고해서 수정
	HC_Insert_Line(startX, startY, 0.0, endX, endY, 0.0);
}

void PmRenderSketchCenterline(PmeHStdSketchGeometry hGeometry)
{
	PmeHStdSketchGeometry hStartPoint, hEndPoint;

	PmeStdSketchCenterlineAPI::GetStartPoint(hGeometry, hStartPoint);
	PmeStdSketchCenterlineAPI::GetEndPoint(hGeometry, hEndPoint);

	double startX, startY;
	double endX, endY;

	PmeStdSketchControlPointAPI::GetPosition(hStartPoint, startX, startY);
	PmeStdSketchControlPointAPI::GetPosition(hEndPoint, endX, endY);

	//CString name;
	//PmeStdSketchGeometryAPI::GetName(hGeometry, name);
	
	// 한글 입력이 안되기 때문에 임시로 평면 이름을 생성하여 삽입
	CString _cLineame;
	_cLineame = _T("CenterLine");
	_cLineame.AppendFormat(_T("%d"), centerLineCount);
	centerLineCount ++;

	HC_KEY hKey = HC_KOpen_Segment(_cLineame);
		HC_Set_Line_Pattern("- -");
        HC_Set_Color("lines = blue");
        HC_Insert_Line(startX, startY, 0.0, endX, endY, 0.0);
	HC_Close_Segment();
}

void PmRenderSketchCircle(PmeHStdSketchGeometry hGeometry)
{
	PmeHStdSketchGeometry hCenterPoint;

	PmeStdSketchCircleAPI::GetCenterPoint(hGeometry, hCenterPoint);

	double centerX, centerY;
	double radius;

	PmeStdSketchControlPointAPI::GetPosition(hCenterPoint, centerX, centerY);
	PmeStdSketchCircleAPI::GetRadius(hGeometry, radius);

	HPoint center(centerX, centerY, 0.0);
	HPoint major(centerX + radius, centerY, 0.0);
	HPoint minor(centerX, centerY + radius, 0.0);	
	
	// 센터라인 쪽 참고해서 수정
	HC_Insert_Elliptical_Arc(&center, &major, &minor, 0.0, 1.0);
}

void PmRenderSketchCircularArc(PmeHStdSketchGeometry hGeometry)
{
	PmeHStdSketchGeometry hCenterPoint;

	PmeStdSketchCircularArcAPI::GetCenterPoint(hGeometry, hCenterPoint);

	double centerX, centerY;
	double radius;
	double startAngle, endAngle;

	PmeStdSketchControlPointAPI::GetPosition(hCenterPoint, centerX, centerY);

	PmeStdSketchCircularArcAPI::GetRadius(hGeometry, radius);

	HPoint center(centerX, centerY, 0.0);
	HPoint major(centerX + radius, centerY, 0.0);
	HPoint minor(centerX, centerY + radius, 0.0);

	PmeStdSketchCircularArcAPI::GetStartAngle(hGeometry, startAngle);
	PmeStdSketchCircularArcAPI::GetEndAngle(hGeometry, endAngle);

	HC_Insert_Elliptical_Arc(&center, &major, &minor, startAngle / (2.0 * M_PI), endAngle / (2.0 * M_PI));
}