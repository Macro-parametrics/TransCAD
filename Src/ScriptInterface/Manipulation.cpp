#include "stdafx.h"
#include "Manipulation.h"
#include "CustomFeature.h"

// 특징형상을 수정하는 함수
void Manipulation::Modify(char * command, Part * pPart)
{
	string token;

	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pPart->GetFeatureByName(token) == NULL, "No such a feature!");
	
	pPart->CheckCurrentState();
	
	Feature * pFeature = pPart->CopyFeature(pPart->GetFeatureByName(token));
	
	try
	{
		pFeature->SetModified(true);
		pFeature->Modify(command);
		
		if(!pPart->GetCurrentSketch())
		{
			pPart->SetHistoryFeature(pFeature);
			RegenerateFeature(pFeature->GetOriginalOrder(), pPart->GetCurrentState(), 0, pPart);
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
		pPart->SetUpdateCount(pPart->GetUpdateCount() - 1);
	}
}

// Undo를 수행하는 함수
void Manipulation::UndoFeature(Part * pPart)
{
	if (pPart->GetUpdateCount() > abs(pPart->GetUndoCount() - pPart->GetRedoCount()))
	{
		pPart->SetUndoCount(pPart->GetUndoCount() + 1);
		
		// Undo 시 가장 최근 생성된 특징형상이 현재 상태
		pPart->SetCurrentState(pPart->GetHistoryFeatureListSize() - pPart->GetUndoCount() + pPart->GetRedoCount() + 1);
	
		Feature * pFeature = pPart->CopyFeature(pPart->GetHistoryFeature(pPart->GetCurrentState() - 1));

		// 1. 생성 된 경우 → 제거
		if (!pFeature->IsModified() && !pFeature->IsDeleted())
		{
			DeleteFeature(pFeature->GetName(), pPart);
			pPart->GetPartDocumentPtr()->Update(); // 업데이트
		}
		// 2 .수정 혹은 제거 된 경우 → 제거 후 재 생성
		else
			RegenerateFeature(pFeature->GetOriginalOrder(), pPart->GetCurrentState() - 1, 1, pPart);
	}
}

// Redo를 수행하는 함수
void Manipulation::RedoFeature(Part * pPart)
{
	if (pPart->GetUndoCount() > pPart->GetRedoCount())
	{
		pPart->SetRedoCount(pPart->GetRedoCount() + 1);
		
		// Redo 시 현재 상태보다 한 단계 최근에 생성된 특징형상이 현재 상태
		pPart->SetCurrentState(pPart->GetHistoryFeatureListSize() - pPart->GetUndoCount() + pPart->GetRedoCount());

		Feature * pFeature = pPart->CopyFeature(pPart->GetHistoryFeature(pPart->GetCurrentState() - 1));

		// 1. 제거 된 경우
		if (pFeature->IsDeleted())
		{
			DeleteFeature(pFeature->GetName(), pPart);
			pPart->GetPartDocumentPtr()->Update(); // 업데이트
		}
		// 2. 생성 혹은 수정 된 경우
		else
			RegenerateFeature(pFeature->GetOriginalOrder(), pPart->GetCurrentState() - 1, 0, pPart);
	}
}

// 해당 특징형상을 재생성하는 함수
void Manipulation::RegenerateFeature(int start, int end, int mode, Part * pPart)
{
	// 제거 된 특징형상을 포함하여 나중에 생성된 특징형상들을 모두 제거
	for (int i = end; i > start; --i)
	{
		if (pPart->GetHistoryFeature(i)->GetOriginalOrder() >= start)
		{
			pPart->GetFeaturesPtr()->DeleteByName(pPart->GetHistoryFeature(i)->GetName().c_str()); // TransCAD에서 제거
			
			for (int j = 0; j < pPart->GetFeatureListSize(); ++j) // 현재 특징형상 목록에서 제거
			{
				if (pPart->GetHistoryFeature(i)->GetName() == pPart->GetFeature(j)->GetName())
					pPart->EraseFeature(j);
			}
		}
	}
	//

	pPart->GetPartDocumentPtr()->Update(); // 업데이트
	
	// 뒤에서 부터 검색하여 제거 된 특징형상들을 재생성
	for (int i = start; i <= end; ++i)
	{
		Feature * pFeature = 0;

		if (mode == 0)	// 일반적인 수정 혹은 Redo인 경우
			pFeature = BacktraceFeature(pPart->GetHistoryFeature(i), start, end, pPart);
		else			// Undo인 경우
			pFeature = BacktraceFeature(pPart->GetHistoryFeature(i), start, end - 1, pPart);
		
		// 해당 특징형상이 있는 경우 현재 특징형상 리스트에 추가
		if (pFeature)
		{
			CMD::SetTitle(TEXT("Regenerating features"), i);

			pFeature->Restore();
			pFeature->Create();
			pFeature->SetDeleted(false);
			pFeature->SetModified(false);
			
			pPart->SetFeature(pFeature);
		}
	}
	//

	CMD::SetTitle(TEXT("TransCAD Script Interface 1.0"), 0);
}

// 입력 된 범위 내에서 (start ~ end) 입력 된 특징형상의 가장 최신 버전을 리턴하는 함수
Feature * Manipulation::BacktraceFeature(Feature * pFeature, int start, int end, Part * pPart)
{
	if (pFeature->GetOriginalOrder() < start) // 이전에 생성된 특징형상이면 건너 뜀
		return NULL;
	
	for (int i = end; i >= start; --i)
	{
		// 해당 특징형상의 부모가 현재 특징형상 목록에 없으면 건너 뜀
		if (!pFeature->IsAncestorAvailable())
			break;
		
		// 해당 특징형상이 현재 생성되어있으면 건너뜀
		if (pPart->GetFeatureByName(pFeature->GetName()))
			break;

		// 생성 된 특징형상인 경우에만 진입
		if (!pFeature->IsModified() && !pFeature->IsDeleted())
		{
			if (pFeature->GetName() == pPart->GetHistoryFeature(i)->GetName())
			{
				// 해당 특징형상이 최근에 삭제되었으면 건너뜀
				if (pPart->GetHistoryFeature(i)->IsDeleted())
					break;
				// 가장 최근에 생성, 수정 된 버전으로 리턴
				else
					return pPart->CopyFeature(pPart->GetHistoryFeature(i));
			}
		}
	}

	return NULL;
}

// 특징형상을 제거하는 함수. 내부에서 DeleteFeature 함수를 호출함
void Manipulation::Delete(char * command, Part * pPart)
{
	string token;
	
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pPart->GetFeatureByName(token) == NULL && pPart->GetCustomFeatureByName(token) == NULL, "No such a feature!");

	// 커스텀 피쳐인 경우 제거하고 빠져나감
	if (pPart->GetCustomFeatureByName(token))
	{
		pPart->EraseCustomFeature(pPart->GetCustomFeatureByName(token)->GetOrder());
		return;
	}

	// 일반적인 피쳐의 제거
	pPart->CheckCurrentState();
	
	Feature * pFeature = pPart->CopyFeature(pPart->GetFeatureByName(token));
	
	try
	{
		pFeature->SetDeleted(true);
		DeleteFeature(token, pPart);
		pPart->SetHistoryFeature(pFeature);

		pPart->GetPartDocumentPtr()->Update(); // 업데이트
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
		pPart->SetUpdateCount(pPart->GetUpdateCount() - 1);
	}
	//
}

// 해당 특징형상과 자식 특징형상을 모두 제거하는 함수
void Manipulation::DeleteFeature(string name, Part * pPart)
{
	vector<string> descendants;
	GetDescendants(name, descendants, pPart);
	
	// 해당 특징형상 제거 후, 첫 번째 순서에 감법(-) 특징형상이 생기는 경우 제거하지 않음
	for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
	{
		int flag = 0;
		int type = pPart->GetFeature(i)->GetType();

		for (int j = 0; j < (int)descendants.size(); ++j)
		{
			if (pPart->GetFeature(i)->GetName() == descendants[j])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;
		else if (type == 0)
			continue;
		else if (flag == 0 && (type == 2 || type == 5 || type == 8 || type == 13 || type == 14 || type == 15))
			TSIThrowExceptionIf<TSIArgumentException>(flag == 0, "You cannot delete this feature. Please reconsider your operation!");
		else
			break;
	}
	
	// 해당 특징형상과 자식 특징형상을 모두 제거
	for (int i = 0; i < (int)descendants.size(); ++i)
	{
		for (int j = 0; j < pPart->GetFeatureListSize(); ++j)
		{
			if (pPart->GetFeature(j)->GetName() == descendants[i])
			{
				pPart->EraseFeature(j);
				pPart->GetFeaturesPtr()->DeleteByName(descendants[i].c_str());
				break;
			}
		}
	}
}

// 해당 특징형상과 자식 특징형상 목록을 가져오는 함수. 재귀적 호출
void Manipulation::GetDescendants(string name, vector<string> & descendants, Part * pPart)
{
	for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
	{
		if (pPart->GetFeature(i)->IsChildOf(name))
			GetDescendants(pPart->GetFeature(i)->GetName(), descendants, pPart);
	}

	descendants.push_back(name);
}