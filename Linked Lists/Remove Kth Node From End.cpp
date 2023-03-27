#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.

  if(!head)return;

  int count = 0;
  LinkedList *current = head;

  while(current){
    count++;
    current = current->next;
  }

  int target = count -k;

  current = head;
  count = 0;

  if(target == 0){

    current = head->next;

    head->value = current->value;

    head->next = current->next;

    delete current;

    return;
  }

  else if (target < 0)return;

  while(count != target-1){

    count++;
    current = current->next;
  }

  LinkedList *removal = current->next;
  current->next = current->next->next;
  delete removal;
}
