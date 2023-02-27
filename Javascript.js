alert("Hello"); // creates an pop-up with string Hello

console.log("Hello"); // Creates output in console instead of pop up

var name1 = "Akash"; //creates a variable 'name1' with data type string and sets its value to 'Akash'

alert("Hello" + " " + "World"); //creates a popu-up with string 'Hello World'  [string concatenation]

var a = name1.length; // retrives length of string name1 and assigns that number to var a  { i.e. 5 here }

name1.slice(0, 3); // slices part of string name1 from postion 0 (first letter considered 0) to 3 (excluding 3) { i.e. Aka here }

name1 = name1.toUpperCase(); // changes all letters of name1 to upper case and sets that as value to name1 again

name1 = name1.toLowerCase(); // changes all letters of name1 to lower case and sets that as value to name1 again


/*
-----------------------------------ARITHMETIC OPERATORS---------------------------------
a + b  --> Add
a - b  --> Subtract
a * b  --> Multiply
a / b  --> Divide
a % b  --> Remainder of division
a++    --> equivalent to a = a + 1
a--    --> equivalent to a = a - 1
a += 3 --> increases value of 'a' by 3
a -= 3 --> decreases value of 'a' by 3
a = 3  --> assigns values 3 to a
a == 3 --> checks if a=3
a === 3--> checks if a=3 and also if a and 3 are same data types (i.e. if a belongs to numbers here)
-----------------------------------------------------------------------------------------
*/

function funcName() {
      /*  function's code here*/ 
}                                     //DECLARING FUNCTION

funcName(); //  Calling/Using function

Math.floor(x); // rounds down the value of x to nearest integer Ex: 4.3=>4   3.9=>3
Math.pow(base, power); // used to power a number..... ex: 5^6 -> Math.pow(5, 6)

function func2(x) { 
    alert(x); 
}  //passes value x to function as variable and pop's it up


/*
--------------------------------RETURNING VALUE FROM FUNCTION-------------------------------------- */
// DECLARATION=> 
    function func3(x)
    {
        alert (x);
        return x+10;
    }
// USAGE =>
    var plus10 = func3(10); //passes value 10 to func3 which pops it out once, and returns it by addign 10...saved in var plus10

// -----------------------------------------------------------------------------------------------------



//IF ELSE STATEMENTS
if (a==b) {
    alert("EQUAL");
}
else if (a > b) {
    alert("A IS GREATER");
}
else {
    alert("B IS GREATER");
}



//ARRAYS
var names = ["name1", "name2", "name3"];
var marks = ["33", "12", "54"];

names.includes("name1");  //returns true if name1 is present in array named 'names'
names.push("name4");  //Pushes an element 'name4' as the last item in the array
names.pop(); // takes out the last item from array
