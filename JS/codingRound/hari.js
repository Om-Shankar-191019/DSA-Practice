function sumToN(n) {
  let sum = 0;
  for (let i = 1; i <= n; i++) sum += i;
  return sum;
}

function sumToN2(n) {
  return (n * (n + 1)) / 2;
}

// console.log(sumToN2(100));

function fibonacci(n) {
  let a = 0;
  let b = 1;
  if (n == 1) console.log(0);
  else if (n == 2) console.log(1);
  else {
    let c;
    console.log(0);
    console.log(1);
    for (let i = 3; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
      console.log(c);
    }
  }
}

function fibonacciInArray(n) {
  if (n == 1) return [0];
  else if (n == 2) return [0, 1];
  else {
    let fibo = [0, 1];
    for (let i = 2; i < n; i++) fibo.push(fibo[i - 2] + fibo[i - 1]);
    return fibo;
  }
}

// console.log(fibonacciInArray(10));

// *
// **
// ***
// ****
// *****
function pattern1(r) {
  for (let i = 1; i <= r; i++) {
    let stars = "";
    for (let j = 1; j <= i; j++) stars += "*";
    console.log(stars);
  }
}

// **
// ****
// ******
// ********
function pattern2(n) {
  for (let i = 1; i <= n; i++) {
    let str = "";
    for (let j = 1; j <= i; j++) {
      str += "**";
    }
    console.log(str);
  }
}
// pattern2(4);

// ****
// ***
// **
// *
function invertedRightAngleTriangle(n) {
  for (let i = 0; i < n; i++) {
    let str = "";
    for (let j = 0; j < n - i; j++) {
      str += "*";
    }
    console.log(str);
  }
}

function invertedRightAngleTriangle2(n) {
  for (let i = n; i >= 1; i--) {
    let str = "";
    for (let j = 0; j < i; j++) {
      str += "*";
    }
    console.log(str);
  }
}

// invertedRightAngleTriangle2(4);

//     *
//    ***
//   *****
//  *******
// *********
function pyramid(r) {
  for (let i = 1; i <= r; i++) {
    let str = "";
    for (let j = 1; j <= r - i; j++) {
      str += " ";
    }
    for (let j = 1; j <= 2 * i - 1; j++) {
      str += "*";
    }
    console.log(str);
  }
}

// pyramid(5);

function removeDuplicates(arr) {
  return [...new Set(arr)];
}

// console.log(removeDuplicates([1, 2, 2, 3, 4, 4, 5]));

function isPrime(num) {
  if (num <= 1) return false;
  if (num === 2) return true;

  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) return false;
  }

  return true;
}

console.log(isPrime(11));
