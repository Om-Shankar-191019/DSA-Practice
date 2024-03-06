const id = Symbol("id");

let person = {
  name: "om",
  [id]: 1,
};

console.log(Symbol.for("id"));
