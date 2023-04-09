function threeNumberSort(array, order) {

if(array.length === 0) return [];

const first = order[0];
const last = order[order.length - 1];

let left = 0;
let right = array.length - 1;

while(left < right){

  if(array[left] === first) left++;
  else if(array[right] !== first) right--;
  else if(array[left] !== first && array[right] === first){

    const temp = array[left];
    array[left] = array[right];
    array[right] = temp;
    left++;
    right--;
  }
  else left++;
}

left = 0;
right = array.length - 1;

while(left < right){

  if(array[left] !== last) left++;
  else if(array[left] === last && array[right] !== last){

    const temp = array[right];
    array[right] = array[left];
    array[left] = temp;
    left++;
    right--;
  }
  else right--;
}

return array;
}


const array = [1, 0, 0, -1, -1, 0, 1, 1];
const order = [0, 1, -1];

const sortedArray = threeNumberSort(array, order);

console.log(sortedArray);

// Do not edit the line below.
exports.threeNumberSort = threeNumberSort;


