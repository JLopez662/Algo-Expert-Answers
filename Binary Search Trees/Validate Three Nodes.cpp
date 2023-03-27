#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};


bool isSuccessor(BST *nodeTwo, BST *nodeOne){
  
  if(nodeOne == NULL)return false;

  if(nodeOne == nodeTwo)return true;

  BST *current = nodeOne;

  if(current->value > nodeTwo->value) return isSuccessor(nodeTwo, current->left);

  else return isSuccessor(nodeTwo, current->right);
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  // Write your code here.

  bool successor = isSuccessor(nodeTwo, nodeOne);

  bool ancestor = isSuccessor(nodeThree, nodeTwo);

  if(!successor || !ancestor){

   successor = isSuccessor(nodeTwo, nodeThree);

   ancestor = isSuccessor(nodeOne, nodeTwo);
  }

  return successor && ancestor;
}
