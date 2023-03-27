#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.

  vector<vector<int>> Sum;

  sort(array.begin(), array.end());

  int first = 0;

  int index = 0;

  int result = 0, pivot = 0;

  for(int last = 1; last < array.size(); last++)
  {
    pivot = (array[first] + array[last]);
    pivot = -pivot;
    //cout << "pivot: " << pivot << endl;
    if(array[first] <= pivot)
    {
      for(int i = 1; i < last; i++)
      {
        if(pivot == array[i] && pivot != array[first]&& pivot != array[last])
        {
          Sum.push_back(vector<int>());
          //cout << pivot << endl;
          Sum[index].push_back(array[first]);
          Sum[index].push_back(pivot);
          Sum[index].push_back(array[last]);
          
          index++;
        }
      }
      
      if(last == array.size()-1){
        first++;
        last = first+1;
      }
      
    }
    
  }
  
  return Sum;
}