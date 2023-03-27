#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array){

  int startRow = 0, endRow = array.size()-1, startCol = 0, endCol = array[0].size()-1;

  vector<int> result;

  while(startRow <= endRow && startCol <= endCol){
    //traverse top row
    for(int col = startCol; col <= endCol; col++)result.push_back(array[startRow][col]);

    //traverse last col
    for(int row = startRow+1; row  <= endRow; row++)result.push_back(array[row][endCol]);

    //traverse last row
    if(startRow < endRow){
      for(int col = endCol-1; col >= startCol; col--)result.push_back(array[endRow][col]);
    }

    //traverse first col
    if(startCol < endCol){
      for(int row = endRow-1; row > startRow; row--)result.push_back(array[row][startCol]);
    }
    //Shrink dimensions
    startRow++;
    startCol++;
    endRow--;
    endCol--;
  }

  return result;
}