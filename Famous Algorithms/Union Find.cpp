#include <optional>
#include <iostream>
#include<unordered_map>
using namespace std;

// Do not edit the class below except for
// the constructor, push, pop, peek, and
// isEmpty methods. Feel free to add new
// properties and methods to the class.
class UnionFind {
public:

  unordered_map<int,int>parent, size;

  void createSet(int value) {
    // Write your code here.

    if(parent.count(value) > 0)return;

    parent[value] = value;
    size[value] = 1;
  }

  optional<int> find(int value) {
    // Write your code here.

    if(parent.count(value) ==0)return nullopt;

    while(parent[value] != value) value = parent[value];
    
    return value;
  }

  void createUnion(int valueOne, int valueTwo) {
    // Write your code here.

    if(valueOne == valueTwo) return;

    if(parent.count(valueOne) == 0 || parent.count(valueTwo) == 0) return;

    int parentOne = find(valueOne).value();

    int parentTwo = find(valueTwo).value();

    if(parentOne == parentTwo) return;

    int smallParent = parentOne > parentTwo ? parentOne : parentTwo;

    int value = smallParent == parentOne ? valueTwo : valueOne;

    while(parent[smallParent]!= value){

      int biggerParent = find(value).value();
      parent[biggerParent] = smallParent;
      size[smallParent]+=1;
      value = parent[smallParent];
      
    }
    
  }
};
