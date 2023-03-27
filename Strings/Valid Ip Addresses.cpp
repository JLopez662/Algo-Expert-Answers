#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool validIp(string str){

  if(stoi(str) > 255 || (str.size() > 1 && str[0] == '0') || str.size() > 3) return false;

  return true;
}

vector<string> validIPAddresses(string str) {
  // Write your code here.

  vector<string> ipAddresses;

  vector<string>ipParts(4, "");

  int dots = 0;

  string result = "";

  for (int i = 1; i < min(static_cast<int>(str.size()), 4); i++){

    ipParts[0] = str.substr(0, i);

    if (!validIp(ipParts[0]))continue;

    for(int j = i+1; j < i + min(static_cast<int>(str.size()) -i, 4); j++ ){

      ipParts[1] = str.substr(i, j-i);

      if(!validIp(ipParts[1]))continue;

      for (int k = j+1; k < j + min(static_cast<int>(str.size()) - j, 4); k++){

        ipParts[2] = str.substr(j, k-j);

        ipParts[3] = str.substr(k);

        if(validIp(ipParts[2]) && validIp(ipParts[3])){

          for(int p = 0; p < ipParts.size(); p++){

            if(dots < 3){
              result = result + ipParts[p] + '.';
              dots++;
            } 
            else result += ipParts[p];
          }
          dots = 0;

          ipAddresses.push_back(result);

          result = "";
        }
      }
    }
  }
  
  return ipAddresses;
}