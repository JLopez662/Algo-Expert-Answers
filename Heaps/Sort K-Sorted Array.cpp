#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MinHeap{

public:

  vector<int> heap;

  MinHeap(vector<int> vector){

    heap = builHeap(vector);
  }

  vector<int> builHeap(vector<int> &vector){

    for(int i = 0; i < vector.size(); i++){

      int node = i;
      siftDown(node, vector);
    }
    return vector;
  }

  bool isEmpty(){

    if(heap.empty())return 1;

    else return 0;
  }

  void siftDown(int currentIdx, vector<int> &heap){

    int min = INT_MAX, minIndex = 0;

    for(int i = currentIdx; i < heap.size(); i++){

      if(min > heap[i]){

        min = heap[i];
        minIndex = i;
      }
    }
    swap(heap[currentIdx], heap[minIndex]);
  }

  void siftUp(int currentIdx, vector<int> &heap){

    int max = INT_MIN, maxIndex = 0;

    for(int i = currentIdx; i < heap.size(); i++){

      if(max < heap[i]){

        max = heap[i];
        maxIndex = i;
      }
    }
    swap(heap[currentIdx], heap[maxIndex]);
  }

  int peek(){

    if(heap.empty())return -1;

    return heap[0];
  }

  int remove(){

    int removal = heap[0];

    heap[0] = heap[heap.size()-1];

    heap.pop_back();

    siftDown(0, heap);

    heap = builHeap(heap);

    return removal;
  }

  void insert(int value){

    heap.push_back(value);

    siftUp(heap.size()-1, heap);

    heap = builHeap(heap);
  }
};

vector<int> kSort(vector<int> &array, int k, int sortIndex){

  if(sortIndex >= array.size() -k){

    sortIndex = sortIndex -1;

    MinHeap heap(vector<int>(array.begin() + sortIndex, array.end()));

    while(!heap.isEmpty()){
      array[sortIndex] = heap.remove();
      sortIndex++;
    }

    return array;
  }

  MinHeap heap(vector<int>(array.begin() + sortIndex, array.begin() + sortIndex + k + 1));

  while(!heap.isEmpty()){

    array[sortIndex] = heap.remove();
    sortIndex++;
  }

  return kSort(array, k, sortIndex - k);
}

vector<int> sortKSortedArray(vector<int> array, int k) {

  if(array.size() <= 1 || k == 0)return array;

  if(k >= array.size()){

    sort(array.begin(), array.end());
    return array;
  }

  return kSort(array, k, 0);
}

int main(){

  vector<int> array = {1, 2, 3, 4, 5, 6, 1};
  
  int k = 8;

  vector<int> sortedArray = sortKSortedArray(array, k);

  for(auto it : sortedArray) cout << it << " "; cout << endl;
  
  return 0;
}