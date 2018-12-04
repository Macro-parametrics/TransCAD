#include "StdAfx.h"
#include ".\PmeReference.h"
#include ".\PmeArgumentException.h"
#include ".\PmeReferences.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeReference, PmeObject)

PmeReference::PmeReference(PmePart * pPart)
: m_pPart(pPart)
{
	GiveDefaultName();
}

PmeReference::PmeReference(PmePart * pPart, const CString & name)
: m_pPart(pPart)
{
	SetName(name);
}

PmeReference::~PmeReference(void)
{
}

void PmeReference::Update(void)
{
}

void PmeReference::SetName(const CString & name)
{
	if(!CheckName(name))
		throw PmeArgumentException(_T("같은 이름을 가진 참조가 존재합니다."));

	m_name = name;
}

void PmeReference::GiveDefaultName(void)
{
	PmeReferences::SizeType size = GetPart()->GetSelectionManager()->GetReferences()->GetSize();
	CString className = GetRuntimeType()->ClassName();
	className.Delete(0, 3);

	do
	{
        m_name.Format(_T("%s%d"), className, ++ size);
	} while(!CheckName(m_name));
}

bool PmeReference::CheckName(const CString & name) const
{
	PmeReferences * pReferences = GetPart()->GetSelectionManager()->GetReferences();
	PmeReferences::SizeType index = pReferences->FindByName(name);

	return index == -1;
}