#include <iostream>

// Time Complexity: O(N^2)
// Space Complexity: O(1)

void bubbleSort(int32_t *array, int32_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
            swapped = true;
        }
        if (not swapped)
            break;
    }
}

void printArray(int32_t *array, int32_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

int main()
{
    int32_t array[] = {4, 5, 3, 2, 4, 1};
    int32_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Bubble Sort: ";
    bubbleSort(array, size);
    printArray(array, size);

    return 0;
}