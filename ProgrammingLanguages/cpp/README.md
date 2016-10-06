#C++ Fast-Forward
This readme will tell about important syntax and concepts in cpp.

##Classes: 
* Class-declaration : 
	- object Myobject : Will do static allocation, i.e., object will be deleted after function returns. 
	- object * Myobject = new object(): Will do dynamic allocation on heap. One has to delete manually from heap after use. Similar to malloc. [stack overflow](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)

##Declarations: 
* int a : only memory allocated, garbage is present. 
* int\* a: might not be equal to NULL(***especially in classes***), set it manually. 

##memset: 
:
##STL : 
```
#include<bits/stdc++.h>
```

##Queue
- queue<int> q;
- q.push(1), q.pop() returns nothing, q.empty(), q.size(), q.front(), q.back()
- q.back() return ***Seg Fault*** on uninitialized queue, q.front() returns 0. 

#C Fast-Forward
### Storage classes in C: 
- There are three concepts:
	- Blocks: Are group of code statements which are treated as units for the purpose of defining scope.
	- LifeTime: Variable creation and deletion time
	- Scope: Area of code within which the variable can be accessed
	- Visiblity: is the "accessiblity" of variable. It is the result of hiding the variable in outer scope.
	- Really nice explaination: [link](http://opensourceforu.com/2011/10/joy-of-programming-scope-lifetime-and-visibility-in-c/)

