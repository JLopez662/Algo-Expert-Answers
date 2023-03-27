#include <any>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)


int productSumHelp(vector<any> array, int depth)
{
  
  //Find a way to pass just the parts of the array you haven't checked yet.

  //Don't pass the part of the array already in sum

  int sum = 0;

  for (int run = 0; run < array.size(); run++)
  {
    if((array[run].type() == typeid(vector<any>)) ) 
      sum+= (productSumHelp(any_cast<vector<any>>(array[run]), depth+1));
    
    else if( (array[run].type() == typeid(int) ) ) 
      sum+= ( any_cast<int>(array[run]) );
    
  }
  return depth * sum;
}

int productSum(vector<any> array) 
{
  // Write your code here.
  return productSumHelp(array, 1);
}


