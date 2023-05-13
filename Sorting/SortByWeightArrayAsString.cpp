#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int calculateWeight(int num){

  int sum = 0;

  while(num > 0){
    sum += num % 10; //last digit
    num /= 10; // equals previous digit
  }
  return sum;
}


bool sorter(int a, int b){
  int weightA = calculateWeight(a), weightB = calculateWeight(b);

  //return ascii comparisons if weights are tied
  if(weightA == weightB)return to_string(a) < to_string(b);

  return weightA < weightB; //return lowest weight comparison
}



string sortAndPrint(string numbers){

  //receives as input the elements from the string using sstream
  istringstream iss(numbers); //input stringstream
  int eachNum;
  vector<int> numbersList;

  //while each element is extracted to eachNum as input is true
  while(iss >> eachNum) numbersList.push_back(eachNum);

  //sorter defines how the sort will work
  sort(numbersList.begin(), numbersList.end(), sorter);
  
  ostringstream oss; //output stringstream

  for(int i = 0; i < numbersList.size(); i++){
    oss << numbersList[i] << " "; //cout inside the array as a character
  }
  return oss.str(); //return a string copy of the sorted array
}

int main(){
  string input = "56 65 74 100 99 68 86 180 90";
  string sortedStr = sortAndPrint(input);
  cout << sortedStr << endl;
  return 0;
}

