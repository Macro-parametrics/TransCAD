#pragma once

#include ".\PmeMacro.h"

class PME_API PmeException
{
public:
	PmeException(void);
	PmeException(const CString & message);
	virtual ~PmeException(void);

	CString GetMessage(void) const {return m_message;}

private:
	CString m_message;
};
