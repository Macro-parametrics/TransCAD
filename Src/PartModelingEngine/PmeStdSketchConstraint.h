#pragma once

#include ".\PmeObject.h"
#include ".\PmeStdSketchConstraintType.h"

class PmeStdSketchFeature;
class PmeStdSketchEditor;

class PmeStdSketchConstraint
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchConstraint)
public:
	PmeStdSketchConstraint(PmeStdSketchFeature * pSketchFeature);
	PmeStdSketchConstraint(PmeStdSketchFeature * pSketchFeature, const CString & name);
	virtual ~PmeStdSketchConstraint(void);
	
	virtual PmeStdSketchConstraintType GetType(void) const = 0;

	CString GetName(void) const {return m_name;}
	PmeStdSketchFeature * GetSketchFeature(void) const {return m_pSketchFeature;}

	void SetName(const CString & name);
	void GiveDefaultName(void);

	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor) = 0;
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor) = 0;

private:
	bool CheckName(const CString & name) const;

private:
	CString m_name;
	PmeStdSketchFeature * m_pSketchFeature;
};