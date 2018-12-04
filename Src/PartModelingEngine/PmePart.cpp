#include "StdAfx.h"	//
#include ".\pmepart.h"	//
#include ".\PmeFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeStdDefaultDatumPlaneFeature.h"
#include ".\PmeSelectionManager.h"	//
#include ".\PmeSolid.h"
#include ".\PmeException.h"	//
#include ".\PmeFeatureTagMarker.h"

// For uploading git, separate license file
#include "License\License.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmePart, PmeObject)

PmePart::PmePart(void)
{
	if(!unlock_spatial_products_6394())
		throw PmeException(_T("Failed to initialize ACIS license"));

	m_pFeatures = new PmeFeatures();

	m_pExplicitModel = new PmeExplicitModel();
	
	m_pSelectionManager = new PmeSelectionManager(this);

	CreateDefaultPlanes();

	m_isBrepPart = FALSE;

	m_placement = m_placement.OXY();

	SetName(_T("Part"));
}

PmePart::~PmePart(void)
{	
	ClearExplicitModel();
	ClearFeatures();

	ASSERT(m_pSelectionManager);
	delete m_pSelectionManager;	

	ASSERT(m_pExplicitModel);
	delete m_pExplicitModel;

	ASSERT(m_pFeatures);
	delete m_pFeatures;
}

void PmePart::CreateDefaultPlanes(void)
{
	PmeStdDefaultDatumPlaneFeature * pXYPlane = new PmeStdDefaultDatumPlaneFeature(this, PmeStdDefaultDatumPlaneFeatureType_XYPlane);
	PmeStdDefaultDatumPlaneFeature * pYZPlane = new PmeStdDefaultDatumPlaneFeature(this, PmeStdDefaultDatumPlaneFeatureType_YZPlane);
	PmeStdDefaultDatumPlaneFeature * pZXPlane = new PmeStdDefaultDatumPlaneFeature(this, PmeStdDefaultDatumPlaneFeatureType_ZXPlane);

	m_pFeatures->Add(pXYPlane);
	m_pFeatures->Add(pYZPlane);
	m_pFeatures->Add(pZXPlane);
}

void PmePart::ClearFeatures(void)
{
	PmeFeatures::SizeType size = m_pFeatures->GetSize();

	for(PmeFeatures::SizeType i = 0; i < size; ++ i)
	{
		PmeFeature * pFeature = m_pFeatures->GetItem(i);
		if(pFeature)
			delete pFeature;
	}
}

void PmePart::UpdateAll(void)
{
	ClearExplicitModel();

	PmeSolid * pSolid = new PmeSolid();
	pSolid->SetName("PartBody");
	GetExplicitModel()->SetSolid(pSolid);

	PmeFeatures::SizeType size = m_pFeatures->GetSize();

	for(PmeFeatures::SizeType i = 0; i < size; ++ i)
	{
		PmeFeature * pFeature = m_pFeatures->GetItem(i);
		ASSERT(pFeature);
		pFeature->Update();
		m_pFeatures->Update(pFeature);
	}
}

void PmePart::UpdateLast(void)
{
	PmeFeatures::SizeType last = m_pFeatures->GetSize() - 1;
	if(last < 0)
		return;

	PmeFeature * pFeature = m_pFeatures->GetItem(last);

	if(m_pFeatures->IsUpdated(pFeature))
	{
		pFeature->Update();
		
		//if (pFeature->GetFeatureType() != PmeFeatureType_StdDefaultDatumPlaneFeature
		//	&& pFeature->GetFeatureType() != PmeFeatureType_StdSketchFeature)
		//{
		//	DELTA_STATE * ds;
		//	api_note_state(ds);
		//}

		m_pFeatures->Update(pFeature);
	}
}

void PmePart::ClearExplicitModel(void)
{
	PmeExplicitModel::SizeType size = m_pExplicitModel->GetSize();

	for(PmeExplicitModel::SizeType i = 0; i < size; ++ i)
	{
		PmeExplicitModelObject * pObject = m_pExplicitModel->GetItem(i);
		if(pObject)
			delete pObject;
	}

	m_pExplicitModel->Clear();
}

void PmePart::ClearBody(void)
{
	BODY * pBody = GetExplicitModel()->GetSolid()->GetSolid();

	PmeFeatureTagMarker::Clear(pBody);
}

void PmePart::Clear()
{
	ClearFeatures();
	CreateDefaultPlanes();
	ClearExplicitModel();	
}

void PmePart::Undo(void)
{
	HISTORY_STREAM * m_hs;
	api_get_default_history(m_hs);
	
	//DELTA_STATE * active_ds;
	//api_get_active_state(active_ds, m_hs);
    //api_change_state
	//active_ds->roll();

	//DELTA_STATE * next_ds = m_deltaStateList[m_deltaStateList.size() - 1];
	
	int nActual;
	outcome result = api_roll_n_states(m_hs, -1, nActual);
	//outcome result = api_change_state(active_ds->prev());

	//api_get_active_state(active_ds, m_hs);

	//outcome result = api_change_to_state(m_hs, next_ds, nActual);

	if (!result.ok())
		return;
}

void PmePart::Redo(void)
{
	//if (!m_hs)
	HISTORY_STREAM * m_hs;
	api_get_default_history(m_hs);

	int nRequest = 7;
	int nActual;
	outcome result = api_roll_n_states(m_hs, nRequest, nActual);
	//outcome result = api_change_to_state(m_hs, 6, nActual);
	
	if (!result.ok())
		return;
}
