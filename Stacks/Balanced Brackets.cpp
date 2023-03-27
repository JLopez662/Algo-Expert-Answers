#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.

  if(str.empty())return true;

  stack<char>stack;

  for(int i = 0; i < str.size(); i++){

    if(str[i] == '(' || str[i] == '[' || str[i] == '{')stack.push(str[i]);

    else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
      if(!stack.empty())stack.pop();
      
      else return false;
    }
  }
  
  if(stack.empty()) return true;
  else return false;
}
