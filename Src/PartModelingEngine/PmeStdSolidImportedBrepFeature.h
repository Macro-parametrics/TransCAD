#pragma once
#include "pmestdsolidfeature.h"
#include "IPmePattern.h"

class PmeStdSolidImportedBrepFeature :
	public PmeStdSolidFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidImportedBrepFeature)
public:
	PmeStdSolidImportedBrepFeature(PmePart * pPart, const CString & filePath);
	virtual ~PmeStdSolidImportedBrepFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidImportedBrepFeature;}
	virtual void Update(void);
	
	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

	//void SetBrepBody(BODY * pBrepBody) {m_pBrepBody = pBrepBody;}
	//BODY * GetBrepBody(void) {return m_pBrepBody;}

	CString GetFilePath(void) const {return m_filePath;}

protected:
	void CreateSolidBody(BODY *& pBody);

private:
	void AttachName(BODY *& pBody);

private:
	//BODY * m_pBrepBody;
	CString m_filePath;
};
