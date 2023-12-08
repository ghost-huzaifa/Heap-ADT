#include "BinaryHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename comparable>
BinaryHeap <comparable> :: BinaryHeap(int capacity)
{
    currentSize = 0;
    array(capacity + 1);    // one extra space for '0' index
}

template <typename comparable>
BinaryHeap <comparable> :: BinaryHeap(const vector<comparable> &items)
{
    currentSize = items.size();

    //Copy the items to vector array
    array(items.size() + 1);
    for (int i = 0; i < items.size(); i++)
        array[i + 1] = items[i];

    //Make a heap out of this vector array
    buildHeap();
}

template <typename comparable>
bool BinaryHeap <comparable> :: isEmpty() const
{
    return currentSize == 0;
}

template <typename comparable>
void BinaryHeap <comparable> :: insert(const comparable &x)
{

}

template <typename comparable>
void BinaryHeap <comparable> :: deleteMin();

template <typename comparable>
void BinaryHeap <comparable> :: deleteMin(comparable &minItem);

template <typename comparable>
void BinaryHeap <comparable> :: makeEmpty();

template <typename comparable>
void BinaryHeap <comparable> :: buildHeap()
{
    for (int i = 0; i < currentSize; i++)
    {
        percolateDown(i);
    }
}

template <typename comparable>
void BinaryHeap <comparable> :: percolateDown(int hole)
{
    int child;

    Comparable tmp = array[hole];           //create a hole at root
    for( ; hold * 2 <= currentSize; hole=child)
    {

        //identify child position
        child = hole*2;

        //compare left and right child, select the smaller one
        if (child != currentSize && array[child+1] < array[child])
            child++;

        //compare the smaller child with tmp
        if(array[child] < tmp)
            array[hole] = array[child];     //bubble down if child is smaller
        else
            break; //bubble stops movement

    }

    array[hole] = tmp; //fill the hole
}
