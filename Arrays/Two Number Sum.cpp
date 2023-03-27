#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
  int length = sizeof(array)/sizeof(int);

  vector<int> sums;

  for(auto it = array.begin(); it != array.end(); it++)
  {
      for(auto ik = array.begin(); ik != array.end(); ik++)
      {
        if(*it + *ik == targetSum && *it != *ik)
        { 
          sums.push_back(*it); 
        }
      }
}
  
  return{sums};
}