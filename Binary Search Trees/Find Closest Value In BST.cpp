#include <iostream>
#include <cmath>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int closest = 999999;

int findClosestValueInBst(BST *tree, int target) 
{
  BST* current = tree;
  while(current != NULL)
  {
    if( abs(target - closest) > abs(target - current->value) )
    {
      closest = current->value;
    }

    if(target < current->value)
    {
      current = current->left;
    }

    else if(target > current->value)
    {
      current = current->right;
    }

    else
    {
      break;
    }

  
  }
  return closest;

}
