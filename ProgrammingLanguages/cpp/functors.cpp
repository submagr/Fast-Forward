#include<iostream>
using namespace std;

class CA{
    int *i;
    double *d;
public:
    static int count;
    CA():i(new int(10)), d(new double(10.10)) {
        count++;
        cout << "CA ctor" << endl;
    }

    // COPY OVERRIDE
    CA(const CA &par) :i(new int(*par.i)), d(new double(*par.d)){
        cout << "Deep copy" << endl;
    }
    // assignment operator OVERRIDE
    /* <TODO>: this is the way to overload assignment */
    CA& operator=(CA &par){
        *i = *par.i;
        *d = *par.d;
        return *this;
    }

    // Move override
    CA(CA&& par): i(par.i), d(par.d){
        cout << "Move(shallow) copy" << endl;
        par.i = NULL;
        par.d = NULL;
    }
        
    ~CA(){
        cout << "CA dtor" << count << endl;
        delete i;
        delete d;
    }
};

CA CreateCA(){
    // pre construction
    cout << "Pre construction" << endl;
    CA temp;
    // post construction
    cout << "Post construction" << endl;
    return temp; 
}
int CA::count = 0;

int main(){
    CA obj1 = CreateCA();
    return 0;
}
