#include "StdAfx.h"
#include ".\pmeexplicitmodel.h"
#include ".\PmeSolid.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeExplicitModel, PmeObject)

PmeExplicitModel::PmeExplicitModel(void)
: m_pSolid(0)
{
}

PmeExplicitModel::~PmeExplicitModel(void)
{
	if(m_pSolid)
        delete m_pSolid;
	
	m_pSolid = 0;
}

void PmeExplicitModel::Add(PmeExplicitModelObject * item)
{
	SizeType index = Find(item);
	if(index == -1)
	{
        BaseList::Add(item);
        m_updateFlags[item] = true;
	}
	else
	{
		Update(item);
	}
}

void PmeExplicitModel::Update(PmeExplicitModelObject * item)
{
	UpdateMap::iterator i = m_updateFlags.find(item);
	if(i == m_updateFlags.end())
		return;

	i->second = false;
}

bool PmeExplicitModel::IsUpdated(PmeExplicitModelObject * item) const
{
	UpdateMap::const_iterator i = m_updateFlags.find(item);
	
	ASSERT(i != m_updateFlags.end());

	return i->second;
}

void PmeExplicitModel::SetSolid(PmeSolid * pItem)
{
	int index = Find(pItem);
	if(index == -1)
		Add(pItem);

	m_pSolid = pItem;
}

PmeSolid * PmeExplicitModel::GetSolid(void) const
{
	return m_pSolid;
}

PmeExplicitModelObject * PmeExplicitModel::FindByName(const CString & name) const
{
	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeExplicitModelObject * pObject = GetItem(i);
		if(pObject->GetName() == name)
			return pObject;
	}

	return 0;
}

void PmeExplicitModel::Clear(void)
{
	BaseList::Clear();
	m_pSolid = 0;
}

void PmeExplicitModel::Delete(SizeType index)
{
	if(GetItem(index) == m_pSolid)
		m_pSolid = 0;

	BaseList::Delete(index);
}