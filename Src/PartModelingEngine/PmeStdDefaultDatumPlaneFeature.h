#pragma once
#include "pmestddatumplanefeature.h"
#include ".\PmeStdDefaultDatumPlaneFeatureType.h"

class PmeStdDefaultDatumPlaneFeature
	: public PmeStdDatumPlaneFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdDefaultDatumPlaneFeature)
public:
	PmeStdDefaultDatumPlaneFeature(PmePart * pPart, PmeStdDefaultDatumPlaneFeatureType type);
	virtual ~PmeStdDefaultDatumPlaneFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdDefaultDatumPlaneFeature; }
	virtual void Update(void);

	PmeStdDefaultDatumPlaneFeatureType GetType(void) const {return m_type;}

private:
	PmeStdDefaultDatumPlaneFeatureType m_type;	
};
