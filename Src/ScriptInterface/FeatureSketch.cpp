#include "stdafx.h"
#include "FeatureSketch.h"
#include "Part.h"

#include "SketchItemCircle.h"
#include "SketchItemArc.h"
#include "SketchItemLine.h"
#include "SketchItemCenterLine.h"
#include "SketchItemPolyLine.h"
#include "SketchItemRectangle.h"
#include "SketchItemFillet.h"
#include "SketchItemChamfer.h"
#include "SketchItemExtendLines.h"
#include "SketchItemPolygon.h"
#include "SketchItemTranslate.h"
#include "SketchItemRotate.h"

#include "Manipulation.h"

FeatureSketch::FeatureSketch(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
	m_updateCount = 0;
	m_undoCount = 0;
	m_redoCount = 0;
}

FeatureSketch::~FeatureSketch(void)
{
	// 스케치 요소 목록 제거
	ClearList(m_sketchItemList);
	
	// 스케치 생성 이력 모두 제거
	for (int i = 0; i < GetHistorySketchItemListSize(); ++i)
		ClearList(GetHistorySketchItem(i));
}

void FeatureSketch::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	SetReferencePtr(GetPart()->GetCurrentReferencePtr());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Enter sketch name!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencePtr() == NULL, "Select a reference first!");

	SetSketchPtr(GetPart()->GetFeaturesPtr()->AddNewSketchFeature(GetName().c_str(), GetReferencePtr()));
	
	AddReference(GetReferencePtr());
	GetPart()->SetCurrentReferencePtr(NULL);
	
	// Coordinate 정보를 입력받지 못하는 경우, 시스템 내부에 설정된 정보로 값을 세팅
	GetSketchPtr()->GetCoordinateSystem(&m_sketchCoord[0], &m_sketchCoord[1], &m_sketchCoord[2],	// Origin
										&m_sketchCoord[3], &m_sketchCoord[4], &m_sketchCoord[5],	// Local X direction
										&m_sketchCoord[6], &m_sketchCoord[7], &m_sketchCoord[8]);	// Local Y direction
	
	GetPart()->SetCurrentSketch(this);
	CMD::SetColor(D_BLUE, WHITE);
}

void FeatureSketch::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSketchFeaturePtr _spFeature = spFeature;
	SetSketchPtr(_spFeature);

	string name(GetSketchPtr()->GetName());
	SetName(name);
	SetType(0);

	SetReferencePtr(GetSketchPtr()->GetSketchPlane());
	assert(GetReferencePtr());
	AddReference(GetReferencePtr());

	TransCAD::IStdSketchGeometriesPtr _spGeometries = GetSketchPtr()->GetGeometries();
	
	GetSketchPtr()->GetCoordinateSystem(&m_sketchCoord[0], &m_sketchCoord[1], &m_sketchCoord[2],	// Origin
										&m_sketchCoord[3], &m_sketchCoord[4], &m_sketchCoord[5],	// Local X direction
										&m_sketchCoord[6], &m_sketchCoord[7], &m_sketchCoord[8]);	// Local Y direction

	for (int i = 1; i <= _spGeometries->GetCount(); ++ i)
		AddSketchItem(_spGeometries->GetItem(i));

	CheckCloseness();
}

void FeatureSketch::AddSketchItem(TransCAD::IStdSketchGeometryPtr spSketchItem)
{
	SketchItem * pSketchItem = 0;
	
	switch(spSketchItem->Type)
	{
		case TransCAD::Line :
			pSketchItem = new SketchItemLine(this, 0);
			break;
		case TransCAD::Centerline :
			pSketchItem = new SketchItemCenterLine(this, 1);
			break;
		case TransCAD::Circle :
			pSketchItem = new SketchItemCircle(this, 2);
			break;
		case TransCAD::CircularArc :
			pSketchItem = new SketchItemArc(this, 3);
			break;
	}

	if (pSketchItem)
	{
		pSketchItem->AddInfo(spSketchItem);
		SetSketchItem(pSketchItem);
	}
}

void FeatureSketch::Modify(char * command)
{
	// 해당 스케치 이후에 생성 된 특징형상들 임시로 제거
	for (int i = GetPart()->GetFeatureListSize() - 1; i > GetOrder(); --i)
		GetPart()->GetFeaturesPtr()->DeleteByName(GetPart()->GetFeature(i)->GetName().c_str());

	GetPart()->GetPartDocumentPtr()->Update();
	
	GetPart()->SetCurrentSketch(this);
	CMD::SetColor(D_BLUE, WHITE);

	for (int i = 0; i < GetSketchItemListSize(); ++i)
	{
		GetSketchItem(i)->SetModified(false);
		GetSketchItem(i)->SetCreated(false);
		GetSketchItem(i)->SetDeleted(false);
	}
}

void FeatureSketch::Create(void)
{
	SetSketchPtr(GetPart()->GetFeaturesPtr()->AddNewSketchFeature(GetName().c_str(), GetReference()->GetReferencePtr()));
	assert(GetSketchPtr());

	SetEditorPtr(GetSketchPtr()->OpenEditorEx(VARIANT_FALSE));
	assert(GetEditorPtr());

	GetSketchPtr()->SetCoordinateSystem(m_sketchCoord[0], m_sketchCoord[1], m_sketchCoord[2],	// Origin
										m_sketchCoord[3], m_sketchCoord[4], m_sketchCoord[5],	// Local X direction
										m_sketchCoord[6], m_sketchCoord[7], m_sketchCoord[8]);	// Local Y direction

	for (int i = 0; i < GetSketchItemListSize(); ++i)
		GetSketchItem(i)->Create();

	GetEditorPtr()->Close();

	// 스케치 요소가 하나도 없는 경우 TransCAD에서 제거
	if (GetSketchItemListSize() == 0)
	{
		GetPart()->GetFeaturesPtr()->DeleteByName(GetName().c_str());
		GetPart()->GetPartDocumentPtr()->Update();
	}
}

void FeatureSketch::AskInfo(void)
{
	char buffer[500];

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		
		cout << "opensketch " << GetName() << endl;

		sprintf_s(buffer, sizeof(buffer), "setcoordinatesystem %f %f %f %f %f %f %f %f %f", 
			m_sketchCoord[0], m_sketchCoord[1], m_sketchCoord[2], m_sketchCoord[3], m_sketchCoord[4], m_sketchCoord[5], m_sketchCoord[6], m_sketchCoord[7], m_sketchCoord[8]);

		cout << buffer << endl;

		for (int i = 0; i < GetSketchItemListSize(); ++i)
			GetSketchItem(i)->AskInfo();
		
		cout << "closesketch" << endl;
	}
	else if (IsModified())
	{
		cout << "modify " << GetName() << endl;

		sprintf_s(buffer, sizeof(buffer), "setcoordinatesystem %f %f %f %f %f %f %f %f %f", 
			m_sketchCoord[0], m_sketchCoord[1], m_sketchCoord[2], m_sketchCoord[3], m_sketchCoord[4], m_sketchCoord[5], m_sketchCoord[6], m_sketchCoord[7], m_sketchCoord[8]);

		cout << buffer << endl;

		// 제거된 스케치 요소를 찾아서 출력
		for (int i = GetPart()->GetCurrentState() - 1; i >= 0; --i)
		{
			if (GetPart()->GetHistoryFeature(i)->GetName() == this->GetName()
				&& GetPart()->GetHistoryFeature(i) != this
				&& !GetPart()->GetHistoryFeature(i)->IsDeleted())
			{
				FeatureSketch * recentSketch = (FeatureSketch *)GetPart()->GetHistoryFeature(i);

				for (int j = 0; j < recentSketch->GetSketchItemListSize(); ++j)
				{
					int count = 0;
					
					for (int k = 0; k < this->GetSketchItemListSize(); ++k)
					{
						if (recentSketch->GetSketchItem(j)->GetName() == this->GetSketchItem(k)->GetName())
						{
							count++;
							break;
						}
					}

					if (count == 0)
						cout << "delete " << recentSketch->GetSketchItem(j)->GetName() << endl;
				}

				break;
			}
		}
		///

		// 스케치 수정 중, 수정된 요소나 새로 생성된 요소에 대해 출력
		for (int i = 0; i < GetSketchItemListSize(); ++i)
		{
			if (GetSketchItem(i)->IsModified() || GetSketchItem(i)->IsCreated())
				GetSketchItem(i)->AskInfo();
		}
		
		cout << "closesketch" << endl;
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer), "delete %s", GetName());
	}
}

void FeatureSketch::Help(void)
{
	cout << " [opensketch p1]" << endl;
	cout << " -p1 : " << "New Sketch Name" << endl;
	cout << " [EXAMPLE] " << "	opensketch Sketch1" << endl;
	cout << "		createcircle Circle1 0 0 30" << endl;
	cout << "		closesketch" << endl;
	cout << " [NOTE 1] " << "Need to select a plane or a face before using this function" << endl;
	cout << " [NOTE 2] " << "'closesketch' function must be entered after finishing the sketch" << endl;
}

/*** 스케치는 하위 스케치 요소들로 구성되므로, 특징형상들로 구성되는 파트와 비슷함 ***/
/*** 따라서 파트와 유사한 기능들이 요구됨. 아래는 그와 같은 기능들을 구현한 함수들 ***/

// 스케치 요소의 생성, 수정, 제거 시 호출되는 함수. 각 상태에서 Undo와 Redo를 체크하기 위해 활용
void FeatureSketch::CheckCurrentState(void)
{
	// 현재 상태 갱신
	m_currentState = GetHistorySketchItemListSize() - m_undoCount + m_redoCount;
	
	// Undo, Redo를 거쳐 가장 최근보다 이전 상태에서 특징형상의 생성, 수정, 삭제가 이루어지는 경우 이 후의 이력을 모두 제거
	// 새로운 특징형상을 목록에 추가 하기 전에 호출되어야 함
	if ((m_updateCount != 0)
		&& (m_currentState < GetHistorySketchItemListSize()))
	{
		m_undoCount = 0;
		m_redoCount = 0;
		
		// Initial 상태 이후의 이력을 모두 삭제
		for (int i = GetHistorySketchItemListSize() - 1; i > m_currentState - 1; --i)
		{
			ClearList(GetHistorySketchItem(i));
			EraseHistorySketchItem(i);
			m_updateCount--;
		}
	}

	m_updateCount++;
}

// 모든 명령어를 수행하는 함수
void FeatureSketch::RunCommands(char * command)
{
	try
	{
		TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "No command!");

		// 스케치 에디터 시작
		SetEditorPtr(GetSketchPtr()->OpenEditorEx(VARIANT_FALSE));

		if ((sType = Commands.GetSketchItemType(token)) != NoSketchItem)	// SketchItem을 생성하는 부분
			RunSketchItemCommand(sType, command);
		else if ((gType = Commands.GetCommandType(token)) != NoCommand)		// 기타 명령어를 수행하는 부분
			RunGeneralCommand(gType, command);
		else if (token != "closesketch" && token != "스케치종료")
			cout << "Invalid command!" << endl;
			
		// 스케치 에디터 종료
		GetEditorPtr()->Close();
		GetPart()->GetPartDocumentPtr()->Update();
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}

// 스케치 요소 생성
void FeatureSketch::RunSketchItemCommand(SketchItemType type, char * command)
{
	SketchItem * pSketchItem = 0;
	
	switch(type)
	{
		case CSYS_Type:
			SetCoordinateSystem(command);
			break;
		case Line_Type:
			pSketchItem = new SketchItemLine(this, 0);
			break;
		case CenterLine_Type:
			pSketchItem = new SketchItemCenterLine(this, 1);
			break;
		case Circle_Type:
			pSketchItem = new SketchItemCircle(this, 2);
			break;
		case Arc_Type:
			pSketchItem = new SketchItemArc(this, 3);
			break;
		case PolyLine_Type:
			pSketchItem = new SketchItemPolyLine(this, 4);
			break;
		case Rectangle_Type:
			pSketchItem = new SketchItemRectangle(this, 5);
			break;
		case FilletLines_Type:
			pSketchItem = new SketchItemFillet(this, 6);
			break;
		case ChamferLines_Type:
			pSketchItem = new SketchItemChamfer(this, 7);
			break;
		case ExtendLines_Type:
			pSketchItem = new SketchItemExtendLines(this, 8);
			break;
		case Polygon_Type:
			pSketchItem = new SketchItemPolygon(this, 9);
			break;
		case TranslateSketch_Type:
			pSketchItem = new SketchItemTranslate(this, 10);
			break;
		case RotateSketch_Type:
			pSketchItem = new SketchItemRotate(this, 11);
			break;
	}

	if (pSketchItem)
	{
		try
		{
			pSketchItem->GetInfo(command);
			
			// Profile인 경우 추가
			if (pSketchItem->GetType() < 4)
				SetSketchItem(pSketchItem);
			
			// Sketch가 수정 중인 경우, 수정 중 생성되었음을 설정
			if (IsModified())
				pSketchItem->SetCreated(true);

			CheckCurrentState();
			SetHistorySketchItem(CopySketchItemList(m_sketchItemList));
		}
		catch (TSIArgumentException & e)
		{
			cout << e.GetMessageW() << endl;
			delete pSketchItem;
		}
	}
}

// 기타 명령어를 수행
void FeatureSketch::RunGeneralCommand(GeneralType type, char * command)
{
	switch(type)
	{
		case Modify_Type:
			ModifySketchItem(command);
			break;
		case Delete_Type:
			DeleteSketchItem(command);
			break;
		case Undo_Type:
			UndoSketchItem();
			break;
		case Redo_Type:
			RedoSketchItem();
			break;
		case Ask_Type:
			Ask(command);
			break;
		case Parent_Type:
			Information::Parent(command, GetPart());
			break;
		case Highlight_Type:
			HighlightSketchItem(command);
			break;
		case Help_Type:
			GetPart()->Help(command);
			break;
	}
}

// 스케치 요소를 복사하는 함수. 깊은 복사를 위함
SketchItem * FeatureSketch::CopySketchItem(SketchItem * pSketchItem)
{
	SketchItem * pCopiedSketchItem = 0;
	
	if (pSketchItem->GetType() == 0)
		pCopiedSketchItem = new SketchItemLine(*(SketchItemLine*)pSketchItem);
	else if (pSketchItem->GetType() == 1)
		pCopiedSketchItem = new SketchItemCenterLine(*(SketchItemCenterLine*)pSketchItem);
	else if (pSketchItem->GetType() == 2)
		pCopiedSketchItem = new SketchItemCircle(*(SketchItemCircle*)pSketchItem);
	else if (pSketchItem->GetType() == 3)
		pCopiedSketchItem = new SketchItemArc(*(SketchItemArc*)pSketchItem);

	pCopiedSketchItem->SetSketch(this);

	return pCopiedSketchItem;
}

// 스케치 요소 목록(이력)을 복사하는 함수. 
SketchItemList FeatureSketch::CopySketchItemList(SketchItemList pSketchItemList)
{
	SketchItemList temp;

	for (int i = 0; i < (int)pSketchItemList.size(); ++i)
		temp.push_back(CopySketchItem(pSketchItemList[i]));

	return temp;
}

// 이름으로 스케치 요소를 가져오는 함수
SketchItem *  FeatureSketch::GetSketchItemByName(string name)
{
	SketchItem * pSketchItem = 0;
	
	for (int i = 0; i < GetSketchItemListSize(); ++i)
	{
		if (GetSketchItem(i)->GetName() == name)
			pSketchItem = GetSketchItem(i);
	}
	
	return pSketchItem;
}

// 스케치의 Closeness를 체크하는 함수
void FeatureSketch::CheckCloseness(void)
{
	int totalCount = 0; // 전체 요소 개수
	int connCount = 0;	// 연결 된 부분
	
	// 스케치의 포인트 저장소
	vector<Point2D> _points;

	// 스케치의 Line과 Arc의 시작 및 끝 포인트 저장. Circle이나 Centerline은 Closeness와 관련없다.
	for (int i = 0; i < GetSketchItemListSize(); ++i)
	{
		if (GetSketchItem(i)->GetType() == 0)
		{
			SketchItemLine * pLine = (SketchItemLine *)GetSketchItem(i);
			
			_points.push_back(pLine->GetStartPoint());
			_points.push_back(pLine->GetEndPoint());
			totalCount++;
		}
		else if (GetSketchItem(i)->GetType() == 3)
		{
			SketchItemArc * pArc = (SketchItemArc *)GetSketchItem(i);

			_points.push_back(pArc->GetStartPoint());
			_points.push_back(pArc->GetEndPoint());
			totalCount++;
		}
	}

	// 각 포인트마다 동일한 X,Y 좌표를 갖는 포인트가 있는지 검색
	for (int i = 0; i < (int)_points.size(); ++i)
	{
		Point2D _point1 = _points[i];
		
		for (int j = 0; j < (int)_points.size(); ++j)
		{
			if (i == j) // 같은 점은 건너 뜀
				continue;

			Point2D _point2 = _points[j];

			// X, Y 좌표가 동일하면 해당 포인트에서 연결
			if (abs(_point1.X() - _point2.X()) <= tolerance
				&& abs(_point1.Y() - _point2.Y()) <= tolerance)
				connCount++;
		}
	}
	
	_points.clear();

	if (totalCount == connCount/2)			// Connected and closed
		SetCloseness(1);
	else if (totalCount - 1 == connCount/2)	// Connected but not closed
		SetCloseness(2);
	else if (totalCount < connCount/2)		// Multiple profiles are connected
		SetCloseness(3);
	else									// Disconnected
		SetCloseness(0);
}

// 스케치 내에서 Undo를 수행하는 함수
void FeatureSketch::UndoSketchItem(void)
{
	if (m_updateCount > abs(m_undoCount - m_redoCount))
	{
		m_undoCount++;
	
		// 현재 상태
		m_currentState = GetHistorySketchItemListSize() - m_undoCount + m_redoCount;
	
		// 스케치 요소 TransCAD에서 제거
		for (int i = 0; i < GetSketchItemListSize(); ++i)
			GetEditorPtr()->DeleteByName(GetSketchItem(i)->GetName().c_str());

		// 스케치 요소 목록 제거
		ClearList(m_sketchItemList);

		// 재생성
		if (m_currentState != 0)
		{
			SketchItemList pList = CopySketchItemList(GetHistorySketchItem(m_currentState - 1));
		
			for (int i = 0; i < (int)pList.size(); ++i)
			{
				SketchItem * pSketchItem = CopySketchItem(pList[i]);
				pSketchItem->Create();
				SetSketchItem(pSketchItem);
			}
		}
	}
}

// 스케치 내에서 Redo를 수행하는 함수
void FeatureSketch::RedoSketchItem(void)
{
	if (m_undoCount > m_redoCount)
	{
		m_redoCount++;
		
		// 현재 상태
		m_currentState = GetHistorySketchItemListSize() - m_undoCount + m_redoCount;
	
		// 스케치 요소 TransCAD에서 제거
		for (int i = 0; i < GetSketchItemListSize(); ++i)
			GetEditorPtr()->DeleteByName(GetSketchItem(i)->GetName().c_str());

		// 스케치 요소 목록 제거
		ClearList(m_sketchItemList);

		// 재생성
		if (m_currentState != 0)
		{
			SketchItemList pList = CopySketchItemList(GetHistorySketchItem(m_currentState - 1));
		
			for (int i = 0; i < (int)pList.size(); ++i)
			{
				SketchItem * pSketchItem = CopySketchItem(pList[i]);
				pSketchItem->Create();
				SetSketchItem(pSketchItem);
			}
		}
	}
}

// 스케치 요소를 제거하는 함수
void FeatureSketch::DeleteSketchItem(char * command)
{
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Enter sketch item name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketchItemByName(token) == NULL, "No such a sketch item!");
	
	CheckCurrentState();
	
	//스케치 요소끼리는 부모, 자식 관계가 없으므로 해당 요소만 제거하면 됨
	for (int i = 0; i < GetSketchItemListSize(); ++i)
	{
		SketchItem * pSketchItem = GetSketchItem(i);
		
		if (token == pSketchItem->GetName())
		{
			EraseSketchItem(i);
			GetEditorPtr()->DeleteByName(token.c_str());
		}
	}
	
	SetHistorySketchItem(CopySketchItemList(m_sketchItemList));
}

// 스케치 요소를 수정하는 함수
void FeatureSketch::ModifySketchItem(char * command)
{
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Enter sketch item name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketchItemByName(token) == NULL, "No such a sketch item!");
				
	try
	{
		CheckCurrentState();

		SketchItem * pSketchItem = GetSketchItemByName(token);
		pSketchItem->SetModified(true);
		pSketchItem->Modify(command);

		GetEditorPtr()->DeleteByName(token.c_str());
		pSketchItem->Create();

		SetHistorySketchItem(CopySketchItemList(m_sketchItemList));
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
		m_updateCount--;
	}
}

// 스케치 좌표계를 설정하는 함수
void FeatureSketch::SetCoordinateSystem(char * command)
{
	for (int i = 0; i < 9; ++i)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		m_sketchCoord[i] = atof(token.c_str());
	}
				
	TSIThrowExceptionIf<TSIArgumentException>(token == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(m_sketchCoord[3] == m_sketchCoord[6] 
											&& m_sketchCoord[4] == m_sketchCoord[7] 
											&& m_sketchCoord[5] == m_sketchCoord[8], "X and Y directions should be different!");	// X, Y 방향이 같은 경우 예외

	GetSketchPtr()->SetCoordinateSystem(m_sketchCoord[0], m_sketchCoord[1], m_sketchCoord[2],	// Origin
										m_sketchCoord[3], m_sketchCoord[4], m_sketchCoord[5],	// Local X direction
										m_sketchCoord[6], m_sketchCoord[7], m_sketchCoord[8]);	// Local Y direction
}

// 정보를 얻어오는 함수
void FeatureSketch::Ask(char * command)
{
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Enter feature or sketch item name!");
	
	CMD::SetColor(D_BLUE, SKYBLUE); // cmd 색상 변경(배경:파랑, 글자:밝은 스카이블루)

	//if (token == GetName())
	//	AskInfo();
	if (GetSketchItemByName(token) != NULL)
		GetSketchItemByName(token)->AskInfo();
	else
		Information::Ask((char *)token.c_str(), GetPart());

	CMD::SetColor(D_BLUE, WHITE);
}

// 해당 스케치 요소를 GUI 상에서 깜빡이며 하이라이트 하는 함수
void FeatureSketch::HighlightSketchItem(char * command)
{
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Enter sketch item name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketchItemByName(token) == NULL, "No such a sketch item!");
	
	for (int i = 0; i < 5; ++i)
	{
		// 스케치 요소 삭제
		GetEditorPtr()->DeleteByName(token.c_str());
		
		// 스케치 에디터 종료
		GetEditorPtr()->Close();
		GetPart()->GetPartDocumentPtr()->Update();
		Sleep(300);

		// 스케치 에디터 시작
		SetEditorPtr(GetSketchPtr()->OpenEditorEx(VARIANT_FALSE));

		// 스케치 요소 생성
		GetSketchItemByName(token)->Create();

		// 스케치 에디터 종료
		GetEditorPtr()->Close();
		GetPart()->GetPartDocumentPtr()->Update();
		Sleep(300);

		// 스케치 에디터 시작
		SetEditorPtr(GetSketchPtr()->OpenEditorEx(VARIANT_FALSE));
	}
}