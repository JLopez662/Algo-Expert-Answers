#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

 BST &insert(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.

    BST*node = new BST(val);

    if(val < value){
  
      if(!this->left)this->left = node;
  
      else this->left->insert(val);
    }

    else if(val >= value){

      if(!this->right)this->right = node;

      else this->right->insert(val);
    }
    return *this;
  }

  bool contains(int val) {
    // Write your code here.

    if(!this)return false;

    if (value == val)return true;

    bool leftTree = false, rightTree = false;

    if(this->left && val < value)leftTree = this->left->contains(val);

    if(this->right && val > value)rightTree = this->right->contains(val);
    
    return leftTree || rightTree;
  }


 BST &remove(int val) {
    
    BST * current = this, *parent = this;
    bool Right = true;

    // traverse the BST to find the node with the value to remove
    while(current){
      
      if(val < current->value){
        parent = current;
        current = current->left;
        Right = false;
      }
        
      else if(val > current->value){
        parent = current;
        current = current->right;
        Right = true;
      }
      else if(val == current->value){

        // if the node has a right child
        if(current->right){
          // get the minimum value in the right subtree and remove it from the subtree
          current->value = getAndRemoveMin(current->right,current, true);
        }
        // if the node has a left child but not a right child
        else if(current->left) {
          // if the node to remove is the root of the BST
          if(current == parent){
              current->value = current->left->value;
              current->left = current->left->left;
              break;
          }
          // if the node to remove was reached by traversing left
          if(!Right) parent->left = current->left;
          // if the node to remove was reached by traversing right
          else parent->right = current->left;
        }
        // if the node has no left or right child
        else{
          // if the node to remove was reached by traversing left
          if(!Right) parent->left = nullptr;
          // if the node to remove was reached by traversing right
          else parent->right = nullptr;
        }
        // exit the loop and return the modified BST
        break;
      }
      // if the end of the BST is reached without finding the value to remove, exit the loop
      else{
        break;
      }
    }
    
    return *this;
  }

  int getAndRemoveMin(BST *node, BST * parentNode, bool right = false){
      // If the current node has no left or right child and is not the right child of its parent, then it's the minimum value
      if(!node->left && !node->right && !right) {
        parentNode->left = nullptr; // Remove the current node from the tree
        return node->value; // Return the minimum value
      }
      // If the current node has no left or right child and is the right child of its parent, then it's the minimum value
      if(!node->left && !node->right && right) {
        parentNode->right = nullptr; // Remove the current node from the tree
        return node->value; // Return the minimum value
      }
      // If the current node has no left child but has a right child, then the minimum value is in the right subtree
      if(!node->left && node->right ) {
        parentNode->right = node->right; // Update the parent's pointer to the right subtree
        return node->value; // Return the minimum value
      }
      // If the current node has a left child, then the minimum value is in the left subtree
      return getAndRemoveMin(node->left, node, false); // Recursively search for the minimum value in the left subtree
  }
};