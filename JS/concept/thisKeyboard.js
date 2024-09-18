// "use strict";

// let person = {
//   name: "john",

//   sayBye: function () {
//     return " Bye " + this.name;
//   },
//   sayHi: function () {
//     return "hi " + this.name + this.sayBye();
//   },
// };

// let human = person;
// person = { car: "xuv" };

//   console.log(human.sayHi()); // hi john

function sayHi() {
  return "hi " + this.name;
}

let person = {
  name: "john",
  sayHi: () => {
    return "hi " + this.name;
  },
};

console.log(person.sayHi()); // Error
