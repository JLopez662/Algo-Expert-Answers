using namespace std;

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

int depth = 0;

int nodeTraverse(BinaryTree *root, int depth)
{
  if (root== NULL){ return depth = 0; }
  
  return depth + nodeTraverse(root->left, depth+1) + nodeTraverse(root->right, depth+1);
}

int nodeDepths(BinaryTree *root) 
{
  // Write your code here.
  return nodeTraverse(root, depth);
}
