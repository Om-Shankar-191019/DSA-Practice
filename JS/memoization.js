function heavy(x) {
  //   console.log("i am heavy fun " + x);
  return "i am heavy fun " + x;
}

// heavy(4);

function memoizationPattern(fx) {
  return function (x) {};
}

function memoizer(fx) {
  let map = new Map();
  return function (x) {
    if (map.has(x)) {
      return map.get(x);
    } else {
      let result = fx(x);
      map.set(x, result);
      return result;
    }
  };
}

let memoizedHeavy = memoizer(heavy);

console.log(memoizedHeavy(4));
console.log(memoizedHeavy(5));
