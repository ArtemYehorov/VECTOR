#include "Vector.h"
#define LIMIT_CAPACITY 10

#pragma region Сonstructors:
	Vector::Vector(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}
	Vector::~Vector()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
#pragma endregion

	void Vector::EnsureCapacity()
	{
		if (size == capacity) // если все элементы массива заняты
		{
			capacity *= 2;
			int* temp = new int[capacity];
			for (unsigned int i = 0; i < size; i++)
				temp[i] = data[i];
			delete[] data;
			data = temp;
		}
	}

	void Vector::PushBack(int value)
	{
		EnsureCapacity();
		data[size++] = value;
	}
	void Vector::PushFront(int value)
	{
		EnsureCapacity();
		for (unsigned int i = size; i > 0; i--)
			data[i] = data[i - 1];
		data[0] = value;
		size++;
	}
	void Vector::Clear()
	{
		size = 0;
	}

	void Vector::Insert(int num, unsigned int index)
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

	void Vector::RemoveByIndex(unsigned int index)
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

	void Vector::RemoveByValue(int value)
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

	void Vector::PopFront()
	{
		RemoveByIndex(0);
	}

	void Vector::PopBack()
	{
		RemoveByIndex(size - 1);
	}

	void Vector::TrimToSize()
	{
		capacity = size;
		int* temp = new int[capacity];
		for (unsigned int i = 0; i < size; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}

	int Vector::IndexOf(unsigned int index)
	{
		for (int i = size; i > 0; i--)
		{
			if (data[i] == index) return i;
		}
		return -1;
	}

	int Vector::LastIndexOf(unsigned int index)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == index) return i;
		}
		return -1;
	}

	void Vector::Reverse()
	{
		reverse(data, size + data);
	}

	void Vector::SortAsc()
	{
		int temp = 0;
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

	void Vector::Shuffle()
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
			swap(data[i], data[rand() % size]);
	}

	void Vector::RandomFill()
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			data[i] = rand();
		}
	}

	void Vector::Equals(const Vector& a)
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

	int Vector::GetElementAt(unsigned int index)
	{

		if (index > size)
		{
			return -1;
		}
		else
		{
			int a = data[index];
			return a;
		}
	}

	void Vector::SortDesc()
	{
		SortAsc();
		Reverse();
	}

#pragma region GETTERS :
	int Vector::GetSize() const
	{
		return size;
	}
	int Vector::GetCapacity() const
	{
		return capacity;
	}
#pragma endregion

	bool Vector::IsEmpty() const
	{
		return size == 0;
	}
	void Vector::Print() const
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

	Vector& Vector::operator=(Vector& v)
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

	int& Vector::operator [](int index)
	{
		if (index < 0 || index >= size)
			return data[0];
		return data[index];
	}

	istream& operator>>(istream& cin, Vector& v)
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

		v.data = new int[v.capacity];
		for (int i = 0; i < v.size; i++)
		{
			cout << "Enter vector element: ";
			cin >> v.data[i];
			cout << "\n";
		}
		return cin;
	}

	ostream& operator << (ostream& os, const Vector& original)
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

	Vector::Vector(const Vector& v)
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