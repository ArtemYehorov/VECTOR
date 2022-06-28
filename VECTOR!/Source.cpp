#include"Vector.h"

int main()
{
	srand(time(0));
	Vector v;
	Vector a;

	v.PushBack(3);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(6);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);
	v.PushBack(8);
	v.PushBack(0);
	
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
	a.PushBack(6);
	a.PushBack(7);
	a.PushBack(7);
	a.PushBack(7);

	a = v;
	a.Print();
	cin >> v;
	cout << v;
}

