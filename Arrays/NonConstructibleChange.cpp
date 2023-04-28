#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.

  sort(coins.begin(), coins.end());

  int maxChange = 0, nonChange = 0;

  for(auto coin : coins){
    if(coin <= maxChange +1) maxChange += coin;

    else{
        nonChange = maxChange + 1;
        return nonChange;
    }
  }

  return maxChange +1;
}



