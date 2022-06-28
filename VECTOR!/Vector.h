#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#define DEFAULT_CAPACITY 10
#pragma once

class Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = DEFAULT_CAPACITY; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив данных

public:

	Vector() : Vector(10) {}
	Vector(unsigned int capacity);
	~Vector();

private:
	void EnsureCapacity();
public:

	void PushBack(int value);
	void PushFront(int value);
	void Clear();
	void Insert(int num, unsigned int index);
	void RemoveByIndex(unsigned int index);
	void RemoveByValue(int value);
	void PopFront();
	void PopBack();
	void TrimToSize();
	int IndexOf(unsigned int index);
	int LastIndexOf(unsigned int index);
	void Reverse();
	void SortAsc();
	void Shuffle();
	void RandomFill();
	void Equals(const Vector& a);
	void SortDesc();
	bool IsEmpty() const;
	void Print() const;

	int GetElementAt(unsigned int index);
	int GetSize() const;
	int GetCapacity() const;


	Vector& operator=(Vector& v);
	int& operator [](int index);
	friend istream& operator>>(istream& cin, Vector& v);
	friend ostream& operator << (ostream& os, const Vector& original);

	Vector(const Vector& v);
	// остальные методы обязательно появятся здесь ;)
};
