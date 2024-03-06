function counter() {
  let count = 0;
  function increaseCounter() {
    count++;
    return count;
  }
  return increaseCounter;
}

let increase = counter();
let d = counter();


increase();
increase();
increase();
increase();
console.log(increase());
console.log(d());