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

// Strings in JS
let a = "Akash";
console.log(a[0]); // access 0th element, here 'A'
a.length; // returns length of string (it is a property.. thus a.length... not a.length() )

a.concat("str1", "str2"); // same as a + str1 + str2 ...

// Template literals
// used to code efficiently
// ex:
console.log("Name starts with " + a[0] + " and it is " + a); // without template literals
console.log(`Name starts with ${a[0]} and it is ${a}`); // with template literals

// another use of template literal:
// for printing TEST"
// console.log("TEST"");  gives error
console.log(`TEST"`);

a.slice(1, 4); // returns a string from 1st index (included) to second index (excluded)
a.slice(1); // gives 1 ke baad ke saare.. i.e. default values of end index = string length

a.replace("search", "replace"); // replaces 'first' occurence of substring within a string

a.trim(); // removes whitespaces :)

// * * * STRING IN JS ARE IMMUTABLE
// All the above functions return a new string on performing an operation (no modification to existing string)

// Arrays in JS
let arr = [1, 2, 3, 4, 5];
// * * ARRAYS ARE MUTABLE, so changes to original array directly
console.log(arr.length);

arr.toString(); // returns a string of comma separated array elements

arr.join(" & "); // returns string with elements separated by given arg.

arr.push(100); // insert element at end
arr.pop(); // remove last element
arr.unshift(100); // insert element at start
arr.shift(); // remove element from start

let z = arr.concat(arr2, arr3);
// same as string concat.. adds elements at end (* * RETURNS NEW ARRAY.. NONE OF THEEXISTING ARRAY MODIFIED)

arr.splice(startIndex, noOfElementsToDelete);
// deletes given number of elements starting from given index (element at index included)

// * * * MAP FUNCTION IN ARRAY
// Suppose we have an array of numbers, and we want to calculate an array of squares of those numbers
// classic approach:
let newarr = [];
for (let i = 0; i < arr.length; i++) {
  newarr.push(arr[i] * arr[i]);
}

// using map method:
arr.map((val, index) => {
  arr[index] = val * val;
});
// or:
arr.map((val) => {
  return val * val; // replace val with val*val
});

// * * * FILTER METHOD
// takes arrow function as arg, keep element if arrow func returns true for that arg
const greaterThanTen = (ele) => {
  return ele > 10 ? true : false;
};
let filteredArray = arr.filter(greaterThanTen); // returns new array, doesnt modify existing

// Javascript Document Object Model (DOM)
// tree like structure in which each html entity is considered as an object of its parent element
// can be accessed from JS for runtime manipulations

// Different ways to select elements from DOM

document.getElementsByClassName("className");
// returns array of all elements having given class name

document.getElementById("elementId");
// gets specific element

document.querySelector(".box");
// returns first element having the provided css selector

document.querySelectorAll(".box");
// returns list of all element having provided css selector
// if using querySelector all, we need to iterate to each element of HTML collection (list) using foreach loop and do necessary scripting

element.getAttribute("attrName");
// used to get value of an attribute for given element

document.getElementById("container").innerHTML = "";
// make parent container ka innerHTML = ""

// innerHTML = container ke andar ka HTML
// outerHTML = container ka HTML + innerHTML

// data attribute in JS
// we can add custom attributes to our HTML element starting with data-* and then access them as an array in JS, along with values
// ex:
// <div id="a" data-createdBy="test"> Some Random Text </div>
document.getElementById("a").dataset;
// Returns a Map, having all data-* elements for an element in key value pair

// Creating and Inserting elements in JS
let d = document.createElement("div");
d.setAttribute("class", "byJS"); // add class attribute with value byJS

document.getElementById("container").append(d);
// * * append method use karne pr, always inserted to end of parent element

document.getElementById("container").prepend(d);
// adds to start of parent

document.getElementById("container").before(d);
// insert before container.. similarly, we have after..

document.getElementById("container").replaceWith(d);
// replace container with d

// Deleting Element
document.getElementById("container").remove();

// View list of class for an element
document.getElementById("container").className;

// Add or remove class for an element
document.getElementById("container").classList.add("a");
document.getElementById("container").classList.remove("a");

document.getElementById("container").classList.toggle("a");
// hoga to remove, nahi hoga to add

// Events in JS
// JS have lot of predefined events such as onMouseMove, onKeyPress, etc..
// We coult listen to this events, track them, and run JS codes using event listeners
// event listeners are functions for an html element that take 2 parameters: eventToListen, callBack function to be executed
d.addEventListener("mouseover", () => {
  console.log("Hovering...");
});

// https://developer.mozilla.org/en-US/docs/Web/Events
// list of all predefined events

// * * * Event Bubbling in JS (IMP)
// Consider Following html:
/*
<div class="cont">
    <div class="child">
      Some Random Text
    </div>
</div>
*/

// we want to add alert for clicks ..
document.querySelector(".child").addEventListener("click", () => {
  console.log("child clicked");
});
document.querySelector(".cont").addEventListener("click", () => {
  console.log("container clicked");
});
// * * Now, jab child pr click karege.. event bubble ho jaega..
// bcoz child is inside cont, events for those would also be triggered

// This can be fixed by stopping propogation
// take event object as parameter in callback function, adn use its stopPropogation method
document.querySelector(".child").addEventListener("click", (e) => {
  console.log("child clicked");
  e.stopPropagation();
});

// SetInterval -> to perform specific action repeatedly
// takes 2 args: callback func to execute, delay in ms
setInterval(() => {
  //code
}, 1000); // runs each second
// setInterval function returns an unique interval id
// this can be stored in a variable, to clearInterval() later

// setTimeout -> pause code execution for provided delay -> run callback function only once
// syntax same as setInterval
// timeout can also be cleared using clearTimeout, even if its in pause phase

// asynchronus nature of JS
// consider the code:
console.log("a");
setTimeout(() => {
  console.log("b");
}, 1000);
console.log("c");
// expected output = a -> wait 1 sec -> b -> c
// But, async nature of JS will keep async functions for later and run other code block first
// setTimeout being async, is set for later
// thus, output: a -> c -> wait 1 sec -> b

// Callback functions = functions that run when a other function is executed (usually passed as a paramter)
// ex:
const loader = (data, callback) => {
  a = data; // perform operation
  callback("done");
};

// now this is different from calling function from function coz in that way its static
// here, we can dynamically pass function to run by our choice
// ex:
loader(1, myPredefinedFunc(arg));
// or
loader(22, (arg) => {
  console.log(arg);
});

// Promises in JS
// way to handle async operations
// take a arrow function as argument which also has 2 function arg (resolve, reject)
// we could specify when a promise is resolved and rejected by calling this parameter functions

// this helps us run code based on whether an async operation is completed successfully or not (based on whether the promise has been resolved)

// ex:
let prom = new Promise((resolve, reject) => {
  if (someCondition) {
    // logic
    resolve(data);
  } else reject();
});

prom
  .then((d) => {
    console.log("Promise Resolved - ", d);
  })
  .catch(() => {
    console.log("Promise Rejected");
  });

// Fetch API in JS
// used to fetch data from an API endpoint
fetch("https://endpointUrlHere")
  .then((response) => response.json()) // First promise that would take data from endpoint and convert it to json (bcoz .json() is async method, so used promise to wait for it to be resolved)
  .then((json) => console.log(json)); // logged parsed json

// alternate way using async awai t:
let x = await fetch("https://endpointUrlHere");
let data = await x.json();
console.log(data);

// get req for getting data, post req for sending data and getting a response

// * * * Making a post request using fetch api
// fetch api takes an optional 2nd argument (object with req info)
/* 
  imp info to be configured:
  1. method -> method must be set to 'POST' for making a post request
  2. body -> body of data that need to be sent to server in post req
  3. headers -> contains headers with info that the server must know about the req
    3.1 IMP header = "Content-Type" -> defines the type of content being sent... * * must snychronise with type of content in body
    => for json data, "Content-Type": "application/json"
*/
// ex. post req:
let r = await fetch("http://jsonplaceholder.typicode.com/posts", {
  method: "POST",
  body: JSON.stringify({
    name: "akash",
    id: 1,
  }),
  headers: {
    "Content-Type": "application/json",
  },
});
data = await r.json();
console.log(data);

// or
fetch("http://jsonplaceholder.typicode.com/posts", {
  method: "POST",
  body: JSON.stringify({
    name: "akash",
    id: 1,
  }),
  headers: {
    "Content-Type": "application/json",
  },
}).then((resp) => {
  resp.json().then((data) => {
    console.log(data);
  });
});
// understand the version with promises along with async await too

// * * used json stringify to convert our json object to string, bcoz directly object cant be sent to server.. so data vahi, but as string
// and server ko bol diya ki json hai, so it will consider that way

// Error Handling in JS
// throw keyword is used to throw error in JS
throw Error("error message");

// try catch
try {
  // running this piece of code
} catch (err) {
  // error aa gaya and stored in err object
} finally {
  // runs in both cases, even if try is executed or catch
  // usually used for cleanup, closing files, db connections etc
}

//* * IF its executed anyways, why not simply write in below the try catch block
// this is mainly useful when try catch is wrapped inside a function block
// ex:
const xyz = () => {
  try {
    // some code
    return 8718; // some value
  } catch (err) {
    // some code
    return -1; // some value
  } finally {
    // cleanup code
  }
};

// * * In this case, if we dont use finally and write up the code directly after try catch block, it would never be executed
// bcoz function return ho jayega, so below code ignored
// but if its in finally, it is still executed after function return from either try or catch

// Classes and objects in Javascript
// class -> blueprint or template
// object -> entity made on class template that has properties specified
class Animal {
  constructor(name) {
    console.log("Object Created!");
    this.name = name;
  }

  eat = () => {
    console.log("Kha raha hu");
  };
}

class Lion extends Animal {
  // inheritance using extends
  roar = () => {
    console.log("Roaring");
  };
  constructor(name) {
    console.log("Lion created."); // * * * THIS WILL GIVE ERROR BCOZ WE NEED TO CALL CONSTRCTOR OF BASE CLASS TOO (using super) if modifying after inheritance
  }

  // modified constructor:
  constructor(name) {
    super(name);
    console.log("Lion created.");
  }
}
