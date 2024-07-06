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

console.log(generateHashTag("go and watch panchayat web     series."));
