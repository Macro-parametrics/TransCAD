#pragma once

#include ".\PmeHandle.h"

class PmeBrepFileReader
{
public:
	PmeBrepFileReader(PmeHPart hPart, CString filename);
	PmeBrepFileReader(void);
	~PmeBrepFileReader(void);
	void Read();


private:
	PmeHPart m_hPart;
	CString m_filename;
};

