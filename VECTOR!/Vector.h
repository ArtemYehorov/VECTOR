#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#define DEFAULT_CAPACITY 10
#pragma once

template < typename T>
class Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = DEFAULT_CAPACITY; // ёмкость (вместительность, запас памяти)
	T* data = nullptr; // указатель на динамический массив данных

public:

	Vector() : Vector(10) {}
	Vector(unsigned int capacity);
	~Vector();

private:
	void EnsureCapacity();
public:

	void PushBack(T value);
	void PushFront(T value);
	void Clear();
	void Insert(T num, unsigned int index);
	void RemoveByIndex(unsigned int index);
	void RemoveByValue(T value);
	void PopFront();
	void PopBack();
	void TrimToSize();
	int IndexOf(T index);
	int LastIndexOf(T index);
	void Reverse();
	void SortAsc();
	void Shuffle();
	void RandomFill();
	void Equals(const Vector& a);
	void SortDesc();
	bool IsEmpty() const;
	void Print() const;

	T GetElementAt(unsigned int index);
	int GetSize() const;
	int GetCapacity() const;


	Vector& operator=(Vector& v);
	int& operator [](int index);
	friend istream& operator>>(istream& cin, Vector& v);
	friend ostream& operator << (ostream& os, const Vector& original);

	Vector(const Vector& v);
	// остальные методы обязательно появятся здесь ;)
};

#define LIMIT_CAPACITY 10

#pragma region Сonstructors:

template < typename T>
Vector<T>::Vector(unsigned int capacity)
{
	if (capacity < 10)
	{
		capacity = 10;
	}
	this->capacity = capacity;
	data = new T[capacity];
	// cout << "C-TOR WITH PARAMS!\n";
}

template < typename T>
Vector<T>::~Vector()
{
	// cout << "DESTRUCTOR!\n";
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

#pragma endregion

template < typename T>
void Vector<T>::EnsureCapacity()
{
	if (size == capacity) // если все элементы массива заняты
	{
		capacity *= 2;
		T* temp = new int[capacity];
		for (unsigned int i = 0; i < size; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}
}

template < typename T>
void Vector<T>::PushBack(T value)
{
	EnsureCapacity();
	data[size++] = value;
}

template < typename T>
void Vector<T>::PushFront(T value)
{
	EnsureCapacity();
	for (unsigned int i = size; i > 0; i--)
		data[i] = data[i - 1];
	data[0] = value;
	size++;
}

template < typename T>
void Vector<T>::Clear()
{
	size = 0;
}


template < typename T>
void Vector<T>::Insert(T num, unsigned int index)
{
	if (index > size)
	{
		index = size;
	}
	else if (index < 0)
	{
		index = 0;
	}
	size++;
	EnsureCapacity();
	for (unsigned int i = size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = num;
}

template < typename T>
void Vector<T>::RemoveByIndex(unsigned int index)
{
	if (index > size)
	{
		index = size;
	}
	for (int i = index; i < size; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template < typename T>
void Vector<T>::RemoveByValue(T value)
{
	for (int i = size; i > 0; --i)
	{
		if (data[i] == value)
		{
			RemoveByIndex(i);
		}
	}
	if (data[0] == value)
	{
		RemoveByIndex(0);
	}
}

template < typename T>
void Vector<T>::PopFront()
{
	RemoveByIndex(0);
}

template < typename T>
void Vector<T>::PopBack()
{
	RemoveByIndex(size - 1);
}

template < typename T>
void Vector<T>::TrimToSize()
{
	capacity = size;
	T* temp = new int[capacity];
	for (unsigned int i = 0; i < size; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
}

template < typename T>
int Vector<T>::IndexOf(T index)
{
	for (int i = size; i > 0; i--)
	{
		if (data[i] == index) return i;
	}
	return -1;
}

template < typename T>
int Vector<T>::LastIndexOf(T index)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == index) return i;
	}
	return -1;
}

template < typename T>
void Vector<T>::Reverse()
{
	reverse(data, size + data);
}

template < typename T>
void Vector<T>::SortAsc()
{
	T temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

template < typename T>
void Vector<T>::Shuffle()
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		swap(data[i], data[rand() % size]);
}

template < typename T>
void Vector<T>::RandomFill()
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		data[i] = rand();
	}
}

template < typename T>
void Vector<T>::Equals(const Vector& a)
{
	bool capa;
	bool siz;
	bool dat;
	if (a.capacity == capacity)
	{
		capa = true;
	}
	else
	{
		capa = false;
	}
	if (a.size == size)
	{
		siz = true;
	}
	else
	{
		siz = false;
	}
	for (int i = 0; i < size; i++)
	{
		if (a.data[i] == data[i])
		{
			dat = true;
		}
		else
		{
			dat = false;
			break;
		}
	}
	if (capa && siz && dat)
	{
		cout << "THE SAME!!\n";
	}
	else
	{
		cout << "Not the same!\n";
	}
}

template < typename T>
T Vector<T>::GetElementAt(unsigned int index)
{
	if (index > size)
	{
		return -1;
	}
	else
	{
		T a = data[index];
		return a;
	}
}

template < typename T>
void Vector<T>::SortDesc()
{
	SortAsc();
	Reverse();
}

#pragma region GETTERS :
template < typename T>
int Vector<T>::GetSize() const
{
	return size;
}

template < typename T>
int Vector<T>::GetCapacity() const
{
	return capacity;
}
#pragma endregion

template < typename T>
bool Vector<T>::IsEmpty() const
{
	return size == 0;
}

template < typename T>
void Vector<T>::Print() const
{
	if (IsEmpty())
	{
		cout << "Vector is empty.\n";
		return;
	}
	for (unsigned int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << "\n";
	cout << "Size - " << size << "\n";
	cout << "Capacity - " << capacity << "\n";
}

template < typename T>
Vector<T>& Vector<T>::operator = (Vector<T>& v)
{
	if (this == &v)
	{
		return *this;
	}
	size = v.size;
	data = v.data;

	v.data = nullptr;
	v.size = 0;

	return *this;
}

template < typename T>
int& Vector<T>::operator [](int index)
{
	if (index < 0 || index >= size)
		return data[0];
	return data[index];
}

template < typename T>
istream& operator >> (istream& cin, Vector<T>& v)
{
	delete[] v.data;
	cout << "Enter size: ";
	cin >> v.size;
	cout << "Enter capacity: ";
	cin >> v.capacity;

	if (v.capacity > LIMIT_CAPACITY)
	{
		v.capacity = 10;
	}
	if (v.size <= 0 || v.size > v.capacity)
	{
		v.size = 2;
	}

	v.data = new T[v.capacity];
	for (int i = 0; i < v.size; i++)
	{
		cout << "Enter vector element: ";
		cin >> v.data[i];
		cout << "\n";
	}
	return cin;
}

template < typename T>
ostream& operator << (ostream& os, const Vector<T>& original)
{
	if (original.IsEmpty())
	{
		os << "Vector is empty.\n";
		return os;
	}
	for (unsigned int i = 0; i < original.size; i++)
		os << original.data[i] << " ";
	os << "\n";
	os << "Size - " << original.size << "\n";
	os << "Capacity - " << original.capacity << "\n";
	return os;
}

template < typename T>
Vector<T>::Vector(const Vector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->data = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = v.data[i];
	}
}
// остальные методы обязательно появятся здесь ;)