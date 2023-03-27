#include <vector>
#include <iostream>

using namespace std;

class AncestralTree{
public:
  char name;
  AncestralTree* ancestor;

  AncestralTree(char name){
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree*> descendants);
};

vector<AncestralTree*> treeTraversal(AncestralTree* topAncestor, AncestralTree* descendant)
{
  vector<AncestralTree*> path;

  while(descendant != topAncestor){

    path.push_back(descendant);
    descendant = descendant->ancestor;
  }
  path.push_back(topAncestor);

  return path;
}

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor, AncestralTree* descendantOne, AncestralTree* descendantTwo)
{

  //Write your code

  if(descendantOne == NULL || descendantTwo == NULL) return nullptr;

  if(descendantOne->name == descendantTwo->name) return descendantOne;

  vector<AncestralTree*>pathOne = treeTraversal(topAncestor, descendantOne);

  vector<AncestralTree*>pathTwo = treeTraversal(topAncestor, descendantTwo);

  int sizeDif = 0;

  if(pathOne.size() > pathTwo.size()){

    sizeDif = pathOne.size() - pathTwo.size();

    pathOne.erase(pathOne.begin(), pathOne.begin() + sizeDif);
  }

  else if (pathOne.size() < pathTwo.size()){

    sizeDif = pathTwo.size() - pathOne.size();

    pathTwo.erase(pathTwo.begin(), pathTwo.begin() + sizeDif);
  }

  if(pathOne.size() == pathTwo.size()){

    for(int i = 0; i < pathOne.size(); i++){

      if(pathOne[i]->name == pathTwo[i]->name) return pathOne[i];
    }
  }

  return NULL;
}