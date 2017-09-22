#include<iostream>
using namespace std;
namespace nm13
{
	class CA
	{
		static void* operator new (size_t size)
		{
			return NULL;
		}
			static void operator delete (void *pv)
		{
		}
		static void* operator new [](size_t size)
		{
			return NULL;
		}
			static void operator delete[](void *pv)
		{
		}
	public:
		CA()
		{
			cout << "CA Ctor " << endl;
		}
		void fun()
		{
			cout << "CA fun" << endl;
		}
		~CA()
		{
			cout << "CA Dtor" << endl;
		}
	};

	//CA obj1;
	//static CA obj2;
	void main()
	{
		CA obj3;
		//static CA obj4;
		//CA *obj5 = new CA();


		//delete obj5;

		//CA *obj6 = new CA[5];

		//delete[] obj6;
	}
}