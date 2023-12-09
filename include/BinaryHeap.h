#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template <typename comparable>
class BinaryHeap
{
    public:
        BinaryHeap(int capacity=100);
        explicit BinaryHeap(const vector<comparable> &items);
        bool isEmpty() const;
        void insert(const comparable &x);
        void deleteMin();
        void deleteMin(comparable &minItem);
        void makeEmpty();
        vector<comparable> getSorted();
        void printHeap();
    private:
        int currentSize; //number of elements in heap
        vector<comparable> array; //the heap array
        void buildHeap();
        void percolateDown(int hole);
};


#endif // BINARYHEAP_H
