#include<iostream>
using namespace std;

class Bank{
    Bank *_next;
public:
    virtual void Handler(int)=0;
    void setSuccessor(Bank *next){
        _next = next;
    }
    void passNext(int amount){
        if(_next != NULL)
            _next->Handler(amount);
        else
            cout << "The requested amount can't be handled" << endl;
    }
};

class Director: public Bank{
public:
    Director(){
        this->setSuccessor(NULL);
    }
    void Handler(int amount){
        if( 200000 < amount and amount <= 1000000) {
            cout << "Director handles the job" << endl;
        }else{
            this->passNext(amount);
        }
    }  
};

class Manager: public Bank{
public:
    Manager(Director *director){
        this->setSuccessor(director);
    }
    void Handler(int amount){
        if( 50000 < amount and amount <= 200000) {
            cout << "Manager handles the job" << endl;
        }else{
            this->passNext(amount);
        }
    }  
};

class Cashier: public Bank{
public:
    Cashier(Manager *manager){
        this->setSuccessor(manager);
    }
    void Handler(int amount){
        if(amount <= 50000) {
            cout << "Cashier handles the job" << endl;
        }else{ 
            this->passNext(amount);
        }
    }  
};

int main(){
    Director *director = new Director();
    Manager *manager = new Manager(director);
    Cashier *cashier = new Cashier(manager);
    cashier->Handler(100);
    cashier->Handler(100000);
    cashier->Handler(1000000);
    cashier->Handler(10000000);
    return 0;
}
