#include"Vector.h"
#include"Stack.h"

int main()
{
	Stack<int> a;
	a.Push(10);
	a.Push(20);
	a.Push(30);

	cout<<a.Peek();
	a.Pop(10);
	cout << a.Peek();
	cout << a.Peek();
	a.Pop(10);
	cout << a.Peek();

	/*srand(time(0));
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
	cout << v;*/
}

