// Used for adding logic to the webpage

alert("used for creating alerts in a site");
prompt("prints this string like alert, but returns user input text");
confirm("print string, user input boolean");
console.log("used to log contents to debug console");

// Variables, data types and objects
// variable names are case sensitive in JS
// data type is automatically inferred in JS
// typeof operator:
console.log(typeof var_name);

//  Difference between let, var and const
// var is globally scoped
// let is blocked scop
// const is block scoped but has a constant value
// * * * using 'let' in global namespace also creates a global variable (thus, always use of let is preferred)

// Primitive data types in JS: NULL, Number, String, Boolean, Undefined, etc
// Objects: User defined data types -> similar to a struct in CPP
// Objects contains data in key value pair (as it is not defined in beginning like a struct, so each time.. key and value)
let item = {
  name: "value",
  key: 888,
};
// * * * we can specify the key with or without double quotes.. if its single word(without space)
// if space present, must use quote for key too
// better practice: always use quotes.. for consistency
// value string hogi to hi quotes mei, number/bool hoga to nah

a ** b; // equivalent of pow(a, b) OR a^b

// Conditionals in Javascript
if (condition) {
  // Statements
} else {
  // Statements
}

// Ternary Operator
condition ? ifTrue : ifFalse;

// Loops in JS
// For Loop
for (let index = 0; index < array.length; index++) {
  // Statements
}

// For each loop
array.forEach((element) => {
  // Statements
});

// For in Loop (used for accessing properties of an object)
for (const key in object) {
  // Statements
}

// For of loop (used for accessing member data of an object)
for (const iterator of object) {
  // Statements
}

// difference between forin and forof:
let list = [4, 5, 6];
for (let i in list) {
  console.log(i); // "0", "1", "2" (properties of list.. here, its index only.. object hota to key value aata)
}
for (let i of list) {
  console.log(i); // "4", "5", "6" (iterates to the values in object)
}

// While loop
while (condition) {
    // Statements
}

// do While loop
do {
    // Statements
} while (condition);


// Functions in JS
function name(arguments) {
    // Statements
    return;
}

// Arrow Function in JS
// more readable, provide lexical scope of 'this' keyword
// that means... this keyword hass scope in which the arrow func is present
// Function defined like.. const variable = func -> definition of func
const func = (arguments) => {
    // Statements
};
// semicolon at end, as it is defined like var