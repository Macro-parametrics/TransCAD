#pragma once

#include ".\PmeStdSketchConstraint.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeSamePointsType.h"
#include ".\PmeReference.h"

class PmeStdSketchFeature;

class PmeStdSketchVertical
	: public PmeStdSketchConstraint
	, public PmeDcmParallel
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchVertical)
public:
	PmeStdSketchVertical(PmeStdSketchFeature * pSketchFeature, PmeReference * pTarget);
	virtual ~PmeStdSketchVertical(void);

	void SetDNode(d_node * pDNode) {m_pDNode = pDNode;}
	d_node * GetDNode(void) const {return m_pDNode;}

	PmeReference * GetTarget(void) const {return m_pTarget;}
	IPmeConstraintable * GetGeometryPart(PmeReference * pReference);

	// PmeStdSketchConstraint
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// PmeStdSketchDimension
	virtual PmeStdSketchConstraintType GetType(void) const {return PmeStdSketchConstraintType_Vertical;}
	
	virtual DCM_d_type DcmGetDimensionType() {return DCM_PARALLEL;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}

private:
	d_node * m_pDNode;
	PmeReference * m_pTarget;
};
