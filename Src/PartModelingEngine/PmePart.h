#pragma once

#include ".\PmeObject.h"
#include <vector>

class PmeFeatures;
class PmeExplicitModel;
class PmeReferences;
class PmeSelectionManager;

class PmePart
	: public PmeObject
{
/*	typedef std::vector<CString> Hierarchy;*/
// 	 	void AddHierarchy(CString str){m_hierarchy.push_back(str);}
// 	 	int GetHierarchySize(void){return m_hierarchy.size();}
// 	 	CString GetHierarchy(int index){return m_hierarchy[index];}
	PME_DECLARE_RUNTIME_TYPE(PmePart)
public:
	PmePart(void);
	virtual ~PmePart(void);

	PmeFeatures * GetFeatures(void) const {return m_pFeatures;}
	PmeExplicitModel * GetExplicitModel(void) const {return m_pExplicitModel;}
	PmeSelectionManager * GetSelectionManager(void) const {return m_pSelectionManager;}
	void SetExplicitModel (PmeExplicitModel* pExplicitModl) {m_pExplicitModel = pExplicitModl;}

	void UpdateAll(void);
	void UpdateLast(void);

	void SetName(CString name) {m_name = name;}
	CString GetName(void) const {return m_name;}

	CString GetParentName() const { return m_parent_name; }
	void SetParentName(CString val) { m_parent_name = val; }

	BOOL isBrepPart() const { return m_isBrepPart; }
	void isBrepPart(BOOL val) { m_isBrepPart = val; }
	CString GetBrepFilePath() const { return m_BrepFilePath; }
	void SetBrepFilePath(CString val) { m_BrepFilePath = val; }
	void Clear();
	void ClearBody(void);

	void SetPlacement(const MrAxis2 & placement) {m_placement = placement;}
	MrAxis2 GetPlacement(void) const {return m_placement;}

	//HISTORY_STREAM * GetHistoryStream(void) {return m_hs;}

	void Undo(void);
	void Redo(void);

private:
	void CreateDefaultPlanes(void);
	void ClearFeatures(void);
	void ClearExplicitModel(void);	
	

private:
	CString m_parent_name;

	CString m_name;
	PmeFeatures * m_pFeatures;
	PmeExplicitModel * m_pExplicitModel;
	
	MrAxis2 m_placement;	

	BOOL m_isBrepPart;
	CString m_BrepFilePath;

	PmeSelectionManager * m_pSelectionManager;

//private:
//	HISTORY_STREAM * m_hs; // Undo, Redo를 위한 히스토리 스트림
//	std::vector<DELTA_STATE *> m_deltaStateList;
};