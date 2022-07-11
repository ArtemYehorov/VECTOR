#include"Vector.h"
#pragma once

template < typename T>
class Stack
{
	Vector<int> data;

	bool IsEmpty() const { return data.IsEmpty(); }
public:

	void Push(T value)
	{
		data.Insert(value , 0);		
	}

	int Peek()
	{
		if (!IsEmpty())
			return data[0];
		else
			return -1;
	}

	void Pop(T value)
	{
		if (!IsEmpty())
		{
			value = data[0];
			data.RemoveByIndex(0);
		}
		else
			value = -1;
	}

	unsigned int GetSIZE()
	{
		return data.GetSize();
	}

	void Clear()
	{
		data.Clear();
	}

};

