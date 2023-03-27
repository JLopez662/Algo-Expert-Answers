#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.

  if(n == 0)return 1;

  if(denoms.size() ==1){

    if(denoms[0] != n) return 0;
  }

  
  vector<int> waysOfChange((n+1));

  waysOfChange[0] = 1;

  for(int i = 0; i < denoms.size(); i++){

    for(int k = denoms[i]; k <= n; k++){
      
      waysOfChange[k] += waysOfChange[k - denoms[i] ];
    
    }
  }

  return waysOfChange[n];
}