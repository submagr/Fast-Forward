#include<iostream>
using namespace std;

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
public:
    Wrapper() :ptr(new CA())
    {
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

int main()
{
    Wrapper wrap1;
    wrap1->fun();
    Wrapper wrap2;
    Wrapper Wrap3(wrap2);
    // Wrapper wrap4;
    // wrap4 = wrap1;
}
