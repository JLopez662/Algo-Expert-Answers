using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int getHeight(BinaryTree *current, int &height){

  if(!current)return 0;

  int leftHeight = getHeight(current->left, height);

  int rightHeight = getHeight(current->right, height);

  height = 1 + max(leftHeight, rightHeight);

  return height;
}

bool heightBalancedBinaryTree(BinaryTree *tree){

  if(!tree)return true;

  int height = 0;

  bool leftBalance = heightBalancedBinaryTree(tree->left);

  bool rightBalance = heightBalancedBinaryTree(tree->right);

  if(leftBalance && rightBalance){

    int leftHeight = getHeight(tree->left, height);

    int rightHeight = getHeight(tree->right, height);

    if(abs(leftHeight - rightHeight) <= 1)return true;
  }
  return false;
}