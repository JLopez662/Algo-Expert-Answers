#include <iostream>
#include <climits>

using namespace std;

class BST{
  public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST &insert(int val);
};

bool isValid(BST *tree, int lower, int higher){

  if(tree->value < lower || tree->value >= higher)return false;

  if(tree->left && !isValid(tree->left, lower, tree->value))return false;

  if(tree->right && !isValid(tree->right, tree->value, higher))return false;

  return true;
}

bool validateBst(BST *tree){

  if(!tree|| (!tree->left && !tree->right))return true;

  bool validLeft = isValid(tree->left, INT_MIN, tree->value);

  bool validRight = isValid(tree->right, tree->value, INT_MAX);

  return (validLeft && validRight);
}
