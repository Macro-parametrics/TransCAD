#pragma once

#include ".\PmeMacro.h"

#define PME_RUNTIME_TYPE(name) &##name::s_runtimeType##name

#define PME_DECLARE_RUNTIME_TYPE(name) \
	public: \
	static const PmeRuntimeType s_runtimeType##name; \
	virtual PmeRuntimeType const * GetRuntimeType(void) const;

#define PME_IMPLEMENT_RUNTIME_TYPE(name, base) \
	const PmeRuntimeType name::s_runtimeType##name = PmeRuntimeType(_T(#name), PME_RUNTIME_TYPE(base)); \
	PmeRuntimeType const * name::GetRuntimeType(void) const {return &s_runtimeType##name;}

class PME_API PmeRuntimeType
{
public:
	PmeRuntimeType(const CString & className, const PmeRuntimeType * pBaseClass = 0);
	~PmeRuntimeType(void);

	CString ClassName(void) const {return m_className;}
	const PmeRuntimeType * BaseClass(void) const {return m_pBaseClass;}

	bool IsSubclassOf(const PmeRuntimeType * pBaseClass) const;

private:
	CString m_className;
	const PmeRuntimeType * m_pBaseClass;
};