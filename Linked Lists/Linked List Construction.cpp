using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node *node) {
    if (!head) {
      head = node;
      tail = node;
      return;
    }
    if(head == node)return;
    
    insertBefore(head, node);
  }

  void setTail(Node *node) {
    if (!tail) {
      head = node;
      tail = node;
      return;
    }
    insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
    
    if (nodeToInsert == head && nodeToInsert == tail) return; 
    
    remove(nodeToInsert); 
    
    nodeToInsert->prev = node->prev;
    nodeToInsert->next = node;

    if (!node->prev) head = nodeToInsert;
    else node->prev->next = nodeToInsert;
    
    node->prev = nodeToInsert;
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    
    if (nodeToInsert == head && nodeToInsert == tail) return;
    
    remove(nodeToInsert);
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;

    if (!node->next) tail = nodeToInsert;
    else node->next->prev = nodeToInsert;
  
    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    if (position == 0) {
      setHead(nodeToInsert);
      return;
    }

    Node *current = head;
    int pos = 1;

    while (current && pos != position) {
      current = current->next;
      pos++;
    }
    if (current) insertBefore(current, nodeToInsert);
    else setTail(nodeToInsert);
  }

  void removeNodesWithValue(int value) {
    Node *current = head;
    
    while (current) {
      
      Node *removal = current;
      current = current->next;
      
      if (removal->value == value) remove(removal);
    }
  }

  void remove(Node *node) {
    if (node == head) head = head->next;
      
    if (node == tail) tail = tail->prev;
    
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    node->~Node();
  }

  bool containsNodeWithValue(int value) {
    Node *current = head;
    while (current && current->value != value) current = current->next;
    return current; //current != NULL
  }
};