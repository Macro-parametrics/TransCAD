#pragma once
#include ".\PmeStdDatumPlaneFeature.h"
#include ".\PmeDatumPlane.h"

//class PmeDatumPlane;
class PmeReference;


class PmeStdDatumPlaneOffsetFeature
	: public PmeStdDatumPlaneFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)
public:
	PmeStdDatumPlaneOffsetFeature(PmePart * pPart);

	PmeStdDatumPlaneOffsetFeature(PmePart * pPart,
								PmeReference * pSelectedPlane,
								double distance,
								bool isFlip = false);

	PmeStdDatumPlaneOffsetFeature(PmePart * pPart,
								double ox, double oy, double oz,// Origin location 
								double xx, double xy, double xz,// X axis coords
								double yx, double yy, double yz,// Y axis coords
								bool isFlip = false);


	virtual ~PmeStdDatumPlaneOffsetFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdDatumPlaneOffsetFeature; }
	virtual void Update(void);

	// PmeStdDatumPlaneFeature
	PmeDatumPlane * GetDatumPlane(void) const {return m_pDatumPlane;}
	//void SetCoordinateSystem(const MrAxis2& coordinateSystem) {m_coordinateSystem = coordinateSystem;}

	// PmeStdDatumPlaneOffsetFeature
	PmeReference * GetSelectedPlane(void) const {return m_pSelectedPlane;}
	bool IsFlip(void) const {return m_isFlip;}
	bool IsFree(void) const {return m_isFree;}
	double GetDistance(void) const {return m_distance;}

	MrPosition GetOrigin() {return m_origin;}
	MrDirection GetXDirection() {return m_xDir;}
	MrDirection GetYDirection() {return m_yDir;}

	void SetSelectedPlane(PmeReference * pSelectedPlane) {m_pSelectedPlane = pSelectedPlane;}
	void SetFlip(bool isFlip) {m_isFlip = isFlip;}
	void SetDistance(double distance) {m_distance = distance;}
	void SetOrigin(MrPosition origin) {m_origin = origin;}
	void SetXDirection(MrDirection xDir) {m_xDir = xDir;}
	void SetYDirection(MrDirection yDir) {m_yDir = yDir;}

protected:
	MrDirection GetInternalDirection();

private:
	PmeDatumPlane * m_pDatumPlane;

	MrAxis2 m_coordinateSystem;

	MrPosition m_origin;
	MrDirection m_xDir;
	MrDirection m_yDir;

	PmeReference * m_pSelectedPlane;
	bool m_isFlip;
	double m_distance;
	bool m_isFree;
};

