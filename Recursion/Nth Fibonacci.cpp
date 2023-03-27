#include <iostream>
#include <vector>

using namespace std;

int getNthFib(int n) 
{
  int index = 0;
  
  vector<int> cache(n);
  
  // Write your code here.

  for(int i = 0; i < 2; i++){ cache[i] = i; }  

  int m = n-1;

  if(n <= 2) { index = cache[m]; }

  else if (n > 2 )
  {
    cache[m] = getNthFib(n-1) + getNthFib(n-2);
    index = cache[m];
  }

  return index;
}
