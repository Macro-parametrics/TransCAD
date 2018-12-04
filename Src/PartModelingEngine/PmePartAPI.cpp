#include "StdAfx.h"
#include <map>
#include <vector>
#include <algorithm>
#include ".\PmePartAPI.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeReference.h"
#include ".\PmeTransformAPI.h"

#include ".\PmeXmlMacroWriter.h"
#include ".\PmeXmlMacroReader.h"
#include ".\PmeBrepFileReader.h"


typedef std::vector<IPmePartEventListener *> PartListenerList;
typedef std::map<PmeHPart, PartListenerList *> PartListenerMap;
PartListenerMap g_partListeners;

void PmePartAPI::Create(PmeHPart & hPart)
{
	PmePart * pPart = new PmePart();
	hPart = PME_PART2HANDLE(pPart);

	g_partListeners[hPart] = new PartListenerList();

	pPart->UpdateAll();
}

void PmePartAPI::ClearBody(PmeHPart & hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);
	pPart->ClearBody();
}

void PmePartAPI::Delete(PmeHPart & hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerList * pPartListenerList = g_partListeners[hPart];
	if(pPartListenerList)
		delete pPartListenerList;
	pPartListenerList = 0;

	PmePart * pPart = PME_HANDLE2PART(hPart);	
		
	if(pPart)
		delete pPart;
	hPart = 0;
}

void PmePartAPI::UpdateAll(PmeHPart hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);	
		
	pPart->UpdateAll();

	// Update features
	PmeHUpdateInfo hUpdatedFeatures = 0;
	PmeUpdateInfoAPI::Create(hUpdatedFeatures);
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeFeatures::SizeType sizeOfFeatures = pFeatures->GetSize();

	for(PmeFeatures::SizeType i = 0; i < sizeOfFeatures; ++ i)
	{
		PmeFeature * pFeature = pFeatures->GetItem(i);

		PmeUpdateInfoItem infoItem;
		infoItem.hItem = PME_FEATURE2HANDLE(pFeature);
		infoItem.state = PmeUpdateState_Add;

		PmeUpdateInfoAPI::AddItem(hUpdatedFeatures, infoItem);
	}
	
	PmePartAPI::FireFeaturesUpdatedEvent(hPart, hUpdatedFeatures);
	PmeUpdateInfoAPI::Delete(hUpdatedFeatures);

	// Update explicit model
	PmeHUpdateInfo hAddedExplicitModel = 0;
	PmeUpdateInfoAPI::Create(hAddedExplicitModel);
	PmeExplicitModel * pExplicitModel = pPart->GetExplicitModel();

	PmeExplicitModel::SizeType sizeOfExplicitModel = pExplicitModel->GetSize();

	for(PmeExplicitModel::SizeType j = 0; j < sizeOfExplicitModel; ++ j)
	{
		PmeExplicitModelObject * pObject = pExplicitModel->GetItem(j);
		
		PmeUpdateInfoItem infoItem;
		infoItem.hItem = PME_EXPLICITMODELOBJECT2HANDLE(pObject);
		infoItem.state = PmeUpdateState_Add;

		PmeUpdateInfoAPI::AddItem(hAddedExplicitModel, infoItem);
	}	
	
	PmePartAPI::FireExplicitModelUpdatedEvent(hPart, hAddedExplicitModel);
    PmeUpdateInfoAPI::Delete(hAddedExplicitModel);
}

void PmePartAPI::RegisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	if(find(pPartListenerList->begin(), pPartListenerList->end(), pListener) == pPartListenerList->end())
	{
		pPartListenerList->push_back(pListener);
	}
}

void PmePartAPI::UnregisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	
	PartListenerList::iterator i2 = find(pPartListenerList->begin(), pPartListenerList->end(), pListener);
	if(i2 == pPartListenerList->end())
		return;

	pPartListenerList->erase(i2);
}

void PmePartAPI::FireFeaturesUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	PartListenerList::iterator i2 = pPartListenerList->begin();

	while(i2 != pPartListenerList->end())
	{
		(*i2)->OnFeaturesUpdated(hInfo);
		i2 ++;
	}	
}

void PmePartAPI::FireExplicitModelUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	PartListenerList::iterator i2 = pPartListenerList->begin();

	while(i2 != pPartListenerList->end())
	{
		(*i2)->OnExplicitModelUpdated(hInfo);
		i2 ++;
	}	
}

void PmePartAPI::SelectFeatureByName(PmeHPart hPart, CString name, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectFeatureByName(name);
	
	if(pReference)
        hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectObjectByName(PmeHPart hPart, CString name, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectObjectByName(name);
	
	if(pReference)
        hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectBrepByName(PmeHPart hPart, CString name, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectBrepByName(name);
	
	if(pReference)
        hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectPlaneByAxis(PmeHPart hPart, const MrAxis2 & axis2, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectPlaneByAxis(axis2);
	
	if(pReference)
        hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectCurveBy3Points(PmeHPart hPart, const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectCurveBy3Points(start, end, pointOnCurve);
	
	if(pReference)
        hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectCurveByPoint(PmeHPart hPart, const MrPosition & pointOnCurve, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectCurveByPoint(pointOnCurve);

	if(pReference)
		hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::SelectSketchGeometryByName(PmeHPart hPart, CString name, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeSelectionManager * pSelectionManager = pPart->GetSelectionManager();
	PmeReference * pReference = pSelectionManager->SelectSketchGeometryByName(name);

	if(pReference)
		hReference = PME_REFERENCE2HANDLE(pReference);
	else
		hReference = 0;
}

void PmePartAPI::GetFeatures(PmeHPart hPart, PmeHFeatures & hFeatures)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeFeatures * pFeatures = pPart->GetFeatures();
	hFeatures = PME_FEATURES2HANDLE(pFeatures);
}

void PmePartAPI::GetExplicitModel(PmeHPart hPart, PmeHExplicitModel & hExplicitModel)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);
	
	PmeExplicitModel * pExplicitModel = pPart->GetExplicitModel();
	hExplicitModel = PME_FEATURES2HANDLE(pExplicitModel);
}

void PmePartAPI::SaveAsXmlMacro(PmeHPart hPart, CString filename)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeXmlMacroWriter writer(pPart, filename);
	writer.Save();
}


void PmePartAPI::LoadXmlMacro(CString filename, PmeHPart & hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeXmlMacroReader reader(pPart, filename);
	reader.Read();
}

void PmePartAPI::LoadBrepFile( CString filename, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeBrepFileReader reader(pPart, filename);
	reader.Read();
}

void PmePartAPI::SetName(PmeHPart hPart, CString name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->SetName(name);
}

void PmePartAPI::GetName(PmeHPart hPart, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	name = pPart->GetName();
}

void PmePartAPI::GetUniqueName(PmeHPart hPart, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	CString memAddr;

	memAddr.Format("%ld",hPart);

	name = pPart->GetName() + memAddr;
}

void PmePartAPI::SetParentName(PmeHPart hPart, CString name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->SetParentName(name);
}

void PmePartAPI::GetParentName(PmeHPart hPart, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	name = pPart->GetParentName();
}


void PmePartAPI::IsBrepPart( PmeHPart hPart, BOOL& result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	result = pPart->isBrepPart();
}

void PmePartAPI::Undo(PmeHPart hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->Undo();
}

void PmePartAPI::Redo(PmeHPart hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->Redo();
}

void PmePartAPI::SetPlacement( PmeHPart& hPart, MrAxis2 placement )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->SetPlacement(placement);
}

void PmePartAPI::GetPlacement(PmeHPart hPart, MrAxis2 & placement)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	placement = pPart->GetPlacement();
}

void PmePartAPI::GetModellingMatrix(PmeHPart hPart, float* transform)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);
		
	MrTransformation mrTrsf = MrTransformation::CreateCoordinateSystemTransformation(pPart->GetPlacement(), MrAxis2::OXY());

	transform[0] = (float)mrTrsf(0, 0); transform[1] = (float)mrTrsf(1, 0); transform[2] = (float)mrTrsf(2, 0); transform[3] = 0.0f;
	transform[4] = (float)mrTrsf(0, 1); transform[5] = (float)mrTrsf(1, 1); transform[6] = (float)mrTrsf(2, 1); transform[7] = 0.0f;
	transform[8] = (float)mrTrsf(0, 2); transform[9] = (float)mrTrsf(1, 2); transform[10] = (float)mrTrsf(2, 2); transform[11] = 0.0f;
	transform[12] = (float)mrTrsf(0, 3); transform[13] = (float)mrTrsf(1, 3); transform[14] = (float)mrTrsf(2, 3); transform[15] = 1.0f;	
}

/*
void PmePartAPI::GetGlobalModellingMatrix(PmeHPart hPart, float* transform)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	MrTransformation mrTrsf = PmeTransformAPI::CalcModelingMatrix(hComponent);

	transform[0] = mrTrsf(0, 0); transform[1] = mrTrsf(1, 0); transform[2] = mrTrsf(2, 0); transform[3] = 0.0f;
	transform[4] = mrTrsf(0, 1); transform[5] = mrTrsf(1, 1); transform[6] = mrTrsf(2, 1); transform[7] = 0.0f;
	transform[8] = mrTrsf(0, 2); transform[9] = mrTrsf(1, 2); transform[10] = mrTrsf(2, 2); transform[11] = 0.0f;
	transform[12] = mrTrsf(0, 3); transform[13] = mrTrsf(1, 3); transform[14] = mrTrsf(2, 3); transform[15] = 1.0f;	

}
*/