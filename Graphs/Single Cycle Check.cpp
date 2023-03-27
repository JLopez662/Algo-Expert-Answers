#include <vector>
#include <iostream>
using namespace std;

bool hasSingleCycle(vector<int> array) {
  // Write your code here.

  int size = array.size();

  vector<bool> visited(size, false);

  int current = 0;

  while(visited[current] == false){

    visited[current] = true;

    int jump = ((current + array[current])% size + size)%size;

    current = jump;
  }

  //in case of not returning to first element in the end
  if(current != 0) return false;

  //in case of elements not visited
  for(bool it : visited){
    if(it == false) return false;
  }

  return true;
}