#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str){ name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {

    vector<string> result;

    queue<*Node> traversal;

    traversal.push(this);

    while(!traversal.empty()){

      Node* current = traversal.front();

      result.push_back(current->name);

      traversal.pop();

      for(Node* child : children )traversal.push(child);
    }

    return result;
  }

  Node *addChild(string name) {
      Node *child = new Node(name);
      children.push_back(child);
      return this;
    }
};