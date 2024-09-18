// let a = {
//   name: "om shankar",
//   age: 24,
// };

// let lab = {
//   labname: "chemistry",
//   labsize: 45,
//   chemicals: 293,
// };

// let car = {
//   carname: "mercedies",
//   carprice: "4 crore",
//   carmodel: "xtw56",
// };

// a.__proto__ = lab;
// lab.__proto__ = car;

// console.log(a.carmodel);

// ---------------------------------------------------

// debounce------------------

// const input = document.getElementById("inputbox");

// function debounce(fx, timer) {
//   let id = null;
//   return function () {
//     if (id) {
//       clearTimeout(id);
//     }
//     id = setTimeout(fx, timer);
//   };
// }

// function getInput() {
//   console.log(input.value);
// }
// let result = debounce(getInput, 500);

// input.addEventListener("keyup", result);

// ---------------------------------------------------------------------
// throttle--------------------

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

// let throttleCounter = throttle(counter, 1000);
document.addEventListener(
  "scroll",
  throttle(function () {
    console.log("hi there");
  }, 1000)
);
