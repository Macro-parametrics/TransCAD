#include "StdAfx.h"
#include ".\pmereferences.h"
#include ".\PmeReference.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeReferences, PmeObject)

PmeReferences::PmeReferences(void)
{
}

PmeReferences::~PmeReferences(void)
{
}

PmeReferences::SizeType PmeReferences::FindByName(const CString & name) const
{
	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeReference * pReference = GetItem(i);
		if(pReference->GetName() == name)
			return i;
	}

	return -1;
}

ENTITY_LIST PmeReferences::CreateEntityList(void) const
{
	ENTITY_LIST entities;

	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeReference * pReference = GetItem(i);
		if(pReference->GetReferenceType() == PmeReferenceType_Brep)
		{
			ENTITY * pEntity = pReference->GetPart()->GetSelectionManager()->GetBrepFromReference(pReference);
			entities.add(pEntity);
		}
		//if (pReference->GetReferenceType() == PmeReferenceType_ExplicitModelObject)
		//{
		//	ENTITY * pEntity = pReference->GetPart()->GetSelectionManager()->GetObjectFromReference(pReference);
		//}
	}

	return entities;
}

ENTITY_LIST PmeReferences::CreateEdgeList(void) const
{
	ENTITY_LIST entities;

	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeReference * pReference = GetItem(i);
		if(pReference->GetReferenceType() == PmeReferenceType_Brep)
		{
			ENTITY * pEntity = pReference->GetPart()->GetSelectionManager()->GetBrepFromReference(pReference);
			
			CString type = pEntity->type_name();
			
			if (type == _T("face"))
			{
				ENTITY_LIST edges;
				api_get_edges(pEntity, edges);
				for (int j = 0; j < edges.count(); ++j)
				{
					entities.add(edges[j]);
				}
			}
			else
			{
				entities.add(pEntity);
			}
		
		}
	}

	return entities;
}

PmeReferences * PmeReferences::Clone(void) const
{
	PmeReferences * pNew = new PmeReferences();

	*pNew = *this;

	return pNew;
}