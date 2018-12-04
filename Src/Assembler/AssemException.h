#pragma once

#include "AssemMacro.h"

class ASSEM_API AssemException
{
public:
	AssemException(void);
	AssemException(const CString & message);
	virtual ~AssemException(void);

	CString GetMessage(void) const {return m_message;}

private:
	CString m_message; 
};
