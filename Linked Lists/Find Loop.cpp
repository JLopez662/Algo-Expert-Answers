#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  // Write your code here.

  if(!head || !head->next)return NULL;
  
  LinkedList* slow = head->next;
  LinkedList* fast = head->next->next;

  while(slow != fast){

    slow = slow->next;
    fast = fast->next->next;
  }

  if(slow == fast){

    if(slow == head && fast == head)return head;

    slow = head;

    while(slow != fast){
      slow = slow->next;
      fast = fast->next;
      if(slow == fast)return slow;
    }
  }
  return nullptr;
}