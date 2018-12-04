#include "stdafx.h"
#include <map>
#include "AssemRenderPart.h"
#include "AssemDocument.h"
#include "PmeExplicitModelObjectAPI.h"
#include "PmeDatumPlaneAPI.h"
#include "PmeSketchAPI.h"
#include "PmeComponentAPI.h"
#include "PmePartAPI.h"
#include "AssemView.h"

#include "HUtilityGeomHandle.h"


HC_KEY AssemRenderComponent(PmeHComponent hComponent, AssemDocument * pDocument)
{
#ifdef _DEBUG
	CString compName;
	PmeComponentAPI::GetName( hComponent, compName );
#endif
	HC_KEY hKey = NULL;
	if(!hComponent) return hKey;
	
	MrAxis2 placement;
	
	CString name;
	PmeComponentAPI::GetUniqueName(hComponent, name);
	
	PmeHComponent hParent;
	PmeComponentAPI::GetParentComp(hComponent, hParent);

	if(hParent)
	{
		hKey = AssemRenderComponent(hParent,pDocument);
		return hKey;
	}
	
	float transform[16];
	PmeComponentAPI::GetModellingMatrix(hComponent, transform);
	
	int size;
	PmeComponentAPI::GetSize(hComponent, size);

	PmeAssemblyComponentType CompType;
	PmeComponentAPI::GetCompType(hComponent, CompType);

	HC_Open_Segment_By_Key(pDocument->GetModelSegment());
	hKey = HC_KOpen_Segment(name);	
	HC_Set_Modelling_Matrix(transform);
	
	if(CompType == PmeAssemblyComponentType_DefaultDatumPlane) 
	{
		AssemRenderDefaultDatumPlane(hComponent);
	}
	else
	{
		for (int i = 0; i<size;i++)
		{
			BOOL result;
			PmeComponentAPI::IsComponent(hComponent,i,result);

			if(result)
			{	
				PmeHComponent hSubComp;
				PmeComponentAPI::GetComponent(hComponent, i, hSubComp);
#ifdef _DEBUG
	CString subCompName;
	PmeComponentAPI::GetName( hSubComp, subCompName );
#endif
				BOOL updated;
				PmeComponentAPI::IsUpdated(hSubComp, updated);
				if(!updated) continue;
				
				HC_KEY hSubKey = AssemRenderSubComponent(hSubComp , pDocument);
				//pDocument->AddObjectMapPair(hSubComp,hSubKey);
			}
			else
			{
				PmeHPart hSubPart;
				PmeComponentAPI::GetPart(hComponent, i, hSubPart);
				HC_KEY hPartKey = AssemRenderSubPart(hSubPart, hKey, pDocument);
			}
		}
	}
	HC_Close_Segment();
	HC_Close_Segment();
	
	return hKey;
}

HC_KEY AssemRenderSubComponent( PmeHComponent hComponent, AssemDocument * pDocument)
{
	//HC_KEY hKey;
	MrAxis2 placement;
	CString name;
	PmeComponentAPI::GetUniqueName(hComponent, name);

	PmeComponentAPI::GetPlacement(hComponent, placement);
	
	float transform[16];
	PmeComponentAPI::GetModellingMatrix(hComponent, transform);

	int size;
	PmeComponentAPI::GetSize(hComponent, size);
	
	HC_KEY hKey = HC_KOpen_Segment(name);	
	HC_Set_Modelling_Matrix(transform);
	
	for (int i = 0; i<size;i++)
	{
		BOOL result;
		PmeComponentAPI::IsComponent(hComponent,i,result);

		if(result)
		{	
			PmeHComponent hSubComp;
			PmeComponentAPI::GetComponent(hComponent, i, hSubComp);

			BOOL updated;
			PmeComponentAPI::IsUpdated(hSubComp, updated);
			if(!updated) continue;
			
			HC_KEY hSubCompKey = AssemRenderSubComponent(hSubComp, pDocument);
			//pDocument->AddObjectMapPair(hSubComp, hSubCompKey);
		}
		else
		{
			PmeHPart hSubPart;
			PmeComponentAPI::GetPart(hComponent, i, hSubPart);
			HC_KEY hPartKey = AssemRenderSubPart(hSubPart , hKey, pDocument);
		}

	}
	HC_Close_Segment();
	return hKey;
}

HC_KEY AssemRenderSubPart( PmeHPart hPart , HC_KEY hOwnerKey, AssemDocument * pDocument)
{
	HC_KEY hKey = 0;
	PmeHExplicitModel hExplicitModel;
	PmeHExplicitModelObject hObject;
	PmeExplicitModelObjectType type;
	CString name;

	PmePartAPI::GetUniqueName(hPart, name);

	MrAxis2 placement;
	PmePartAPI::GetPlacement(hPart, placement);
	
	float transform[16];
	PmePartAPI::GetModellingMatrix(hPart, transform);

	PmePartAPI::GetExplicitModel(hPart, hExplicitModel);
			
	int size;
	
	PmeExplicitModelAPI::GetSize(hExplicitModel, size);

	HC_KEY hSubKey = HC_KOpen_Segment(name);
	HC_Set_Modelling_Matrix(transform);

	for (int i = 0; i<size;i++)
	{
		PmeExplicitModelAPI::GetItem(hExplicitModel, hObject, i);

		PmeExplicitModelObjectAPI::GetType(hObject,type);
		
		switch(type)
		{
		case PmeExplicitModelObjectType_Solid:
			hKey = AssemRenderSolid(hObject , hSubKey);

			break;
		case PmeExplicitModelObjectType_DatumPlane:
			AssemRenderDatumPlane(hObject, hSubKey);
			break;
		}
	}
	HC_Close_Segment();
	return hSubKey;
}

HC_KEY AssemRenderSolid(PmeHExplicitModelObject hObject, HC_KEY hOwnerKey)
{
	BODY * pBody = new BODY;
	
	PmeSolidAPI::GetSolid(hObject, pBody);

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);

	HC_KEY hKey = HC_KOpen_Segment("solid");
		HC_Set_Visibility("lines = on, markers = on");
		HC_KEY hSubKey = HA_Render_Entity((ENTITY *)pBody);
	HC_Close_Segment();

	return hKey;
}

void AssemDeleteRenderingObject(PmeHComponent hComponent)
{
	int size;

	PmeComponentAPI::GetSize(hComponent, size);
	
	BOOL updated;
	PmeComponentAPI::IsUpdated(hComponent, updated);
	if(!updated) return;

	for (int i = 0; i<size;i++)
	{
		BOOL result;
		PmeComponentAPI::IsComponent(hComponent,i,result);

		if(result)
		{	
			
			PmeHComponent hSubComp;
			PmeComponentAPI::GetComponent(hComponent, i, hSubComp);

			BOOL updated;
			PmeComponentAPI::IsUpdated(hSubComp, updated);
			if(!updated) continue;

			AssemDeleteRenderingObject(hSubComp);
		}
		else
		{
			PmeHPart hSubPart;
			PmeComponentAPI::GetPart(hComponent, i, hSubPart);

			PmeHExplicitModel hExplicitModel;
			PmeHExplicitModelObject hObject;
			PmeExplicitModelObjectType type;

			PmePartAPI::GetExplicitModel(hSubPart, hExplicitModel);
			
			int size;
	
			PmeExplicitModelAPI::GetSize(hExplicitModel, size);

			for (int i = 0; i<size;i++)
			{
				PmeExplicitModelAPI::GetItem(hExplicitModel, hObject, i);

				PmeExplicitModelObjectAPI::GetType(hObject,type);
				BODY * pBody = new BODY;
				switch(type)
				{
				case PmeExplicitModelObjectType_Solid:
			
					PmeSolidAPI::GetSolid(hObject, pBody);		
					HA_Delete_Entity_Geometry((ENTITY *)pBody);
					break;
				case PmeExplicitModelObjectType_DatumPlane:
					//PmeSolidAPI::GetSolid(hObject, pBody);		
					//HA_Delete_Entity_Geometry((ENTITY *)pBody);

					//AssemRenderDatumPlane(hObject, hOwnerKey);
					break;
				}
			}
		}
	}
}

void AssemRenderDefaultDatumPlane(PmeHComponent hComponent)
{

	static const double plane_size = 1;
	HPoint hPoints[5];

	MrPosition points[5] = {
		MrPosition(-plane_size, -plane_size, 0.0)
        , MrPosition(plane_size, -plane_size, 0.0)
		, MrPosition(plane_size, plane_size, 0.0)
		, MrPosition(-plane_size, plane_size, 0.0)
		, MrPosition(-plane_size, -plane_size, 0.0)
	};	

	PmeHPart hSubPart;
	PmeComponentAPI::GetPart(hComponent, 0, hSubPart);

	PmeHExplicitModel hExplicitModel;
	PmeHExplicitModelObject hObject;
	PmeExplicitModelObjectType type;

	PmePartAPI::GetExplicitModel(hSubPart, hExplicitModel);

	int size;

	PmeExplicitModelAPI::GetSize(hExplicitModel, size);
	HC_KEY hKey = HC_KOpen_Segment("Default_datum");
	for (int i = 0; i<size;i++)
	{
		PmeExplicitModelAPI::GetItem(hExplicitModel, hObject, i);

		PmeExplicitModelObjectAPI::GetType(hObject,type);
		BODY * pBody = new BODY;
		switch(type)
		{
		case PmeExplicitModelObjectType_DatumPlane:
			MrAxis2 location;
			PmeDatumPlaneAPI::GetLocation(hObject, location);

			MrTransformation transf = MrTransformation::CreateCoordinateSystemTransformation(location,MrAxis2::OXY());

			for(int i = 0; i < 5; ++ i)
			{
				MrPosition tPoint = transf.Transform(points[i]);
				hPoints[i] = HPoint(tPoint.X(), tPoint.Y(), tPoint.Z());
			}

			CString name;
			PmeExplicitModelObjectAPI::GetName(hObject, name);

			
				HC_Set_Visibility("lines = on");
				// DatumPlane이 camera scaling에 영향을 받지 않게 하려면 아래 내용을 첨부해야 한다.
				HImSetCallback("draw segment tree", "AssemImUtility_DatumPlaneCallback");
				//HC_Scale_Object(size, size, size);
				HC_Insert_Polyline(5, hPoints);
		
			
		}
	}
	HC_Close_Segment();
	

//	return hKey;
}

void AssemRenderDatumPlane(PmeHExplicitModelObject hObject, HC_KEY hOwnerKey)
{
	static const double size = 10;
	HPoint hPoints[5];

	MrPosition points[5] = {
		MrPosition(-size, -size, 0.0)
		, MrPosition(size, -size, 0.0)
		, MrPosition(size, size, 0.0)
		, MrPosition(-size, size, 0.0)
		, MrPosition(-size, -size, 0.0)
	};	

	MrAxis2 location;
	PmeDatumPlaneAPI::GetLocation(hObject, location);

	MrTransformation transf = MrTransformation::CreateCoordinateSystemTransformation(location,MrAxis2::OXY());

	for(int i = 0; i < 5; ++ i)
	{
		MrPosition tPoint = transf.Transform(points[i]);
		hPoints[i] = HPoint(tPoint.X(), tPoint.Y(), tPoint.Z());
	}

	CString name;
	PmeExplicitModelObjectAPI::GetName(hObject, name);
	HC_KEY hKey = HC_KOpen_Segment(name);
	HC_Set_Visibility("lines = on");
	// DatumPlane이 camera scaling에 영향을 받지 않게 하려면 아래 내용을 첨부해야 한다.
	//HImSetCallback("draw segment tree", "AssemImUtility_DatumPlaneCallback");
	//HC_Scale_Object(size, size, size);
	HC_Insert_Polyline(5, hPoints);
	HC_Close_Segment();

	//	return hKey;
}





