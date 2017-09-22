#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace nm21
{
	class IState;

	class IStore
	{
	protected:
		IState  *state;
	public:
		virtual void Hyderate() = 0;
		virtual void Dehyderate() = 0;
	};

	class IState
	{
	public:
		virtual void SetState(IStore *ptr) = 0;
		virtual void GetState(IStore *ptr) = 0;
	};

	class CareTaker
	{
		static map<IStore*, IState*> repository;
	public:
		static void SetToRepo(IStore *store, IState *state)
		{
			repository[store] = state;
		}
		static IState * GetFromRepo(IStore *store)
		{
			return repository[store];
		}
	};
	map<IStore*, IState*> CareTaker::repository;

	class CAState :public IState
	{
		int x;
		int y;
		int z;
	public:
		CAState(int x, int y, int z) :x(x), y(y), z(z)
		{
		}
		CAState() = delete;
		CAState(const CAState&) = delete;
		CAState& operator=(CAState&) = delete;
		virtual void SetState(IStore *ptr)
		{
			CareTaker::SetToRepo(ptr, this);
		}
		virtual void GetState(IStore *ptr);

	};

	class CA :public IStore
	{
		int x;
		int y;
		int z;
	public:
		CA() :x(10), y(x), z(y)
			//CA() : y(x), x(10), z(y)
			//CA() : y(20), x(y), z(y)
			//CA() : y(20), x(y), z(x)
		{
		}
		void SetData(int x, int y, int z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		void Display()
		{
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "z=" << z << endl;
			cout << "__________________" << endl;
		}
		virtual void Hyderate()
		{
			state = new CAState(x, y, z);
			state->SetState(this);
		}
		virtual void Dehyderate()
		{
			state->GetState(this);
		}
	};

	void CAState::GetState(IStore *ptr)
	{
		CAState* temp = dynamic_cast<CAState*>(CareTaker::GetFromRepo(ptr));
		CA* CaTemp = dynamic_cast<CA*>(ptr);
		CaTemp->SetData(temp->x, temp->y, temp->z);
	}


	class CBState :public IState
	{
		int a;
		double d;
		string str;
	public:
		CBState(int a,
			double d,
			string str) :a(a), d(d), str(str)
		{
		}
		CBState() = delete;
		CBState(const CBState&) = delete;
		CBState& operator=(CBState&) = delete;
		virtual void SetState(IStore *ptr)
		{
			CareTaker::SetToRepo(ptr, this);
		}
		virtual void GetState(IStore *ptr);

	};

	class CB :public IStore
	{
		int a;
		double d;
		string str;
	public:
		CB() : a(20), d(3.141), str("sachin")
		{
		}
		void SetData(int a, double d, string str)
		{
			this->a = a;
			this->d = d;
			this->str = str;
		}
		void Display()
		{
			cout << "a=" << a << endl;
			cout << "d=" << d << endl;
			cout << "str=" << str << endl;
			cout << "__________________" << endl;
		}
		virtual void Hyderate()
		{
			state = new CBState(a, d, str);
			state->SetState(this);
		}
		virtual void Dehyderate()
		{
			state->GetState(this);
		}
	};

	void CBState::GetState(IStore *ptr)
	{
		CBState* temp = dynamic_cast<CBState*>(CareTaker::GetFromRepo(ptr));
		CB* CaTemp = dynamic_cast<CB*>(ptr);
		CaTemp->SetData(temp->a, temp->d, temp->str);
	}

	void main()
	{
		CA obj1;
		CB obj2;
		obj1.SetData(111, 222, 333);
		obj2.SetData(100, 6.45, "Sachin");
		obj1.Display();
		obj2.Display();
		obj1.Hyderate();
		obj2.Hyderate();

		obj1.SetData(100, 200, 300);
		obj2.SetData(999, 56.45, "rahul");
		cout << "__________After Setting the data_________" << endl;
		obj1.Display();
		obj2.Display();
		cout << "__________After Retaining old value_________" << endl;
		obj1.Dehyderate();
		obj2.Dehyderate();
		obj1.Display();
		obj2.Display();
	}
}