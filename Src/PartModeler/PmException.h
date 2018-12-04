#pragma once

#include ".\PmMacro.h"

class PM_API PmException
{
public:
	PmException(void);
	PmException(const CString & message);
	virtual ~PmException(void);

	CString GetMessage(void) const {return m_message;}

private:
	CString m_message;
};
