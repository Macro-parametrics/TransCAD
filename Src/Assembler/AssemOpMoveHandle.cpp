//
// Copyright (c) 2000 by Tech Soft 3D, LLC.
// The information contained herein is confidential and proprietary to
// Tech Soft 3D, LLC., and considered a trade secret as defined under
// civil and criminal statutes.  Tech Soft 3D shall pursue its civil
// and criminal remedies in the event of unauthorized use or misappropriation
// of its trade secrets.  Use of this information by anyone other than
// authorized employees of Tech Soft 3D, LLC. is granted only under a
// written non-disclosure agreement, expressly prescribing the scope and
// manner of such use.
//
 
 
#include "stdafx.h"

#include "HBaseModel.h"
#include "HBaseView.h"
#include "HBaseOperator.h"
#include "HEventInfo.h"
#include "HEventManager.h"
#include "HTools.h"
#include "AssemOpMoveHandle.h"
#include "HUtilityGeomHandle.h"
#include "HMarkupManager.h"
#include "HSelectionSet.h"
#include "HBhvBehaviorManager.h"
#include "HBhvAnimation.h"
#include "HBhvInterpolator.h"
#include "HBhvTimeline.h"

#include "AssemDocument.h"
#include "AssemHView.h"
#include "AssemHModel.h"
#include "AssemView.h"
#include "HUndoManager.h"
#include "stdio.h"
#include <math.h>
#include <string.h>
#include <malloc.h>
#include "hc.h"

#include ".\PmeTransformAPI.h"
#include ".\PmeAssemblyAPI.h"
/////////////////////////////////////////////////////////////////////////////
// HSOpMoveHandle
//
// Translate items in the selection list in direction of mouse movement
// parallel to camera target plane.
//
// Currently supports translation if item if it is a segment


//set the world point appropriately if it happens to lie within a screen range window
HPoint get_new_world_point(HPoint const & window_position, HPoint const & world_position, HBaseView * view)
{
	int res = 0, sr_hits = 0;
	HC_KEY * full_path_keys = 0;
	int skey_count = 0;
	char str[MVO_BUFFER_SIZE];
	float x1=-1.f, x2=1.f, y1=-1.f, y2=1.f;
	HPoint ret = world_position;

	HC_Open_Segment_By_Key(view->GetViewKey());
	{
		// We need some sort of path to properly find whether we have a screen range
		// and to compute the coordinates if we do.  Selection is the easiest way to get this.
		HViewSelectionLevel lvl = view->GetViewSelectionLevel();
		view->SetViewSelectionLevel(HSelectionLevelSegment);
		char heur[4096];
		bool heur_saved=false;
		if (HC_Show_Existence("heuristics"))
		{
			HC_Show_Heuristics(heur);
			heur_saved=true;
		}
		HC_Set_Heuristics("related selection limit = 0");
		res = HC_Compute_Selection(".",
			(view->GetSelection()->GetSubwindowPenetration() ? "" : "./scene/overwrite"), 
			"v", window_position.x, window_position.y);
		if (heur_saved)
			HC_Set_Heuristics(heur);
		view->SetViewSelectionLevel(lvl);
	}
	HC_Close_Segment();

	if(res > 0)
	{
		//get a good path for a pshow
		HC_Show_Selection_Keys_Count(&skey_count);
		skey_count += 2;  //make room for the view key and a null terminator at the end
		full_path_keys = new HC_KEY[skey_count];
		HC_Show_Selection_Original_Keys(0, full_path_keys);
		full_path_keys[skey_count-2] = view->GetViewKey();
		full_path_keys[skey_count-1] = 0;

		//find out if we have a screen range
		HC_PShow_One_Net_Rendering_Option(skey_count, full_path_keys, "screen range", str);
		sr_hits=sscanf(str, "%f, %f, %f, %f", &x1, &x2, &y1, &y2);
		
		//if so, convert to the proper window coordinates
		if (sr_hits && (x1!=-1.f || x2!=1.f || y1!=-1.f || y2!=1.f))
			HC_Compute_Coordinates_By_Path(skey_count, full_path_keys, "outer window", &window_position, "world", &ret);

		delete [] full_path_keys;
	}

	return ret;
}



AssemOpMoveHandle::AssemOpMoveHandle(HBaseView* view, AssemView* WinView, AssemDocument* WinDoc, bool allowSelect, int DoRepeat,int DoCapture) : HOpSelectAperture(view, DoRepeat, DoCapture)
{	
//	HC_KEY kay[1000];
	m_pHandleKey = INVALID_KEY;
	m_pObjectKey = INVALID_KEY;
	m_boxzoom = 1;
	m_bAllowSelect = allowSelect;//
//	m_pOwnerDialog = 0;
//	m_pKeyframeEditor = (CKeyframeEditor *)WinView->GetKeyframeEditorDialog(false);
	m_pView = WinView;
	m_pDoc = WinDoc;
	m_bInitialMatrix = false;

	//m_prev_point = HPoint(20,0,0);
	/*
	if (allowSelect)
	{
		HC_KEY key;
		HSelectionSet *ss = view->GetSelection();
		if (ss->GetSize())
		{
			int k;
			for (k=0;k<(int)ss->GetSize();k++)
				kay[k] = ss->GetAt(k);
			key = ss->GetAt(k);
			int msize = ss->GetSize();
			for (k=0;k<msize;k++)
			{
				key = kay[k];
				char type[256];
				HC_Show_Key_Type(key, type);
				if (strcmp(type, "segment")!=0)
				{
					key = HC_KShow_Owner_By_Key(key);
				}
				
				ss->DeSelectAll(); 
				m_pObjectKey = key;
 				SetupObject(m_pObjectKey);			
				GetView()->Update();
			}
		}
	}
	*/
}

void AssemOpMoveHandle::SetupObject(HC_KEY key)
{  
	HUtility::NameSegments(m_pObjectKey, GetView());
	HUtilityGeomHandle::GetCenterPoint(key, m_midpoint); 
}


AssemOpMoveHandle::~AssemOpMoveHandle()
{
	HUtilityGeomHandle::ClearAllHandles(GetView());
	GetView()->Update();
}


HBaseOperator * AssemOpMoveHandle::Clone()
{
	return (HBaseOperator *)new AssemOpMoveHandle(GetView(), m_pView, m_pDoc);
}

void AssemOpMoveHandle::Reset(HC_KEY okey)
{
	m_pHandleKey = INVALID_KEY;
	m_pObjectKey = okey;
}


const char * AssemOpMoveHandle::GetName() { return "HSOpMoveHandle"; }
 
/////////////////////////////////////////////////////////////////////////////
// HSOpMoveHandle message handlers



HC_KEY AssemOpMoveHandle::FindHandle(HEventInfo &event)
{  
	HPoint new_pos = event.GetMouseWindowPos();
	return ( HUtilityGeomHandle::SelectHandle(GetView(), new_pos));

}
 

HC_KEY AssemOpMoveHandle::FindObject(HEventInfo &event, HC_KEY oldkey, bool exclude)
{
	HPoint  new_pos;  
	new_pos = event.GetMouseWindowPos();
	return (HUtilityGeomHandle::SelectObject(GetView(),new_pos, oldkey, exclude));
}

int AssemOpMoveHandle::OnLButtonDown(HEventInfo &event)
{
	HUtilityGeomHandle ghandle;

	m_rotater = 0;
	m_TempShadowMode = HShadowNone;
  
	if (!OperatorStarted()) 
		SetOperatorStarted(true);
	else return true;

	m_pHandleKey =FindHandle(event);
	
	if (m_pHandleKey == INVALID_KEY)
	{
		if (m_bAllowSelect == false)
		{
			SetOperatorStarted(false);
			return (HOP_OK);
		}			
		
		HC_KEY okey = FindObject(event, m_pObjectKey, true);
		
		if (okey!=m_pObjectKey)
		{
			if (m_pObjectKey != INVALID_KEY)
			{
	
				HC_Open_Segment_By_Key(m_pObjectKey);
				HC_Begin_Contents_Search(".", "segments");
				HC_KEY skey;
				char type[256];
				while (HC_Find_Contents(type, &skey))
				{
					char text[MVO_BUFFER_SIZE];
					char ssegname[MVO_BUFFER_SIZE];

						HC_Show_Segment(skey, text);
						HC_Parse_String(text, "/", -1, ssegname);

					if (ghandle.IsGeomHandle(skey ) != INVALID_KEY ||  strcmp(ssegname, "cpbox") == 0)
					{
						char text[MVO_BUFFER_SIZE];
						HC_Show_Segment(skey, text);
						HC_Delete_By_Key(skey);
					}

				}
				HC_End_Contents_Search();
				HC_Close_Segment();
			}
			m_pHandleKey = INVALID_KEY;

			m_pObjectKey = okey;
 			if (m_pObjectKey != INVALID_KEY)
			{
				HUtility::NameSegments(m_pObjectKey, GetView());
				m_boxzoom = 1;
				SetupObject(m_pObjectKey);
			}
		}
		SetOperatorStarted(false);
	}
	else
	{
// 		if (!HUtility::IsModelKey(GetView()->GetModelKey(),m_pHandleKey))
// 			GetView()->GetConstantFrameRateObject()->SetActivityType(CuttingPlaneActivity);
// 		else
// 			GetView()->GetConstantFrameRateObject()->SetActivityType(MovementActivity);
 		ShowHandle(ghandle, m_pHandleKey);
		m_pObjectKey = HUtilityGeomHandle::GetMMSegment(m_pHandleKey);
		
		if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToPlane || ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRay || ghandle.GetConstraintType(m_pHandleKey) == HConstrainToViewplane)
		{
			if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRay)
			{
				SetNewPoint(get_new_world_point(event.GetMouseWindowPos(), event.GetMouseWorldPos(), GetView()));
				HC_KEY camerakey = GetView()->GetSceneKey();
				m_prev_point = GetNewPoint();
		
			}
			else
			{
			
				SetNewPoint(get_new_world_point(event.GetMouseWindowPos(), event.GetMouseWorldPos(), GetView()));
				HC_KEY camerakey = GetView()->GetSceneKey();
				m_prev_point = GetNewPoint();
			
			}
		}
		else
		{
			if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRotationVector)
			{
				SetNewPoint(get_new_world_point(event.GetMouseWindowPos(), event.GetMouseWorldPos(), GetView()));
				HC_KEY camerakey = GetView()->GetSceneKey();

				HPoint d = GetNewPoint();

				ghandle.AdjustPointToRay(m_pHandleKey, d, camerakey, GetView());

				m_rotation_axis = d;

				float transform[16];
				PmeHComponent hComp = m_pDoc->GetComponentFromHKey(m_pView->Selected_key());
				PmeComponentAPI::GetGlobalModellingMatrix(hComp,transform);
				HC_Open_Segment_By_Key(camerakey);
				HC_Set_Modelling_Matrix(transform);
				HC_Compute_Coordinates(".", "world",&m_rotation_axis, "object", &m_rotation_axis);
				HC_UnSet_Modelling_Matrix();
				HC_Close_Segment();
			}
		}

		if( !GetView()->GetAllowInteractiveShadows() && (m_TempShadowMode = GetView()->GetShadowMode()) != HShadowNone )
			GetView()->SetShadowMode(HShadowNone);
		if( !GetView()->GetAllowInteractiveCutGeometry() && (m_TempCutGeometryVisibility = GetView()->GetCutGeometryVisibility()) != HCutGeometryVisibilityNone)
			GetView()->SetCutGeometryVisibility(HCutGeometryVisibilityNone);
	}
	if (m_pObjectKey != INVALID_KEY)
	{
		HC_Open_Segment_By_Key(m_pObjectKey);
			if (GetView()->GetSpritingMode())
 				HC_Set_Heuristics("quick moves = spriting");	
			HC_Set_Rendering_Options("no simple shadow");
		HC_Close_Segment();
	}
    SetNewPoint(event.GetMouseWorldPos());
 	SetFirstPoint(event.GetMouseWindowPos());
	
	GetView()->Update();
	
	return (HLISTENER_CONSUME_EVENT);
	
}

int AssemOpMoveHandle::OnNoButtonDownAndMove(HEventInfo &event)
{
   	int ret = HLISTENER_PASS_EVENT;
   	HUtilityGeomHandle ghandle;
	
 	HC_KEY ghandleKey = FindHandle(event);

	if (m_pHandleKey!=INVALID_KEY && ghandleKey != m_pHandleKey)
	{		
		ghandle.ResetHandle(m_pHandleKey);
 		GetView()->Update();
	}
 
     m_pHandleKey = ghandleKey;
  
	if (ghandleKey != INVALID_KEY)
	{
	    ret = HLISTENER_CONSUME_EVENT;
		
		ghandle.ShowHandle(ghandleKey,0.7f, (HBaseView*)m_pView);
	    GetView()->Update();	
	}	
// 	SetNewPoint(get_new_world_point(event.GetMouseWindowPos(), event.GetMouseWorldPos(), GetView()));
// 	HPoint new_point =GetNewPoint();
// 	
// 	TRACE("\nhandle newpoint : %f, %f, %f",new_point.x,new_point.y,new_point.z);
	
    return (ret);

}


HC_KEY AssemOpMoveHandle::IsCameraSet(HC_KEY key)
{
	while(1)
	{
		HC_Open_Segment_By_Key(key);
		int cexists = HC_Show_Existence("camera");
		HC_Close_Segment();
		if (cexists)
 			return key;
		if (key == GetView()->GetModelKey() || key == GetView()->GetViewKey())
			return INVALID_KEY;
		key = HC_KShow_Owner_By_Key(key);
	}
}
 

int AssemOpMoveHandle::OnLButtonDownAndMove(HEventInfo &event)
{
	if (!OperatorStarted())
		return HBaseOperator::OnLButtonDownAndMove(event);

	SetNewPoint(get_new_world_point(event.GetMouseWindowPos(), event.GetMouseWorldPos(), GetView()));
	HPoint tmp = event.GetMouseWindowPos();
	
 	HC_KEY camerakey = GetView()->GetSceneKey();

	//store modelling matrix before manipulator usage, for undo history list
	HUtilityGeomHandle ghandle;
	float seg_matrix[16];
	if(!m_bInitialMatrix)
	{
		m_bInitialMatrix = true;
		HC_KEY segkey = ghandle.GetMMSegment(m_pHandleKey);
		HC_Open_Segment_By_Key(segkey);
		{
			//float seg_matrix[16];
			if (HC_Show_Existence ("modelling matrix")) 
			{
				HC_Show_Modelling_Matrix (seg_matrix);

			}
			else 
			{
				memset(seg_matrix,0,16*sizeof(float));
				seg_matrix[0] = seg_matrix[5] = seg_matrix[10] = seg_matrix[15] = 1;
			}

			HUndoItemMatrix *item = new HUndoItemMatrix(GetView(), 1, &segkey, seg_matrix);
			GetView()->GetUndoManager()->AddUndoItem(item);
		}
		HC_Close_Segment();
	}

 	if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToPlane || ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRay || ghandle.GetConstraintType(m_pHandleKey) == HConstrainToViewplane)
	{

		if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRay){

			HPoint tmp(GetNewPoint());
			
			ghandle.AdjustPointToRay(m_pHandleKey, tmp, camerakey, GetView());
		
			SetNewPoint(tmp);
		}

			ghandle.AdjustPointToRay(m_pHandleKey, m_prev_point, camerakey, GetView());

			HC_KEY camerakey = GetView()->GetSceneKey();
			HPoint new_point = GetNewPoint();

			HPoint ds = m_prev_point - m_new_point;

			float transform[16];
			PmeHComponent hComp = m_pDoc->GetComponentFromHKey(m_pView->Selected_key());
			PmeComponentAPI::GetGlobalModellingMatrix(hComp,transform);
			HC_Open_Segment_By_Key(camerakey);
			HC_Set_Modelling_Matrix(transform);
			HC_Compute_Coordinates(".", "world",&ds, "object", &ds);
			HC_UnSet_Modelling_Matrix();
			HC_Close_Segment();
		

		PmeTransformAPI::Translate(m_pDoc->GetAssembly(), hComp, 
			ds.x,
			ds.y,
			ds.z
		);

		m_prev_point = GetNewPoint();

	}
	else
	{
		if (ghandle.GetConstraintType(m_pHandleKey) == HConstrainToRotationVector)
		{
 			
			//HPoint tmp(GetNewPoint());
			
			PmeHComponent hComp = m_pDoc->GetComponentFromHKey(m_pView->Selected_key());

			PmeTransformAPI::Rotate(m_pDoc->GetAssembly(),hComp,m_rotation_axis.x,m_rotation_axis.y,m_rotation_axis.z,(GetFirstPoint().x-tmp.x));
			
			//ghandle.Rotate(m_pHandleKey, (tmp.x - GetFirstPoint().x)*360.0f);
			//m_rotater += (tmp.x - GetFirstPoint().x);
			
		}
		else
		{
			float sf = 1.0f - (tmp.x - GetFirstPoint().x)*5.0f;		
			ghandle.Scale(m_pHandleKey,sf,sf,sf);
		}
	}
	
	HLISTENER_EVENT(HObjectManipulationListener, GetView()->GetEventManager(), ObjectMovedEvent(GetView(),m_pObjectKey,0));

	SetFirstPoint(tmp);

	GetView()->UpdateHighlighting();
	GetView()->SetGeometryChanged();
	GetView()->Update();

	return (HLISTENER_CONSUME_EVENT);
}


int AssemOpMoveHandle::OnLButtonUp(HEventInfo &event)
{

    if(!OperatorStarted())
		return HBaseOperator::OnLButtonUp(event);

	if (m_pObjectKey!= INVALID_KEY)
	{	
	HC_Open_Segment_By_Key(m_pObjectKey);
			    if (HUtility::ShowOneHeuristic("quick moves")) {
					    HC_UnSet_One_Heuristic("quick moves");
				    }
				
				HC_Close_Segment();
	}
 	HUtilityGeomHandle ghandle;

	SetOperatorStarted(false);
	m_bInitialMatrix = false;
  	ResetHandle(ghandle, m_pHandleKey);
	if (m_pHandleKey != INVALID_KEY)
	{	
		if( !GetView()->GetAllowInteractiveCutGeometry() && m_TempCutGeometryVisibility != HCutGeometryVisibilityNone)
			GetView()->SetCutGeometryVisibility(m_TempCutGeometryVisibility);
		/* Drawing the shadows and cut geometry over again takes a long time, lets take them one at a time... */ 
 		GetView()->ForceUpdate();

		if( !GetView()->GetAllowInteractiveShadows() && m_TempShadowMode != HShadowNone ) 
			GetView()->SetShadowMode(m_TempShadowMode);
	}
	
    GetView()->GetSelection()->DeSelectAll();
	m_pView->SetGeomHandleStatus(FALSE);	
	m_pHandleKey = INVALID_KEY;

	GetView()->Update();

	ghandle.ClearAllHandles(GetView());

	return (HLISTENER_CONSUME_EVENT);
}



/*!
	OnKeyDown inserts annotation text near the second point in the annotation line. The text field is terminated by a 
	carriage return event.  Erase is backspace.
	\param event An HEventInfo object containing information about the current event.
	\return An integer value indicating success or failure.
*/
int AssemOpMoveHandle::OnKeyDown(HEventInfo &event)
{

	if (OperatorStarted() || !m_pHandleKey) 
		return HBaseOperator::OnKeyDown(event);

	char the_char = event.GetChar();

	HUtilityAnnotation ghandle;
	char col[256];
	HPoint resx;
	switch((int)the_char){

	case '1':
			HC_Open_Segment_By_Key(m_pObjectKey);
			HC_Set_Color("everything = (transmission = black)");
			HC_Close_Segment();
			//ModifyColorKeyframe(0);
			break;

	case '2':
			HC_Open_Segment_By_Key(m_pObjectKey);
			resx.Set(0.1f, 0.1f, 0.1f);
			sprintf(col,"everything = (transmission = (r=%f g=%f b=%f))", resx.x, resx.y, resx.z);
			HC_Set_Color(col);
			HC_Close_Segment();
			//ModifyColorKeyframe(0);
			break;

	case '0':
			HC_Open_Segment_By_Key(m_pObjectKey);
			HC_Set_Color("everything = (transmission = white)");
			HC_Close_Segment();
			//ModifyColorKeyframe(1);
			break;

	case '5':
			HC_Open_Segment_By_Key(m_pObjectKey);
			char col[MVO_BUFFER_SIZE];
			HC_Show_Color(col);
			HC_Set_Color("everything = (transmission = grey)");
			HC_Show_Color(col);
			HC_Close_Segment();
			//ModifyColorKeyframe(0.5f);
			break;

	case '9':
			HC_Open_Segment_By_Key(m_pObjectKey);
			HC_Show_Color(col);
			HC_Set_Color("everything = (transmission = light grey)");
			HC_Show_Color(col);
			HC_Close_Segment();
			//ModifyColorKeyframe(0.8f);
			break;

	case '+':
			m_boxzoom++;
			HUtilityGeomHandle::ClearAllHandles(GetView());
			if (m_pObjectKey != INVALID_KEY)
			SetupObject(m_pObjectKey);
			m_pHandleKey = INVALID_KEY;
			GetView()->Update();
			break;

	case '-':
			m_boxzoom--;
 			HUtilityGeomHandle::ClearAllHandles(GetView());
			if (m_pObjectKey != INVALID_KEY)
				SetupObject(m_pObjectKey);
			m_pHandleKey = INVALID_KEY;
			GetView()->Update();
			break;

	default:
		break;

	}//switch
 	
 	GetView()->Update();
	return (HOP_OK);
}

void AssemOpMoveHandle::ShowHandle(HUtilityGeomHandle &handle, HC_KEY key)
{
	handle.ShowHandle(key, 0.7f, (HBaseView*)m_pView);
}

void AssemOpMoveHandle::ResetHandle(HUtilityGeomHandle &handle, HC_KEY key)
{
	handle.ResetHandle(key);
}

int AssemOpMoveHandle::SetupHandlesEvent(HBaseView *view, HC_KEY key, bool complex)
{
    Reset(INVALID_KEY);

    return HLISTENER_PASS_EVENT;
}

