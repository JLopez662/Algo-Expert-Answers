#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getQuickSort(int left, int right, vector<int> &array){

  if(left >= right)return;

  int pivot = left, low = left+1, high = right;

  while(low <= high){

    if(array[low] > array[pivot] && array[high] <= array[pivot]){

      swap(array[low], array[high]);
      low++;
      high--;
    }

    else if(array[low] <= array[pivot]) low++;

    else if(array[high] > array[pivot]) high--;
  }

  swap(array[pivot], array[high]);
  swap(pivot, high);

  getQuickSort(left, pivot-1, array);
  getQuickSort(pivot+1, right, array);

  return;
}


vector<int> quickSort(vector<int> array) {
  // Write your code here.

  if(array.size() < 2)return array;

  if(array.size() == 2){

    if(array[0] > array[1])swap(array[0], array[1]);
  }

  getQuickSort(0, array.size()-1, array);
  
  return array;
}
