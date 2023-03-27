#include <iostream>
#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
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

void getSums(BinaryTree *current, int currentSum, vector<int>&SumList)
{
  if(current == NULL){ return; }

  currentSum += current->value;

  if(current->left == NULL && current->right == NULL) { SumList.push_back(currentSum); }

  getSums(current->left, currentSum, SumList);
  getSums(current->right, currentSum, SumList);

}

vector<int> branchSums(BinaryTree *root) 
{
  vector<int> SumList;

  getSums(root, 0, SumList);

  return SumList;
}

