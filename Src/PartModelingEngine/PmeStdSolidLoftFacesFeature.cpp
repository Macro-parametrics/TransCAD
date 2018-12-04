#include "StdAfx.h"
#include "PmeStdSolidLoftFacesFeature.h"
#include <algorithm>

#include "PmePart.h"
#include "PmeSelectionManager.h"
#include "PmeSolid.h"
#include "PmeExplicitModel.h"

#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"

#include ".\pmepersistentname.h"
#include ".\attr_pme_vertexname.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature, PmeStdSolidFeature)

PmeStdSolidLoftFacesFeature::PmeStdSolidLoftFacesFeature(PmePart * pPart)
	: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidLoftFacesFeature::PmeStdSolidLoftFacesFeature(PmePart * pPart,
	PmeReference * pFace1,
	double param1,
	PmeReference * pFace2,
	double param2)
	: PmeStdSolidFeature(pPart)
	, m_Face1(pFace1)
	, m_Face2(pFace2)
	, m_param1(param1)
	, m_param2(param2)
{
}

PmeStdSolidLoftFacesFeature::~PmeStdSolidLoftFacesFeature(void)
{

}

BODY * PmeStdSolidLoftFacesFeature::LoftSolid(FACE *& pFace_1, FACE *& pFace_2)
{

	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	skin_options options;
	
	options.set_defaults();


	API_BEGIN
		FACE* face_c1;
		FACE* face_c2;
		api_copy_entity_contents(pFace_1,(ENTITY*&)face_c1);
		api_copy_entity_contents(pFace_2,(ENTITY*&)face_c2);

		result = api_loft_faces(face_c1, m_param1, face_c2, m_param2, pResult, &options);
		
		if(!result.ok())
		{
			TRACE("\nextension err: %s\n",result.get_error_info()->error_message()); 
			return 0;
		}
	check_outcome(result);
	API_END

// 		if(g_bNamingType)
// 			AttachName(pNewProfile);
// 		else
// 		{
// 			AttachVertexName_pointbased(pNewProfile);
// 			AttachFaceName_pointbased(pNewProfile);
// 		}


		api_clear_annotations();

	return pResult;
}

void PmeStdSolidLoftFacesFeature::Update(void)
{

	FACE * face_1 = (FACE*) GetPart()->GetSelectionManager()->GetBrepFromReference(m_Face1);
	FACE * face_2 = (FACE*) GetPart()->GetSelectionManager()->GetBrepFromReference(m_Face2);

 	BODY * pBody = LoftSolid(face_1, face_2);
 
 	PmePart * pPart = GetPart();
 	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
 
 	BODY * pOldBody = pSolid->GetSolid();
 
 	API_BEGIN
 
 		result = api_boolean(pBody, pOldBody, UNION);
 
 
 	if(result.ok())
 	{
 		PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
 		pSolid->UpdateSolid(pOldBody);
 		SetSolid(pSolid);
 	}
	else
	{
		TRACE("\nextension err: %s\n",result.get_error_info()->error_message()); 
	}
	check_outcome(result);
 	API_END	
}