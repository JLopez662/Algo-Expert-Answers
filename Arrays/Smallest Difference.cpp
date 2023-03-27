#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.

  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());

  int first = 0, second = 0;
  int pointer1 = 0, pointer2 = 0;

  int diff = INT_MAX;

  while(first != arrayOne.size() && second!= arrayTwo.size()){

    if(abs(arrayOne[first] - arrayTwo[second]) == 0 )return {arrayOne[first], arrayTwo[second]};

    else{
      if(abs(arrayOne[first] - arrayTwo[second]) < diff){

        diff = abs(arrayOne[first] - arrayTwo[second]);
        pointer1 = first;
        pointer2 = second;
      } 
    }

  if (arrayOne[first] < arrayTwo[second]) first++;
  else second++;
    
  }
  
  return {arrayOne[pointer1], arrayTwo[pointer2]};
}