#include "stdafx.h"
#include "AssemHModel.h"

AssemHModel::AssemHModel(void): 
HBaseModel()
{
	SetBRepGeometry(true);
}

AssemHModel::~AssemHModel(void)
{
}

// void AssemHModel::Init()
// {
// 	HBaseModel::Init();
// 
// 	HC_Open_Segment_By_Key(GetModelIncludeKey());
// 	m_hMeshKey = HC_KCreate_Segment("Mesh");
// 	HC_Close_Segment();
// 
// }