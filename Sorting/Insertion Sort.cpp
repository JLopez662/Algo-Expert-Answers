#include <vector>
#include <iostream>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  for (int i = 1; i < array.size(); i++) {
    int key = array[i];
    int j = i - 1;
    
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  return array;
}
