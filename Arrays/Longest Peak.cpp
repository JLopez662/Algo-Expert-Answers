#include <vector>
#include <iostream>

using namespace std;

int longestPeak(const vector<int>& array){
  int peak = 1, right = 0, left = 0;

  if(array.size() < 3) return 0;

  int maxLength = 0;

  while(peak < array.size()-1){

    if(array[peak-1] < array[peak] && array[peak] > array[peak+1]){

      left = peak;
      right = peak;

      while(left > 0 && array[left -1] < array[left])left--;

      while(right < array.size()-1 && array[right] > array[right+1]) right++;

      maxLength = max(maxLength, right - left +1);

      peak = right;
    }

    else peak++;
  }
  return maxLength;
  
}