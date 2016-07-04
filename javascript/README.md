A JavaScript function is a block of JavaScript code, that can be executed when "asked" for.
For example, a function can be executed when an event occurs, like when the user clicks a button.

It is a good idea to place scripts at the bottom of the <body> element.
This can improve page load, because script compilation can slow down the display.

script can also be placed in external files. Don't put <script> tags in external files.
To import script use : 
<script src="myScript.js"></script>
The script will behave as if it was located exactly where the <script> tag is located.

functions: 
	<script>
	function myFunction() {
		document.getElementById("demo").innerHTML = "Paragraph changed.";
	}
	</script>

Javascript outputs : 
	Writing into an alert box, using window.alert().
	Writing into the HTML output using document.write(). -- Should be used only for testing
	Writing into an HTML element, using innerHTML.
	Writing into the browser console, using console.log().

JavaScript statements are separated by semicolons.To be on safe side - always insert semicolons

String concatenation : 'a'+ ' '+ 'b' == 'a b'

Comments : /* */ or //

**Variables are case sensitive**

Uninitialized variables will have value **undefined**

variable type : typeof(var) 

++,+= both are available

=== : equal value and type

Arrays : var cars = ["Saab", "Volvo", "BMW"]; 

Objects : 
	var person = {
		firstName:"John",
		lastName:"Doe",
		age:50,
		eyeColor:"blue",
		fullName: function(){
			return this.firstName+ " " + this.lastName
		}
	};
	person['firstName'] or person.firstName is OK
	person.fullName()
	
	// Object Constructor 
	function person(first, last, age, eye) {
		this.firstName = first;
		this.lastName = last;
		this.age = age;
		this.eyeColor = eye;
	}
	var myFather = new person("John", "Doe", 50, "blue");
	var myMother = new person("Sally", "Rally", 48, "green");
	
	var x = y
	x is not copy of y, **x is y**
	**Objects are mutable, they are addressed by reference**
			

null : In JavaScript null is "nothing". It is supposed to be something that doesn't exist.You can empty an object by setting it to null. typeof(null) is object

SCOPE : 
JavaScript has function scope: The scope changes inside functions.
**If you assign a value to a variable that has not been declared, it will automatically become a GLOBAL variable.**

EVENTS: 
<some-HTML-element some-event='some JavaScript'>

ERRORS: 
	try {
		Block of code to try
	}
	catch(err) {
		err.msg
		Block of code to handle errors
	} 
	finally {
		Block of code to be executed regardless of the try / catch result
	}

HTML DOM : 
	HTML DOM methods are actions you can perform (on HTML Elements).  
	HTML DOM properties are values (of HTML Elements) that you can set or change.
