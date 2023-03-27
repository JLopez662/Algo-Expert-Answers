#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> &matrix) {
  int row = 0, col = 0, pass = -1;

  queue<pair<int, int>> coordinates;

  while(row != matrix.size() && col != matrix[row].size()){

    if(matrix[row][col] > 0 ) coordinates.push({row, col});

    col++;
    if(col == matrix[row].size()){
      row++;
      col = 0;
    }
  }

  int neighbors[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  while(!coordinates.empty()){

    int size = coordinates.size();
    pass++;

    while(size--){
      int x = coordinates.front().first, y = coordinates.front().second;
      coordinates.pop();

      for(auto neighbor : neighbors){
        int rows = x + neighbor[0], cols = y + neighbor[1];

        if(rows >= 0 && rows < matrix.size() && cols >= 0 && cols < matrix[0].size() && matrix[rows][cols] < 0 ){

          coordinates.push({rows, cols});
          matrix[rows][cols] = abs(matrix[rows][cols]);
        }
      }
    }
  }

  for(int row = 0; row < matrix.size(); row++){
    for(int col = 0; col < matrix[row].size(); col++){

      if(matrix[row][col] < 0) return -1;
    }
  }
  return pass;
}

int main() {
  // Test the function with an example matrix
  vector<vector<int>> matrix = {
      {0, -1, -3, 2, 0},
      {1, -2, -5, -1, -3},
      {3, 0, 0, -4, -1}
  };
  int passes = minimumPassesOfMatrix(matrix);
  cout << "Minimum number of passes required: " << passes << endl;
  return 0;
}
