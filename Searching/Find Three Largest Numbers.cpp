#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.

  if(array.size() <=3)
  {
    int start = 0, end = array.size()-1, temp = 0;

    while(start != end)
    {
      if(array[start] > array[end])
      {
        temp = array[end];
        array[end] = array[start];
        array[start] = temp;
      }
      end--;
    }
    
    return array;
  }

  vector<int> triple;

  for(int i = 0; i < 3; i++) triple.push_back(array[i]);

  int start = 0, end = triple.size()-1, temp = 0;

  while(start != end)
    {
      if(triple[start] > triple[end])
      {
        temp = triple[end];
        triple[end] = triple[start];
        triple[start] = temp;
      }
      end--;
    }
  
  for(int it = 3; it < array.size(); it++)
  {
    if (array[it] > triple[2])
    { 
      triple[0] = triple[1];
      triple[1] = triple[2];
      triple[2] = array[it];
    }
      
    else if (array[it] > triple[1])
    {
      triple[0] = triple[1];
      triple[1] = array[it];
    }

    else if (array[it] > triple[0]) triple[0] = array[it];
    
  }
  
  return triple;
}