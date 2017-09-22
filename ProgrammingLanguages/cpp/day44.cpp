#include<iostream>
#include<future>
using namespace std;
using namespace std::placeholders;

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
    using Math::y;
protected:
    using Math::z;
public:
    // using Math::AddFun;//vbertical access control
    void AddFun(int x, int y, int z)
    {
        cout << "MathEx AddFun(int,int,int)" << endl;
    }
    // void AddFun(int x, int y, int z, int a)
    // {
    //     cout << "MathEx AddFun(int,int,int,int)" << endl;
    // }
    void fun()
    {
        cout << "Mathex (Derived) Fun" << endl;
    }
};

int main()
{
    MathEx mathex;
    // mathex.AddFun(10);
    mathex.AddFun(1, 2);
    // mathex.AddFun(11, 22, 33);
    // mathex.AddFun(1, 2, 3, 4);

    /*mathex.fun();
    Math math;
    //math.fun();
    //LSP
    Math *ptr = &mathex;
    ptr->fun();*/
}
