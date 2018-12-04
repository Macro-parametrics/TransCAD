#include "StdAfx.h"
#include ".\pmefeatures.h"
#include ".\PmeFeature.h"


PME_IMPLEMENT_RUNTIME_TYPE(PmeFeatures, PmeObject)

PmeFeatures::PmeFeatures(void)
{
}

PmeFeatures::~PmeFeatures(void)
{
}

void PmeFeatures::Add(PmeFeature * item)
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

void PmeFeatures::Update(PmeFeature * item)
{
	UpdateMap::iterator i = m_updateFlags.find(item);
	if(i == m_updateFlags.end())
		return;

	i->second = false;
}

PmeFeature * PmeFeatures::FindByName(const CString & name) const
{
	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeFeature * pFeature = GetItem(i);
		if(pFeature->GetName() == name)
			return pFeature;
	}

	return 0;
}


bool PmeFeatures::IsUpdated(PmeFeature * item) const
{
	UpdateMap::const_iterator i = m_updateFlags.find(item);
	
	ASSERT(i != m_updateFlags.end());

	return i->second;
}

void PmeFeatures::MustUpdate(PmeFeature * item)
{
	UpdateMap::iterator i = m_updateFlags.find(item);
	if(i == m_updateFlags.end())
		return;

	i->second = true;
}