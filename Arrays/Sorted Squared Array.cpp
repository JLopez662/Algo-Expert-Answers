#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) 
{
  int data = 0, y = 0, start =0, end = array.size()-1;

  vector<int> sorted;

  for(auto it = array.begin(); it != array.end(); it++)
    {
      y = *it;
      y = pow(y,2);
      *it = y;
    }

  // 1, 2, 3 -> 4 <- 5, 6

  // 

  while(start != end)
    {
      if(array[start] >= array[end])
      {
        sorted.push_back(array[start]);
        start++;
      }
      else 
      {
        sorted.push_back(array[end]);  //end = array.size()-1;
        end--;
      }
    }
  
  if(start == end){ sorted.push_back(array[start]); }

  reverse(sorted.begin(), sorted.end());

  return sorted;
}