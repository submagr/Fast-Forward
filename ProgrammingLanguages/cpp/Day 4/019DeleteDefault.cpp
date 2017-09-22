#include<iostream>
using namespace std;
namespace nm19
{
	class CA
	{
	public:
		CA() = default;
		CA(int x)
		{
		}
	};
	class CB
	{
	public:
		CB() = delete;
		CB(int x)
		{
		}
		CB(const CB&) = delete;
		CB&operator=(CB&) = delete;
	};
	void main1()
	{
		CB obj(78);
		CB obj1(999);
		//CB obj2(obj1);
		//obj = obj1;
	}

	class CC
	{
	public:
		void AddFun(double x, double y)
		{
		}
		void AddFun(int, int) = delete;

		void SubFun(int x, int y)
		{

		}
		template<typename T>
		void SubFun(T x, T y) = delete;
	};
	void main()
	{
		CC obj;
		obj.AddFun(10.2, 34.5);
		obj.AddFun(12.3f, 45.4f);
		//obj.AddFun(12, 45);
	}
}