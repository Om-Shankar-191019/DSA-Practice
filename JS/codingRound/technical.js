//Longest word in a string

function findLongestWord(str) {
  let words = str.split(" ");

  //   words = words.sort((a, b) => a.length - b.length);
  //   return words.at(-1);

  //   words = words.sort((a, b) => b.length - a.length);
  //   return words[0];

  return words.reduce(
    (acc, word) => (word.length > acc.length ? word : acc),
    ""
  );
}
// console.log(findLongestWord("go and watch panchayat wet     series."));

function findLongestWord2(str) {
  let words = str.split(" ");
  let result = words[0];
  for (let i = 1; i < words.length; i++) {
    if (words[i].length > result.length) result = words[i];
  }
  return result;
}

// i/p : "go and watch panchayat web     series."
// o/p : #GoAndWatchPanchayatWebSeries.
function generateHashTag(str) {
  let res = "#";
  let resArray = str.split(" ");
  for (let i = 0; i < resArray.length; i++) {
    if (resArray[i] !== "") {
      res = res + resArray[i][0].toUpperCase() + resArray[i].slice(1);
    }
  }
  return res;
}

function generateHashTag2(str) {
  let words = str.split(" ");
  words = words.map((item) => {
    if (item.length != 0) {
      // return item.replace(item[0], item[0].toUpperCase());
      return item.charAt(0).toUpperCase() + item.slice(1);
    }
  });
  words = words.join("");
  words = `#${words}`;
  return words;
}

// console.log(generateHashTag2("go and watch panchayat web     series."));

// count of given char from string.
function countChar(str, key) {
  let c = 0;
  for (let i = 0; i < str.length; i++) {
    if (str[i] === key.toLowerCase() || str[i] === key.toUpperCase()) c++;
  }
  return c;
}

function countChar2(str, key) {
  str = str.toLowerCase();
  key = key.toLowerCase();

  arr = str.split("");
  return arr.reduce((acc, char) => {
    if (char === key) {
      acc++;
    }
    return acc;
  }, 0);
}
// console.log(countChar2("MissIssippi", "I"));

// function to sort an array in ascending order

function bubbleSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let flag = false;
    for (let j = 1; j < arr.length; j++) {
      if (arr[j - 1] > arr[j]) {
        let temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        flag = true;
      }
    }
    if (flag === false) break;
  }
  return arr;
}

function sortAscending(arr) {
  return arr.sort((a, b) => a - b);
}

function sortDescending(arr) {
  return arr.sort((a, b) => b - a);
}
// console.log(sortDescending([12, 23, 6, 9, 29, 14]));

function isPalindrome(str) {
  str = str.trim();
  let input = "";
  for (let i = 0; i < str.length; i++) {
    let char = str[i];
    if ((char >= "a" && char <= "z") || (char >= "A" && char <= "Z")) {
      input += char;
    }
  }
  input = input.toLowerCase();
  let i = 0;
  let j = input.length - 1;
  while (i < j) {
    if (input[i] !== input[j]) return false;
    i++;
    j--;
  }

  return true;
}

console.log(isPalindrome("A man, a plan, a canal, Panama"));
