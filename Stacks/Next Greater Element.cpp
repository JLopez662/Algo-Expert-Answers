#include <stack>
#include <vector>
#include <iostream>

using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  // Write your code here.

  stack<int> stack;

  vector<int> result(array.size(), -1);

  int index = 0, size = 2 * array.size();

  for(int i = 0; i <size; i++){

    int j = i%array.size();

    if(stack.empty()) stack.push(j);

    else if (array[j] > array[stack.top()] ){
        
      result[stack.top()] = array[j];
  
      stack.pop();

      if(!stack.empty())i--;
      
      else stack.push(j);
    }
    else if (array[j] <= array[stack.top()] ) stack.push(j);
  }
  return result;
}