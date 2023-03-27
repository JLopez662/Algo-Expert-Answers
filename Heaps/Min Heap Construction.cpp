#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    // Write your code here.

    for(int i = 0; i < vector.size(); i++){

      int node = i;
      siftDown(node, vector.size() -1, vector);
    }
    
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    // Write your code here.

    int min = INT_MAX, minIndex = 0;

    for(int i = currentIdx; i < heap.size(); i++){

      if(min > heap[i]){
        min = heap[i];
        minIndex = i;
      }
    }
    swap(heap[currentIdx], heap[minIndex]);
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    // Write your code here.

    int max = INT_MIN, maxIdx = 0;

    for(int i = 0; i < heap.size(); i++){

      if(max < heap[i]){
        max = heap[i];
        maxIdx = i;
      }
    }
    swap(heap[currentIdx], heap[maxIdx]);
    
  }

  int peek() {
    // Write your code here.

    if(heap.empty())return -1;
   
    return heap[0];
  }

  int remove() {
    // Write your code here.

    int removal = heap[0];

    heap[0] = heap[heap.size()-1];

    heap.pop_back();

    siftDown(0, heap.size() -1, heap);

    heap = buildHeap(heap);

    return removal;
  }

  void insert(int value) {
    // Write your code here.

    heap.push_back(value);

    siftUp(heap.size() -1, heap);    

    heap = buildHeap(heap);
  }
};
