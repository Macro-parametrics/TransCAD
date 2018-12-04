#pragma once
#include "TransCADScript.h"
#include "Part.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"

class CustomFeature
{
public:
	CustomFeature(Part * pPart);
	virtual ~CustomFeature(void);

	void Create(char * command);
	void Run(char * command);

	void Initialize(void);

	void Help(void);

	VARIABLE_GET_AND_SET_FUNC_IMPL(string, Name, m_name);
	VARIABLE_GET_AND_SET_FUNC_IMPL(int, Order, m_order);
	LIST_GET_AND_SET_FUNC_IMPL(string, Parameters, m_params);
	LIST_GET_AND_SET_FUNC_IMPL(string, Commands, m_commands);

protected:
	void AddParameter(char * command);
	void ProcessLoop(char * command, int & index);
	void ProcessIf(char * command, int & index);

	VARIABLE_GET_AND_SET_FUNC_IMPL(Part *, Part, m_pPart);

private:
	Part *	m_pPart;
	string m_name;
	int m_order;
	vector<string> m_params;
	vector<string> m_initParams;
	vector<string> m_inputParams;
	vector<string> m_commands;
	vector<string> m_initCommands;
};