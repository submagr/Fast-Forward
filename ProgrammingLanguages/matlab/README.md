#MATLAB (for machine learning)

## Matrices and arrays
- All matlab variables are multi-dimensional arrays
- Single dim: a = [1 2 3 4]
- Multi dim: a = [1 2; 3 4]
- a+10 : add 10 to all elements
- a': Transpose
- \* : Normal Matrix multiplication
- .\* : Elementwise Matrix multiplication
- Matlab stores numbers as floating point values. *Use format long to display digits after decimal*
- Concatenation : 
	- [a, a] Horizontally (same number of rows)
	- [a: a] Vertically (same number of columns)
- Accessing elements of arrays:
	- Matlab arrays are 1 indexed
	- A(4, 2)
	- A(8) : Linear indexing, Traverse columns in order: A(4, 2)
	- Multiple Elements: A(1:3, 2) prints elements in 1,2,3 row, 2nd column
		* Alone colon specify all the elements in that dimension
	- range: start:step:end

## Text and Characters
- single quotes ('' for escaping single quote)
- Concatenation is similar as Horizontal concatenation of matrices (comma separated)
- num2str, int2str 

## Functions
- Multiple arguments : [ maxA, location] = max(A)
- max(A), disp('This is print function')

## Plots
- plot(x, y) 
- use *hold on* to add plots to existing figures. *hold off* to stop appending to same figure
- surface plot : *surf(X, Y, Z)* 

## Loops
- for k = 1:10
	COde
  end
- if elseif else end
