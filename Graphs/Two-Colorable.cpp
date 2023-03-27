#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool twoColorable(vector<vector<int>> edges) {
  // Write your code here.

  vector<int> color(edges.size(), 0);

  int green = 1, blue = 2;

  for(int index = 0; index < edges.size(); index++){
    
    if(color[index]== 0)color[index] = green;

    for(int col = 0; col < edges[index].size(); col++){
      
      int node = edges[index][col];
      
      if(color[node]==0) color[node] = color[index] == green ? blue : green;

      if(color[node] == color[index])return false;
    }
  }
  return true;
}
