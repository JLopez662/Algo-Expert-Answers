#include <iostream>
#include <string>
using namespace std;

int firstNonRepeatingCharacter(string string) {
  // Write your code here.
  int index = -1;

  int alphabet[26] = {0};

  //storing repetitions in index (used letters as index)
  for(char letter : string){
    index = (letter - 'a');
    alphabet[index]++;
  }

  char answer;

  //Looking for first unique character
  for(int i = 0; i < string.size(); i++){
    
    index = (string[i] - 'a');

    if(alphabet[index] == 1){
      answer = string[i];
      break;
    }
  }

  //finding index of unique character
  for(int i = 0; i < string.size(); i++){
    
    if(string[i] == answer) return i;
  }
  
  return -1;
}