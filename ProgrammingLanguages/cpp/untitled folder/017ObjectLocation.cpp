#include<iostream>
using namespace std;

class CA
{
	bool isOnHeap;
	static bool gHeap;
	static int count;
public:
	CA() :isOnHeap(gHeap)
	{
		count--;
		if (count <= 0)
		{
			gHeap = false;
		}
	}
	static void* operator new(size_t size)
	{
		count = 1;
		gHeap = true;
	
		return malloc(size);;
	}
	static void* operator new[](size_t size)
	{
		gHeap = true;
		count = size / sizeof(CA);
		return malloc(size);
	}
	void Location()
	{
		if (isOnHeap == true)
		{
			cout << "Object is on heap" << endl;
		}
		else
		{
			cout << "Object is (NOT) on heap" << endl;
		}
	}
};
bool CA::gHeap=false;
int CA::count;

void main()
{
	CA obj1;
	CA *ptr1 = new CA();
	CA obj2;
	CA *ptr2 = new CA();
	obj1.Location();
	obj2.Location();
	cout << "___________________" << endl; 
	ptr1->Location();
	ptr2->Location();
	cout << "___________________" << endl;
	CA *ptr = new CA[5];
	for (int i = 0; i < 5; i++)
	{
		(ptr + i)->Location();
	}
	cout << "___________________" << endl;
}