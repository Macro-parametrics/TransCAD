#pragma once


class TSIException
{
public:
	TSIException(void);
	TSIException(const char * message);
	virtual ~TSIException(void);

	const char * GetMessage(void) const {return m_message;}

private:
	const char * m_message;
};