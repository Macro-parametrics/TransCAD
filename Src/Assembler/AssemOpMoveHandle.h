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
// $Header: /files/homes/master/cvs/hoops_master/shared/partviewer_common/HSOpMoveHandle.h,v 1.16 2007-06-05 18:57:57 reuben Exp $
//

// HSOpMoveHandle.h : interface of the HSOpMoveHandle class
// selection/movement of geometry handles

#ifndef _HSOpMoveHandle_H
#define _HSOpMoveHandle_H

#include "HTools.h"
#include "HBaseOperator.h"
#include "HUtilityGeomHandle.h"

//! The HSOpMoveHandle class selects/moves "handles" and their associated geometry
/*! 
  HSOpMoveHandle implements three mouse event methods defined on the base class and maps the event information
  to operator routines. This operation consists of the following steps:
  <ol>
  <li>Left Button Down:				new handle object selected
  <li>Left Button Down and Drag:	dragging of handle and associated geometry
  <li>Left Button Up:				operation ended
  </ol>
  More Detailed Description: see event methods
*/
class CDialog;
////class CKeyframeEditor;
class AssemView;
class AssemDocument;

class AssemOpMoveHandle : public HOpSelectAperture, public HObjectManipulationListener
{
public:
     AssemOpMoveHandle (HBaseView* view, AssemView* WinView, AssemDocument* WinDoc,  bool allowSelect = true, int DoRepeat=0, int DoCapture=1);
    ~AssemOpMoveHandle();


	/*!
		\return A pointer to a character string denoting the name of the operator  'Move Handle'
	*/
  	virtual const char * GetName();  

	/*!
		OnLButtonDown selects an existing handle if the mouse is over a handle or designates a new object
		for handle based movement 
		\param event An HEventInfo object containing information about the current event.
		\return A value indicating the result of the event handling.
	*/
    virtual int OnLButtonDown (HEventInfo &event);

	/*!
		OnLButtonDownAndMove moves/rotates/scales the handle and it's associated geometry based on various constrains (ray, plane, etc)
 		\param event An HEventInfo object containing information about the current event.
		\return A value indicating the result of the event handling.
	*/
	virtual int OnLButtonDownAndMove(HEventInfo &event);

	/*!
		OnNoButtonDownAndMove activates handle in mouse cursor range
 		\param event An HEventInfo object containing information about the current event.
		\return A value indicating the result of the event handling.
	*/
	virtual int OnNoButtonDownAndMove(HEventInfo &event);

	/*!
		OnLButtonUp finalizes mouse movement and deselectes active handle
 		\param event An HEventInfo object containing information about the current event.
		\return A value indicating the result of the event handling.
	*/
    virtual int OnLButtonUp (HEventInfo &event);
 

	//! Find handle based on mouse position
	virtual HC_KEY FindHandle(HEventInfo &event);

	/*!
		Find geometry based on mouse position
 		\param event An HEventInfo object containing information about the current event.
 		\param key Key of currently selected object
 		\param exclude Exclude currently selected object from search
		\return key of the geometry at mouse position that serves as new handle target
	*/
	virtual HC_KEY FindObject(HEventInfo &event, HC_KEY key, bool exclude = false);

	/*!
		Create various handles for choosen geometry
  		\param key  Key of geometry to attach handles to
 	*/
	virtual void SetupObject(HC_KEY key);

	//! Reset operator
	virtual void Reset(HC_KEY okey = -1);
	
	virtual HBaseOperator * Clone();
	virtual int OnKeyDown(HEventInfo &event);

  	//virtual void ModifyKeyframe(HConstrainType ct);
	float m_rotater;
	//void ModifyColorKeyframe(float t);
	HPoint m_midpoint;
 	HC_KEY GetObjectKey() { return m_pObjectKey; }
//	void SetOwnerDialog(CDialog *dialog) { m_pOwnerDialog = dialog; }
//	void SetKeyframeEditor(CKeyframeEditor *ke) { m_pKeyframeEditor = ke; }
	void ShowHandle(HUtilityGeomHandle &handle, HC_KEY key);
 
	void ResetHandle(HUtilityGeomHandle &handle, HC_KEY key);
	HC_KEY IsCameraSet(HC_KEY key);
	int SetupHandlesEvent(HBaseView *view, HC_KEY key, bool complex);
protected:
//	CKeyframeEditor *		m_pKeyframeEditor;
	AssemView *		m_pView;
	AssemDocument * m_pDoc;
 	HC_KEY m_pHandleKey;	//!< key of active handle
	HC_KEY m_pObjectKey;    //!< key of handle object
	bool m_bAllowSelect;    //!< allow selection of different handle objects (disabled for cutting plane)
	int m_boxzoom;
	HC_KEY m_selected_key;
	HPoint m_new_point;
	HPoint m_prev_point;
	HPoint m_rotation_axis;
	//CDialog					*m_pOwnerDialog;
	bool					m_bInitialMatrix;
};


#endif
