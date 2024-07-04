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
console.log(findLongestWord("go and watch panchayat wet     series."));
