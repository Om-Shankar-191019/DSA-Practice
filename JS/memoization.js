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

function sum(a) {
  return a + 10;
}

function memoization(fx) {
  let map = new Map();

  return function (a) {
    console.log(map);
    if (map.has(a)) return map.get(a);
    else {
      let result = fx(a);
      map.set(a, result);
      console.log("else");
      return result;
    }
  };
}

const memoizedSum = memoization(sum);
console.log(memoizedSum(12));
console.log(memoizedSum(13));
console.log(memoizedSum(14));
console.log(memoizedSum(14));
console.log(memoizedSum(13));
console.log(memoizedSum(14));
console.log(memoizedSum(25));
