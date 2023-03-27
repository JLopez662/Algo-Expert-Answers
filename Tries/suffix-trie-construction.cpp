#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

 void populateSuffixTrieFrom(string str) {
    // Write your code here.

    for(int i = 0; i < str.size(); i++) {

      TrieNode *node = root;

      for(int j = i; j < str.size(); j++){

        char x = str[j];

        if(node->children.find(x) == node->children.end() )
          node->children[x] = new TrieNode();
        
        node = node->children[x];
      }
      
      node->children[endSymbol] = NULL;
    }
  }

  bool contains(string str) {
    // Write your code here.

    TrieNode* node = root;

    for(int i = 0; i < str.size(); i++){

      char x = str[i];

      if(node->children.find(x) == node->children.end() ) return false;

      node = node->children[x];

    }

    if(node->children.find(endSymbol) == node->children.end()) return false;
    
    return true;
  }
};
