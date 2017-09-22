# Functions:
1. Constructors: are called after the construction; derived class; no default constructor by compiler
2. Vendor (Creator of api), Consumer(who uses the api, programmers)
3. **Function names** change after compilation. It depends on compiler. Function name depends on (scope, class it belongs etc etc. ) 
    1. This means api I created should be used be same compiler programmer.
    2. Check once, that u can create same name function with different arguments.
    3. **Function Overloading** : Same function name, but either different in parameters or in return type
        -  
        ```cpp
        extern "C++" fun1(){}
        ```
        - What is use of extern? <TODO>
        - extern "C++" was default. can use "Fortran". This was naming conventions of function.
        - Using this, one can instruct the compiler to use naming convention (of function) of another compiler
    4. <todo>  type of int depeneds on compiler. in stack, size of int may vary. 
    5. Memory allocated on stack is cleared by .... (vendors/ consumer)?
        - Consumer remove the memory from stack
        - But code "add esp 8" is repeated for consumer
    6. **Epilog/ Prolog** of functions
    7. **Calling convention**. (default is \_\_cdecl, can be configured) (\_\_stdcall: ret 0 converted to ret 8, ie, ret adds 8 bytes before returning)
        - When to use what? What if u don't know the number of arguments ? (printf) 
        - \_\_fastcall : Request to use registers instead of pushing on stack. Maybe use it in forloop parameters. <TODO: Check this out>
        - \_\_thiscall : pass this pointer to function (lea vs move)
    8. **Exception List**: void funNew() throw(int, float, double) 

# Classes:
## Constructors:
```cpp
CA obj;
```
- Main purpose is **not Initialization**, do not use in constructor. Initialization should be done via initialization list. 
- RAII: Acquire all the resources what obj is going to use. Eg. File pointers 
- Order of calling in constructor:
    * Base's constructor is called. (in case of multiple base classes left to right)
    * Then set vptr to its vftable
    * If objects'constructors are called in top to bottom fashion after this  <TODO: Need reference>
    * Derived's constructor is getting called first, which first call base's constructor. There are cases when <BOOK: Inside object model, chapter: symentics of objects> compiler synthesizes constructor on it's own:
- base class first,  then objects (top to bottom).
- What if u don't have a constructor. Generally, compiler does not synthesize a constructor on it's own. There are 4 special cases:
    * Suppose base has constructor, derived not, then what happens?
    * Containers, Contained objects: Limb in cub, limb has constructor, cub has not 
    *  When u have a virtual function and don't have a constructor
    * <TODO: 5th day>
- Assume some pre-construction and post-construction jobs. So we use factory and creators
- Move, explicit with multi param, 
- Explicit keyword: not allow copy-initialization
- Perfect forwarding constructor
- Ownership transfer

## Destructor 
- 
```cpp
~CAT(){// setvptr(CAT::vftable)
    
}// call base's destructor(~ANIMAL())
```
## Inheritance:
- Protected, Public, Private: Private members are accessible only with the class and friends of class. Private members are accessible in derived class and friends of derived class also.
- By default, inheritance is **private**
- Public: as it is; protected: base class's public and protected becomes protected of derived class; Private: public, protected members of base class becomes private of derived
- Functions in derived class which do not override the functions in base class but have same name will **hide** other functions of the same name in base class.

## Virtual functions:
- vptr, virtual table, 
- Why there was first vptr pointing to address of vtable and then that address actually pointing to virtual table. <TODO>
- Function appending
- Function overriding
- Don't confuse function overloading here: it's basically same func name but different parameters or return type
- How is code segment referenced. There's is some gap I see 
- setting the vptr to appropriate vtable: = Prologue of constructor
- <TODO> Virtual functions on reference and pointers. Expanded through vptr. (Others, normal object: never use vtable, in case of ref and ptrs, normal functions calls don't use vtable; ptrs and refs when call virtual functions, use vtable)
- Order, call the base class constructor, then set vptr. Basically, base class's constructor will set vptr to it's vtable, then derived's class
- If more than one base class: Derived class will have two vptr and two vftables, one for extending each of the base class. NEVER CAST BETWEEN BASE CLASSES. DOWNCAST FIRST AND THEN UPCAST
- Many times, we don't want to expose derived classes <TODO: When>
- dynamic\_cast
- Polymorphic types: Whenever you have types with virtual function
- RTTI
    
## Abstract class and Interfaces:
- If a class contain any **pure** virtual functions.
```cpp
class Base{ // This is an abstract class
    virtual void fun() = 0; // Syntax for declaring pure virtual functions
}
```
- Abstract classes are used when we know some particular method will exist, but don't know right now. For eg. Shape class don't know how to draw, until it's derived class (circle/rectangle) is provided
    

    
## Namespace:
- 

## Casting Operator, Operator overloading:
-

## Callbacks:
- <TODO> Callbacks through the virtual function
- <TODO> Callbacks through the function pointer 
- Closure Concept: Parent's context can be carried to callback, Functors are used in C++ to achieve closure.
- Lambda expressions in c++11:
    * Compiler actually create a functor for this shortcut
    * 
    ```cpp
    [capture](parameters)-><return type>{/\*function body \*/}
    ```
    * effect of [=]: captures everyting from parent's context as const. Don't want to be captured as const, use mutable (in c++ this means never constant)
    * [a,b]: capture only a and b; [&a, b]: a is <TODO>captured by reference
    * [&]: capture all by reference
    * [=,&d]: capture d by reference, rest all by value
    * tyepe duduce: Can be mentioned specifically: 
    ```cpp
    auto func = []()->double{if()return 1; else return 2.0;}
    ```
- decltype(expression) will return datatype of expression. Useful in templates.
```cpp
template<typename T1, typename T2>
auto AddFun(T1 x, T2 y)->decltype(x+y){
    return x+y;
}
```
- std::function
- What if callback need arguments from vendor function: Lambda function, apart from context, can also take parameters



## Template:
- **Template bloating**: Every time consumer demand new datatype, every function inside template class is repeated irrespective of some generic functions that do not depend on template type. We can prevent them from recreating every time:
    * Create common base class for template function
    * NOTE: It's the biggest harm while developing libraries.
- Variadic Templates: 
    * <TODO>: Lookup std args 


## Exception Handling: 
- Own terminate function: set\_terminate(<customTerminateFunction>):
    * Every try will have a catch table. Each table will have catch blocks
    * throw exp: exp copied to catch table. 
    * Then all local variables allocated upto this point gets released.
    * Information from catch table is carried to catch block. Catch executes and completes.
    * Then catch's local variable are released. Then catch table is also released.
- <TODO> This catch table is messy, sort it out.
- empty throw rethrows the exception from **catch table**, not from catch block.
- catch(...) If no other catches match, then this catches

## Iterators:

## Miscellaneous:
- size of empty class is 1 due to **this** pointer 
- <TODO> Cell Padding, offset calculations, allignments, memory allocation. Context was size of class
- <TODO> Reference vs pointers. **Oh please**, look up this. Occured many times before also now
- Some principles to follow for writing a class:
    * yagni, kiss, srp(single responsibility principal: One class should have one responsibility), high cohesion, low coupling(one class should not depend on internals of other class), ocp(open for extension but closed for moidification), lsp(baseclass )
    * Pure fabrication: When multiple class share common information/functionalities, move it to another class. Whatever is common, pull it out.
    * DRY 
    * TEMPLATE METHOD: Business skeleton maintained in base class, variying info to derived class
- <TODO> static variables in a class : It might be used to get count of this class variables.
- Factory Classes: <TODO>
- <TODO> Lookup lsp, it's somehow related to conversion between derived class and base class pointer
- <TODO> Capture in c++, context was passing values for initialization in constructor
- NOTE: Never throw an exception from destructor. Prone to overlap
- Whenever **new** keyword is used:
    * Compiler generates a temp ptr on which operator new is called.
    * After which there is a try catch block (generated by compiler) (with general exception catch).
    ```cpp
    obj = new CB();
    \*
        CB *temp=operator new()();
        try{
            temp->CB::CB();
        }catch(...){
            free(temp);
            throw;
        }
        obj = temp;
    *\
    ```
- delete keyword: Destructor is called before deallocating the memory. Note: Try calling delete in destructor
```cpp
delete obj;
obj->MyClass::~MyClass();
operator MyClass::delete();
```
```cpp
using FPTR = void(*)();
```
- foreach syntax in cpp <TODO>
```cpp
int arr[5]{1, 2, 3, 4, 5};
```
- Whenever equate two objects: bitwise copy occur: ie Copy constructor is called: 
- Value objects: deep copy
- rvalue object: for return value
- Braced Initialization in c++11. Can use it with equal to or without equal to
    * If marked "explicit" in front of constructor, can't use equal to to assign.
- Member initialization new in C++
- <TODO> : When did constructors of object within a class are called
- SmartPointers: Context was how to create a class which can only be created via new
- Casting operator
- Lazy load, lazy 
- Order of initialization always maps to order of declaration

## HW:
- Variadic templates with class
- No throw new and placement new
- Body Handle Technique
- Identify two apis called mem\_fn, bind, tie and ref
