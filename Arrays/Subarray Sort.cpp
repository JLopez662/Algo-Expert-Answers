#include <vector>
#include <iostream>
#include <climits>
using namespace std;

vector<int> subarraySort(vector<int> array){

  int left = -1, right = -1;

  int max = INT_MIN, min = INT_MAX;

  //finding last position where number is smaller than the max number
  for(int i = 0; i < array.size(); i++){
    if(array[i] >= max) max = array[i];

    else right = i;
  }

  //finding last position where a number is larger than min number
  for(int i = array.size()-1; i >= 0; i--){
    if(array[i] <= min) min = array[i];

    else left = i;
  }

  return {left, right};
}

int main(){
  vector<int> array = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
  for(auto it : subarraySort(array)) cout << it << " ";
  // output: 3 9
}
