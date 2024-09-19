// function heavy(x) {
//   //   console.log("i am heavy fun " + x);
//   return "i am heavy fun " + x;
// }

// // heavy(4);

// function memoizationPattern(fx) {
//   return function (x) {};
// }

// function memoizer(fx) {
//   let map = new Map();
//   return function (x) {
//     if (map.has(x)) {
//       return map.get(x);
//     } else {
//       let result = fx(x);
//       map.set(x, result);
//       return result;
//     }
//   };
// }

// let memoizedHeavy = memoizer(heavy);

// console.log(memoizedHeavy(4));
// console.log(memoizedHeavy(5));
// -------------------------------------------------------------

// function sum(a) {
//   return a + 10;
// }

// function memoization(fx) {
//   let map = new Map();

//   return function (a) {
//     console.log(map);
//     if (map.has(a)) return map.get(a);
//     else {
//       let result = fx(a);
//       map.set(a, result);
//       console.log("else");
//       return result;
//     }
//   };
// }

// const memoizedSum = memoization(sum);
// console.log(memoizedSum(12));
// console.log(memoizedSum(13));
// console.log(memoizedSum(14));
// console.log(memoizedSum(14));
// console.log(memoizedSum(13));
// console.log(memoizedSum(14));
// console.log(memoizedSum(25));
// ----------------------------------------------

// function add(x) {
//   return x + 10;
// }

// function memo(fx) {
//   let cache = {};
//   return function (x) {
//     if (cache[x]) {
//       console.log("result from cache: ");
//       return cache[x];
//     } else {
//       let result = fx(x);
//       cache[x] = result;
//       console.log("result from calculation: ");
//       return result;
//     }
//   };
// }

// let memoizedAdd = memo(add);
// console.log(memoizedAdd(11));
// console.log(memoizedAdd(22));
// console.log(memoizedAdd(30));
// console.log(memoizedAdd(11));
// console.log(memoizedAdd(30));
// ---------------------------------------------------------------

// for multiple arguments ------------

// function add(...data) {
//   return data.reduce((total, curr) => total + curr);
// }

// function memo(fx) {
//   let cache = {};
//   return function (...args) {
//     let key = JSON.stringify(args);
//     if (cache[key]) {
//       console.log("result from cache: ");
//       return cache[key];
//     } else {
//       let result = fx(...args);
//       cache[key] = result;
//       console.log("result from calculation");
//       return result;
//     }
//   };
// }

// let memoizedAdd = memo(add);

// console.log(memoizedAdd(1, 2, 3));
// console.log(memoizedAdd(1, 2, 30, 3));
// console.log(memoizedAdd(1, 2, 30, 3));
// console.log(memoizedAdd(1, 2, 3));
// console.log(memoizedAdd(1, 2, 3));

// ========================================================

// for two arguments

// function add(a, b) {
//   return a + b;
// }

// function memo(fx) {
//   let cache = {};
//   return function (a, b) {
//     let key = JSON.stringify(arguments);
//     if (cache[key]) {
//       console.log("result from cache: ");
//       return cache[key];
//     } else {
//       let result = fx(a, b);
//       cache[key] = result;
//       console.log("result from calculation");
//       return result;
//     }
//   };
// }

// let memoizedAdd = memo(add);

// console.log(memoizedAdd(1, 2));
// console.log(memoizedAdd(1, 4));

// real world use case -- fibonacci series using recursion
// -----------------------------------------

// memoization with set time out ------- asynchronous code ----------

// function fun(name) {
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve(`welcome ${name}`);
//     }, 2000);
//   });
// }

// let memoizedFun = function (fx) {
//   let cache = {};
//   return async function (name) {
//     try {
//       if (cache[name]) {
//         console.log("Result from cache:");
//         return cache[name];
//       } else {
//         console.log("Heavy calculation:");
//         let result = fx(name);
//         cache[name] = result;
//         return await result;
//       }
//     } catch (error) {
//       console.log(error);
//     }
//     return null;
//   };
// };

// let memoizedGreet = memoizedFun(fun);
// memoizedGreet("om shankar").then((res) => console.log(res));
// memoizedGreet("om shankar").then((res) => console.log(res));
// memoizedGreet("om shankar").then((res) => console.log(res));
