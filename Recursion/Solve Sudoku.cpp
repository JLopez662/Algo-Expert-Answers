#include <vector>
#include <iostream>
using namespace std;

bool isValid(int row, int col, int value, vector<vector<int>> &board){

  for(int y = 0; y < board[0].size(); y++){

    if(board[row][y] == value) return false;
  }

  for(int x = 0; x < board.size(); x++){

    if(board[x][col] == value)return false;
  }

  int gridRow = (row/3) * 3, gridCol = (col/3) * 3;

  for(int x = gridRow; x < gridRow+3; x++){

    for(int y = gridCol; y < gridCol +3; y++) if(board[x][y] == value)return false;
  }
  
  return true;
}

bool fillSudoku(vector<vector<int>> &board){

  for(int row = 0; row < board.size(); row++){

    for(int col = 0; col < board[0].size(); col++){

      if(board[row][col] == 0){

        for(int value = 1; value <=9; value++){

          if(isValid(row, col, value, board)){

            board[row][col] = value;

            if(fillSudoku(board))return true;

            board[row][col] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
  // Write your code here.

  fillSudoku(board);
  
  return board;
}
