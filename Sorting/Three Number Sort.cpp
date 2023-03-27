#include <iostream>
#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> &array, vector<int> &order) {
  // Write your code here.

  if(array.empty())return{};

  int first = order[0], last = order[order.size()-1];

  int left = 0, right = array.size()-1;

  while(left < right){

    if(array[left] == first)left++;
    else if(array[right] != first)right--;
    else if (array[left] != first && array[right] ==first){

      int temp = array[left];
      array[left] = array[right];
      array[right] = temp;
      left++;
      right--;
    }
    else left++;
  }
  
  left =0;
  right = array.size()-1;
  
  while(left < right){

    if(array[left] != last)left++;
    else if (array[left] == last && array[right] != last){

      int temp = array[right];
      array[right] = array[left];
      array[left] = temp;
      left++;
      right--;
    }
    else right--;
  }
  
  return array;
}