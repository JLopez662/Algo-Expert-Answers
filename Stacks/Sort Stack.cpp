#include <vector>
#include <iostream>
using namespace std;


vector<int> sortStack(vector<int> &stack) {
  // Write your code here.

  if(stack.empty()) return stack;

  int top = stack[stack.size() -1];

  stack.pop_back();

  stack = sortStack(stack);

  if(stack.empty() || stack[stack.size() -1] <= top ) stack.push_back(top);

  else{

    int newTop = stack[stack.size()-1];

    stack.pop_back();

    stack.push_back(top);

    stack = sortStack(stack);

    stack.push_back(newTop);
  }
  
  return stack;
}