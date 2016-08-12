ljfisdkjfk C++ Fast-Forward
This readme will tell about important syntax and concepts in cpp.

##Classes: 
* Class-declaration : 
	- object Myobject : Will do static allocation, i.e., object will be deleted after function returns. 
	- object * Myobject = new object(): Will do dynamic allocation on heap. One has to delete manually from heap after use. Similar to malloc. [stack overflow](http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself)

##Declarations: 
* int a : only memory allocated, garbage is present. 
* int\* a: might not be equal to NULL(***especially in classes***), set it manually. 

##STL : 
```
#include<bits/stdc++.h>
```

##Queue
- queue<int> q;
- q.push(1), q.pop() returns nothing, q.empty(), q.size(), q.front(), q.back()
- q.back() return ***Seg Fault*** on uninitialized queue, q.front() returns 0. 

