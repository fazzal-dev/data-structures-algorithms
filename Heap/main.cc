#include <iostream>
#include "heap.h"
int main()
{
    MinHeap Heap(5);
    Heap.append(7);
    Heap.append(4);
    Heap.append(3);
    Heap.append(9);
    Heap.append(8);
    // Heap.deleteKey(3);
    // Heap.heapSort();
    Heap.printArray();

    return 0;
}