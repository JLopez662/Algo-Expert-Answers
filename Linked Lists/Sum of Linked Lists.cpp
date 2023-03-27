using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne, LinkedList *linkedListTwo) {
  // Write your code here.

  if(!linkedListOne && !linkedListTwo)return NULL;

  else if (!linkedListOne) return linkedListTwo;

  else if (!linkedListTwo) return linkedListOne;

  LinkedList *current1 = linkedListOne, *current2 = linkedListTwo;

  vector<int> list1, list2, list3;

  while(current1 || current2){

    if(current1){
      list1.insert(list1.begin(), current1->value);
      current1 = current1->next;
    }
    else list1.insert(list1.begin(), 0);

    if(current2){
      list2.insert(list2.begin(), current2->value);
      current2 = current2->next;
    }
    else list2.insert(list2.begin(), 0);
  }

  int remainder = 0;

  if(list1.size() >= list2.size()){

    for(int i = list1.size()-1; i >= 0; i--){

      if((remainder + list1[i] + list2[i]) >= 10 ){

        list3.push_back( remainder + (list1[i] + list2[i]) % 10);

        if(i >= 0 )remainder = (list1[i] + list2[i])/10;
      }
        
      else {
        list3.push_back( remainder + list1[i] + list2[i]);
        remainder = 0;
      }
    }
    if(remainder > 0)list3.push_back(remainder);
    
  }

  LinkedList *newLL = new LinkedList(0), *current = newLL;

  for(int i = 0; i < list3.size(); i++){

    current->value = list3[i];
    if(i < list3.size()-1)current->next = new LinkedList(0);
    current = current->next;
  }
  return newLL;
}