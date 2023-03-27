#include <vector>
#include <iostream>

using namespace std;

int minRewards(vector<int> scores){

  int size = scores.size();

  int awards = 0;

  vector<int> rewards(size, 1);

  for(int i = 1; i < size; i++){

    if(scores[i-1] < scores[i]) rewards[i] = rewards[i-1]+1;
  }

  for(int i = size-2; i >= 0; i--){

    if(scores[i] > scores[i+1]) rewards[i] = max(rewards[i], rewards[i+1]+1);
  }

  for(auto it : rewards) awards += it;

  return awards;
}
