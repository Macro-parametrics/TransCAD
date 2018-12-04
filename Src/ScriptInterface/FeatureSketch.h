#pragma once
#include "TransCADScript.h"
#include "Object.h"
#include "Feature.h"
#include "SketchItem.h"
#include "Reference.h"

class SketchItem;
class Reference;

typedef vector<SketchItem*> SketchItemList;

class FeatureSketch : public Feature
{
public:
	FeatureSketch(Part * pPart, int featureType);	// 기본 생성자
	FeatureSketch(FeatureSketch & pSketch)			// 복사 생성자
		:Feature(pSketch.GetPart(), pSketch.GetType())
	{
		CopyBasicInformation(pSketch);
		SetSketchPtr(pSketch.GetSketchPtr());
		SetEditorPtr(pSketch.GetEditorPtr());
		SetCloseness(pSketch.GetCloseness());
		m_currentState = 0;
		m_updateCount = 0;
		m_undoCount = 0;
		m_redoCount = 0;

		m_sketchItemList = CopySketchItemList(pSketch.m_sketchItemList);
		m_tempSketchList.push_back(CopySketchItemList(m_sketchItemList));

		for (int i = 0; i < 9; ++i)
			m_sketchCoord[i] = pSketch.m_sketchCoord[i];
	}

	virtual ~FeatureSketch(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	void AddSketchItem(TransCAD::IStdSketchGeometryPtr spSketchItem);

	void Create(void);
	void Modify(char * command);
	void AskInfo(void);
	void Help(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::IStdSketchFeaturePtr, SketchPtr, m_spSketch);
	VARIABLE_GET_AND_SET_FUNC_IMPL(TransCAD::ISketchEditorPtr, EditorPtr, m_spEditor);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, Closeness, m_closeness);
	void CheckCloseness(void);

	LIST_GET_AND_SET_FUNC_IMPL(SketchItemList, HistorySketchItem, m_tempSketchList);
	LIST_GET_AND_SET_FUNC_IMPL(SketchItem *, SketchItem, m_sketchItemList);
	SketchItem * GetSketchItemByName(string name);
	
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, UpdateCount, m_updateCount);
	void RunCommands(char * command);

private:
	void RunSketchItemCommand(SketchItemType type, char * command);
	void RunGeneralCommand(GeneralType type, char * command);

	void CheckCurrentState(void);
	void UndoSketchItem(void);
	void RedoSketchItem(void);
	
	SketchItem * CopySketchItem(SketchItem * pSketchItem);
	SketchItemList CopySketchItemList(SketchItemList pSketchItemList);

	void DeleteSketchItem(char * command);
	void ModifySketchItem(char * command);
	void SetCoordinateSystem(char * command);

	void Ask(char * command);
	void HighlightSketchItem(char * command);

private:
	TransCAD::IStdSketchFeaturePtr m_spSketch;
	TransCAD::ISketchEditorPtr m_spEditor;
	SketchItemList m_sketchItemList;
	vector<SketchItemList> m_tempSketchList;

	double m_sketchCoord[9];
	int m_closeness;
	int m_currentState;
	int m_updateCount, m_undoCount, m_redoCount;

	SketchItemType sType;
	GeneralType gType;
};