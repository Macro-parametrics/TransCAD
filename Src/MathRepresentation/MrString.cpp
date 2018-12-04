#include <cstdio>
#include <cstdarg>
#include <algorithm>
#include ".\MrString.h"
#include ".\MrExceptionTest.h"
#include ".\MrArgumentOutOfRangeException.h"
#include ".\MrDebug.h"

using namespace std;

MrString::MrString(void)
: _pData(0)
{
	AllocateString();
}

MrString::MrString(const __wchar_t * pStr)
: _pData(0)
{
	AllocateString(pStr);
}

MrString::MrString(const unsigned short * pStr)
: _pData(0)
{
	AllocateString((const __wchar_t *)pStr);
}

MrString::MrString(const MrString & str)
: _pData(0)
{
	AllocateString(str._pData);
}

MrString::MrString(unsigned int size)
{
	_pData = new __wchar_t[size + 1];
	_length = size;
}

MrString::~MrString(void)
{
	ReleaseString();
}

unsigned int MrString::Length(void) const
{
	return _length;
}

MrString MrString::Substring(unsigned int startIndex) const
{
	return Substring(startIndex, Length() - startIndex);
}

MrString MrString::Substring(unsigned int startIndex, unsigned int count) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(
		count == 0
		|| startIndex >= Length()
		|| startIndex + count > Length()
		);

	MrString ret(count);

	wcsncpy(ret._pData, _pData + startIndex, count);
	ret._pData[count] = L'\0';

	return ret;
}

MrString MrString::Append(const MrString & str) const
{
	unsigned int len = Length() + str.Length();
	MrString ret(len);

	wcscpy(ret._pData, _pData);
	wcscat(ret._pData, str._pData);

	return ret;
}

MrString MrString::Insert(unsigned int position, const MrString & str) const
{
	unsigned int srcLen = Length();

	MrThrowExceptionIf<MrArgumentOutOfRangeException>(position > srcLen);

	unsigned int retLen = Length() + str.Length();
	unsigned int strLen = str.Length();

	MrString ret(retLen);

	if(position)
        wcsncpy(ret._pData, _pData, position);
	ret._pData[position] = '\0';
	
	wcscat(ret._pData + position, str._pData);
	
	if(position < srcLen)
        wcscpy(ret._pData + position + strLen, _pData + position);

	return ret;
}

MrString MrString::Remove(unsigned int startIndex) const
{
	return Remove(startIndex, Length() - startIndex);
}

MrString MrString::Remove(unsigned int startIndex, unsigned int count) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(
		startIndex >= Length()
		|| startIndex + count > Length()
		);

	unsigned int retLen = Length() - count;
	MrString ret(retLen);

	if(startIndex)
		wcsncpy(ret._pData, _pData, startIndex);
	ret._pData[startIndex] = '\0';

	wcscpy(ret._pData + startIndex, _pData + startIndex + count);
	
	return ret;
}

int MrString::Compare(const MrString & str) const
{
	return wcscmp(_pData, str._pData);
}

int MrString::FindIndexOf(__wchar_t ch, unsigned int startIndex) const
{
	if(startIndex >= Length())
		return -1;

	__wchar_t * index = wcschr(_pData + startIndex, ch);
	
	if(index == 0)
		return -1;
	else
		return (int)(index - _pData);
}

int MrString::FindIndexOf(const MrString & str, unsigned int startIndex) const
{
	if(startIndex >= Length() || str.Length() == 0)
		return -1;

	__wchar_t * index = wcsstr(_pData + startIndex, str._pData);
	
	if(index == 0)
		return -1;
	else
		return (int)(index - _pData);
}

int MrString::FindLastIndexOf(__wchar_t ch) const
{
	if(Length() == 0)
		return -1;

	__wchar_t * index = wcsrchr(_pData, ch);
	
	if(index == 0)
		return -1;
	else
		return (int)(index - _pData);
}

int MrString::FindLastIndexOf(__wchar_t ch, unsigned int startIndex) const
{
	unsigned int len = Length();

	if(len == 0)
		return -1;
	if(startIndex >= len)
		startIndex = len - 1;

	__wchar_t * cur = _pData + startIndex;

	while(cur != _pData && *cur != ch)
		-- cur;

	if(*cur == ch)
		return (int)(cur - _pData);
	else
		return -1;
}

int MrString::FindLastIndexOf(const MrString & str) const
{
	return FindLastIndexOf(str, Length() - 1);
}

int MrString::FindLastIndexOf(const MrString & str, unsigned int startIndex) const
{
	unsigned int len1 = Length();
	unsigned int len2 = str.Length();

	if(len1 == 0 || len2 == 0)
		return -1;
	if(startIndex >= len1)
		startIndex = len1 - 1;

	__wchar_t * cur = _pData + startIndex - len2 + 1;

	while(cur != _pData && wcsncmp(cur, str._pData, len2))
		cur --;

	if(wcsncmp(cur, str._pData, len2))
        return -1;
	else
		return (int)(cur - _pData);
}

MrString MrString::Reverse(void) const
{
	unsigned int srcLen = Length();

	if(srcLen == 0)
		return *this;

	MrString ret = *this;
	_wcsrev(ret._pData);

	return ret;
}

bool MrString::StartsWith(const MrString & str) const
{
	unsigned int len = str.Length();

	if(len > Length())
		return false;

	return Substring(0, len).Compare(str) == 0;
}

bool MrString::EndsWith(const MrString & str) const
{
	unsigned int len1 = Length();
	unsigned int len2 = str.Length();

	if(len2 > len1)
		return false;

	return Substring(len1 - len2).Compare(str) == 0;
}

MrString MrString::Trim(__wchar_t ch) const
{
	return TrimLeft(ch).TrimRight(ch);
}

MrString MrString::Trim(const MrString & target) const
{
	return TrimLeft(target).TrimRight(target);
}

MrString MrString::TrimLeft(__wchar_t ch) const
{
	if(Length() == 0)
		return *this;

	__wchar_t * cur = _pData;
	while((*cur != L'\0') && (*cur == ch))
		++ cur;

	unsigned int retLen = (int)wcslen(cur);
	MrString ret(retLen);
	wcscpy(ret._pData, cur);
	
	return ret;
}

MrString MrString::TrimLeft(const MrString & target) const
{
	if(Length() == 0)
		return *this;

	__wchar_t * cur = _pData;
	while((*cur != L'\0') && (target.FindIndexOf(*cur) != -1))
		++ cur;

	unsigned int retLen = (unsigned int)wcslen(cur);
	MrString ret(retLen);
	wcscpy(ret._pData, cur);

	return ret;
}

MrString MrString::TrimRight(__wchar_t ch) const
{
	unsigned int srcLen = Length();

	if(Length() == 0)
		return *this;

	__wchar_t * cur = _pData + srcLen - 1;
	while((cur != _pData) && (*cur == ch))
		-- cur;

	unsigned int retLen = (unsigned int)(cur - _pData) + 1;
	MrString ret(retLen);
	wcsncpy(ret._pData, _pData, retLen);
	ret._pData[retLen] = L'\0';

	return ret;
}

MrString MrString::TrimRight(const MrString & target) const
{
	unsigned int srcLen = Length();

	if(Length() == 0)
		return *this;

	__wchar_t * cur = _pData + srcLen - 1;
	while((cur != _pData) && (target.FindIndexOf(*cur) != -1))
		-- cur;

	unsigned int retLen = (unsigned int)(cur - _pData) + 1;
	MrString ret(retLen);
	wcsncpy(ret._pData, _pData, retLen);
	ret._pData[retLen] = L'\0';

	return ret;
}

MrString MrString::ToUpper(void) const
{
	MrString ret = *this;
	_wcsupr(ret._pData);
	
	return ret;
}

MrString MrString::ToLower(void) const
{
	MrString ret = *this;
	_wcslwr(ret._pData);

	return ret;
}

__wchar_t & MrString::operator()(unsigned int index)
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Length());

	return *(_pData + index);
}

__wchar_t MrString::operator()(unsigned int index) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Length());

	return *(_pData + index);
}

MrString & MrString::operator=(const MrString & str)
{
	if(this == &str)
		return *this;

	AllocateString(str._pData);

	return *this;
}

MrString & MrString::operator+=(const MrString & str)
{
	unsigned int len = Length() + str.Length();

	__wchar_t * buf = new __wchar_t[len + 1];

	wcscpy(buf, _pData);
	wcscat(buf, str._pData);

	swap(buf, _pData);

	delete [] buf;

	return *this;
}

MrString::operator const __wchar_t *() const
{
	return _pData;
}

MrString::operator const unsigned short *() const
{
	return (const unsigned short *)_pData;
}

void MrString::AllocateString(const __wchar_t * pStr)
{
	ReleaseString();

	unsigned int len = 0;

	if(pStr)
        len = (unsigned int)wcslen(pStr);

	_pData = new __wchar_t[len + 1];
	
	if(len)
		wcscpy(_pData, pStr);
	else
		_pData[0] = L'\0';

	_length = (unsigned int)len;
}

void MrString::ReleaseString(void)
{
	if(_pData)
	{
		delete [] _pData;
		_pData = 0;
		_length = -1;
	}
}

MrString MrString::CreateFormattedString(const __wchar_t * pFormat, ...)
{
	using namespace std;

	va_list args;
	va_start(args, pFormat);

	int retLen = _vscwprintf(pFormat, args);
    
	MrString ret(retLen);
	vswprintf(ret._pData, pFormat, args);

	va_end(args);

	return ret;
}

MrString MrString::CreateFormattedString(const unsigned short * pFormat, ...)
{
	using namespace std;

	const __wchar_t * pNewFormat = (const __wchar_t *)pFormat;

	va_list args;
	va_start(args, pFormat);

	int retLen = _vscwprintf(pNewFormat, args);
    
	MrString ret(retLen);
	vswprintf(ret._pData, pNewFormat, args);

	va_end(args);

	return ret;
}