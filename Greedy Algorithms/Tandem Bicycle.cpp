#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) 
{
  int sum = 0;

  int size = redShirtSpeeds.size();
  
  // Write your code here.
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

  if(fastest == true)
  {
    reverse(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    
    for(int i = 0; i < size; i++ )
    {
      if(redShirtSpeeds[i] > blueShirtSpeeds[i]) sum += redShirtSpeeds[i];
      else sum+= blueShirtSpeeds[i];
    }
  }

  else
  {
    for(int i = 0; i < size; i++ )
    {
      if(redShirtSpeeds[i] >= blueShirtSpeeds[i]) sum += redShirtSpeeds[i];
      else sum+= blueShirtSpeeds[i];
    }
  }

  return sum;
