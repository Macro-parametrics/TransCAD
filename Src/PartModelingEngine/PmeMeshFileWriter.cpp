#include "StdAfx.h"
#include "PmeMeshFileWriter.h"
#include "PmeHandleMacro.h"
#include "PmeBrepFileReader.h"
#include "PmePart.h"
#include "PmeExplicitModel.h"
#include "PmeSolid.h"
#include "PmeComponentAPI.h"
#include "PmeComponent.h"
#include "PmeTransformAPI.h"
#include "stlmmg.hxx"
#include "fct_utl.hxx"
#include "facet_options.hxx"
#include "transf.hxx"

PmeMeshFileWriter::PmeMeshFileWriter(void)
{
}

PmeMeshFileWriter::PmeMeshFileWriter(PmeHComponent hComp, int i, CString filename )
	:m_hComp(hComp)
	, m_filename(filename)
{
	
 	PmeComponent* pComp = PME_HANDLE2COMPONENT(m_hComp);
 	m_hPart = pComp->GetPart(i);
	
	TRACE("\n%s",pComp->GetName());
}




PmeMeshFileWriter::~PmeMeshFileWriter(void)
{

}

void PmeMeshFileWriter::Save()
{
	PmePart * pPart = PME_HANDLE2PART(m_hPart);

	outcome res;
	ENTITY_LIST list;

	PmeExplicitModel * pExplicitModel = pPart->GetExplicitModel();
	
	int size = pExplicitModel->GetSize();

	SPAtransf tr = GetMatrix();

	TRANSFORM* TR = new TRANSFORM; TR->set_transform(tr.inverse());

	for (int i = 0; i<size;i++)
	{
		PmeExplicitModelObject* pExpObj =  pExplicitModel->GetItem(i);
		
		PmeExplicitModelObjectType type = pExpObj->GetType();

		if(type == PmeExplicitModelObjectType_Solid)
		{
				PmeSolid * pSolid = (PmeSolid*)pExpObj;
		
				BODY* pBody =pSolid->GetSolid(); 

				outcome o = api_change_body_trans(pBody,TR);
				check_outcome(o);
				list.add(pBody);
		}
	}
		

	STL_MESH_MANAGER * MyMeshManager = NULL;

	// Get the previous mesh manager.
	FILE * fp_stl = NULL;
	fopen_s(&fp_stl, (CStringA)m_filename,"wt");

// 		facet_options_precise * fop =new facet_options_precise;
//  		fop->set_surface_tolerance(0.001);
//  		fop->set_normal_tolerance(10);
		
	// Tell the Faceter to use our STL_MESH_MANAGER.
	MyMeshManager = ACIS_NEW STL_MESH_MANAGER();
	res = api_set_mesh_manager( MyMeshManager );
	MyMeshManager->set_output_file(fp_stl);
	check_outcome( res );

	for(int i = 0 ; i<list.count();i++)
	{
		// Facet all entities in the model.
		res = api_facet_entity(list[i]);
		check_outcome( res );
	}

	delete MyMeshManager;

	fclose(fp_stl);
}

SPAtransf PmeMeshFileWriter::GetMatrix()
{
	SPAtransf tr;
	PmeHComponent hComp = m_hComp;
	PmeHComponent hParent;
	
	do 
	{
		MrAxis2 placement;
		PmeComponentAPI::GetPlacement(hComp, placement);
		
		MrPosition O = placement.Location();
		MrDirection dirx = placement.XDirection();
		MrDirection diry = placement.YDirection();

		SPAposition new_origin(O.X(),O.Y(),O.Z());
		SPAunit_vector new_x_axis = normalise(SPAvector(dirx.X(),dirx.Y(),dirx.Z()));
		SPAunit_vector new_y_axis = normalise(SPAvector(diry.X(),diry.Y(),diry.Z()));
		
		SPAtransf trp = coordinate_transf(new_origin, new_x_axis, new_y_axis);

		if(!trp.identity()) 
			tr *= trp;

		PmeComponentAPI::GetParentComp(hComp,hParent);
		hComp = hParent;
	}
	while (hComp);

	return tr;
}