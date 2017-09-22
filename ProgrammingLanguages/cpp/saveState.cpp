#include<iostream>
#include<future>
#include<functional>
#include<string>
#include<map>
using namespace std;
using namespace std::placeholders;

// 8. Momento Design 
//

class IStore;
class CA8State;
class IState{
public:
    virtual void setState(IStore *ptr) = 0;
    virtual IState * getState(IStore *ptr) = 0;
};

class IStore{
protected:
    IState *state;
public:
    virtual void hyderate() = 0;
    virtual void deHyderate() = 0;
};


class CareTaker{
    static map<IStore*, IState*> repo;
public:
    static void setToRepo(IStore *store, IState *state){
        repo[store] = state;
    }
    static IState* getFromRepo(IStore *store){
        return repo[store];
    }
};

map<IStore *, IState *> CareTaker::repo;

class CA8State: public IState{
public:
    int x;
    int y;
    int z;
    CA8State(int x, int y, int z): x(x), y(y), z(z){
    }
    // Prevent CA8State creation from other methods 
    CA8State() = delete;
    CA8State(const CA8State&) = delete;
    CA8State& operator=(CA8State&) = delete;

    void setState(IStore *ptr){
        CareTaker::setToRepo(ptr, this);
    }
    IState * getState(IStore *ptr){
        return CareTaker::getFromRepo(ptr);
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
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void hyderate(){
        state = new CA8State(x, y, z);
        state->setState(this);
    }
    void deHyderate(){
        CA8State* oldState = dynamic_cast<CA8State *>(state->getState(this));
        this->setData(oldState->x, oldState->y, oldState->z);
    }
};

class CB8State: public IState{
public:
    int x;
    string str;
    CB8State(int x, string str): x(x), str(str){
    }
    void setState(IStore *ptr){
        CareTaker::setToRepo(ptr, this);
    }
    IState * getState(IStore *ptr){
        return CareTaker::getFromRepo(ptr);
    }
};

class CB8: public IStore{
    int x;
    double d;
    string str;
public:
    CB8(int x, double d, string str): x(x), d(d), str(str){}
    void Display(){
        cout << "x = " << x << endl;
        cout << "d = " << d << endl;
        cout << "str = " << str << endl;
    }
    void setData(int x, double d, string str){
        this->x = x;
        this->d = d;
        this->str = str;
    }
    void hyderate(){
        state = new CB8State(x, str);
        state->setState(this);
    }
    void deHyderate(){
        CB8State* oldState = dynamic_cast<CB8State *>(state->getState(this));
        this->setData(oldState->x, this->d, oldState->str);
    }
};
int main(){
    CA8 obj1;
    obj1.Display();
    obj1.hyderate();
    cout << "Hydrating above state" << endl;
    obj1.setData(11,22,33);
    obj1.Display();
    cout << "Dehydrating saved state" << endl;
    obj1.deHyderate();
    obj1.Display();


    cout << "For another class" << endl;
    CB8 obj11(1, 1.1, "cool");
    obj11.Display();
    obj11.hyderate();
    cout << "Hydrating above state" << endl;
    obj11.setData(2,2.2,"Cooler");
    obj11.Display();
    cout << "Dehydrating saved state" << endl;
    obj11.deHyderate();
    obj11.Display();
    return 0;
}
