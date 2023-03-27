#include <vector>
#include <iostream>
using namespace std;


vector<int> arrayOfProducts(vector<int> array) {
  
  int totalProduct = 1, numZeros = 0;
  
  for (int i = 0; i < array.size(); i++) {
    
    if (array[i] != 0) totalProduct *= array[i];
      
    else numZeros++;
  }
  
  for (int i = 0; i < array.size(); i++) {
    
    if (numZeros > 1 || array[i] != 0){

      if(numZeros > 0) array[i] = 0;

      else array[i] = totalProduct / array[i];
    }
      
    else array[i] = totalProduct;
  }
  return array;
}
