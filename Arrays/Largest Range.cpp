#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Write your code here.

  sort(array.begin(), array.end());

  int maxLength = 0, currLen = 0;

  int start = array[0], end = array[0];

  int startIdx = 0, size = array.size();

  for(int i = 1; i < size; i++){

    if(array[i-1] == array[i]) continue;

    if(array[i-1] +1 != (array[i]) ) startIdx = i;

    else{

      currLen = i - startIdx +1;

      if(currLen > maxLength){

        maxLength = currLen;
        start = array[startIdx];
        end = array[i];
      }
    }
  }
return {start, end};
}
