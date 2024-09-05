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

console.log(reverseWordFromSent2("harse bhai kaise ho"));
