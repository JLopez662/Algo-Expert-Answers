#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.

  vector<vector<int>> sumQuads;
  unordered_map<int, vector<vector<int>> > sumPairs;

  for(int i = 0; i < array.size(); i++){

    for(int after = i+1; after < array.size(); after++){

      int key = array[i] + array[after];
      int difference = targetSum - key;

      if(sumPairs.count(difference)!= 0){

        for(auto firstPair : sumPairs[difference]){
          firstPair.push_back(array[i]);
          firstPair.push_back(array[after]);
          sumQuads.push_back(firstPair);
        }
      }
    }

    for(int before = 0; before < i; before++){

      int newKey = array[i] + array[before];

      if(sumPairs.count(newKey) == 0) sumPairs[newKey] = {{array[before], array[i]}};

      else sumPairs[newKey].push_back({array[before], array[i]});
    }
  }
  
  return sumQuads;
}
