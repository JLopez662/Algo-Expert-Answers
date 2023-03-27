#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &matrix, int x, int y, int &size){

  int height = matrix.size(), width = matrix[0].size();

  if((x >= 0 && x < height) && (y >= 0 && y < width)){

    if(matrix[x][y]==1){

      matrix[x][y] = -1;
      size++;

      dfs(matrix, x, y-1, size);
      dfs(matrix, x, y+1, size);
      dfs(matrix, x-1, y, size);
      dfs(matrix, x+1, y, size);
    }
  }
}

vector<int> riverSizes(vector<vector<int>> matrix){
  //Write your code here
  vector<int> rivers;

  int height = matrix.size(), width = matrix[0].size();
  int riverLength = 0;

  for(int y = 0; y < height; y++){

    for(int x = 0; x < width; x++){

      if(matrix[y][x] == 1){

        riverLength = 0;
        dfs(matrix, y, x, riverLength);
        rivers.push_back(riverLength);
      }
    }
  }
  return rivers;
}
