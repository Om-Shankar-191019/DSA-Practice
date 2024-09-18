var employee1 = { firstName: "John", lastName: "Rodson" };
var employee2 = { firstName: "Jimmy", lastName: "Baily" };

function invite(greeting1, greeting2) {
  console.log(
    greeting1 + " " + this.firstName + " " + this.lastName + ", " + greeting2
  );
}

const inviteArrow = (greeting1, greeting2) => {
  console.log(
    greeting1 + " " + this.firstName + " " + this.lastName + ", " + greeting2
  );
};

// inviteArrow.call(employee1, "HELLO", "Stonish");
// invite.call(employee1, "HELLO", "Stonish");
let object = {
  k1: "value1",
  k2: "value2",
  k3: "value3",
};
// let c = 0;
// for (let key in object) {
//   console.log(key + " ---> " + object[key]);
//   c++;
// }
// console.log(c);

// pi = 45;
// console.log(pi);
// console.log(window);

// debounce --
let count = 0;
function counter() {
  count++;
  console.log(count);
}

// function debounce(fx, timer) {
//   let id = null;
//   return function () {
//     if (id) {
//       clearTimeout(id);
//     }
//     id = setTimeout(fx, timer);
//   };
// }

// let debounceCounter = debounce(counter, 1000);

// test cases
// setTimeout(debounceCounter, 1000);
// setTimeout(debounceCounter, 1500);
// setTimeout(debounceCounter, 2100);
// setTimeout(debounceCounter, 5000);

// throttle function -------------------

function throttle(fx, timer) {
  let parameters = [];
  let id = null;
  return function (x) {
    if (!id) {
      id = setTimeout(() => {
        fx(parameters[parameters.length - 1]);
        id = null;
      }, timer);
    }
    parameters.push(x);
  };
}

let throttleCounter = throttle(counter, 1000);

// test cases
// setTimeout(throttleCounter, 1000);
// setTimeout(throttleCounter, 1500);
// setTimeout(throttleCounter, 2100);
// setTimeout(throttleCounter, 5000);

// console.log(Promise.resolve(34));
function pro() {
  const t = Promise.resolve(34);
  t.then((value) => console.log(value));
}
// async function pro() {
//   const t = await Promise.resolve(34);
//   console.log(t);
// }

// pro();

// --------------------------------------------------

let obj = new Object();
(obj.name = "om "), (obj.age = 34);

// console.log(obj);

let a = {};
a.name = "om shankar";
// console.log(a);

let b = Object.create(null);
b.name = "ravi shankar";

// console.log(b);

function Person(name, age) {
  this.name = name;
  this.age = age;
}

// console.log(Person("manu", 34));

// class Person {
//   constructor(name, age) {
//     this.name = name;
//     this.age = age;
//   }
// }
fun();

var fun = () => {
  console.log("hi om");
};
