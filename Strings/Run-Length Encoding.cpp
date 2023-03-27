#include <string>
#include <iostream>

using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  
  string decode;
  char encode;

  int repeats = 0;
  
  for(int i = 0; i < str.size(); i++){
    char encode = str[i];

    if(str[i-1] > -1 && str[i-1] != str[i]) repeats = 1;
    
    if(str[i] == str[i+1]){
      
      if(repeats == 9){
        decode.push_back(char(repeats + 48));
        decode.push_back(encode);
        repeats = 0;
      }
      
      repeats++;
    }

    else{

        decode.push_back(char(repeats + 48));
        decode.push_back(encode);
    }
  }
  
  return decode;
}