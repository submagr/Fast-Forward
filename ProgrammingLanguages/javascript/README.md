# Javascript
## Syntax
- It is a good idea to place scripts at the bottom of the <body> element.
This can improve page load, because script compilation can slow down the display.
- script can also be placed in external files. Don't put \<script\> tags in external files. To import script use:
    ```javascript
    <script src="myScript.js"></script>
    ```
    The script will behave as if it was located exactly where the \<script\> tag is placed in HTML.

-   document.getElementById 
    ```javascript
    <script>
    function myFunction() {
        document.getElementById("demo").innerHTML = "Paragraph changed.";
    }
    </script>
    ```

- Javascript outputs : 
	* Writing into an alert box, using window.alert().
	* Writing into the HTML output using document.write(). -- Should be used only for testing
	* Writing into an HTML element, using innerHTML.
	* Writing into the browser console, using console.log().

- JavaScript statements are separated by semicolons.To be on safe side - always insert semicolons
- String concatenation : 'a'+ ' '+ 'b' == 'a b'
- Comments : /* */ or //
- **Variables are case sensitive**
- Uninitialized variables will have value **undefined**
- variable type : typeof(var) 
- ++,+= both are available
- === : equal value and type
- Arrays: var cars = ["Saab", "Volvo", "BMW"]; 
- Objects: 
    ```javascript
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
    // x is not copy of y, **x is y**
    ```

- null: In JavaScript null means "nothing". It is supposed to be something that doesn't exist. You can empty an object by setting it to null. typeof(null) is Object
- SCOPE: 
    * JavaScript has function scope: The scope changes inside functions.
    * **If you assign a value to a variable that has not been declared, it will automatically become a GLOBAL variable.**
- ERRORS: 
    ```javascript
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
    ```

## With HTML:
- EVENTS: 
    ```html
    <some-HTML-element some-event='some JavaScript'>
    ```
- HTML DOM : 
	* HTML DOM methods are actions you can perform (on HTML Elements).  
	* HTML DOM properties are values (of HTML Elements) that you can set or change.

## Objects:
- JS has one complex datatype: Object. Other five are simple datatypes: Number, String, Boolean, undefined and null
- Simple datatypes are immutable(can't be altered). Objects are mutable
- An object is an unordered list of primitive data types (and sometimes reference data types)
- ***Reference data type vs Primitive data types****:
    * Ref. Data type value are stored as reference. 
    * Primitive data type value are stored at variable
- Owned and inherited properties
    * All object inherit properties like (hasOwnProperty) from Object.prototype
    * To check for a property, use: (propertyToCheck in correspondingObject)
    * We cannot delete properties that were inherited

## Prototypes:
- Every js function has a prototype property (which is empty initially)
- We attach properties and method on this prototype property when we want to implement inheritence
- ***Prototype Attribute***:
    * Think of it as a characterstic of the object. This characterstics tells us the object's parent
    * The prototype attribute is normally referred as prototype object and is created simultaneously with object creation
- All objects created with Object literal (var a = {};) or Object constructor (var a = new Object();)
- Objects created with constructor function get their prototype from constructor function
- All inheritence in js is made possible through prototype property
    ```javascript
    function PersonClassConstructor(fn, ln){
        // Notice the use of capital first letter for functions which are constructors
        this.firstname = fn;
        this.lastname = ln;
    }
    ```
## AJAX Requests:
- Asynchronous JS and XML
- AJAX is just a combination of `XMLHTTPRequest` Object and JS HTML DOM processing 
- Usage example:
    ```javascript
    var xhttp = new XMLHTTPRequest();
    xhttp.onReadyStateChange = function() {
        if (this.readyState = 4 && this.status = 200) {
            /* handle response data from server */
        } else {
            /* or handle some error */
        } 
    };
    xhttp.open("GET", someUrl, true);
    xhttp.send();
    ```
- Syntax:
    * Methods
        ```javascript
        open(method,url,async,user,psw):
            method: GET/POST etc. url: async: user (optional): psw (optional)
        send(): send request to server
        ```
    * Properties:
        ```javascript
        onreadystatechange : `function` to be called when state of request changes
        readyState: when 4: request is finished and response is received
        responseText: response data as a string
        responseXML: response data as XML
        status: status of the response
        statusText:
        ```
- GET Requests: Add query parameters in the url itself.
- POST Requests: The data you want to send is specified in `send(string)`
    ```javascript
    var xhttp = new XMLHTTPRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState === 4 && this.status === 200)
            console.info(this.responseText);
        else
            throw Error({status: this.status, statusText: this.statusText});
    }
    xhttp.setRequestHeaders("Content-type", "application/x-www-form-url-encoded");
    xhttp.send("fist=shubham&&last=agrawal");
    ```
- Security concerns:
    * Browsers do not allow access across different domains, i.e., `someUrl` in the example above must be inside domain of the referring website

## Javascript Imports, Exports, Modules:
ECMA6 support imports. But Browsers are yet to migrate to ECMA6. There are various methods via which one can split the javascript code in multiple files.
- JQuery
- Ajax Requests and eval
- Javascript Compilers like webpack

## Webpack
- static module bundler
- Core concepts
    * Entry - Which js to treat as entry point js
    * Output - 
    * Loaders
    * Plugin