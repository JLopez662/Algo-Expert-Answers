#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.

  string sortedWord = "", current = "";

  unordered_map<string, vector<string> > anagrams;

  
  for(int i = 0; i < words.size(); i++){

    sortedWord = words[i];
      
    sort(sortedWord.begin(), sortedWord.end());

    anagrams[sortedWord].push_back(words[i]);
 
  } 

  vector<vector<string>> result(anagrams.size());

  int index = 0;

  for(auto word : anagrams){

    result[index] = word.second;

    index++;
    
  } 

  return result;
}
