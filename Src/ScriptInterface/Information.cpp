#include "stdafx.h"
#include "Information.h"
#include "Feature.h"

// 정보를 얻어오는 함수
void Information::Ask(char * command, Part * pPart)
{
	string token;
	
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	
	CMD::SetColor(D_BLUE, SKYBLUE); // cmd 색상 변경(배경:파랑, 글자:밝은 스카이블루)

	if (token == "all" || token == "모두")
	{
		for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
			pPart->GetFeature(i)->AskInfo();
	}
	else if (token == "history" || token == "히스토리")
	{
		for (int i = 0; i < pPart->GetHistoryFeatureListSize() - pPart->GetUndoCount() + pPart->GetRedoCount(); ++i)
			pPart->GetHistoryFeature(i)->AskInfo();
	}
	else if (pPart->GetFeatureByName(token) != NULL)
		pPart->GetFeatureByName(token)->AskInfo();

	CMD::SetColor(D_BLUE, YELLOW);
}

// 부모 특징형상 정보를 출력하는 함수
void Information::Parent(char * command, Part * pPart)
{
	string token;
	
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pPart->GetFeatureByName(token) == NULL, "No such a feature!");
	
	CMD::SetColor(D_BLUE, SKYBLUE); // cmd 색상 변경(배경:파랑, 글자:밝은 스카이블루)

	for (int i = 0; i < pPart->GetFeatureByName(token)->GetParentNameListSize(); ++i)
	{
		string parent = pPart->GetFeatureByName(token)->GetParentName(i);
		cout << "Parent : " << parent << endl;
	}

	CMD::SetColor(D_BLUE, YELLOW);
}

// 자식 특징형상 정보를 출력하는 함수
void Information::Children(char * command, Part * pPart)
{
	string token;
	
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pPart->GetFeatureByName(token) == NULL && token != "XYPlane" && token != "YZPlane" && token != "ZXPlane", "No such a feature!");
	
	int count = 0;

	for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
	{
		if (pPart->GetFeature(i)->IsChildOf(token))
			count ++;
	}
	
	TSIThrowExceptionIf<TSIArgumentException>(count == 0, "No children!");

	CMD::SetColor(D_BLUE, SKYBLUE); // cmd 색상 변경(배경:파랑, 글자:밝은 스카이블루)

	cout << token;
		GetChildren(token, 0, pPart);
	cout << endl;

	CMD::SetColor(D_BLUE, YELLOW);
}

// 자식 특징형상 정보를 출력하는 함수. 재귀적 호출
void Information::GetChildren(string parentName, int parentDepth, Part * pPart)
{
	string temp;
	
	for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
	{
		if (pPart->GetFeature(i)->IsChildOf(parentName))
		{
			temp = "\n";
				
			for (int j = 0; j < parentDepth + 1; ++j)
				temp = temp + "	";
				
			cout << temp << pPart->GetFeature(i)->GetName();

			GetChildren(pPart->GetFeature(i)->GetName(), parentDepth + 1, pPart);
		}
	}
}

// 해당 특징형상을 GUI 상에서 깜빡이며 하이라이트 하는 함수
void Information::Highlight(char * command, Part * pPart)
{
	string token;
	
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pPart->GetFeatureByName(token) == NULL, "No such a feature!");

	for (int i = pPart->GetFeatureListSize() - 1;i >= pPart->GetFeatureByName(token)->GetOrder(); --i)
		pPart->GetFeaturesPtr()->DeleteByName(pPart->GetFeature(i)->GetName().c_str());

	pPart->GetPartDocumentPtr()->Update(); // 업데이트

	for (int i = 0; i < 5; ++i)
	{
		pPart->GetFeatureByName(token)->Create();
		Sleep(300);

		pPart->GetFeaturesPtr()->DeleteByName(token.c_str());
		pPart->GetPartDocumentPtr()->Update(); // 업데이트
		Sleep(300);
	}

	for (int i = pPart->GetFeatureByName(token)->GetOrder();i < pPart->GetFeatureListSize(); ++i)
		pPart->GetFeature(i)->Create();

	pPart->GetPartDocumentPtr()->Update(); // 업데이트
}
