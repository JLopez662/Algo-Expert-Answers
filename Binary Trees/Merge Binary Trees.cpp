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

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
    // Write your code here.

    if(!tree1 && !tree2)return NULL;

    if(!tree1)return tree2;

    else if (!tree2)return tree1;

    int mergedValue = tree1->value + tree2->value;

    BinaryTree *merged = new BinaryTree(mergedValue);

    merged->left = mergeBinaryTrees(tree1->left, tree2->left);

    merged->right = mergeBinaryTrees(tree1->right, tree2->right);

    return merged;
}

