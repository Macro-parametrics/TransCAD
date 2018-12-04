#pragma once

#include ".\PmeStdSketchConstraint.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeSamePointsType.h"
#include ".\PmeReference.h"

class PmeStdSketchFeature;

class PmeStdSketchCoincident
	: public PmeStdSketchConstraint
	, public PmeDcmCoincident
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchCoincident)
public:
//	PmeStdSketchCoincident(PmeStdSketchFeature * pSketchFeature, IPmeConstraintable * pFirstGeometry, IPmeConstraintable * pSecondGeometry);
	PmeStdSketchCoincident(PmeStdSketchFeature * pSketchFeature, PmeReference * pFirstGeometry, PmeSamePointsType firstType, PmeReference * pSecondGeometry, PmeSamePointsType secondType);
	virtual ~PmeStdSketchCoincident(void);

	void SetDNode(d_node * pDNode) {m_pDNode = pDNode;}
	d_node * GetDNode(void) const {return m_pDNode;}

// 	IPmeConstraintable * GetFirstGeometry(void) const {return m_pFirstGeometry;}
// 	IPmeConstraintable * GetSecondGeometry(void) const {return m_pSecondGeometry;}
	PmeReference * GetFirstGeometry(void) const {return m_pFirstGeometry;}
	PmeReference * GetSecondGeometry(void) const {return m_pSecondGeometry;}
	IPmeConstraintable * GetGeometryPart(PmeReference * pReference, PmeSamePointsType type);
	PmeSamePointsType GetFirstObjectType(void) const {return m_FirstType;}
	PmeSamePointsType GetSecondObjectType(void) const {return m_SecondType;}

	// PmeStdSketchConstraint
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// PmeStdSketchDimension
//	virtual PmeStdSketchConstraintType GetType(void) const {return PmeStdSketchConstraintType_Coincident;}
	virtual PmeStdSketchConstraintType GetType(void) const {return PmeStdSketchConstraintType_CoincidentSamePoints;}
	
	virtual DCM_d_type DcmGetDimensionType() {return DCM_COINCIDENT;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}

private:
	d_node * m_pDNode;
//	IPmeConstraintable * m_pFirstGeometry;
	PmeReference * m_pFirstGeometry;
	PmeSamePointsType m_FirstType;
//	IPmeConstraintable * m_pSecondGeometry;
	PmeReference * m_pSecondGeometry;
	PmeSamePointsType m_SecondType;
};
