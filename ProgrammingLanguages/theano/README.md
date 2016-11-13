#Theano
Library that lets you define, optimize and evaluate mathematical expressions, especially ones with multi-dimensional array.

##Scan Function
- Accumulation
	```python 
	import theano
	import theano.tensor as T

	k = T.iscalar("k")
	A = T.vector("A")

	# Symbolic description of the result
	# Output of previous call to fn is the first parameter to next call
	result, updates = theano.scan(fn=lambda prior_result, A: prior_result * A,
								  outputs_info=T.ones_like(A),
								  non_sequences=A,
								  n_steps=k)

	# We only care about A**k, but scan has provided us with A**1 through A**k.
	# Discard the values that we don't care about. Scan is smart enough to
	# notice this and not waste memory saving them.
	final_result = result[-1]

	# compiled function that returns A**k
	power = theano.function(inputs=[A,k], outputs=final_result, updates=updates)

	print(power(range(10),2))
	print(power(range(10),4))
	```
- The thing to be looped over should be provided as sequences = [] 
- When outputs\_info is set to None, this means that fn does not pass return value as first parameter of next call
- The general order of function parameters to fn is 
	```python 
	sequences (if any), prior result(s) (if needed), non-sequences (if any)
	```
#Numpy

