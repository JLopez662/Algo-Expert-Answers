#include <vector>
#include <iostream>
#include <set>

using namespace std;

void makePermutation(int x, vector<int> &array, set<vector<int>>&permutations){

  if (x == array.size()-1 ) permutations.insert(array);

  else{
    
    for(int i = 0; i < array.size(); i++){

      int temp = array[i];
      array[i] = array[x];
      array[x] = temp;

      makePermutation(x+1, array, permutations);
      
      temp = array[i];
      array[i] = array[x];
      array[x] = temp;

    }
  }
}

set<vector<int>> getPermutations(vector<int> &array) {
  // Write your code here.

  set<vector<int>> permutations;

  makePermutation(0, array, permutations);

  return permutations;
}
