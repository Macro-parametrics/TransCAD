#include "StdAfx.h"
#include ".\pmepersistentname.h"
#include ".\attr_pme_facename.h"
#include ".\attr_pme_vertexname.h"

CString PmePersistentName::FindName(ENTITY * pEntity)
{
	const char * pTypeName = pEntity->type_name();
	CString name;

	if(!strcmp(pTypeName, "face"))
		name = FindFaceName((FACE *)pEntity);

	if(!strcmp(pTypeName, "edge"))
		name = FindEdgeName((EDGE *)pEntity);

	return name;
}

CString PmePersistentName::FindFaceName(FACE * pFace)
{
	ATTRIB_FACENAME * pFaceNameAttr = (ATTRIB_FACENAME *)find_attrib(pFace, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);
	
	if(pFaceNameAttr)
		return pFaceNameAttr->GetFaceName();
	else
		return CString();
}

CString PmePersistentName::FindEdgeName(EDGE * pEdge)
{
	if(g_bNamingType)
	{
		FACE * pFace1 = 0;
		FACE * pFace2 = 0;

		FindAdjacentFaces(pEdge, pFace1, pFace2);

		if (!pFace1 || !pFace2)
			return "";

		CString name1 = FindFaceName(pFace1);
		CString name2 = FindFaceName(pFace2);

		return name1 + "#" + name2;
	}
	else
	{
		VERTEX * ver1;
		VERTEX * ver2;

		ver1 = pEdge->start();
		ver2 = pEdge->end();

		if (ver1 == ver2)
		{
			SPAposition onePoint;
			onePoint = pEdge->start_pos();

			ELLIPSE* el = (ELLIPSE*)pEdge->geometry();

			SPAposition centerPoint;
			centerPoint = el->centre();

			double radius;
			radius = sqrt( (centerPoint.x() - onePoint.x()) * (centerPoint.x() - onePoint.x()) + (centerPoint.y() - onePoint.y()) * (centerPoint.y() - onePoint.y()) + (centerPoint.z() - onePoint.z()) * (centerPoint.z() - onePoint.z()));

			double vertexcoord[3];
			CString vertexNum[3];

			vertexcoord[0] = centerPoint.x();
			vertexcoord[1] = centerPoint.y();
			vertexcoord[2] = centerPoint.z();

			vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
			vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
			vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);

			CString radiusname;
			radiusname.Format(_T("%3.2f"), radius);

			CString EdgeName;

			EdgeName = "Edge, Rev1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] +  "),"+ radiusname ;

			return EdgeName;	
		}


		else
		{
			CString name1 =  FindVertexName(ver1);
			CString name2 =  FindVertexName(ver2);

			return "EDGE," + name1 + "," + name2;	
		}
	}



}

CString PmePersistentName::FindVertexName(VERTEX * pVertex)
{
	if(g_bNamingType)
	{
		// 17-03-04 권순조 추가
		CString vertexName;
	
		if (!pVertex->edge()->geometry())
			return "";

		BODY * pBody = (BODY *)pVertex->owner()->owner()->owner()->owner()->owner()->owner()->owner();
		ENTITY_LIST adjFaceList;
		ENTITY_LIST allFaceList;
		api_get_faces(pBody, allFaceList);

		for (int i = 0; i < allFaceList.count(); ++i)
		{
			FACE * pFace = (FACE *)allFaceList[i];
		
			ENTITY_LIST vertices;
			api_get_vertices(pFace, vertices);

			for (int j = 0; j < vertices.count(); ++j)
			{
				VERTEX * pVert = (VERTEX *)vertices[j];

				if (pVertex == pVert)
				{
					adjFaceList.add(pFace);
					break;
				}
			}
		}
	
		for (int i = 0; i < adjFaceList.count(); ++i)
		{
			FACE * pFace = (FACE *)adjFaceList[i];
		
			if (i == adjFaceList.count() - 1)
				vertexName = vertexName + FindFaceName(pFace);
			else
				vertexName = vertexName + FindFaceName(pFace) + "#";
		}
	
		return vertexName;
	}
	else
	{
		int count = pVertex->count_edges();
	
		for (int i = 0; i < count; ++i)
		{
			EDGE * pEdge = pVertex->edge(i);

			FACE * pFace1 = 0;
			FACE * pFace2 = 0;

			FindAdjacentFaces(pEdge, pFace1, pFace2);
		}
	
		ATTRIB_VERTEXNAME * pVertexNameAttr = (ATTRIB_VERTEXNAME *)find_attrib(pVertex, ATTRIB_PME_TYPE);

		if(pVertexNameAttr)
			return pVertexNameAttr->GetVertexName();
		else
			return CString();
	}
}


ENTITY * PmePersistentName::FindEntity(BODY * pBody, CString persistentName)
{
	if(g_bNamingType)
	{
		PmePersistentNameData nameData;

		SplitName(persistentName, nameData);

		if(nameData.faceNames.size() == 1)
		{
			return FindFace(pBody, nameData);	
		}
		else if(nameData.faceNames.size() == 2)
		{
			return FindEdge(pBody, nameData);	
		}

		return 0;
	}
	else
	{
		int SearchType;

		SearchType = persistentName.Find(_T('F'), 0); // 이름 맨 앞이 F 면 Face

		if ( SearchType == 0)
		{
			return FindFace(pBody, persistentName);	
		}
		else if(SearchType == -1)
		{
			return FindEdge(pBody, persistentName);	
		}
		return 0;
	}
}

/// Topology-based 네이밍에 사용
void PmePersistentName::SplitName(CString persistentName, PmePersistentNameData & nameData)
{
	int prev = 0;
	int next = 0;

	for(;;)
	{
        next = persistentName.Find(_T('#'), prev);
		if(next == -1)
		{
			CString faceName = persistentName.Mid(prev, persistentName.GetLength() - prev);
			nameData.faceNames.push_back(faceName);

			break;
		}
			
		CString faceName = persistentName.Mid(prev, next - prev);
		nameData.faceNames.push_back(faceName);

		prev = next + 1;
	}
}

ENTITY * PmePersistentName::FindFace(BODY * pBody, const PmePersistentNameData & nameData)
{
	CString faceName = nameData.faceNames[0];
	int _secondColon = faceName.Find(":", faceName.Find(":") + 1);
	
	// TransCAD 네이밍 체크
	if(!CheckPersistentFaceName(faceName))
		return 0;

	CString temp = faceName.Left(_secondColon);
	
	ENTITY_LIST faceList;
	api_get_faces(pBody, faceList);

	faceList.init();
	
	ENTITY * pFace = 0;

	std::map<FACE *, int> faceMap;

	while((pFace = faceList.next()) != NULL)
	{
		CString name = FindFaceName((FACE *)pFace);
		
		if(name == faceName) // 완전 동일한 이름의 face 리턴
		{
			faceMap.insert(pair<FACE *, int>((FACE *)pFace, 0));
			//return pFace;
		}
		else if (name.Find(temp) != -1 && name.Find(temp) == 0) // Basic Naming + Split 까지 동일한 face 리턴. 단, 맨 처음부터 동일해야함.
		{
			faceMap.insert(pair<FACE *, int>((FACE *)pFace, 1));
			//return pFace;
		}
	}

	// 위에서 찾지 못했을 경우 Basic naming 까지만 동일한 face 리턴 (16-07-08 권순조)
	faceList.init();

	int _firstColon = faceName.Find(":");
	temp = faceName.Left(_firstColon);

	while((pFace = faceList.next()) != NULL)
	{
		CString name = FindFaceName((FACE *)pFace);
		
		if (name.Find(temp) != -1) // For finding secondary name in case of merged faces. By Soonjo Kwon (15-05-12)
		{
			faceMap.insert(pair<FACE *, int>((FACE *)pFace, 2));
			//return pFace;
		}
	}
	
	// 선택된 모든 면 중, 일치도가 가장 높은 면 리턴
	// 즉, 두 번째 int값이 가장 작은 면을 리턴 (17-03-02 권순조)
	map<FACE *, int>::iterator iter;
	FACE * selectedFace = 0;	// 선택된 면
	int type = 3;				// 일치도. 0~2 사이의 값을 가짐

	for (iter = faceMap.begin(); iter != faceMap.end(); ++iter)
	{
		if (iter->second < type)
		{
			selectedFace = iter->first;
			type = iter->second;
		}
	}

	return selectedFace;
}

ENTITY * PmePersistentName::FindEdge(BODY * pBody, const PmePersistentNameData & nameData)
{
	ENTITY_LIST edgeList;
	api_get_edges(pBody, edgeList);

	edgeList.init();
	
	ENTITY * pEntity;
	
	// TransCAD 네이밍 체크
	if(!CheckPersistentFaceName(nameData.faceNames[0])
		|| !CheckPersistentFaceName(nameData.faceNames[1]))
		return 0;
	
	// 조건에 맞는 엣지와 그 일치도를 저장
	std::map<EDGE *, int> edgeMap;

	while((pEntity = edgeList.next()) != NULL)
	{
		EDGE * pEdge = (EDGE *)pEntity;

		FACE * pFace1 = 0;
		FACE * pFace2 = 0;

		FindAdjacentFaces(pEdge, pFace1, pFace2);

		if (pFace1 == 0 || pFace2 == 0)
			continue;

		CString name1 = FindFaceName(pFace1);
		CString name2 = FindFaceName(pFace2);
		
		// For finding secondary name in case of merged faces. By Soonjo Kwon (15-06-01)
		if (name1 == "" || name2 == "")
			continue;

		/** 엣지 선택 알고리즘 개선 (16-07-08 권순조) **/
		/// 1. 동일한 이름의 엣지인 경우 리턴
		if((nameData.faceNames[0] == name1 && nameData.faceNames[1] == name2) 
			|| (nameData.faceNames[0] == name2 && nameData.faceNames[1] == name1))
		{
			edgeMap.insert(pair<EDGE *, int>(pEdge, 0));
		}

		// Names Including Split Information
		CString name1withSI = name1.Left(name1.Find(":", name1.Find(":") + 1));
		CString name2withSI = name2.Left(name2.Find(":", name2.Find(":") + 1));

		/// 2. Basic Naming + Split 정보까지 동일한 edge 리턴
		if((nameData.faceNames[0].Find(name1withSI) != -1 && nameData.faceNames[1].Find(name2withSI) != -1)
			|| (nameData.faceNames[0].Find(name2withSI) != -1 && nameData.faceNames[1].Find(name1withSI) != -1))
		{
			edgeMap.insert(pair<EDGE *, int>(pEdge, 1));
		}

		// Basic names
		CString name1Basic = name1.Left(name1.Find(":"));
		CString name2Basic = name2.Left(name2.Find(":"));

		/// 3. Basic Naming 정보까지 동일한 edge 리턴
		//** 이 부분은 수정이 필요할 수 있다. Edge Split만 일어나는 경우는 고려가 되어있지 않다. **/
		if((nameData.faceNames[0].Find(name1Basic) != -1 && nameData.faceNames[1].Find(name2Basic) != -1)
			|| (nameData.faceNames[0].Find(name2Basic) != -1 && nameData.faceNames[1].Find(name1Basic) != -1))
		{
			edgeMap.insert(pair<EDGE *, int>(pEdge, 2));
		}

		// Merge Information of names
		CString MI1 = name1.Right(name1.GetLength() - name1.Find(":", name1.Find(":") + 1) - 1);
		CString MI2 = name2.Right(name2.GetLength() - name2.Find(":", name2.Find(":") + 1) - 1);
	
		/// 4. Merge 정보를 체크하여 해당 edge를 찾는 경우 리턴
		if(MI1 != "0;0" || MI2 != "0;0")
		{
			CString mFaceName[2], temp;
			mFaceName[0] = name1; mFaceName[1] = name2;
			
			int mFaceNum[2], count = 0;
			mFaceNum[0] = _ttoi(MI1.Left(1)); mFaceNum[1] = _ttoi(MI2.Left(1));

			for (int i = 0; i < 2; ++i)
			{
				// 아예 동일하면 카운트 후 넘어감
				if(nameData.faceNames[0] == mFaceName[i] 
					|| nameData.faceNames[1] == mFaceName[i])
				{
					count++;
					continue;
				}
				
				// Basic Naming이 동일하면 카운트 후 넘어감
				int colon = mFaceName[i].Find(":");
				temp = mFaceName[i].Left(colon);

				if(nameData.faceNames[0].Find(temp) != -1 
					|| nameData.faceNames[1].Find(temp) != -1)
				{
					count++;
					continue;
				}

				// Secondary Name들 포함 여부 체크. 뒤에서부터 하나씩 체크
				for (int j = 0; j < mFaceNum[i]; ++j)
				{
					int semiColon = mFaceName[i].ReverseFind(';');
					temp = mFaceName[i].Right(mFaceName[i].GetLength() - semiColon - 1);
			
					if(nameData.faceNames[0].Find(temp) != -1 
						|| nameData.faceNames[1].Find(temp) != -1)
						count++;
			
					mFaceName[i] = mFaceName[i].Left(semiColon);
				}
			}

			// 입력 요소명을 포함하는 엣지를 리턴
			if (count >= 2)
			{
				edgeMap.insert(pair<EDGE *, int>(pEdge, 3));
			}
		}
	}

	// 선택된 모든 엣지 중, 일치도가 가장 높은 엣지 리턴
	// 즉, 두 번째 int값이 가장 작은 엣지를 리턴 (17-03-02 권순조)
	map<EDGE *, int>::iterator iter;
	EDGE * selectedEdge = 0;	// 선택된 엣지
	int type = 4;				// 일치도. 0~3 사이의 값을 가짐

	for (iter = edgeMap.begin(); iter != edgeMap.end(); ++iter)
	{
		if (iter->second < type)
		{
			selectedEdge = iter->first;
			type = iter->second;
		}
	}

	return selectedEdge;
}
///

// 16-07-28 권순조 (TransCAD 네이밍 체크)
bool PmePersistentName::CheckPersistentFaceName(CString persistentName)
{
	// TransCAD 네이밍에는 colon, semicolon, comma 등이 모두 포함되어 있어야 함
	int _colon1, _colon2;
	_colon1 = persistentName.Find(":");
	_colon2 = persistentName.Find(":", _colon1 + 1);
	
	int _semiColon = persistentName.Find(";");
	int _feature = persistentName.Find("Feature");
	
	int _comma = -1; // comma의 위치
	int _count = 0;	// comma의 개수

	// 기본 Face 네이밍에는 comma가 7개 있음
	for (;;)
	{
		_comma = persistentName.Find(",", _comma + 1);
		
		if (_comma == -1)
			break;
		else
			_count++;
	}

	// 만약 하나라도 없으면 false 리턴
	if (_colon1 != -1 && _colon2 != -1 
		&& _semiColon != -1 
		&& _feature != -1 
		&& _count >= 7)
		return true;
	else
		return false;

	return false;
}

void PmePersistentName::FindAdjacentFaces(EDGE * pEdge, FACE *& pFace1, FACE *& pFace2)
{
	if (!pEdge->geometry())
		return;
	
	COEDGE * pCoedge1 = pEdge->coedge();
	if (!pCoedge1)
		return;

	COEDGE * pCoedge2 = pCoedge1->partner();
	if (!pCoedge2)
		return;
	
	const char * tn1 = pCoedge1->owner()->type_name();
	const char * tn2 = pCoedge2->owner()->type_name();

	ASSERT(strcmp(pCoedge1->owner()->type_name(), "loop") == 0);
	ASSERT(strcmp(pCoedge2->owner()->type_name(), "loop") == 0);

	LOOP * pLoop1 = (LOOP *)pCoedge1->owner();
	LOOP * pLoop2 = (LOOP *)pCoedge2->owner();

	pFace1 = pLoop1->face();
	pFace2 = pLoop2->face();
}

// 2009.10.30, Suchul Shin
CString PmePersistentName::FindPersistentNameOption(CString persistentName)
{
	char * buff;
	char * context = NULL;
	int len = persistentName.GetLength();
	buff = new char[len + 1];
	strcpy_s(buff, sizeof(buff), persistentName);

	char seps_temp[]   = " ,\t\n"; //구분자
	strtok_s( buff, seps_temp, &context ); //첫번째 단어
	strtok_s( NULL, seps_temp, &context );  //두번째 단어
	strtok_s( NULL, seps_temp, &context );  //세번째 단어
	strtok_s( NULL, seps_temp, &context );  //네번째 단어	
	strtok_s( NULL, seps_temp, &context );  //세번째 단어
	strtok_s( NULL, seps_temp, &context );  //네번째 단어	
	return (strtok_s( NULL, seps_temp, &context ));  //네번째 단어	
}

// 2009.10.30, Suchul Shin
void PmePersistentName::GetArgumentNames(CString persistentName, CString *featureID, CString *id1, CString *id2, CString *id3, CString *id4, CString *id5)
{
	char * buff;
	char * context = NULL;
	int len = persistentName.GetLength();
	buff = new char[len + 1];
	strcpy_s(buff, sizeof(buff), persistentName);

	CString strID1, strID2, strID3, strID4, strID5;

	char seps_temp[]   = " ,\t\n"; //구분자
	(*featureID).Format("%s", strtok_s( buff, seps_temp, &context ));

	strID1.Format("%s", strtok_s( NULL, seps_temp, &context ));
	strID2.Format("%s", strtok_s( NULL, seps_temp, &context ));
	strID3.Format("%s", strtok_s( NULL, seps_temp, &context ));
	strID4.Format("%s", strtok_s( NULL, seps_temp, &context ));
	strID5.Format("%s", strtok_s( NULL, seps_temp, &context ));

	if(id1)	(*id1) = strID1;
	if(id2)	(*id2) = strID2;
	if(id3)	(*id3) = strID3;
	if(id4)	(*id4) = strID4;
	if(id5)	(*id5) = strID5;
}


/// Point-based 네이밍에 사용
ENTITY * PmePersistentName::FindFace(BODY * pBody, CString Persistentname)
{	
	ENTITY_LIST faceList;
	api_get_faces(pBody, faceList);

	faceList.init();

	ENTITY * pFace;

	while((pFace = faceList.next()) != NULL)
	{
		CString name = FindFaceName((FACE *)pFace);
		
		if(name == Persistentname)
			return pFace;
	}

	return 0;
}

ENTITY * PmePersistentName::FindEdge(BODY * pBody, CString Persistentname)
{
	ENTITY_LIST edgeList;
	api_get_edges(pBody, edgeList);

	edgeList.init();

	ENTITY * pEntity;

	while((pEntity = edgeList.next()) != NULL)
	{
		EDGE * pEdge = (EDGE *)pEntity;
		CString name = FindEdgeName(pEdge);

		if(name == Persistentname)
			return pEdge;		
	}

	return 0;

}
///