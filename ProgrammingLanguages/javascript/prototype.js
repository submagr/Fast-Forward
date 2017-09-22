function PersonClassConstructor(fn, ln){
    this.fn = fn;
    this.ln = ln;
    console.log("PersonClassConstructor called");
    this.print = function print(){
        console.log(this.fn);
        console.log(this.ln);
    };
    var a = 10;
}

var person1 = new PersonClassConstructor('fn1', 'ln1');
var person2 = new PersonClassConstructor('fn2', 'ln2');
person1.print();
person2.print();

console.log("now suppose we want to add new method specifically to person1");
person1.tagline = function(){console.log("1's tagline")};

person1.tagline();
// Following line will gibe error
// person2.tagline(); 

// Prototypes can be used to add properties later on
PersonClassConstructor.prototype.height = new String();
PersonClassConstructor.prototype.showHeight = function(){console.log(this.height);};
person1.height = "1";
person2.height = "2";
person1.showHeight();


person1.prototype.nation = "India";
// console.log(person1.nation);
// console.log(person2.nation);
//
