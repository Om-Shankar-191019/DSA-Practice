function toCsvText(array) {
  // good luck
  let str = "";
  for (let i = 0; i < array.length; i++) {
    if (i > 0) {
      str += "+";
    }
    str = array[i].join(",");
    if (i !== array.length - 1) str += "\n";
  }
  return str;
}

const input = [
  [0, 1, 2, 3, 4],
  [10, 11, 12, 13, 14],
  [20, 21, 22, 23, 24],
  [30, 31, 32, 33, 34],
];

console.log(toCsvText(input));
