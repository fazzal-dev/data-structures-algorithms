#include <iostream>

// Time Complexity: O(N^2)
// Space Complexity: O(1)

void insertionSort(int32_t *array, int32_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        int32_t current = array[i];
        int32_t j = i - 1;

        while (array[j] > current and j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
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
    std::cout << "Inserstion Sort: ";
    insertionSort(array, size);
    printArray(array, size);

    return 0;
}