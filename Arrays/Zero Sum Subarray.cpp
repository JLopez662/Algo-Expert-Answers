#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool zeroSumSubarray(vector<int> nums) {
  // Write your code here.

  unordered_set<int> Sums;

  int currentSum = 0;

  for(auto it : nums){

    currentSum += it;

    if(currentSum == 0 || Sums.find(currentSum) != Sums.end())return true;
    
    else Sums.insert(currentSum);
  }

  return false;
}