#include <vector>
#include <climits>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST* insertBST(vector<int> &array, BST* &current, int min, int max){

  if(array.empty()) return current;

  int value = array[0];

  if(value < min || value >= max) return current;

  current = new BST(value);

  array.erase(array.begin());

  current->left = insertBST(array, current->left, min, value);

  current->right = insertBST(array, current->right, value, max);

  return current;
}


BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.

  BST* current = insertBST(preOrderTraversalValues, current, INT_MIN, INT_MAX);
  return current;
}

