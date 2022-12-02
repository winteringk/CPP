#include<iostream>
using namespace std;
class Router
{

	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
    int *data; // pointer to array of elements in heap
	Router(int cap){
    capacity = cap;
    heap_size = NULL;
    data = new int[cap];
    }
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	int removeMin(){
      if (heap_size <= 0)
          return (0);
    
      if (heap_size == 1){
          heap_size--;
          return data[0];
        }

      int r = data[0];
      data[0] = data[heap_size-1];
      heap_size--;
      downHeap(0);
      return r;
    }

	int min() { // min
      return data[0];
	}
	void insert(int k){
        if (heap_size == capacity){
            cout << "Can not insert\n";
            return;
        }
        heap_size++;
    
        int a = heap_size-1;
        data[a] = k;
    
        while (a != 0 && data[parent(a)] > data[a]){
              swap(data[a], data[parent(a)]);
              a = parent(a);
        }
    }
	void downHeap(int i){
    int l = left(i);
    int r = right(i);
    int s = i;
    
    if (l < heap_size && data[l] < data[i])
        s = l;
    
    if (r < heap_size && data[r] < data[s])
        s = r;
    
    if (s != i){
      swap(data[i], data[s]);
      downHeap(s);
    }
  }

	void reset(int k){
    data[0] = k; // replace k in min
    downHeap(0); // reset to start
    }
};
