#include <iostream>
class MinHeap
{
public:
    MinHeap(int32_t _capacity);
    void append(int32_t _value);
    int32_t extractMin();
    void minHeapify(int32_t index);
    void decreaseKey(int32_t index, int32_t value);
    void deleteKey(int32_t key);
    void heapSort();

    void printArray();
    int32_t linearSearch(int32_t _value);
    int32_t height();
    int32_t getParent(int32_t _index);
    int32_t getLeft(int32_t _index);
    int32_t getRight(int32_t _index);
    int32_t getCapacity();

private:
    int32_t *heap_array;
    int32_t m_capacity;
    int32_t m_size;
};
// void swap(int32_t &, int32_t &);