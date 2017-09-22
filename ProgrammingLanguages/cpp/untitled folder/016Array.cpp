#include<iostream>
using namespace std;
namespace nm16
{
	class CArray
	{
		int arr[5];
	public:
		CArray()
		{
			arr[0] = 10;
			arr[1] = 20;
			arr[2] = 30;
			arr[3] = 40;
			arr[4] = 50;
		}

		class Helper
		{
			CArray *ptr;
			int index;
		public:
			Helper(CArray *ptr, int index) :ptr(ptr), index(index)
			{
			}
			operator int()
			{
				cout << "reading " << endl;
				return ptr->arr[index];
			}
			Helper& operator=(int val)
			{
				cout << "Writing" << endl;
				ptr->arr[index] = val;
				return *this;
			}
			Helper& operator=(Helper par)
			{
				cout << "Reading/Writing" << endl;
				ptr->arr[index] = par.ptr->arr[par.index];
				return *this;
			}
		};




		Helper operator[](int index)
		{
			return Helper(this, index);
		}

		friend ostream & operator<<(ostream & os, CArray & par)
		{
			for (int x : par.arr)
			{
				os << x << endl;
			}
			return os;
		}

	};

	void main()
	{
		CArray obj;
		int x = obj[0];//reading
		obj[1] = 12;//writing
		obj[2] = obj[3];//read/write
		cout << "____________________" << endl;
		cout << obj << endl; //<< "India is great" << endl;


	}


	class CA
	{
		int x;
	public:
		CA& operator=(int val)
		{
			cout << "Writing" << endl;
			x = val;
			return *this;
		}
		operator int()
		{
			cout << "Reading" << endl;
			return x;
		}
		CA& operator=(CA &par)
		{
			cout << "Reading/Writing" << endl;
			x = par.x;
			return *this;
		}
		void display()
		{
			cout << "x=" << x << endl;
		}
	};

	void main2()
	{
		CA obj, obj1;
		obj = 99;
		int h = obj;
		obj = obj1;
		obj.display();
	}
}