#pragma once
#include "TransCADScript.h"
#include "Reference.h"

class Part;

class ReferenceExplicitModelObject : public Reference
{
public:
	ReferenceExplicitModelObject(Feature * pFeature, int referenceType);
	virtual ~ReferenceExplicitModelObject(void);
	
	void GetInfo(char * command);
	void AddInfo(TransCAD::IReferencePtr spReference);
	void AddInfo(TransCAD::IReferencesPtr spReferences);

	void AskInfo(void);
	void Help(void);

	void Restore(void);
};