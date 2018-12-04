#include "stdafx.h"
#include "ReferenceFeature.h"

ReferenceFeature::ReferenceFeature(Feature * pFeature, int referenceType)
	:Reference(pFeature, referenceType)
{
}

ReferenceFeature::~ReferenceFeature(void)
{
}

void ReferenceFeature::GetInfo(char * command)
{
	if (GetType() == 6) // Feature 1개 일 때
		SelectFeature(command);
	else if (GetType() == 7) // Feature 여러 개 일 때
		SelectFeatures(command);
	
	if (GetReferencePtr())
	{
		GetFeature()->GetPart()->SetCurrentReferencePtr(GetReferencePtr());
		GetFeature()->GetPart()->SetCurrentReferencesPtr(NULL);
	}
	else if (GetReferencesPtr())
	{
		GetFeature()->GetPart()->SetCurrentReferencePtr(NULL);
		GetFeature()->GetPart()->SetCurrentReferencesPtr(GetReferencesPtr());
	}
}

void ReferenceFeature::AddInfo(TransCAD::IReferencePtr spReference)
{
	SetReferencePtr(spReference);

	string name(GetReferencePtr()->GetReferenceeName());
	SetReferenceName(name);
	SetName(name);

	SetTargetFeature(GetName());
	
	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceFeature::AddInfo(TransCAD::IReferencesPtr spReferences)
{
	SetReferencesPtr(spReferences);

	for (int i = 1; i <= GetReferencesPtr()->GetCount(); ++i)
	{
		string name = GetReferencesPtr()->GetItem(i)->GetReferenceeName();
		SetReferenceName(name);
		SetTargetFeature(name);
	}
	
	assert(GetTargetFeatureListSize() != 0);

	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceFeature::AskInfo(void)
{
	char buffer[500];
	
	if (GetReferencePtr())			// Reference 포인터일 때
		cout << "selectfeature " + GetName() << endl;
	else if (GetReferencesPtr())	// References 포인터일 때
	{
		if ((int)GetReferencesPtr()->GetCount() == 1)
			cout << "selectfeature " + GetReferencesPtr()->GetItem(1)->GetReferenceeName() << endl;
		else
		{
			sprintf_s(buffer, "selectfeatures %d", (int)GetReferencesPtr()->GetCount());
			cout << buffer << endl;

			for (int i = 1; i <= (int)GetReferencesPtr()->GetCount(); ++i)
			{
				token = GetReferencesPtr()->GetItem(i)->GetReferenceeName();
				cout << "selectfeature " << token << endl;
			}
		}
	}
}

void ReferenceFeature::Help(void)
{
	if (GetType() == 6)
	{
		cout << " [selectfeature p1]" << endl;
		cout << " -p1 : " << "Feature Name" << endl;
		cout << " [EXAMPLE 1] " << "selectfeature Extrude1" << endl;
		cout << " [EXAMPLE 2] " << "selectfeature Cut1" << endl;
		cout << " [NOTE] " << "This function is used for pattern features" << endl;
	}
	else if (GetType() == 7)
	{
		cout << " [selectfeatures p1]" << endl;
		cout << " -p1 : " << "Total Number of Features" << endl;
		cout << " [EXAMPLE 1]" << "	selectfeatures 2" << endl;
		cout << "		selectfeature Extrude1" << endl;
		cout << "		selectfeature Cut1" << endl;
		cout << " [EXAMPLE 2]" << "	selectfeatures 3" << endl;
		cout << "		selectbrep Extrude1" << endl;
		cout << "		cancel" << endl;
		cout << " [NOTE 1] " << "Use 'selectfeature' function during the selection" << endl;
		cout << " [NOTE 2] " << "You should select the correct feature exactly p1 times" << endl;
		cout << " [NOTE 3] " << "'cancel(취소)' will escape this function" << endl;
		cout << " [NOTE 4] " << "This function is used for pattern features" << endl;
	}
}

void ReferenceFeature::Restore(void)
{
	if (GetType() == 7)	// Feature 여러 개 일 때
	{
		SetReferencesPtr(GetFeature()->GetPart()->GetPartPtr()->CreateReferences());

		for (int i = 0; i < (int)GetReferenceNameListSize(); ++i)
		{
			SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectFeatureByName(GetReferenceName(i).c_str()));
			assert(GetReferencePtr());
			GetReferencesPtr()->Add(GetReferencePtr());
		}

		SetReferencePtr(NULL);
	}
	else				// Feature 1개 일 때
	{
		SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectFeatureByName(GetName().c_str()));
		assert(GetReferencePtr());
	}
}

void ReferenceFeature::RunCommands(char * command)
{
	try
	{
		TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "No command!");

		switch(Commands.GetReferenceType(token))
		{
			case Feature_Type:
				SelectFeature(command);
				break;
			default:
				if (token != "취소" && token != "cancel") cout << "Invalid command!" << endl;
				else SetReferencesPtr(NULL);
				break;
		}

		// 레퍼런스가 선택된 경우
		if (GetReferencePtr())
		{
			GetReferencesPtr()->Add(GetReferencePtr());
			SetReferencePtr(NULL);

			m_selectCount++;
		}
		
		// 모든 레퍼런스가 선택된 경우
		if (m_totalCount == m_selectCount)
		{
			CMD::SetColor(D_BLUE, YELLOW);
			GetFeature()->GetPart()->SetCurrentReferencesPtr(GetReferencesPtr());
			GetFeature()->GetPart()->SetCurrentFeature(NULL);
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}

void ReferenceFeature::SelectFeature(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	
	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectFeatureByName(token.c_str()));

	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");
	
	SetName(token);
}

void ReferenceFeature::SelectFeatures(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	
	m_totalCount = atoi(token.c_str());
	m_selectCount = 0;

	TSIThrowExceptionIf<TSIArgumentException>(m_totalCount < 2, "Enter a number greater than 1!");
	SetReferencesPtr(GetFeature()->GetPart()->GetPartPtr()->CreateReferences());

	GetFeature()->GetPart()->SetCurrentFeature(this);
	CMD::SetColor(D_BLUE, WHITE);
}