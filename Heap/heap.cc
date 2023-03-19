#include "heap.h"
#include <iostream>
#include <math.h>

MinHeap::MinHeap(int32_t _capacity) : m_size(0), m_capacity(_capacity), heap_array(new int32_t[_capacity]) {}

int32_t MinHeap::linearSearch(int32_t _value)
{
    for (size_t i = 0; i < m_size; i++)
    {
        if (heap_array[i] == _value)
        {
            return i;
        }
        else
            return false;
    }
    return EXIT_SUCCESS;
}

void MinHeap::printArray()
{
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << heap_array[i] << " ";
    }
}

int32_t MinHeap::height()
{
    return ceil(log2(m_size + 1)) - 1;
}

void MinHeap::append(int32_t _value)
{
    if (m_size == m_capacity)
    {
        throw std::out_of_range("Overflow");
        return;
    }
    m_size++;
    int32_t index = m_size - 1;
    heap_array[index] = _value;
    while (index not_eq 0 and heap_array[getParent(index)] > heap_array[index])
    {
        std::swap(heap_array[getParent(index)], heap_array[index]);
        index = getParent(index);
    }
}

int32_t MinHeap::extractMin()
{
    if (m_size <= 0)
        return INT32_MAX;
    if (m_size == 1)
    {
        m_size--;
        return heap_array[0];
    }
    int32_t _root{heap_array[0]};
    heap_array[0] = heap_array[m_size - 1];
    m_size--;
    minHeapify(0);
    return _root;
}

void MinHeap::minHeapify(int32_t index)
{
    int32_t left{getLeft(index)};
    int32_t right{getRight(index)};
    int32_t smallest{index};

    if (left < m_size and heap_array[left] < heap_array[index])
        smallest = left;
    if (right < m_size and heap_array[right] < heap_array[smallest])
        smallest = right;
    if (smallest not_eq index)
    {
        std::swap(heap_array[index], heap_array[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::decreaseKey(int32_t index, int32_t value = -1)
{
    heap_array[index] = value;
    while (index not_eq 0 and heap_array[getParent(index)] > heap_array[index])
    {
        std::swap(heap_array[index], heap_array[getParent(index)]);
        index = getParent(index);
    }
}

void MinHeap::deleteKey(int32_t key)
{
    decreaseKey(key);
    extractMin();
}

void MinHeap::heapSort()
{
    int32_t sorted_heap[m_capacity]{};
    for (size_t i = 0; i < m_capacity; i++)
    {
        sorted_heap[i] = extractMin();
        minHeapify(i);
        std::cout << sorted_heap[i] << "  ";
    }
}

int32_t MinHeap::getCapacity()
{
    return m_capacity;
}

int32_t MinHeap::getParent(int32_t _index)
{
    return (_index - 1) / 2;
}

int32_t MinHeap::getLeft(int32_t _index)
{
    return (2 * _index + 1);
}

int32_t MinHeap::getRight(int32_t _index)
{
    return (2 * _index + 2);
}

// void swap(int32_t &val1, int32_t &val2)
// {
//     int32_t temp{val1};
//     val1 = val2;
//     val2 = temp;
// }