#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    vector<int> values = {10,20,30,40,50,70,12,3,5};
    BinaryHeap<int> heap(values);
    heap.insert(55);
    heap.insert(28);
    heap.printHeap();
    vector <int> sorted;
    sorted = heap.getSorted();
    for (int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << " ";
    return 0;
}
