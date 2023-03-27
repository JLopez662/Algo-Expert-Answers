#include <iostream>
#include <vector>

using namespace std;

int getWays(vector<vector<int>> &steps, int i, int k){

  if( i > steps.size() || k > steps[0].size())return 0;
  
  if(steps[i-1][k-1] != 0) return steps[i-1][k-1];

  steps[i-1][k-1] = getWays(steps, i, k-1) + getWays(steps, i-1, k);

  return steps[i-1][k-1];
}

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.

  vector<vector<int>>steps(height, vector<int>(width, 0));

  for(int w = 0; w < width; w++)steps[0][w] = 1;

  for(int h = 0; h < height; h++) steps[h][0] = 1;

  int ways = getWays(steps, height, width);
  
  return ways;
}