#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) 
{

  int i = 0;

  if(sequence.size() > array.size()){return false;}

  for(auto it = array.begin(); it != array.end(); it++)
    {
      if(i == sequence.size() ){ break; }

      if(sequence[i] == *it){ i++; }
    }
  
  return (i == sequence.size());
}