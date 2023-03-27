#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  // Write your code here.

  int row = 0;
  int col = matrix[0].size()-1;

  while (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {

    if (target > matrix[row][col])row++;

    else if (target < matrix[row][col] )col--;

    else if (target == matrix[row][col])return {row, col};
  }
  return {-1, -1};
}
