#pragma once

#include ".\MrMacro.h"

class MrString;

class MR_API MrString
{
public:
	// Constructors
	MrString(void);
	MrString(const __wchar_t * pStr);
	MrString(const unsigned short * pStr);
	MrString(const MrString & str);
private:
	explicit MrString(unsigned int size);

public:
	// Destructors
	~MrString(void);

	// Properties
	unsigned int Length(void) const;
	bool IsEmpty(void) const {return Length() == 0;}

	__wchar_t & operator()(unsigned int index);
	__wchar_t operator()(unsigned int index) const;

	// Operators
	MrString Substring(unsigned int startIndex) const;
	MrString Substring(unsigned int startIndex, unsigned int count) const;
	
	MrString Append(const MrString & str) const;
	MrString Insert(unsigned int position, const MrString & str) const;
	MrString Remove(unsigned int startIndex) const;
	MrString Remove(unsigned int startIndex, unsigned int count) const;

	int Compare(const MrString & str) const;

	int FindIndexOf(__wchar_t ch, unsigned int startIndex = 0) const;
	int FindIndexOf(const MrString & str, unsigned int startIndex = 0) const;
	int FindLastIndexOf(__wchar_t ch) const;
	int FindLastIndexOf(__wchar_t ch, unsigned int startIndex) const;
	int FindLastIndexOf(const MrString & str) const;
	int FindLastIndexOf(const MrString & str, unsigned int startIndex) const;

	MrString Reverse(void) const;

	bool StartsWith(const MrString & str) const;
	bool EndsWith(const MrString & str) const;

	MrString Trim(__wchar_t ch = L' ') const;
	MrString Trim(const MrString & target) const;
	MrString TrimLeft(__wchar_t ch = L' ') const;
	MrString TrimLeft(const MrString & target) const;
	MrString TrimRight(__wchar_t ch = L' ') const;
	MrString TrimRight(const MrString & target) const;

	MrString ToUpper(void) const;
	MrString ToLower(void) const;

	MrString & operator=(const MrString & str);
	MrString & operator+=(const MrString & str);

	operator const __wchar_t *() const;
	operator const unsigned short *() const;

	static MrString CreateFormattedString(const __wchar_t * pFormat, ...);
	static MrString CreateFormattedString(const unsigned short * pFormat, ...);

private:
	void AllocateString(const __wchar_t * pStr = 0);
	void ReleaseString(void);

private:
	__wchar_t * _pData;
	unsigned int _length;
};

MR_API inline MrString operator+(const MrString & str1, const MrString & str2) {return str1.Append(str2);}
MR_API inline bool operator==(const MrString & str1, const MrString & str2) {return str1.Compare(str2) == 0;}
MR_API inline bool operator!=(const MrString & str1, const MrString & str2) {return str1.Compare(str2) != 0;}
MR_API inline bool operator>(const MrString & str1, const MrString & str2) {return str1.Compare(str2) > 0;}
MR_API inline bool operator>=(const MrString & str1, const MrString & str2) {return str1.Compare(str2) >= 0;}
MR_API inline bool operator<(const MrString & str1, const MrString & str2) {return str1.Compare(str2) < 0;}
MR_API inline bool operator<=(const MrString & str1, const MrString & str2) {return str1.Compare(str2) <= 0;}