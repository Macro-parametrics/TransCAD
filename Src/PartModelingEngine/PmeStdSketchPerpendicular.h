#pragma once

#include ".\PmeStdSketchConstraint.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeSamePointsType.h"
#include ".\PmeReference.h"

class PmeStdSketchFeature;

class PmeStdSketchPerpendicular
	: public PmeStdSketchConstraint
	, public PmeDcmPerpendicular
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchPerpendicular)
public:
	PmeStdSketchPerpendicular(PmeStdSketchFeature * pSketchFeature, PmeReference * pReferenceEdit, PmeReference * pTarget);
	virtual ~PmeStdSketchPerpendicular(void);

	void SetDNode(d_node * pDNode) {m_pDNode = pDNode;}
	d_node * GetDNode(void) const {return m_pDNode;}

	PmeReference * GetReferenceEdit(void) const {return m_pReferenceEdit;}
	PmeReference * GetTarget(void) const {return m_pTarget;}
	IPmeConstraintable * GetGeometryPart(PmeReference * pReference);

	// PmeStdSketchConstraint
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// PmeStdSketchDimension
	virtual PmeStdSketchConstraintType GetType(void) const {return PmeStdSketchConstraintType_Perpendicular;}
	
	virtual DCM_d_type DcmGetDimensionType() {return DCM_PERPENDICULAR;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}

private:
	d_node * m_pDNode;
	PmeReference * m_pReferenceEdit;
	PmeReference * m_pTarget;
};
