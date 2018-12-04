#pragma once
#include "TransCADScript.h"
#include "Reference.h"

class Part;

class ReferenceFeature : public Reference
{
public:
	ReferenceFeature(Feature * pFeature, int referenceType);
	virtual ~ReferenceFeature(void);
	
	void GetInfo(char * command);
	
	void AddInfo(TransCAD::IReferencePtr spReference);
	void AddInfo(TransCAD::IReferencesPtr spReferences);
	
	void AskInfo(void);
	void Help(void);
	
	void Restore(void);

	void RunCommands(char * command);

private:
	void SelectFeature(char * command);
	void SelectFeatures(char * command);

private:
	int m_totalCount;
	int m_selectCount;
};