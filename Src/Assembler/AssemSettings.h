#pragma once

#include <map>

class AssemSettings
{
public:
	AssemSettings();

	CString GetValue(const CString & key) const;
	void SetValue(const CString & key, const CString & value);

	CString GetStringValue(const CString & key) const;
	void SetStringValue(const CString & key, const CString & value);
	int GetIntValue(const CString & key) const;
	void SetIntValue(const CString & key, int value);
	long GetLongValue(const CString & key) const;
	void SetLongValue(const CString & key, long value);
	bool GetBoolValue(const CString & key) const;
	void SetBoolValue(const CString & key, bool value);
	double GetDoubleValue(const CString & key) const;
	void SetDoubleValue(const CString & key, double value);
	
	void InsertNewValue(const CString & key, const CString & defaultValue);
	void InsertNewValue(const CString & key, bool defaultValue);
	void InsertNewValue(const CString & key, int defaultValue);
	void InsertNewValue(const CString & key, long defaultValue);
	void InsertNewValue(const CString & key, double defaultValue);
private:
	void Initialize();

private:
	struct SettingPair
	{
		CString value;
		CString defaultValue;
	};

	typedef std::map<CString, SettingPair> Entries;

	Entries _entries;
};
