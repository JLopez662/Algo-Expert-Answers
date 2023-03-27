#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


vector<vector<string>> semordnilap(vector<string> words) {
  // Write your code here.

  //Set to check presence of duplicates
  unordered_set<string> word_set(words.begin(), words.end());

  vector<vector<string>> reversePal;

  string reverse;

  for(int i = 0; i < words.size(); i++){

    //make the word backwards
    reverse = "";
    for(auto word = words[i].rbegin(); word != words[i].rend(); word++){
      
      reverse.push_back(*word);
    }

    //make sure word is not a palindrome, and that it can be found in the set
    if(reverse != words[i] && word_set.find(reverse)!= word_set.end())
    {
      //insert the semordnilap pair
      reversePal.push_back({words[i], reverse});

      //remove words from set to not consider adding them again
      word_set.erase(words[i]);
      word_set.erase(reverse);
    }
   
  }
  return reversePal;
}