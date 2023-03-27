#include <vector>
#include <iostream>
using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.

  int left = 0, right = array.size()-1;

  while(left < right){

    if(array[left] < array[right]){
      if(array[left] > array[left+1] )return false;
    }

    if(array[left] > array[right]){
      if(array[left] < array[left+1] )return false;
    }
    left++;
  }
  
  return true;
}