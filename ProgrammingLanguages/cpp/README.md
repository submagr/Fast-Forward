# C++ Fast-Forward
This readme will tell about important syntax and concepts in cpp.

## Classes: 
* Class-declaration : 
	- object Myobject : Will do static allocation, i.e., object will be deleted after function returns. 
	- object * Myobject = new object(): Will do dynamic allocation on heap. One has to delete manually from heap after use. Similar to malloc. [stack overflow](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)

## Declarations: 
* int a : only memory allocated, garbage is present. 
* int \*a: might not be equal to NULL(***especially in classes***), set it manually. 
* new : Creates and initializes objects with dynamic storage duration(i.e. object whose lifetime is not limited by the scope in which they are created). new operator is confused with other operator new[] which is used for allocating arrays.
	- Syntax: 
	```cpp
	[new datatype]
	int *a = new int ;
	myClass *b = new myClass;
	myStruct *c = new myStruct;

	delete a;
	delete b;
	delete c;
	```
	- Procedure: It first allocates space on ***heap*** and then constructs object by calling constructor.

* new[]: for arrays
	- Syntax: 
	```cpp
	myClass *a = new myClass[5];
	delete[] a;
	```

## STL : 
- To include all functionalities of STL, use following code snippet:
```cpp
#include<bits/stdc++.h>
```
- Three major concepts of STL are:
	* Containers
	* Templates
	* Iterators

### Queue
- queue<int> q;
- q.push(1), q.pop() returns nothing, q.empty(), q.size(), q.front(), q.back()
- q.back() return ***Seg Fault*** on uninitialized queue, q.front() returns 0. 

### Stack
```cpp
stack<int> st;
st.push(1);
st.empty(); // returns false 
st.size(); // returns 1 (unsigned integer)
st.top(); // returns the reference to top element in stack
st.pop();  // remove top element
```


### List
Implemented as doubly linked list.
```cpp
list<int> myList;
myList.push\_front(1); // head, 1
myList.push\_front(2); // head, 2, 1 
myList.empty(); // false
myList.push_back(3); // head, 2, 1, 3 
```
### Priority Queue
- For heap
```cpp

```

### Vectors
- Vectors are just arrays with added functionalities.

```cpp 
vector<int> v[10];	// Array of size 10: Initially Empty
v.empty()			// If vector is empty or not
v.size()			// Returns size in unsigned int
v.push\_back()		// Add an element at the end of the vector. Increase size by one 
v.resize(10) 
v.clear()			// Makes vector of size 0
v.begin()

vector<int> Data(100) // Array of size 100, initialized with 0s
vector<string> Data(100, "shubham") // Array of size 100, initialized with "shubham"

vector< vector<int> > Matrix

int M, N;
vector< vector<int> > Matrix(M, vector<int>(N, -1))
```
## Class
```cp
class person{
	private:
		int income;
		int education;
		int password;
	public:
		string name;
		bool checkQualification(){
			/*Write code for check qualification here*/
		} // No Semicolon here
		bool matchPassword(string inputPassword); // The function can be defined here or later
}; // Don't forget the semicolon

bool person::matchPassword(string inputPassword){
	/*Code for password match here*/	
	cout << "Person Name: " << this.name;
}
```

# C Fast-Forward

## Storage classes in C: 
- There are three concepts:
	- Blocks: Are group of code statements which are treated as units for the purpose of defining scope.
	- LifeTime: Variable creation and deletion time
	- Scope: Area of code within which the variable can be accessed
	- Visiblity: is the "accessiblity" of variable. It is the result of hiding the variable in outer scope.
	- Really nice explaination: [link](http://opensourceforu.com/2011/10/joy-of-programming-scope-lifetime-and-visibility-in-c/)

## Pointers vs Reference
## Standard Data Sizes: 
- signed int (+-)10^4
