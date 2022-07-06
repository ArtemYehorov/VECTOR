#include"Vector.h"
#pragma once
class Stack
{
	Vector data;
	bool IsEmpty() const { return data.IsEmpty(); }
public:

	void Push(int value)
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

	void Pop(int value)
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

