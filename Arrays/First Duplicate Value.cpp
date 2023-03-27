#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
using namespace std;

int firstDuplicateValue(vector<int> array) {

  unordered_map<int, vector<int> > values;

  for(int i = 0; i < array.size(); i++){

    if(values.count(array[i]) == 0){
      vector<int> newItem = {array[i]};
      values.insert(make_pair(array[i], newItem));
    }
    else if(values.count(array[i]) == 1) return array[i];
  }
  return -1; 
}