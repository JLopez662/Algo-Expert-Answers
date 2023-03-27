#include <algorithm>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int findDiameter(BinaryTree* current, int &diameter){

  if(!current)return 0;

  int leftHeight = findDiameter(current->left, diameter);
  int rightHeight = findDiameter(current->right, diameter);

  diameter = max(diameter, leftHeight + rightHeight);

  return 1 + max(leftHeight, rightHeight);
  
}

int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  int diameter = 0;
  findDiameter(tree, diameter);
  return diameter;
  
}

