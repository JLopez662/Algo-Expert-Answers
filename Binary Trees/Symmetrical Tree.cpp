using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) {
    this->value = value;
  }
};

bool isSymmetric(BinaryTree *leftSide, BinaryTree *rightSide){

  if(!leftSide && !rightSide)return true;

  else if (!leftSide || !rightSide)return false;
  
  return ((leftSide->value == rightSide->value) && 
    isSymmetric(leftSide->left, rightSide->right) && 
    isSymmetric(leftSide->right, rightSide->left));
  
}

bool symmetricalTree(BinaryTree* tree) {
  // Write your code here.

  if(!tree)return true;

  return isSymmetric(tree->left, tree->right);
}
