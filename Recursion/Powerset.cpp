#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> powerset(vector<int> array){

  vector<vector<int>> pSet = {{}};

  for(int i = 0; i < array.size(); i++){

    vector<int> subset = {array[i]};

    pSet.push_back(subset);

    for(int j = i+1; j < array.size(); j++){

      subset.push_back(array[j]);

      pSet.push_back(subset);
    }
  }

  for(int i = 0; i < array.size(); i++){

    vector<int> subArray = vector<int>(array.begin() + i + 1, array.end());

    vector<vector<int>> subPowerSet = powerset(subArray);

    for(auto subset : subPowerSet){

      subset.insert(subset.begin(), array[i]);

      if(find(pSet.begin(), pSet.end(), subset) == pSet.end()) pSet.push_back(subset);
    }
  }

  return pSet;
}