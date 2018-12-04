#pragma once
#include "TransCADScript.h"

// 최 상단에 존재하는 클래스. Feature, SketchItem, Reference 클래스에서 Object를 상속받음
class Object
{
public:
	Object(int type);
	virtual ~Object(void);

	bool CheckValid(string token);

	VARIABLE_IS_AND_SET_FUNC_IMPL(bool, Modified, m_isModified);
	VARIABLE_IS_AND_SET_FUNC_IMPL(bool, Deleted, m_isDeleted);

	VARIABLE_GET_AND_SET_FUNC_IMPL(string, Name, m_name);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, Type, m_type);

	virtual void GetInfo(char * command) {}	// 명령어 수행
	virtual void AskInfo(void) {}			// 정보 취득
	virtual void Restore(void) {}			// 복구
	virtual void Help(void) {}		// 도움말

	string token;

private:
	string	m_name;		// 객체 이름
	int m_type;			// 객체 타입
	bool m_isModified;	// modify 여부
	bool m_isDeleted;	// delete 여부
};