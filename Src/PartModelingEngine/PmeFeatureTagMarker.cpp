#include "stdAfx.h"
#include "PmeFeatureTagMarker.h"
#include "PmeFeature.h"

#define ATTRIB_NAME "FEATURE"

void PmeFeatureTagMarker::Attach(BODY * pBody, PmeFeature * pFeature)
{
	ENTITY_LIST faces;

	api_get_faces(pBody, faces);

	faces.init();
	while(ENTITY * pEntity = faces.next())
	{
		FACE * pFace = static_cast<FACE *>(pEntity);
		Attach(pFace, pFeature);
	}	
}

void PmeFeatureTagMarker::Attach(FACE * pFace, PmeFeature * pFeature)
{
	api_add_generic_named_attribute(pFace, ATTRIB_NAME, (int)(pFeature), SplitCopy, MergeKeepAll);
}

PmeFeature * PmeFeatureTagMarker::FindFeature(ENTITY * pEntity)
{
	ATTRIB_GEN_NAME * pAttr = find_named_attrib(pEntity, ATTRIB_NAME);
	PmeFeature * pFeature = NULL;

	while(pAttr)
	{
		ATTRIB_GEN_INTEGER * pEntityAttrib = static_cast<ATTRIB_GEN_INTEGER *>(pAttr);		
		pFeature = reinterpret_cast<PmeFeature *>(pEntityAttrib->value());
		
		// 한 개의 속성만 찾는다.
		if(pFeature)
			pAttr = NULL;
		else
			pAttr = find_next_named_attrib(pAttr);		
	}

	return pFeature;
}

void PmeFeatureTagMarker::Clear(ENTITY * pEntity)
{
	ENTITY_LIST faces;
	api_get_faces(pEntity, faces);

	// 각각의 FACE에 부여한 ATTRIB_NAME 속성을 지운다.
	for(int i = 0; i < faces.count(); ++ i)
	{
		FACE * pFace = static_cast<FACE *>(faces[i]);
		Detach(pFace);
	}
	////
}

void PmeFeatureTagMarker::Detach(FACE * pFace)
{
	ATTRIB_GEN_NAME * pAttr = NULL;
	
	while(pAttr = find_named_attrib(pFace, ATTRIB_NAME))
	{
		pAttr->unhook();
		pAttr->lose();
	}
}