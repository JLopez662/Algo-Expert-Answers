#include <vector>
#include <iostream>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.

  if(array.size() <2)return array[0];

  int maxSum = 0, Sum = 0;

  vector<int> maxSubArray;

  for(int i = 0; i < array.size(); i++){

    if(Sum < 0) Sum = 0;

    Sum = Sum + array[i];

    if(Sum > maxSum) maxSum = Sum;
  }

  if(maxSum == 0)return -1;

  return maxSum;
}