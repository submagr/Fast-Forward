#include<iostream>
using namespace std;

namespace nm20
{
	class Math
	{
		int x;
	protected:
		int y;

	public:
		int z;
		void AddFun(int x)
		{
			cout << "Math AddFun(int)" << endl;
		}
		void AddFun(int x, int y)
		{
			cout << "Math AddFun(int,int)" << endl;
		}
		void AddFun(int x, int y, int z)
		{
			cout << "Math AddFun(int,int,int)" << endl;
		}
		void fun()
		{
			cout << "Math (BASE) Fun" << endl;
		}
	};
	class MathEx :public Math
	{
		Math::y;
	protected:
		using Math::z;
	public:
		using Math::AddFun;//vbertical access control
		void AddFun(int x, int y, int z, int a)
		{
			cout << "MathEx AddFun(int,int,int,int)" << endl;
		}
		void fun()
		{
			cout << "Mathex (Derived) Fun" << endl;
		}
	};
	void main1()
	{
		MathEx mathex;
		mathex.AddFun(10);
		mathex.AddFun(1, 2);
		mathex.AddFun(11, 22, 33);
		mathex.AddFun(1, 2, 3, 4);

		/*mathex.fun();
		Math math;
		//math.fun();
		//LSP
		Math *ptr = &mathex;
		ptr->fun();*/
	}

	template<typename ...Rest>
	class MyClass;

	template<typename First, typename ...Rest>
	class MyClass<First, Rest...> :public MyClass < Rest... >
	{
	public:
		using MyClass<Rest...>::AddFun;
		void AddFun(First x)
		{
			cout << "AddFun called for type=" << typeid(First).name() << endl;
		}
	};

	template<>
	class MyClass < >
	{
	public:
		void AddFun()
		{

		}
	};

	void main()
	{
		MyClass<int> obj1;
		MyClass<double> obj2;
		MyClass<float> obj3;
		obj1.AddFun(10);
		obj2.AddFun(30.98);
		obj3.AddFun(40.5f);
		MyClass<int, float, double> obj;
		obj.AddFun(10);
		obj.AddFun(10.f);
		obj.AddFun(34.5);
	}
}
