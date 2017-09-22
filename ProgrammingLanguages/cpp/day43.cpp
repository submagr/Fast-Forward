#include<iostream>
#include<map>
using namespace std;

// Factory: A utility class that creates an instance of a class from the family of the derived class.
class Employee{
public:
    virtual void DoJob() = 0;
};

using FPTR = Employee *(*)(); // This is similar to typedef (Employee *)(FPTR*)()
class Helper{
    static map<int, FPTR> myMap;
public:
    static void Register(int par, FPTR fp){
        myMap[par] = fp;
    }
    static Employee * getJobDone(int par){
        return myMap[par]();
    }
};

map<int, FPTR>Helper::myMap;

class Manager: public Employee{
public:
    void DoJob(){
        cout << "Manager do job" << endl;
    }
};

class Tester: public Employee{
public:
    void DoJob(){
        cout << "Tester do job" << endl;
    }
};

class Developer: public Employee{
public:
    void DoJob(){
        cout << "Developer do job" << endl;
    }
};


class Dummy{
public:
    Dummy(){
        Helper::Register(1, []()->Employee *{ return (Employee *)(new Manager);});
        Helper::Register(2, []()->Employee *{ return (Employee *)(new Developer);});
        Helper::Register(3, []()->Employee *{ return (Employee *)(new Tester);});
    }
}dummy;

int main(){
    Employee *emp = Helper::getJobDone(1);
    emp->DoJob();

    Employee *emp1 = Helper::getJobDone(2);
    emp1->DoJob();
    return 0;
}
// Checkout reflection in java, python
