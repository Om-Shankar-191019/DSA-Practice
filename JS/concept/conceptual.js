// prototypal inheritance -------------
let pencil = {
  a: "vouch",
  b: "sakala",
};

let pen = {
  a: "renold",
  b: "gel",
};

let pp = Object.create({ ...pencil, ...pen, d: "takala" });
pp.c = "asdf";

// console.log(pp.a, pp.b, pp.c, pp.d);
