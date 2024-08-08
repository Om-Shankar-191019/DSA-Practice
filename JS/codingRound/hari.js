function sumToN(n) {
  let sum = 0;
  for (let i = 1; i <= n; i++) sum += i;
  return sum;
}

function sumToN2(n) {
  return (n * (n + 1)) / 2;
}

console.log(sumToN2(100));
