/*
 * Demonstrate how to know whether an object is created on heap or stack 
 */

#include<iostream>
using namespace std;
class A{
    bool isOnHeap;
    static bool gHeap;
    static int count;
public:
    A(): isOnHeap(gHeap){
        count--;
        if(count <= 0){
            count = 0;
            gHeap = false;
        }
    }
    static void * operator new(size_t size){
        A* temp= (A *)malloc(size);
        temp->gHeap = true;    
        count++;
        return temp;
    }
    static void * operator new[](size_t size){
        A* temp= (A *)malloc(size);
        int arrSize = size/sizeof(A);
        count += arrSize;
        gHeap = true;
        return temp;
    }
    void Location(){
        if(isOnHeap == true){
            cout << "On Heap" << endl;
        }else if(isOnHeap == false){
            cout << "Not on Heap" << endl;
        }
    }
    class Helper{
        Helper(){
        }
    };
};

bool A::gHeap = false;
int A::count = 0;
int main(){
    A obj1;
    A *ptr1 =new A();
    A obj2;
    A *ptr2 = new A();
    obj1.Location();
    obj2.Location();
    cout << "-----------" << endl;
    ptr1->Location();
    ptr2->Location();

    A* ptr3 = new A[5];
    for(int i=0; i<5; i++){
        ptr3[i].Location();
    }
    return 0;
}
