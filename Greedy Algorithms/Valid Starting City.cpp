#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
  // Write your code here.

  int mpg_left = 0, currentCity = 0, startCity = 0;

  for(int i = 0; i < distances.size()*2; i++){

    int j = i%distances.size();

    currentCity = j;

    mpg_left+= mpg * fuel[j];
    mpg_left = mpg_left - distances[j];

    if(mpg_left < 0){

      startCity = (startCity + 1)%distances.size();
      i = startCity-1;
      mpg_left = 0;
    }

    else if(mpg_left >= 0 && currentCity == startCity && i > distances.size()-1) return startCity;
  }
  return -1;
}
