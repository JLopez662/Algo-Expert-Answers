#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  if (n == 0) {
    return 0;
  }

  vector<int> minChange(n + 1, INT_MAX);
  minChange[0] = 0;

  for (int i = 0; i < denoms.size(); i++) {
    for (int k = denoms[i]; k <= n; k++) {
      if (minChange[k-denoms[i]] != INT_MAX) {
        minChange[k] = min(minChange[k], 1 + minChange[k - denoms[i]]);
      }
    }
  }

  return (minChange[n] == INT_MAX) ? -1 : minChange[n];
}