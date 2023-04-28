
#include <stack>
using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.

    if(str == "") return true;

    stack<char> palStack;

    for(char elem : str){

        if(elem == '(' || elem == '{' || elem == '[' ) palStack.push(elem);

        else if(elem == ')' || elem == '}' || elem == ']'){

            if(palStack.empty()) return false;

            else if(elem == ')' && palStack.top() == '(') palStack.pop();
            else if(elem == '}' && palStack.top() == '{') palStack.pop();
            else if(elem == ']' && palStack.top() == '[') palStack.pop();
            
            else return false;
        }
    }
    return palStack.empty();
}
