import { Access } from "./labo";

let d: Access = { modelo(x, y) {
  return x*y;
},};

console.log(d.modelo(2, 6));
