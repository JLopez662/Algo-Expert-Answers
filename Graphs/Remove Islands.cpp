#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& matrix, int i, int j, int height, int width){

  if(i < 0 || i >= height || j < 0 || j >= width || matrix[i][j] != 1) return;

  matrix[i][j] = -1;

  dfs(matrix, i-1, j, height, width);
  dfs(matrix, i+1, j, height, width);
  dfs(matrix, i, j-1, height, width);
  dfs(matrix, i, j+1, height, width);

}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  
  int height = matrix.size(), width = matrix[0].size();

  // Mark all the connected components on the borders
  for(int i = 0; i < matrix.size(); i++){

    // moves down first column
    if(matrix[i][0] == 1) dfs(matrix, i, 0, height, width);

    // moves down last column
    if (matrix[i][width-1] == 1) dfs(matrix, i, width-1, height, width);

    // moves right first row
    if(matrix[0][i] == 1) dfs(matrix, 0, i, height, width);

    // moves right last row
    if(matrix[height-1][i] == 1) dfs(matrix, height-1, i, height, width);

  }

  // Replace all remaining 1s with 0s
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(matrix[i][j] == 1) matrix[i][j] = 0;
    }
  }

  // Replace all -1s with 1s
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(matrix[i][j] == -1) matrix[i][j] = 1;
    }
  }

  return matrix;
}