#include<iostream>
using namespace std;
namespace nm11
{
	class CA
	{
		int arr[5];
	public:
		CA()
		{
			arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 10;
			cout << "default" << endl;
		}
		explicit CA(int par)
		{
			arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = par;
			cout << "One Param" << endl;
		}
		explicit CA(int par1, int par2)
		{
			arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = par1 + par2;
			cout << "multi Param" << endl;
		}
		CA(std::initializer_list<int> list)
		{
			cout << "Init ctor" << endl;
			std::initializer_list<int>::iterator it1 = list.begin();
			auto it2 = list.end();
			int i = 0;
			while (it1 != it2)
			{
				arr[i++] = *it1;
				it1++;
			}
		}
		void Display()
		{
			for (int x : arr)
			{
				cout << x << endl;
			}
			cout << "_________________" << endl;
		}
	};

	void main1()
	{
		CA obj1;
		CA obj2(10);
		CA obj3{ 20 };
		//CA obj4 = 30;
		CA obj5 = { 45 };
		CA obj6(1, 2);
		CA obj7 = { 11, 22 };
		CA obj8{ 111, 222 };
		//obj1.Display();
		CA obj9{ 11, 22, 33, 44, 55 };
		//obj9.Display();
	}




	class CAT
	{
	public:
		CAT()
		{
			cout << "CAT Default " << endl;
		}
		CAT(int x)
		{
			cout << "CAT(int) " << endl;
		}
		CAT(int x, int y)
		{
			cout << "CAT(int,int) " << endl;
		}
		CAT(int x, int y, int z)
		{
			cout << "CAT(int,int,int) " << endl;
		}
		CAT(string str1, string str2)
		{
			cout << "CAT(string,string) " << endl;
		}
	};

	class Cage
	{
		CAT cat;
	public:
		template<typename ...T>//packing
		Cage(T ...args) :cat(std::move(args)...)
		{
		}


	};

	void main()
	{
		Cage cage;
		Cage cage1(10);
		Cage cage2(10, 20);
		Cage cage3(10, 20, 30);
		Cage cage4("sachin", "rahul");
	}
}