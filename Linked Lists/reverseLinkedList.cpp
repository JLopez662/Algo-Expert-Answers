#include <iostream>

using namespace std;

class LinkedList{
public:
  int value;
  LinkedList *next;

  LinkedList(int value){
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList * head){

  if(!head->next || !head) return head;

  LinkedList* current = head->next, *prev = head;

  while(current){

    LinkedList *temp = current->next;

    current->next = prev;

    prev = current;

    current = temp;
  }

  head->next = NULL;

  head = prev;

  return head;
}

int main(){

  LinkedList *head = new LinkedList(0);
  LinkedList *current = head;

  for(int i = 1; i <= 5; i++){

    current->next = new LinkedList(i);
    current = current->next;
  }

  current = reverseLinkedList(head);

  while(current != NULL){
    cout << current->value;

    if(current->next)cout << " -> ";

    current = current->next;
  }
}