#include <iostream>
#include <string>
#include <map>
using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.

  map<char, int> docDictionary;

  for(char letter : document){

    if(docDictionary.count(letter) == 0) docDictionary[letter] = 1;
  
    else docDictionary[letter]++;
  }

  cout << "Map for document" << endl; 
  for(auto it : docDictionary) cout << it.first << " " << it.second << endl;
  cout << endl;

  map<char, int> charDictionary;
  
  for(char letter : characters){

    if(charDictionary.count(letter) == 0) charDictionary[letter] = 1;
  
    else charDictionary[letter]++;
  }

  cout << "Map for characters" << endl;
  for(auto it : charDictionary) cout << it.first << " " << it.second << endl;
  cout << endl;

  for(auto frequency : docDictionary){
    if(charDictionary.count(frequency.first) == 0) return false;

    if(charDictionary.at(frequency.first) < frequency.second) return false;
  }

  return true;
}