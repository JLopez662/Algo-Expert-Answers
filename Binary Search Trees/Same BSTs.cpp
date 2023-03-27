#include <iostream>
#include <vector>

using namespace std;

vector<int> getLower(vector<int> array) {
  vector<int> arrayLower;

  int root = array[0];

  for (auto it : array) 
  {
    if (root > it) arrayLower.push_back(it);
  }

  // Special case where the root is equal to a child node
  if(arrayLower.empty() && root == array[1])
  {
    for(int i = 2; i < array.size(); i++)arrayLower.push_back(array[i]);
  }

  return arrayLower;
}

vector<int> getHigher(vector<int> array) {
  vector<int> arrayHigher;

  int root = array[0];

  for (auto it : array) {
    if (root < it) arrayHigher.push_back(it);
  }
  
  // Special case where the root is equal to a child node
  if(arrayHigher.empty() && root == array[1]){
    for(int i = 2; i < array.size(); i++) arrayHigher.push_back(array[i]);
  }
  
  return arrayHigher;
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.

  if (arrayOne.size() != arrayTwo.size())return false;
    
  if (arrayOne.size() == 0 && arrayTwo.size() == 0)return true;
    
  if (arrayOne[0] != arrayTwo[0])return false;
    
  vector<int> arrayOneLower = getLower(arrayOne);

  vector<int> arrayTwoLower = getLower(arrayTwo);

  vector<int> arrayOneHigher = getHigher(arrayOne);

  vector<int> arrayTwoHigher = getHigher(arrayTwo);

  return sameBsts(arrayOneLower, arrayTwoLower) && sameBsts(arrayOneHigher, arrayTwoHigher);
}