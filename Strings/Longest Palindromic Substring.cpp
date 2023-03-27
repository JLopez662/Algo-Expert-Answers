#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int getMaxKey(int left, int right, unordered_map<int, string> &palindromeTable, string &str, int &maxSize ){

  int largestKey = 0;

  for(int i = 0; i < str.size(); i++){

    string palindrome = "";

    if(str[left] == str[right] && right < str.size()){

      while(left-1 >= 0 && right+1 < str.size() && str[left-1] == str[right+1]){

        left--;
        right++;
      }

      for(int k = left; k <= right; k++) palindrome+=str[k];

      if(maxSize < palindrome.size()){
  
        palindromeTable[palindrome.size()] = palindrome;
  
        for(auto it : palindromeTable){
  
          if(it.first > largestKey) largestKey = it.first;
        }
      }
    }
  }
  return largestKey;
  
}

string longestPalindromicSubstring(string str) {
  // Write your code here.

  if(str.size() <=1) return str;

  int left = 0, right = 0, largestKey = 0, maxSize = 0;

  unordered_map<int, string> palindromeTable;

  for(int i = 0; i < str.size(); i++){

    int key = getMaxKey(i-1, i+1, palindromeTable, str, maxSize);
    
    if(largestKey < key)largestKey = key;
  
    key = getMaxKey(i, i+1, palindromeTable, str, maxSize);
  
    if(largestKey < key)largestKey = key;
  } 
  
  return palindromeTable[largestKey];
}
