#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWordsInString(string str) {
  // Write your code here.

  str = ' ' + str;

  vector<int> whitespaces;

  for(int i = 0; i < str.size(); i++) if(str[i] == ' ') whitespaces.push_back(i);

  vector<string>words;

  for(int i = 0; i < whitespaces.size(); i++){

    words.push_back(str.substr(whitespaces[i]+1, whitespaces[i+1] - whitespaces[i]-1));
  }

  string reversed;

  for(int i = words.size()-1; i >= 0; i--){

    if(i > 0)reversed += words[i] + ' ';

    else reversed += words[i];
  }
  return reversed;
}