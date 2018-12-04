#pragma once

#include <vector>

template<class T>
class PmeBaseList
{	
public:
	typedef typename std::vector<T> ListType;
	typedef int SizeType;

	void Add(T item)
	{
		m_list.push_back(item);
	}

	T GetItem(SizeType index) const
	{
		return m_list[index];
	}

	SizeType GetSize(void) const
	{
		return (SizeType)m_list.size();
	}

	void Clear(void)
	{
		m_list.clear();
	}

	void Delete(SizeType index)
	{
		m_list.erase(m_list.begin() + index);
	}

	SizeType Find(T item)
	{
		SizeType size = GetSize();

		for(SizeType i = 0; i < size; ++ i)
		{
			if(GetItem(i) == item)
				return i;
		}

		return -1;
	}

private:
	ListType m_list;
};