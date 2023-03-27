#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


bool oneEdit(string stringOne, string stringTwo) {
  // Write your code here.

  if(stringOne == stringTwo)return true;

  if(stringOne.size() > stringTwo.size() +1 || stringOne.size() +1 < stringTwo.size())return false;

  if(stringOne.size() == stringTwo.size()){

    string replace;

    for(int i = 0; i < stringOne.size(); i++){

      if(stringOne[i] != stringTwo[i]) replace += stringOne[i];
    }

    if(replace.size() > 1)return false;
  }

  else{ //(stringOne.size() != stringTwo.size())

    string remaining;

    int size = max(stringOne.size(), stringTwo.size());

    for(int i = 0; i < size; i++){

      if(stringOne[i] != stringTwo[i]){

        if(size == stringOne.size())remaining+= stringOne[i];

        else remaining+=stringTwo[i];
      }
    }
    if(remaining.size()>1 && stringOne[stringOne.size()-1] != stringTwo[stringTwo.size()-1])return false;
  }
  
  return true;
}