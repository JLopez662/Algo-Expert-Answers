#include <vector>
#include <iostream>
using namespace std;


vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  vector<int> result;

  int totalProduct =  1;

  for(int i = 0; i < array.size(); i++) totalProduct *= array[i];

  for(int i = 0; i < array.size(); i++) array[i] = totalProduct/array[i];
  
  return array;
}
