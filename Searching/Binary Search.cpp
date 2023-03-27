#include <vector>
#include <iostream>
using namespace std;

int BinarySearchHelp(vector<int> array, int target, int left, int right)
{
  
  if (left <= right)
  {
    int mid = (left + right)/2;
    
    if(array[mid] == target) return mid;

    else if (array[mid] > target) return BinarySearchHelp(array, target, left, mid -1);
   
    else if (array[mid] < target) return BinarySearchHelp(array, target, mid+1, right );
  }
  return -1;
}

int binarySearch(vector<int> array, int target) 
{
  return BinarySearchHelp(array, target, 0, array.size() );
}

