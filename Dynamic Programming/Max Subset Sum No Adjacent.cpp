#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.

  if(array.empty())return 0;

  if(array.size() ==1)return array[0];

  int maxInt = -1;

  int sum = 0;

  vector<int> maxSums(array.size(), 0);

  for(int i = 0; i < array.size(); i++){

    if(i-2 >= 0)sum = max(maxSums[i-2] + array[i], maxSums[i-1]);
      

    else if(i-1 >= 0)sum = max(maxSums[i-1], array[i]);
      
      
    else sum = array[i];
      

    maxSums[i] = sum;

    if(sum >= maxInt) maxInt = sum;

  }
  
  return maxInt;
}