#include<iostream>
#include<future>
#include<tuple>
#include<string>
using namespace std;
using namespace std::placeholders;

namespace nm18
{
	float div1(float a, float b)
	{
		return a / b;
	}

	void main1()
	{
		cout << "8/1=" << div1(8, 1) << endl;
		cout << "8/2=" << div1(8, 2) << endl;
		cout << "8/4=" << div1(8, 4) << endl;
		cout << "_______________________" << endl;
		std::function<float(float, float)> divInv = std::bind(div1, _2, _1);
		cout << "8/1=" << divInv(8, 1) << endl;
		cout << "8/2=" << divInv(8, 2) << endl;
		cout << "8/4=" << divInv(8, 4) << endl;
		cout << "_______________________" << endl;
		std::function<float(float)> divBy2 = std::bind(div1, _1, 2);
		cout << "6/2=" << divBy2(6) << endl;
		cout << "8/2=" << divBy2(8) << endl;
		cout << "10/2=" << divBy2(10) << endl;
	}

	class ABC
	{
	public:
		void f1(int x)
		{
			cout << "India   ... x=" << x << endl;
		}
		void f2(int x)
		{
			cout << "Bharath ... x=" << x << endl;
		}
	};

	//using FPTR = void(ABC::*)(int);
	typedef void(ABC::*FPTR)(int);
	void VendorFun(ABC&obj, FPTR fp)
	{
		cout << "Apple" << endl;
		(obj.*fp)(10);
		cout << "Orange" << endl;
	}

	void VendorFunNew(ABC& obj, std::function<void(ABC&, int)> pt)
	{
		cout << "Apple" << endl;
		pt(obj, 10);
		cout << "Orange" << endl;
	}

	void VendorFunNewEx(std::function<void(int)> pt)
	{
		cout << "Apple1" << endl;
		pt(10);
		cout << "Orange1" << endl;
	}

	void main2()
	{
		ABC obj;
		//VendorFun(obj,&ABC::f1);
		//std::function<void(ABC&, int)> pt = std::mem_fn(&ABC::f2);
		//VendorFunNew(obj, pt);
		std::function<void(int)> pt = std::bind(&ABC::f1, obj, _1);
		VendorFunNewEx(pt);
	}



	void func(int & r)
	{
		r++;
	}
	template<typename FUN, class PAR>
	void Proceed(FUN fp, PAR pr)
	{
		fp(pr);
	}
	void main3()
	{
		int i = 10;
		Proceed(func, std::ref(i));
		cout << "i=" << i << endl;
	}



	std::tuple<int, float, double> fun()
	{
		//
		return tuple<int, float, double>(100, 23.4f, 45.6);
	}

	std::tuple<int, float, double> fun1()
	{
		//
		return tuple<int, float, double>(99, 22.7f, 4.8);
	}

	void main()
	{
		auto tup = fun();
		int x = std::get<0>(tup);
		float f = std::get<1>(tup);
		double d = std::get<2>(tup);

		cout << "x=" << x << endl;
		cout << "f=" << f << endl;
		cout << "d=" << d << endl;

		std::tie(x, f, d) = fun1();
		cout << "___________________" << endl;
		cout << "x=" << x << endl;
		cout << "f=" << f << endl;
		cout << "d=" << d << endl;

		std::tie(x, std::ignore, d) = fun1();
		cout << "___________________" << endl;
		cout << "x=" << x << endl;
		cout << "d=" << d << endl;

		tuple<int, string, double> tup1;

		tup1 = std::make_tuple(100, "sachin", 3.141);

		std::tie(x, std::ignore, d) = tup1;
		cout << "___________________" << endl;
		cout << "x=" << x << endl;
		cout << "d=" << d << endl;

		int a = 10, b = 20;
		std::tie(b, a) = std::make_tuple(a, b);
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
	}
}
