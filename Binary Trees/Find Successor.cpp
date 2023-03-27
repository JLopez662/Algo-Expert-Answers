using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node){
  //Write your code here.

  if(node->right){

    BinaryTree *current = node->right;

    while(current->left)current = current->left;
    return current;
  }

  BinaryTree *ancestor = node->parent;

  while(ancestor && node == ancestor->right){
    node = ancestor;
    ancestor = ancestor->parent;
  }

  return ancestor;
}