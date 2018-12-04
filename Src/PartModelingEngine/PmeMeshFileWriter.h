#pragma once

#include ".\PmeHandle.h"

class PmeMeshFileWriter
{
public:
	PmeMeshFileWriter(PmeHComponent hComp, int i, CString filename);
	PmeMeshFileWriter(void);
	~PmeMeshFileWriter(void);
	SPAtransf GetMatrix();
	void Save();

private:

	PmeHComponent m_hComp;
	PmeHPart m_hPart;
	CString m_filename;
	
};

