#include<iostream>
#include<future>
#include<functional>
#include<string>
#include<map>
using namespace std;
using namespace std::placeholders;

// 1: BIND
class ABC{
public:
    void f1(int x){
        cout << "ABC:: f1 called" << endl;
    }
    void f2(int x){
        cout << "ABC:: f2 called" << endl;
    }
};

// using FPTR = void(ABC::*)(int);
typedef void(ABC::*FPTR)(int);
void VendorFun(ABC& obj, FPTR fp){ // OLD TECHNIQUE
    cout << "UP" << endl;
    (obj.*fp)(10);
    cout << "DOWN" << endl;
}

void VendorFunNew(ABC& obj, std::function<void(ABC&, int)> pt){ 
    cout << "UP" << endl;
    pt(obj, 10);
    cout << "DOWN" << endl;
}

void VendorFunNewEx(std::function<void(int)> pt){ 
    cout << "UP" << endl;
    pt(10);
    cout << "DOWN" << endl;
}

int main1(){ // Consumer intend to call f1 or f2 between up and down
    ABC obj;
    VendorFun(obj, &ABC::f1);
    std::function<void(ABC&, int)> pt = std::mem_fn(&ABC::f2);
    VendorFunNew(obj, pt);
    std::function<void(int)> pt2 = std::bind(&ABC::f2, obj, _1);
    VendorFunNewEx(pt2);
    return 0;
}

// 2: REF
void func(int& r){
    r++;
}
template<typename FUN, class PAR>
void Proceed(FUN fp, PAR par){
    fp(par);
}
int main2(){
    int i = 10;
    Proceed(func, std::ref(i));
    cout << "i=" << i << endl;
    return 0;
}

// 3: TUPLE
tuple<int, float, double> fun(){
    return tuple<int, float, double>(100, 23.5f, 45.6);
}

tuple<int, float, double> fun1(){
    return tuple<int, float, double>(10, 24.5f, 45.6);
}

int main3(){
    auto tup = fun();
    int x = get<0>(tup);
    double d = get<2>(tup);
    float f = get<1>(tup);
    cout << x << d << f<< endl;
    tie(x,f,d) = fun1();
    cout << x << d << f<< endl;
    tie(x,ignore,d) = fun1();
    cout << x << d << f<< endl;

    tuple<int, string, double> tup1;
    tup1 = make_tuple(100, "Hundred", 100.0);
    string str;
    tie(x, str, d) = tup1;
    cout << "x = " << x << endl;
    cout << "str = " << str << endl;
    cout << "d = " << x << endl;

    int a = 10; int b=20;
    tie(b,a) = make_tuple(a,b);
    cout << a << " " << b << endl;
    return 0;
}

// 4: Default constructor

class CA4{
public:
    CA4()=default;
    CA4(int x){

    }
};

class CB4{
public:
    CB4()=delete; // Don't synthesize constructor
    CB4(int x){

    }
    CB4(const CB4&) = delete; // Copy Constructor: Don't synthesize
    CB4& operator=(CB4&) = delete; // Assignment operator: Don't synthesize
    void fun(int x, int y){
        cout << x+y << endl;
    }
    template<typename T1, typename T2>
    void fun(T1 x, T2 y) = delete;
};

int main4(){
    CB4 obj(78);
    CB4 obj1(88);
    // CB4 obj2(obj); // Will give error
    // obj1 = obj2; // Will give error

    obj1.fun(1, 2);
    // obj1.fun(1, 2.0); // Will give error
    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------------
// 5: funciton hiding, object slicing happens, vertical access control(old feature)
// Reexposing all the base class information
//  - Vertical access control: using Math::AddFun; 
//      * It can be used to change the access of specific variables
//      * Making a derived class friend of base class: even private memebers will be inherited 
//  <TODO> What will happen on pointer conversion from derived to base, if derived has an int x, base don't. 
//
class Math{
public:
    void AddFun(){
        cout << "Math::Addfun() called" << endl;
    }
    void AddFun(int x){
        cout << "Math::Addfun<int> called" << endl;
    }
};

class MathEx: public Math{
public:
    int data;
    MathEx(int data): data(data){
    }
    void AddFun(int x, int y){
        cout << "MathEx::Addfun<int, int> called" << endl;
    }
};


int main5(){
    MathEx obj1(2);
    obj1.AddFun(10, 5);
    Math *obj2 = &obj1;
    obj2->AddFun(5);
    MathEx* obj3 = (MathEx *)obj2;
    cout << obj3->data << endl;
}

// ------------------------------------------------------------------------------------------------------------------------------------------
// 6: Variadic templates for class
// - Club the set of types, Using variadic templates for class

template<typename ...Rest>
class myClass;

template<typename First, typename ...Rest>
class myClass<First, Rest...>: public myClass<Rest...>{ // This class is made with first and unpacked rest
public:
    // using myClass<Rest...>::AddFun();
    void AddFun(First x){
        cout << "Addfun called for type = " << typeid(x).name() << endl;
    }
};

template<>
class myClass<>{
public:
    void AddFun(){
    }
};

int main6(){
    myClass<int> obj1;
    myClass<double> obj2;
    myClass<float> obj3;
    obj1.AddFun(10);
    obj2.AddFun(10.1);
    obj3.AddFun(10.2f);

    myClass<int, float, double> obj;
    return 0;
}


// 7: DESIGN 
// - ocp, srp, lod, lsp, dip, isp, ioc, info expert
// - lod: 
//      * Each unit should have only limited knowledge about other units: only units "closely" related to the current unit.
//      * Each unit should only talk to its friends; don't talk to strangers.
//      * Only talk to your immediate friends.
// - dip:
//      * High-level modules should not depend on low-level modules. Both should depend on abstractions.
//      * Abstractions should not depend on details. Details should depend on abstractions.

class CA7{
    int x, y, z;
public:
    CA7():x(10), y(x), z(y){ // **NOTE**: Order of initialization always maps to order of declaration
    }
    void Display(){
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
    void setData(int x, int y, int z){
    }
};
int main7(){
    CA7 obj;
    obj.Display();
}

// 8. Momento Design 
//

class IStore{
protected:
    IState *state;
public:
    virtual void hyderate() = 0;
    virtual void deHyderate() = 0;
};

class IState{
public:
    virtual void setState() = 0;
    virtual void getState() = 0;
};

Class CareTaker{
    static map<IStore*, IState*> repo;
public:
    static void setToRepo(IStore *store, IState *state){
        repo[store] = repo[state];
    }
    static IState* getFromRepo(IStore *store){
        return repo[store];
    }
};

class CA8State: public IState{
    int x;
    int y;
    int z;
public:
    CA8State(int x, int y, int z): x(x), y(y), z(z){
    }
    void setState(IStore *ptr){
        CareTaker::setToRepo(ptr, this);
    }
    CA8State * getState(IStore *ptr){
        IState* tempState = CareTaker::getFromRepo(ptr);
        return dynamic_cast<CA8State *>(tempState);
    }
};

class CA8: public IStore{
    int x, y, z;
public:
    CA8():x(10), y(x), z(y){ // **NOTE**: Order of initialization always maps to order of declaration
    }
    void Display(){
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
    void setData(int x, int y, int z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    void hyderate(){
        state = new CA8State(x, y, z);
        state->setState(this);
    }
    void deHyderate(){
        IState* oldState = state->getState(this);
        this->setData(newState->x, newState->y, newState->z);
    }
};

int main(){
    CA8 obj1(1,2,3);
    obj1.Display();
    return 0;
}
