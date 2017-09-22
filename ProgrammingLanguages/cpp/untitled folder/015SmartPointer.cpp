#include<iostream>
#include<map>
using namespace std;

namespace nm15
{
	class CA
	{
		CA()
		{
			cout << "CA Ctor " << endl;
		}
		~CA()
		{
			cout << "CA Dtor" << endl;
		}

	public:
		void fun()
		{
			cout << "CA fun" << endl;
		}
		friend class Wrapper;
	};

	/*
	class Wrapper //DeepCopy from swathi
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
	CA *ptr;
	public:
	Wrapper() :ptr(new CA())
	{
	}
	Wrapper(const Wrapper & par) :ptr(new CA(*par.ptr))//deep copy
	{
	}
	Wrapper & operator=(Wrapper & par) //deep assignment
	{
	if (this->ptr != par.ptr)
	{
	*ptr = *par.ptr;
	}
	return *this;
	}
	CA* operator->()
	{
	return ptr;
	}
	~Wrapper()
	{
	delete ptr;
	}
	};
	*/

	/*
	class Wrapper //ownership transfer
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
	CA *ptr;
	public:
	Wrapper() :ptr(new CA())
	{
	}
	Wrapper( Wrapper & par) :ptr(par.ptr)//deep copy
	{
	par.ptr = NULL;
	}
	Wrapper & operator=(Wrapper & par) //deep assignment
	{
	if (this->ptr != par.ptr)
	{
	delete ptr;
	ptr = par.ptr;
	par.ptr = NULL;

	}
	return *this;
	}
	bool IsValid()
	{
	return ptr != NULL;
	}
	CA* operator->()
	{
	return ptr;
	}
	~Wrapper()
	{
	delete ptr;
	}
	};
	*/

	/*
	class Wrapper
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
	CA *ptr;
	int *count;
	public:
	Wrapper() :ptr(new CA()), count(new int(1))
	{
	}
	Wrapper(Wrapper & par) :ptr(par.ptr), count(par.count)
	{
	++(*count);
	}
	Wrapper & operator=(Wrapper & par)
	{
	if (this->ptr != par.ptr)
	{
	this->Wrapper::~Wrapper();
	this->Wrapper::Wrapper(par);

	}
	return *this;
	}

	CA* operator->()
	{
	return ptr;
	}
	~Wrapper()
	{
	if ((--(*count)) == 0)
	{
	delete ptr;
	delete count;
	}
	}
	};
	*/

	class Wrapper
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
		CA *ptr;
		static map<CA*, int> myMap;
	public:
		Wrapper() :ptr(new CA())
		{
			myMap[ptr] = 1;
		}
		Wrapper(Wrapper & par) :ptr(par.ptr)
		{
			myMap[ptr]++;
		}
		Wrapper & operator=(Wrapper & par)
		{
			if (this->ptr != par.ptr)
			{
				this->Wrapper::~Wrapper();
				this->Wrapper::Wrapper(par);
			}
			return *this;
		}

		CA* operator->()
		{
			return ptr;
		}
		~Wrapper()
		{
			if ((--myMap[ptr]) == 0)
			{
				delete ptr;
				myMap.erase(ptr);
			}
		}
	};

	map<CA*, int> Wrapper::myMap;

	void main()
	{
		Wrapper wrap1;
		wrap1->fun();
		Wrapper wrap2;
		Wrapper Wrap3(wrap2);
		Wrapper wrap4;
		wrap4 = wrap1;

	}
}