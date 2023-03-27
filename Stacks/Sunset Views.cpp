#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
  // Write your code here.

  vector<int> result;

  stack<int> stack, Ordered;

  int maxHeight = 0;

  if(direction == "EAST"){

    for(int i = 0; i < buildings.size(); i++){
  
      if(stack.empty())stack.push(i);
  
      if(buildings[stack.top()] <= buildings[i]){
  
        stack.pop();

        if(!stack.empty()) i--;

        else stack.push(i);
      }
      else stack.push(i);
    }
    
    while(!stack.empty()){

      Ordered.push(stack.top());
      stack.pop();
    }

    while(!Ordered.empty()){
  
      result.push_back(Ordered.top());
      Ordered.pop();
    }
  }  

  else {

    for(int i = buildings.size()-1; i >= 0; i--){

      if(stack.empty())stack.push(i);

      if(buildings[stack.top()] <= buildings[i]){

        stack.pop();

        if(!stack.empty())i++;

        else stack.push(i);
      }
      else stack.push(i);
    }

    while(!stack.empty()){

      result.push_back(stack.top());
      stack.pop();
    }
  }

  return result;
}