#include<iostream>
#include<future>
#include<functional>
using namespace std;
using namespace std::placeholders;

float div1(float a, float b){
    return a/b;
}

class ABC{
public:
    void f1(int x){
        cout << "ABC:: f1 called" << endl;
    }
    void f2(int x){
        cout << "ABC:: f2 called" << endl;
    }
};
void VendorFun(ABC& obj){
    cout << "UP" << endl;
    cout << "DOWN" << endl;

}
int main(){
    cout << "8/1 = " << div1(8,1) << endl;
    cout << "8/2 = " << div1(8,2) << endl;
    std::function<float(float, float)> divInv = std::bind(div1, _2, _1);
    cout << "8/1 = " << divInv(8,1) << endl;
    cout << "8/2 = " << divInv(8,1) << endl;
    std::function<float(float)> divBy2 = std::bind(div1, _1, 2);
    cout << "8/1 = " << divBy2(8) << endl;
    cout << "8/2 = " << divBy2(6) << endl;
}
