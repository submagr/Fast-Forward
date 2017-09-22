#include<iostream>
using namespace std;

class CA{
    int arr[5];
public:
    CA(){
        arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 0;
        cout << "CA()" << endl;
    }

    CA(int par1){
        arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = par1;
        cout << "CA(int)" << endl;
    }

    CA(int par1, int par2){
        arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = par1+par2;
        cout << "CA(int, int)" << endl;
    }

    // CA(std::initializer_list<int> list){
    //     cout << "Initialization lsst constructor" << endl;
    //     std::initializer_list<int>::iterator it1 = list.begin();
    //     auto it2 = list.end();
    //     int i=0;
    //     while(it1 != it2){
    //         arr[i++] = *it1;
    //         it1++;
    //     }
    // }

    void Display(){
        for( int x:arr){
            cout << x << endl;
        }
        cout << "------" << endl;
    }
};

class CAGE{
    CA ca;
public:
    CAGE(){
    }
    CAGE(int par): ca(par){
    }
    CAGE(int par1, int par2): ca(par1, par2){
    }
};

class CAGE2{
    CA ca;
public:
    template<typename ...T> // packing
    CAGE2(T ...args): ca(args...){
    }
};


class Stack{
    int top = -1;
    int arr[5];
};

int main100(){
    CAGE2 obj11;

    CAGE2 obj21(10);
    CAGE2 obj22(10, 20);

    // CAGE obj31(10, 20);
    // CA obj32 = (10, 20);
    // CAGE obj33{10, 20};
    // CA obj34 = {10, 20};

    // CA obj41{11, 22, 33, 44, 55};
    return 0;
}

template<typename T>
void PrintMe(T t){ // Stopping function
    cout << t << endl;
    cout << "Stopping function" << endl;
}

template<typename T>
int Sum(T t){
    return t;
}

template<typename First, typename ...Rest>
int Sum(First f, Rest ...r){
    return f+Sum(r...);
}

template<typename First, typename ...Rest> // Variadic templates
void PrintMe(First x, Rest ...rest){
    cout << x << " ";
    PrintMe(rest...);
}

int main99(){
    PrintMe(10);
    PrintMe(10.1);
    PrintMe(10, 20, 3, "sachin");

    cout << Sum(1) << endl;
    cout << Sum(1, 2 ,3) << endl;
    return 0;
}

class A{
    int i1; 
    int i2;
public:
    A(){
        cout << "CTOR A called" << endl;
        i1 = 1;
    }
    A(int i): i1(i){
        cout << "CTOR A<int> called" << endl;
    }
    A(int i, int j): i1(i), i2(j){
        cout << "CTOR A<int, int> called" << endl;
    }
};

class B{
    A a;
public:
    B(){
        cout << "CTOR B called" << endl;
    }
    B(int i1){
        cout << "CTOR B<int> called" << endl;
    }
    B(int i, int j): a(i, j){
        cout << "CTOR B<int, int> called" << endl;
    }
};

void fun1(){
    static int i=1;
    i++;
    cout << i << endl;
}


int main98(){
    // B b1;
    // B b2(2);
    // B b3(2, 3);
    // B b4{1};
    fun1();
    fun1();
    return 0;
}

// class C{
// public:
//     C(){
//         cout << "C Ctor called" << endl;
//     }
//     static void *  operator new(size_t size){
//         return NULL;
//     }
//     static void operator delete(void *pv){
//     }
//     static void *  operator new[](size_t size){
//         return NULL;
//     }
// };

class D{
private:
    ~D(){
    }
public:
    D(){
    }
    // static void override delete(D *this){
    //     free(this);
    // }
};

int main97(){
    D *d = new D();
    return 0;
}

class E{
    E(){
        cout << "E Ctor called" << endl;
    }
    ~E(){
        cout << "E Dtor called" << endl;
    }
public:
    void fun(){
        cout << "E fun called" << endl;
    }
    friend class wrapperE;
};

class wrapperE{
    static void * operator new(size_t size){
        return NULL;
    }
    static void * operator new[](size_t size){
        return NULL;
    }
    static void operator delete(void *ptr){
    }
    static void operator delete[](void *ptr){
    }
    E *ptr;
public:
    wrapperE(): ptr(new E()){
    }
    ~wrapperE(){
        delete ptr;
    }
    E * operator->(){
        return ptr;
    }
    wrapperE(wrapperE &par): ptr(par.ptr){
        par.ptr = NULL;
    }
};

int main96(){
    wrapperE wrap1;
    wrap1->fun();
    wrapperE wrap2(wrap1); // Wrap1 will no longer be functional
    return 0;
}

class F{
    int i;
    F():i(10){
        cout << "F Ctor called" << endl;
    }
    ~F(){
        cout << "F Dtor called" << endl;
    }
public:
    void fun(){
        cout << "F fun called "<< i  << endl;
    }
    friend class wrapperF;
};

class wrapperF{
    static void * operator new(size_t size){
        return NULL;
    }
    static void * operator new[](size_t size){
        return NULL;
    }
    static void operator delete(void *ptr){
    }
    static void operator delete[](void *ptr){
    }
    F *ptr;
    int *count;
public:
    wrapperF(): ptr(new F()), count(new int()){
        *count=1;
    }
    ~wrapperF(){
        *count = *count-1;
        if(count == 0)
            delete ptr;
    }
    F * operator->(){
        return ptr;
    }
    wrapperF(wrapperF &par): ptr(par.ptr), count(par.count){
        (*count)++;
    }
    wrapperF& operator=(wrapperF &par) {
        ptr = par.ptr;
        (*(par.count))++;
        count = par.count;
        return *this;
    }

    void printCount(){
        cout << "Count = " << *count << endl;
    }
};

int main94(){ // Reference collector
    wrapperF wrapF1;
    wrapF1->fun();
    wrapperF wrapF2(wrapF1);
    wrapF1->fun();
    wrapF1.printCount();
    wrapF2.printCount();
    return 0;
}
// class F{
// public:
//     static void * operator new(size_t size){
//         return NULL;
//     }
//     static void * operator new[](size_t size){
//         return NULL;
//     }
//     static void operator delete(void *ptr){
//     }
//     static void operator delete[](void *ptr){
//     }
//     void fun(){
//         cout << "F fun called" << endl;
//     }
// };
// 
// int main95(){ // Create a class that can't be allocated using new <TODO: What's wrong with this method>
//     // F f;
//     cout << "Hello" << endl;
//     F *f1 = new F();
//     // f1->fun();
//     cout << sizeof(f1) << endl; 
//     return 0;
// }
// 
// class G{
//     ~G(){
//     }
// public:
//     static void operator delete(void *ptr){
//     }
//     static void operator delete[](void *ptr){
//     }
//     static void remove(void *ptr){
//         free(ptr);
//     }
// };
// 
// int main94(){ // Create a class that can be used only through new
//     G *g = new G();
//     G::remove(g);
// }
//

class myArray{
    // Assume only one size array  
    int i1;
public:
    myArray(int i): i1(i){
    }
    int getValue(){
        cout << "read" << endl;
        return i1;
    }
    void setValue(int i){
        i1 = i;
        cout << "write" << endl;
    }
    myArray& operator=(myArray &mar){
        cout << "read/write" << endl;
        return mar;
    }
};

class G{
    int arr[4];
public:
    G(){
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 3;
    }


    class Helper{
        G *ptr;
        int index;
    public: 
        Helper(G *ptr, int index): ptr(ptr), index(index){
        }
        operator int(){
            cout << "Reading" << endl;
            return this->ptr->arr[this->index];
        }
        Helper& operator=(int val){
            cout << "Writing" << endl;
            ptr->arr[index] = val;
            return *this;
        }
        Helper& operator=(Helper par){
            cout << "Reading writing" << endl;
            ptr->arr[index] = par.ptr->arr[par.index];
            return *this;
        }
    };

    Helper operator[](int index){
        // cout << "Operator [] called" << endl;
        return Helper(this, index);
    };

    // operator int(){
    //     cout << "Int type cast called" << endl;
    //     return 2; 
    // }
    // ostream& overload <<(ostream& os, int index){
    //     os << arr[index] << " " << endl;
    // }
};

int main93(){
    G obj;
    int x = obj[0]; // Read
    obj[1] = 10; // Write
    obj[1] = obj[2];
    // obj.Display(cout, 2);
    return 0;
}

// class G{
//     int arr[4];
// public:
//     G(){
//         arr[0] = 0;
//         arr[1] = 1;
//         arr[2] = 2;
//         arr[3] = 3;
//     }
// 
// 
//     class Helper{
//         G *ptr;
//         int index;
//     public: 
//         Helper(G *ptr, int index): ptr(ptr), index(index){
//         }
//         operator int(){
//             cout << "Reading" << endl;
//             return this->ptr->arr[this->index];
//         }
//         Helper& operator=(int val){
//             cout << "Writing" << endl;
//             ptr->arr[index] = val;
//             return *this;
//         }
//         Helper& operator=(Helper par){
//             cout << "Reading writing" << endl;
//             ptr->arr[index] = par.ptr->arr[par.index];
//             return *this;
//         }
//     };
// 
//     Helper operator[](int index){
//         // cout << "Operator [] called" << endl;
//         return Helper(this, index);
//     };
// 
//     // operator int(){
//     //     cout << "Int type cast called" << endl;
//     //     return 2; 
//     // }
//     // ostream& overload <<(ostream& os, int index){
//     //     os << arr[index] << " " << endl;
//     // }
// };

// int main93(){
//     G obj;
//     int x = obj[0]; // Read
//     obj[1] = 10; // Write
//     obj[1] = obj[2];
//     // obj.Display(cout, 2);
//     return 0;
// }

class G{
    int arr[1][2];
public:
    G(){
        arr[0][0] = 0;
        arr[0][1] = 1;
        arr[1][0] = 2;
        arr[1][1] = 3;
    }


    class Helper{
        G *ptr;
    public: 
        Helper(G *ptr, int i): ptr(ptr), i(i){
        }
        class Helper2{
            Helper *ptr;
            int i;
            int j;
        public:
            Helper2(Helper *ptr, int j): ptr(ptr), j(j){
            }

            operator int(){
                cout << "Reading" << endl;
                int i = this->ptr->i;
                return arr[i][j];
            }

            Helper2& operator=(int val){
                cout << "Writing" << endl;
                ptr->arr[i][j] = val;
                return *this;
            }
            Helper& operator=(Helper par){
                cout << "Reading writing" << endl;
                ptr->arr[i] = par.ptr->arr[par.i];
                return *this;
            }
        };


        Helper2 operator[](int j){
            // cout << "Operator [] called" << endl;
            return Helper2(this, j);
        };
    };

    Helper operator[](int i){
        // cout << "Operator [] called" << endl;
        return Helper(this, i);
    };

    // operator int(){
    //     cout << "Int type cast called" << endl;
    //     return 2; 
    // }
    // ostream& overload <<(ostream& os, int index){
    //     os << arr[index] << " " << endl;
    // }
};

int main(){
    G obj;
    int x = obj[0]; // Read
    obj[1] = 10; // Write
    obj[1] = obj[2];
    // obj.Display(cout, 2);
    return 0;
}
