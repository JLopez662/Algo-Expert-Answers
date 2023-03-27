#include <vector>
#include <iostream>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.

  for(int i = 0; i < array.size(); i++){
    int &current = array[i];
    int min = array[i];
    cout << "min: " << min << endl;

    int x = i+1;

    for(; x < array.size(); x++){
      
      if(min > array[x]) min = array[x];

      if(min != current){
      int temp = array[i];
      array[i] = min;
      array[x] = temp;
      }

    }
  
  }
  return array;
}

int main()
{
  //vector<int> array = {8, 5, 2};

  vector<int> array = {8, 5, 2, 9, 5, 6, 3};

  
  for (auto it: selectionSort(array)) cout << it << " ";
}