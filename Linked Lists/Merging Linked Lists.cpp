using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) {
    this->value = value;
  }
};

LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
  // Write your code here.

  if(!linkedListOne || !linkedListTwo)return NULL;

  LinkedList *current1 = linkedListOne, *current2 = linkedListTwo;

  while(current1->value != current2->value){

    if(!current1->next && !current2->next)return NULL;

    if(current2->next)current2 = current2->next;

    else{
      current2 = linkedListTwo;
      if(current1->next)current1 = current1->next;
    }
    if(!current1 && !current2)return NULL;
  }
  return current1;
}
