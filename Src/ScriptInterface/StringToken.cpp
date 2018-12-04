#include "stdafx.h"
#include "StringToken.h"

// 입력받은 buffer 혹은 command의 유효성을 검사. 유효하지 않은 경우 FAIL 문자열을 리턴
string StringToken::GetString (char * buffer, const char * separater, char *& command)
{
	string temp;
	
	// buffer가 있는 경우. 즉, 맨 처음 읽었을 때 진입
	if (buffer != NULL && buffer[0] != NULL)
	{
		temp = strtok_s( buffer, separater, &command );
	}
	// command 값이 NULL 이 아닌 경우. 일반적인 경우 진입
	else if (command != NULL)
	{
		string blank = " ";
		string blanks = "";

		// 공백 문자열 판단
		for (int i = 0; i < 100; ++i)
		{
			char * check = (char *)blanks.c_str();

			if (*command == *check)
			{
				temp = "FAIL";
				return temp;
			}

			blanks = blanks + blank;
		}
		
		// 공백이 아닌 경우
		temp = strtok_s( buffer, separater, &command );
	}
	else
	{
		// 유효하지 않은 경우
		temp = "FAIL";
	}

	return temp;
}