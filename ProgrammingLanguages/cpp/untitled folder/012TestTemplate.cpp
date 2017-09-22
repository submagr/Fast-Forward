#include<iostream>
#include<string>
using namespace std;
namespace nm12
{
	class StackBase
	{
	protected:
		int top = -1;//member intialization new in c++11
	public:
		bool IsFull()
		{
			return top == 4;
		}
		bool IsEmpty()
		{
			return top == -1;
		}
	};

	template<typename T>
	class Stack :public StackBase
	{
		T arr[5];
	public:
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}

	};

	void main1()
	{
		Stack<int> st1;
		Stack<double> st2;
		Stack<string> st3;
	}


	template<typename T> //stopper
	void PrintMe(T x)
	{
		cout << x << endl;
	}
	template<typename First, typename ...Rest>//variadic templates
	void PrintMe(First x, Rest ...rest)
	{
		cout << x << "\t"; PrintMe(rest...);
	}
	void main2()
	{
		/*PrintMe(10);
		PrintMe(20.3);
		PrintMe(34.5f);
		PrintMe("sachin");*/
		PrintMe(10, 20.3, 34.5f, "sachin");
	}

	template<typename T> //stopper
	T Sum(T x)
	{
		return x;
	}
	template<typename First, typename ...Rest>//variadic templates
	First Sum(First x, Rest ...rest)
	{
		return x + Sum(rest...);
	}
	void main()
	{
		cout << Sum(1, 2, 3) << endl;
		cout << Sum(1, 2, 3, 4, 5) << endl;
		cout << Sum(1, 2, 3, 4, 5, 6, 7) << endl;
		cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	}
}
