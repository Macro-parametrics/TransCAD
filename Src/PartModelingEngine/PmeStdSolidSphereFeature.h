#pragma once
#include "pmestdsolidfeature.h"

class PmeStdSolidSphereFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidSphereFeature)
public:
	PmeStdSolidSphereFeature(PmePart * pPart);
	PmeStdSolidSphereFeature(PmePart * pPart, const MrPosition & location, double radius);
	virtual ~PmeStdSolidSphereFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidSphereFeature;}
	virtual void Update(void);

	MrPosition GetLocation(void) const {return m_location;}
	double GetRadius(void) const {return m_radius;}

	void SetLocation(const MrPosition & location) {m_location = location;}
	void SetRadius(double radius) {m_radius = radius;}

private:
	MrPosition m_location;
	double m_radius;
};
