#include "StdAfx.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchGeometry.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchGeometries, PmeObject)

PmeStdSketchGeometries::PmeStdSketchGeometries(void)
{
}

PmeStdSketchGeometries::~PmeStdSketchGeometries(void)
{
}

PmeStdSketchGeometry * PmeStdSketchGeometries::FindByName(const CString & name) const
{
	SizeType size = GetSize();

	for(SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchGeometry * pGeometry = GetItem(i);
		if(pGeometry->GetName() == name)
			return pGeometry;
	}

	return 0;
}