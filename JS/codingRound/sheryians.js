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

let a = ["hi", "there"];
console.log(emptyArray2(a));
console.log(" a : ", a);
