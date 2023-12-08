#include "BinaryHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename comparable>
BinaryHeap <comparable> :: BinaryHeap(int capacity)
{
    currentSize = 0;
}

template <typename comparable>
BinaryHeap <comparable> :: BinaryHeap(const vector<comparable> &items)
{
    currentSize = items.size();

    //Copy the items to vector array
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
    //Percolating hole up
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}

template <typename comparable>
void BinaryHeap <comparable> :: deleteMin()
{
    if (isEmpty())
        return;

    array[1] = array[currentSize--];
    percolateDown(1);
}

template <typename comparable>
void BinaryHeap <comparable> :: deleteMin(comparable &minItem)
{
    if (isEmpty())
        return;

    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
}

template <typename comparable>
void BinaryHeap <comparable> :: makeEmpty()
{
    array.clear();
    array.resize(1);
    currentSize = 0;
}

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

    comparable tmp = array[hole];           //create a hole at root
    for( ; hole * 2 <= currentSize; hole=child)
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

template <typename comparable>
vector <comparable> BinaryHeap <comparable> :: getSorted()
{
    BinaryHeap <comparable> tempHeap(this->array);
    vector <comparable> sortedArray;

    while (!tempHeap.isEmpty())
    {
        comparable min;
        tempHeap.deleteMin(min);
        sortedArray.push_back(min);
    }

    return sortedArray;
}
