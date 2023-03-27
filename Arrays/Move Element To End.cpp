#include <vector>
#include <iostream>

using namespace std;

vector<int> moveElementToEnd(vector<int> &array, int toMove) {
  
  // Write your code here.

  int left = 0, right = array.size()-1;

  int temp;

  while(left < right){

    if(array[left] == toMove && array[right] != toMove){

      array[left] = array[right];
      array[right] = toMove;
      right--;
      left++;
    }

    else if(array[left] != toMove)left++;

    else if(array[right] == toMove)right--;

  }
  
  return array;
}