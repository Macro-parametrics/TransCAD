#pragma once
#include "pmeexplicitmodelobject.h"

class PmeDatumPlane
	: public PmeExplicitModelObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeDatumPlane)
public:
	PmeDatumPlane(void);
	PmeDatumPlane(const MrAxis2 & location);
	virtual ~PmeDatumPlane(void);

	virtual PmeExplicitModelObjectType GetType(void) const {
		if(!isOffset)return PmeExplicitModelObjectType_DatumPlane;
		else return PmeExplicitModelObjectType_OffsetDatumPlane;
	}

	MrAxis2 GetLocation(void) const {return m_location;}
	void SetLocation(const MrAxis2 & location) {m_location = location;}
	void SetOffsetFlag(bool nFlag) {isOffset = nFlag;}

private:
	MrAxis2 m_location;
	bool isOffset;
};
