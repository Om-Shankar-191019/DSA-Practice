// function reverseString(str) {
//   let i = 0;
//   let j = str.length - 1;
//   while (i < j) {
//     let temp = str[i];
//     str[i] = str[j];
//     str[j] = temp;
//     i++;
//     j--;
//   }
//   return str;
// }
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
  console.log(resultSent);
}

reverseWordFromSent("harse bhai kaise ho");
