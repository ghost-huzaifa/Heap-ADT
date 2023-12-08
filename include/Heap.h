#ifndef HEAP_H
#define HEAP_H

Template <typename Comparable>
class Heap
{
public:
BinaryHeap(int capacity=100);
explicit BinaryHeap(const vector<comparable> &items);
bool isEmpty() const;
void insert(const Comparable &x);
void deleteMin();
void deleteMin(Comparable &minItem);
void makeEmpty();
private:
int currentSize; //number of elements in heap
vector<Comparable> array; //the heap array
void buildHeap();
void percolateDown(int hole);
}


#endif // HEAP_H
