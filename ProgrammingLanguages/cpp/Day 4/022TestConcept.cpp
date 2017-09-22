#include<iostream>
#include<map>
using namespace std;

class Employee
{
public:
	virtual void DoJob() = 0;
};

using FPTR = Employee *(*)();
class Helper
{
	static map<int, FPTR> MyMap;
public:
	static Employee* getEmp(int par)
	{
		return MyMap[par]();
	}
	static void Register(int par, FPTR fp)
	{
		MyMap[par] = fp;
	}
};

map<int, FPTR>Helper::MyMap;

class Manager :public Employee
{
public:
	void DoJob()
	{
		cout << "Manager job done" << endl;
	}
};
class  Tester :public Employee
{
public:
	void DoJob()
	{
		cout << "Tester job done" << endl;
	}
};
class Developer :public Employee
{
public:
	void DoJob()
	{
		cout << "Developer job done" << endl;
	}
};

class Dummy
{
public:
	Dummy()
	{	
		Helper::Register(10, []()->Employee*{return new Manager(); });
		Helper::Register(20, []()->Employee*{return new Tester(); });
		Helper::Register(30, []()->Employee*{return new Developer(); });
	}
}dummy;

void main()
{
	Employee *emp = Helper::getEmp(30);
	emp->DoJob();
}