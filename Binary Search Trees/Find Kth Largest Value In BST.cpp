#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void treeToArray(BST* &tree, vector<int> &array){

  if(!tree) return;

  treeToArray(tree->right, array);

  array.push_back(tree->value);

  treeToArray(tree->left, array);
  
}

int findKthLargestValueInBst(BST *tree, int k) {
  // Write your code here.

  if(!tree) return -1;

  if(!tree->left && !tree->right)return tree->value;

  vector<int> array;

  treeToArray(tree, array);
  
  return array[k-1];
}