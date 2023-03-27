#include <vector>
#include <iostream>

using namespace std;

bool isSorted(vector<int>array){
  for (int i = 0; i < array.size()-1; i++){
    
    if(array[i] > array[i+1]) return false;
  }
  return true;
}

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.

  if (isSorted(array) == 1) return array;
  
  int size = array.size();

  while(size > 1){
    
    for(int i = 0; i <size-1; i++){
      int temp = 0;

      if(array[i] > array[i+1]){
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
      }
    }
    size--;
  }
  
  return array;
}
