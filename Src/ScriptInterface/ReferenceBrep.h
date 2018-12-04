#pragma once
#include "TransCADScript.h"
#include "Reference.h"

class Part;

class ReferenceBrep : public Reference
{
public:
	ReferenceBrep(Feature * pFeature, int referenceType);
	virtual ~ReferenceBrep(void);
	
	void GetInfo(char * command);
	void AddInfo(TransCAD::IReferencePtr spReference);
	void AddInfo(TransCAD::IReferencesPtr spReferences);

	void AskInfo(void);
	void Help(void);

	void Restore(void);
	
	void RunCommands(char * command);

private:
	void SelectBrep(char * command);
	void SelectBreps(char * command);
	void SelectFaceByAxis(char * command);
	void SelectEdgeByPoint(char * command);
	void SelectEdgeByPoints(char * command);

	void GetTargetFeaturesFromBrepName(string brepName);
	void GetTargetFeaturesFromFaceName(string faceName);

private:
	int m_totalCount;
	int m_selectCount;
};