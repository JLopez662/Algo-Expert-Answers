#include <stack>
#include <iostream>
#include <climits>

using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {

private:
  stack<int> stack;

public:
  int peek() {
    // Write your code here.
    if (stack.empty()) return -1;
    return stack.top();
  }

  int pop() {
    // Write your code here.
    if(stack.empty())return -1;

    int min = getMin();

    int max = getMax();
    
    int popped = stack.top();
    stack.pop();
    
    return popped;
  }

  void push(int number) {
    // Write your code here.

    int min = getMin();

    int max = getMax();
    
    stack.push(number);
    
  }

  int getMin() {
    // Write your code here.

    if(stack.empty())return -1;

    int current = stack.top();

    stack.pop();

    int min =  INT_MAX;

    if(current > getMin() && getMin() != -1) min = getMin();

    else min = current;

    stack.push(current);
    
    return min;
  }

  int getMax() {
    // Write your code here.

    if(stack.empty())return -1;

    int current = stack.top();

    stack.pop();

    int max = INT_MIN;

    if(current < getMax() ) max = getMax();

    else max = current;

    stack.push(current);
    
    return max;
  }
};
