#include "StdAfx.h"
#include ".\pmestdsketchconstraint.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchConstraints.h"
#include ".\PmeArgumentException.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchConstraint, PmeObject)

PmeStdSketchConstraint::PmeStdSketchConstraint(PmeStdSketchFeature * pSketchFeature)
: m_pSketchFeature(pSketchFeature)
{
	GiveDefaultName();
}

PmeStdSketchConstraint::PmeStdSketchConstraint(PmeStdSketchFeature * pSketchFeature, const CString & name)
: m_pSketchFeature(pSketchFeature)
{
	SetName(name);
}

PmeStdSketchConstraint::~PmeStdSketchConstraint(void)
{
}

void PmeStdSketchConstraint::SetName(const CString & name)
{
	if(!CheckName(name))
		throw PmeArgumentException(_T("동일한 스케치 안에 같은 이름을 가진 구속조건이 존재합니다."));

	m_name = name;
}

void PmeStdSketchConstraint::GiveDefaultName(void)
{
	PmeStdSketchConstraints::SizeType size = GetSketchFeature()->GetConstraints()->GetSize();
	CString className = GetRuntimeType()->ClassName();
	className.Delete(0, 3);

	do
	{
        m_name.Format(_T("%s%d"), className, ++ size);
	} while(!CheckName(m_name));
}

bool PmeStdSketchConstraint::CheckName(const CString & name) const
{
	PmeStdSketchConstraints * pConstraints = GetSketchFeature()->GetConstraints();
	
	return pConstraints->FindByName(name) == NULL;
}