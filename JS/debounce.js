let count = 0;
function counter() {
  count++;
  console.log("current count: ", count);
  return count;
}

function debounce(fx, debounceTime) {
  let id = null;
  return function () {
    if (id) {
      clearTimeout(id);
    }
    id = setTimeout(fx, debounceTime);
  };
}

let showCouter = debounce(counter, 2000);
showCouter();
setTimeout(showCouter, 800);
setTimeout(showCouter, 1600);
setTimeout(showCouter, 5200);
