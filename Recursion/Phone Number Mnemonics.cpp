#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

void getmnemonic(int index, string &mnemonic, unordered_map<int, string> &dials, string &phoneNumber, vector<string> &result) {

  if(index >= phoneNumber.size()){
    result.push_back(mnemonic);
    return;
  }

  string letters = dials[phoneNumber[index] - '0']; //1

  for(int i = 0; i < letters.size(); i++){

    string mnemonicBuild = mnemonic + letters[i];
    getmnemonic(index+1, mnemonicBuild, dials, phoneNumber, result);
  }
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  // Write your code here.

  unordered_map<int, string> dials;

  dials[0] = '0';
  dials[1] = '1';
  dials[2] = {'a','b','c'};
  dials[3] = {'d','e','f'};
  dials[4] = {'g','h','i'};
  dials[5] = {'j','k','l'};
  dials[6] = {'m','n','o'};
  dials[7] = {'p','q','r','s'};
  dials[8] = {'t','u','v'};
  dials[9] = {'w','x','y','z'};

  vector<string> result;

  string mnemonic = "";

  getmnemonic(0, mnemonic, dials, phoneNumber, result);
  
  return result;
}