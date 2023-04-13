function BinarySearchHelp(array, target, left, right){
    if(left <= right){

        let mid = Math.floor(left+right/2);

        if(array[mid] == target) return mid;

        else if (array[mid] > taret) return BinarySearchHelp(array, target, left, mid-1);

        else if(array[mid] < target) return BinarySearchHelp(array, target, mid+1, right);

        return -1;
    }
}

function binarySearch(array, target){
    return BinarySearchHelp(array, target, 0, array.length - 1);
}

