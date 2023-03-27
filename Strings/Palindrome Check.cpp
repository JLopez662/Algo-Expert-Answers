#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
  
  int len = str.size(), i = 0, mid = len/2;

  stack<char> S;

  char letter;

  for(i; i < mid; i++)
  { 
    S.push(str[i]); 
  }

  if(len %2 != 0){ i++;}

  while(str[i] != '\0')
    {
      letter = S.top(); 
      S.pop();

      if(letter != str[i]){ return false; }
      
      i++;
    }
  return true;
}