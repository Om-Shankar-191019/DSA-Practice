let a = {
  name: "om shankar",
  age: 24,
};

let lab = {
  labname: "chemistry",
  labsize: 45,
  chemicals: 293,
};

let car = {
  carname: "mercedies",
  carprice: "4 crore",
  carmodel: "xtw56",
};

a.__proto__ = lab;
lab.__proto__ = car;

console.log(a.carmodel);
