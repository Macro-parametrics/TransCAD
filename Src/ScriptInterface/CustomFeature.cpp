#include "stdafx.h"
#include "CustomFeature.h"

CustomFeature::CustomFeature(Part * pPart)
{
	m_pPart = pPart;
}

CustomFeature::~CustomFeature(void)
{
}

void CustomFeature::Create(char * command)
{
	string token;
	char buffer[1000];
	char * context = NULL;

	// 파라메터 저장 (ex. 'a', 'b', 'c' 등)
	while (token != "FAIL")
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		
		if (token != "FAIL")
			m_params.push_back(token);

	}

	// 모든 명령어 저장
	while (token != "endcustom" && token != "커스텀종료")
	{
		CMD::SetColor(D_BLUE, WHITE); // cmd 색상 변경(배경:파랑, 글자:하얀색)
		
		cout << "> ";
		cin.getline(buffer, 1000);

		token = buffer;
		
		if(token != "endcustom" && token != "커스텀종료")
			m_commands.push_back(token);

	}

	// 커스텀피쳐 순서 저장
	SetOrder(GetPart()->GetCustomFeatureListSize());
	Initialize();
}

void CustomFeature::Initialize(void)
{
	m_initParams = m_params;
	m_initCommands = m_commands;
}

void CustomFeature::Run(char * command)
{
	string token;

	try
	{
		// Input 파라메터 저장
		while (token != "FAIL")
		{
			token = StringToken::GetString( NULL, seps_blank, command );
		
			if (token != "FAIL")
				m_inputParams.push_back(token);
		}
	
		// Input 파라메터가 부족하거나 많이 입력되었을 시 빠져나감
		if (m_inputParams.size() != m_params.size())
		{
			m_inputParams.clear();
			TSIThrowExceptionIf<TSIArgumentException>(m_inputParams.size() != m_params.size(), "Insufficient input parameters!");
		}

		// 명령어 수행
		for (int i = 0; i < (int)m_commands.size(); ++i)
		{
			// 파라메터 연산이 있는 경우
			if (m_commands[i].find("파라메터") != -1 || m_commands[i].find("parameter") != -1)
			{
				token = m_commands[i];
				AddParameter((char *)token.c_str());
				continue;
			}
		
			// 해당 파라메터를 Input 파라메터로 교체
			for (int j = 0; j < (int)m_params.size(); ++j)
			{
				size_t pos = 0;
			
				while ((pos = m_commands[i].find(m_params[j])) != -1)
					m_commands[i].replace(pos, m_params[j].length(), m_inputParams[j]);
			}

			// 실행할 커멘드
			token = m_commands[i];

			// 루프 처리
			if (token.find("loop", 0) != -1)
			{
				ProcessLoop((char *)token.c_str(), i);
				continue;
			}

			// 조건문 처리
			if (token.find("if", 0) != -1)
			{
				ProcessIf((char *)token.c_str(), i);
				continue;
			}

			// 스케치가 열려있을 때
			if (GetPart()->GetCurrentSketch())
				GetPart()->OnCreatingSketch((char *)token.c_str());
			// 다 수의 레퍼런스를 선택 중일 때
			else if (GetPart()->GetCurrentReference())
				GetPart()->OnSelectingReferences((char *)token.c_str());
			// 일반적인 경우
			else
				GetPart()->RunCommands((char *)token.c_str());
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}

	// 초기화
	m_inputParams.clear();
	m_commands.clear();
	m_params.clear();
	m_commands = m_initCommands;
	m_params = m_initParams;
}

void CustomFeature::Help(void)
{
	cout << "customfeature " << GetName();

	for (int i = 0; i < (int)m_params.size(); ++i)
		cout << " " << m_params[i];

	cout << endl;

	for (int i = 0; i < (int)m_initCommands.size(); ++i)
		cout << m_initCommands[i] << endl;

	cout << "endcustom" << endl;
}

void CustomFeature::AddParameter(char * command)
{
	string token, temp;

	token = StringToken::GetString( NULL, " =", command );
	token = StringToken::GetString( NULL, " =", command );

	// 파라메터 이름 저장 (좌변)
	m_params.push_back(token);

	temp = StringToken::GetString( NULL, "=", command );

	TSIThrowExceptionIf<TSIArgumentException>(temp == "FAIL", "Invalid parameter definition!");

	// 새로운 파라메터 값 계산 (우변)
	// 입력 파라메터 값들의 사칙연산을 통해 계산
	for (int i = 0; i < (int)m_params.size(); ++i)
	{
		size_t pos = 0;
			
		while ((pos = temp.find(m_params[i])) != -1)
		{
			// 음수인 경우(ex.-1 → (0-1))로 변환
			if(atof(m_inputParams[i].c_str()) < 0)
			{
				token = "(0" + m_inputParams[i] + ")";
				temp.replace(pos, m_params[i].length(), token);
			}
			else
				temp.replace(pos, m_params[i].length(), m_inputParams[i]);
		}
	}

	token = StringCalc::GetPostFix(temp);			// 후위 표기법으로 변환
	double result = StringCalc::Calculate(token);	// 계산

	char buffer[500];
	sprintf_s(buffer, sizeof(buffer), "%f", result);
	//

	// 파라메터 값 저장
	token = buffer;
	m_inputParams.push_back(token);
}

void CustomFeature::ProcessLoop(char * command, int & index)
{
	// Loop 처리 루틴
	string token, param;
	string start, end;

	token = StringToken::GetString( NULL, seps_blank, command );
	
	token = StringToken::GetString( NULL, seps_blank, command );
	param = token;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	start = token;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	end = token;
	
	m_params.push_back(param);
	int paramPos = (int)m_params.size() - 1;
	
	string tempCommand;
	vector<string> tempCommands;
	index++;
	int indexif = index;
	int endif = index;

	while (m_commands[index] != "endloop")
	{
		tempCommands.push_back(m_commands[index]);
		index++;
	}
		
	//tempCommand = m_commands[index];
		
	for (int i = atoi(start.c_str()); i <= atoi(end.c_str()); ++i)
	{
		for (int j = 0; j < (int)tempCommands.size(); ++j)
		{
			indexif = index;
			
			size_t pos = 0;
			
			char str[128];
			_itoa_s(i, str, 10);
			token = str;

			if (i == atoi(start.c_str()))
				m_inputParams.push_back(token);
			else
				m_inputParams[paramPos].replace(0, token.length(), str);

			token = tempCommands[j];

			while ((pos = token.find(param)) != -1)
				token.replace(pos, param.length(), str);
			
			// 조건문 처리
			if (token.find("if", 0) != -1)
			{
				ProcessIf((char *)token.c_str(), endif);
				j = j + endif - indexif;
				continue;
			}

			// 스케치가 열려있을 때
			if (GetPart()->GetCurrentSketch())
				GetPart()->OnCreatingSketch((char *)token.c_str());
			// 다 수의 레퍼런스를 선택 중일 때
			else if (GetPart()->GetCurrentReference())
				GetPart()->OnSelectingReferences((char *)token.c_str());
			// 일반적인 경우
			else
				GetPart()->RunCommands((char *)token.c_str());
		}

		if (endif != 0)
			index = endif;
		
		index++;
	}
}

void CustomFeature::ProcessIf(char * command, int & index)
{
	// If 처리 루틴
	string token, param1, param2;
	vector<double> result;
	string condition;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	
	token = StringToken::GetString( NULL, seps_blank, command );
	param1 = token;
	token = StringCalc::GetPostFix(param1);
	result.push_back(StringCalc::Calculate(token));	// 계산

	token = StringToken::GetString( NULL, seps_blank, command );
	condition = token;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	param2 = token;
	token = StringCalc::GetPostFix(param2);
	result.push_back(StringCalc::Calculate(token));	// 계산

	bool isTrue = false;

	// 조건문 판별
	if (condition == "==")
	{
		if (result[0] == result[1])
			isTrue = true;
	}
	else if  (condition == "!=")
	{
		if (result[0] != result[1])
			isTrue = true;
	}
	else if  (condition == ">")
	{
		if (result[0] > result[1])
			isTrue = true;
	}
	else if  (condition == "<")
	{
		if (result[0] < result[1])
			isTrue = true;
	}
	else if  (condition == ">=")
	{
		if (result[0] >= result[1])
			isTrue = true;
	}
	else if  (condition == "<=")
	{
		if (result[0] <= result[1])
			isTrue = true;
	}

	string tempCommand;
	index++;

	while (m_commands[index] != "endif")
	{
		tempCommand = m_commands[index];

		for (int i = 0; i < (int)m_params.size(); ++i)
		{
			size_t pos = 0;
			
			while ((pos = tempCommand.find(m_params[i])) != -1)
			{
				// 음수인 경우(ex.-1 → (0-1))로 변환
				if(atof(m_inputParams[i].c_str()) < 0)
				{
					token = "(0" + m_inputParams[i] + ")";
					tempCommand.replace(pos, m_params[i].length(), token);
				}
				else
					tempCommand.replace(pos, m_params[i].length(), m_inputParams[i]);
			}
		}

		token = tempCommand;
		
		if (isTrue)
		{
			// 루프 처리
			if (token.find("loop", 0) != -1)
			{
				ProcessLoop((char *)token.c_str(), index);
				index++;
				continue;
			}
			
			// 스케치가 열려있을 때
			if (GetPart()->GetCurrentSketch())
				GetPart()->OnCreatingSketch((char *)token.c_str());
			// 다 수의 레퍼런스를 선택 중일 때
			else if (GetPart()->GetCurrentReference())
				GetPart()->OnSelectingReferences((char *)token.c_str());
			// 일반적인 경우
			else
				GetPart()->RunCommands((char *)token.c_str());
		}
		
		index++;
	}
}