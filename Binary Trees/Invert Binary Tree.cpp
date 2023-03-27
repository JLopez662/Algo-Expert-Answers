#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.

  if(tree== NULL)return;

  else if(tree->left == NULL && tree->right == NULL) return;

  BinaryTree* swapL = tree->left;

  BinaryTree* swapR = tree->right;

  tree->right = swapL;

  tree->left = swapR;

  invertBinaryTree(tree->left);

  invertBinaryTree(tree->right);

  
}

