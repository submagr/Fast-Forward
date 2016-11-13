#PYTHON

##*os* Module:
It is used to provide operating system based functionalities
- os.path: Provide path based functionalities like isdir, isfile etc. 
- os.walk: is used to traverse a directory subtree.
	- dirpath
	- dirnames: list of subdirectories excluding \. and \.\.  
	- filenames: list of names of non directory files
	To get full path (instead of names), use os.path.join(dirpath, name)
	Usage 
```python 
for dirpath, dirnames, filenames in os.walk("path to directory"):
	print dirpath, dirnames, filenames
``` 

###@ in python:

## Single Underscore format: 
- Single Underscore: This method/name is treated as private by the programmer. As the Python documentation notes:
```python 
A name prefixed with an underscore (e.g. _spam) should be treated as a non-public part of the API (whether it is a function, a method or a data member). 
It should be considered an implementation detail and subject to change without notice.
```
- From **interpreter's point of view**, an interpreter will not import names that start with \_'s unless the \_\_all\_\_ list explicitly contains them.

## Double Underscore format: 
- It is treated to distinguish subclass's method names from those of class's. Whenever a name starts with \_\_, interpreter treats the method name as nameClass\_name

## \_\_init\_\_ in python: 
- It is kind of a class constructer.
```python 
class A():
	def __init__(self):
		self.x = "This will be initialized when you create class instant. classObject = A()"			
```

## if \_\_name\_\_ == "\_\_main\_\_":
- It is used when we want to write a module that itself can be executed

## List Comprehension: 
```python 
[x for x in range(0,10)]
[(i,j) for i in range(0, 10) for j in range(0, 10)]
[x for x in range(0, 10) if x%2 == 0]
```

## Lambda
- Syntax: lambda argument\_list: expression 
	```python 
	f = lambda x,y: x+y
	```

## Map function:
- Syntax: map(function, input-list)
	```python 
	>>> f = lambda x: x*x
	>>> map(f, [1, 2, 3, 4])
	[1, 4, 9, 16]

	>>> a = [1,2,3,4]
	>>> b = [17,12,11,10]
	>>> c = [-1,-4,5,9]
	>>> map(lambda x,y,z:x+y+z, a,b,c)
	[17, 10, 19, 23]
	```

## IsEmpty:
- For sequences, (strings, lists, tuples), use the fact that empty sequences are false.
	```python
	Yes: if not seq:
		 if seq:

	No:  if len(seq):
		 if not len(seq):
	```
## Numpy functionalities:

## Error commited in past:
- ```python 
	>>> length = 2
	>>> [[[]]*length]*length
	>>> a = [[[]]*length]*length
	>>> a
	[[[], []], [[], []]]
	>>> a[0]
	[[], []]
	>>> a[0][0] = 1
	>>> a
	[[1, []], [1, []]]
  ```
