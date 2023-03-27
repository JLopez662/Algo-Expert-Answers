#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minInsert(const vector<int> &array, int left, int right, BST* &current){

  if(left > right )return current;

  int mid= (left + right)/2;
  
  current->insert(array[mid]);
  
  minInsert(array, left, mid-1, current);
  
  minInsert(array, mid+1, right, current);

  return current;
    
}
  
BST *minHeightBst(vector<int> &array) {
    // Write your code here.
  
    int right = array.size()-1, left = 0;
  
    int mid= (left + right)/2;

    BST* current = new BST(array[mid]);
  
    current = minInsert(array, left, mid-1, current);

    current = minInsert(array, mid+1, right, current);

    return current;
  }