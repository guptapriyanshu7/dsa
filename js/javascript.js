function is_even(arr) {
  return arr.filter(function (i) {
    return i % 2 === 0;
  });
}
var arr = [1, 2, 3];
console.log(is_even(arr));
function sq(arr) {
  return arr.reduce(function (prev, curr) {
    return prev + curr * curr;
  }, 0);
}
console.log(sq(arr));
function bool(arr, criteria) {
  return arr.filter(function (i) {
    return !criteria(i);
  });
}
console.log(bool(arr, criteria));
function criteria(num) {
  return num % 2 == 0;
}
console.log(criteria(1));
