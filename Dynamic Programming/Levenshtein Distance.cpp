#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int levenshteinDistance(string str1, string str2) {

  str1 = " " + str1;
  str2 = " " + str2;
  
  if(str1.size() > str2.size()) return levenshteinDistance(str2, str1);
  
  vector<vector<int>>table(str2.size(), vector<int>(str1.size()));
  
  
  for(int i = 0; i < str2.size(); i++) table[i][0] = i;
  
  for(int k = 0; k < str1.size(); k++) table[0][k] = k;
  
  
  for(int i = 1; i < str2.size(); i++){
  
    for(int k = 1; k < str1.size(); k++){
  
      if(str2[i] == str1[k]) table[i][k] = table[i-1][k-1];
  
      else table[i][k] = 1 + min({table[i][k-1], table[i-1][k], table[i-1][k-1]});
    }
  }
  
  return table[str2.size()-1][str1.size()-1];
}