let object = {
  k1: "value1",
  k2: "value2",
  k3: "value3",
};
let c = 0;
for (let key in object) {
  console.log(key + " ---> " + object[key]);
  c++;
}
console.log(c);
