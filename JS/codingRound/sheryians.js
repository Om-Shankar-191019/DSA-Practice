function reverseString(str) {
  let strArray = str.split("");
  let reverseStr = strArray.reverse().join("");
  return reverseStr;
}
// console.log(reverseString("asdf"));

function reverseWordFromSent(sent) {
  let sentArray = sent.split(" ");
  let result = [];
  for (item of sentArray) {
    result.push(reverseString(item));
  }
  let resultSent = result.join(" ");
  return resultSent;
}

// reverseWordFromSent("harse bhai kaise ho");

function reverseWordFromSent2(sent) {
  let arr = sent.split(" ");
  let reversedArr = arr.map(function (item) {
    return item.split("").reverse().join("");
  });
  return reversedArr.join(" ");
}

// console.log(reverseWordFromSent2("harse bhai kaise ho"));

// Q.2 check whether an object is an array or not ? --------

function checkArray(obj) {
  return Array.isArray(obj);
}

// console.log(checkArray([]));
// console.log(checkArray({}));
// console.log(checkArray("string"));

// Q.3 How to empty an array in js ?

function emptyArray(arr) {
  //   arr = []; not a good solution.
  while (arr.length > 0) {
    arr.pop();
  }
  return arr;
}

function emptyArray2(arr) {
  arr.length = 0;
  return arr;
}

// let a = ["hi", "there"];
// console.log(emptyArray2(a));
// console.log(" a : ", a);

// Q4 How to check whether a number is an integer?

function checkInteger(num) {
  return Number.isInteger(num);
}

function checkInteger2(num) {
  return num % 1 === 0;
}

// console.log(checkInteger2(12.3));

// Q5 given [1,2,3,4,5]  o/p [1,2,3,4,5,1,2,3,4,5] . i.e duplicate it
function duplicate(arr) {
  let copyArr = [...arr];
  return [...arr, ...copyArr];
}

function duplicate2(arr) {
  return arr.concat(arr);
}

// let a = [1, 2, 3, 4, 5];
// console.log(duplicate2(a));
// console.log(a);

// Q6 reverse number
function reverseNumber(num) {
  let y = 0;
  let n = num;
  while (n) {
    let r = n % 10;
    y = y * 10 + r;
    n = Math.floor(n / 10);
  }
  return y;
}

function reverseNumber2(num) {
  //   return parseInt(num.toString().split("").reverse().join(""));
  return Number(num.toString().split("").reverse().join(""));
}

// console.log(reverseNumber(341));

// Q7 is string palindrome

function isPalindrome(str) {
  let copyStr = str;
  return copyStr === str.split("").reverse().join("");
}

// console.log(isPalindrome("hiom"));

// function alphabeticalString(str){
//     let arr = str.split("");
//     let resultArr = arr.map(function (char){

//     })
// }
