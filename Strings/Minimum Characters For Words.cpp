#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
  // Write your code here.

  vector<unordered_map<char, int>>characters;
  
  for(int i = 0; i < words.size(); i++){

    unordered_map<char, int> charMap;

    for(int k = 0; k < words[i].size(); k++){

      charMap[words[i][k]]++;
     }
    characters.push_back(charMap);
    charMap.clear();
  }

  unordered_map<char, int>eachChar;

  for(auto charMap : characters){

    for(auto it : charMap){

      char key = it.first;
      int value = it.second;

      if(eachChar.count(key) == 0 || eachChar[key] < value){

        eachChar[key] = value;
      }
    }
  }

  vector<char> allChars;

  for(auto it : eachChar){

    for(int i = 0; i < it.second; i++){

      allChars.push_back(it.first);
    }
  }
  
  return allChars;
}