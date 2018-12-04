#pragma once
#include "TransCADScript.h"

class Feature;
class Reference;
class ReferenceBrep;
class ReferenceFeature;
class CustomFeature;
class FeatureSketch;

class Part
{
public:
	Part(void);
	virtual ~Part(void);

	void RunCommands(char * command);

	void OnCreatingSketch(char * command);
	void OnSelectingReferences(char * command);
	void OnSelectingFeatures(char * command);

public:
	void Clear(void);
	void AddInfo(void);
	void CheckCurrentState(void);
	Feature * CopyFeature(Feature * pFeature);

private:
	void RunFeatureCommand(FeatureType type, char * command);
	void RunReferenceCommand(ReferenceType type, char * command);
	void RunGeneralCommand(GeneralType type, char * command);
	
	void AddFeature(TransCAD::IFeaturePtr spFeature);
	
	// 커스텀 피쳐
	void ReadCustomFeatures(void);
	void CreateCustomFeature(char * command);
	
public:
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IDocsPtr, DocsPtr, m_spDocuments);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IPartDocumentPtr, PartDocumentPtr, m_spDocument);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IPartPtr, PartPtr, m_spPart);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IFeaturesPtr, FeaturesPtr, m_spFeatures);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IReferencePtr, CurrentReferencePtr, m_spCurrentRef);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IReferencesPtr, CurrentReferencesPtr, m_spCurrentRefs);

	VARIABLE_GET_AND_SET_FUNC_IMPL(string, InitialTitle, m_initialTitle);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, InitialState, m_initialState);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, CurrentState, m_currentState);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, UpdateCount, m_updateCount);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, UndoCount, m_undoCount);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, RedoCount, m_redoCount);
	VARIABLE_GET_AND_SET_FUNC_IMPL(bool, Restored, m_isRestored);
	
	VARIABLE_GET_AND_SET_FUNC_IMPL(FeatureSketch *, CurrentSketch, m_pCurrentSketch);
	VARIABLE_GET_AND_SET_FUNC_IMPL(ReferenceBrep *, CurrentReference, m_pCurrentReference);
	VARIABLE_GET_AND_SET_FUNC_IMPL(ReferenceFeature *, CurrentFeature, m_pCurrentFeature);
	
	LIST_GET_AND_SET_FUNC_IMPL(Feature *, Feature, m_featureList);
	Feature * GetFeatureByName(string name);

	LIST_GET_AND_SET_FUNC_IMPL(Feature *, HistoryFeature, m_allFeatureList);
	Feature * GetHistoryFeatureByName(string name);
	
	LIST_GET_AND_SET_FUNC_IMPL(CustomFeature *, CustomFeature, m_customFeatureList);
	CustomFeature * GetCustomFeatureByName(string name);

	void Help(char * command);
	vector<string> askInfo;

private:
	TransCAD::IDocsPtr			m_spDocuments;
	TransCAD::IPartDocumentPtr	m_spDocument;
	TransCAD::IPartPtr			m_spPart;
	TransCAD::IFeaturesPtr		m_spFeatures;
	TransCAD::IReferencesPtr	m_spCurrentRefs;
	TransCAD::IReferencePtr		m_spCurrentRef;

	vector<Feature *> m_featureList;		// 현재 특징형상 목록
	vector<Feature *> m_allFeatureList;		// 전체 특징형상 이력 (History)
	vector<CustomFeature *> m_customFeatureList;	// 커스텀 특징형상 목록

	string m_initialTitle;
	int m_initialState, m_currentState;
	int m_updateCount, m_undoCount, m_redoCount;
	bool m_isRestored;

	FeatureType fType;
	ReferenceType rType;
	GeneralType gType;
	SketchItemType sType;

	FeatureSketch * m_pCurrentSketch;
	ReferenceBrep * m_pCurrentReference;
	ReferenceFeature * m_pCurrentFeature;

	string token;
};