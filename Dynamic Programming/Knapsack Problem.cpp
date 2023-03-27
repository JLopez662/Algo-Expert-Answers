#include <vector>
#include <iostream>
using namespace std;

void findAdded(int x, int y, int capacity, vector<vector<int>> &items, vector<vector<int>> &values, vector<int> &itemAdd){

  if(x < 0 || y <= 0)return;

  if(x == 0){
    if(values[x+1][0] >0)itemAdd.push_back(x);
    return;
  }

  if(values[x][y] != values[x-1][y]){
    itemAdd.push_back(x-1);

    findAdded(x-1, y - items[x-1][1], capacity, items, values, itemAdd);
  }

  else findAdded(x-1, y, capacity, items, values, itemAdd);
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  // Write your code here.
  // Replace return below.

  vector<vector<int>> values(items.size()+1, vector<int>(capacity+1));

  int value = 0, weight = 1, maxValue = 0;

  for(int item = 1; item <= items.size(); item++){

    for(int mag = 0; mag <= capacity; mag++){

      if(items[item-1][weight] <= mag){

        values[item][mag] = max(values[item-1][mag], values[item-1][mag - items[item-1][weight]] + items[item-1][value]);
      }

      else values[item][mag] = values[item-1][mag];

      if(maxValue < values[item][mag]) maxValue = values[item][mag];
    }
  }

  
  vector<int> itemAdd;

  findAdded(values.size()-1, capacity, capacity, items, values, itemAdd);
  
  return {
      {maxValue},   // total value
      {itemAdd}, // item indices
  };
}