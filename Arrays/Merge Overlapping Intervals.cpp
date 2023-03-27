#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {

  sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
    return a[0] < b[0];
  });

  int size = intervals.size();

  for(int x = 0; x < size-1; x++){

    if(intervals[x][1] >= intervals[x+1][0]){

      intervals[x][1] = max(intervals[x][1], intervals[x+1][1]);

      intervals.erase(intervals.begin() + x + 1);

      size --;

      x--;
    }
  }
  return intervals;
}
