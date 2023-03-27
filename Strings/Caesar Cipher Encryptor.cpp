#include <iostream>
#include <string>
#include <vector>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.

  vector<int> wordToAscii;

  for(char c : str){
    if(int(c+key) > 122 ) wordToAscii.push_back(int( ( (c + key - 97) %26 )+ 97  ) );
   
    else wordToAscii.push_back(int( c + key ));
  }

  string word;

  for(int ascii: wordToAscii) word += char(ascii);

  return word;
}