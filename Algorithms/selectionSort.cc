#include <iostream>

// Time Complexity: O(N^2)
// Space Complexity: O(1)

void selectionSort(int32_t *array, int32_t size)
{
    for (int32_t i = 0; i < size - 1; i++)
    {
        int32_t Min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[Min])
                Min = j;
        }

        if (Min not_eq i)
            std::swap(array[Min], array[i]);
    }
}

void stableSelectionSort(int32_t *array, int32_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int32_t Min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[Min])
                Min = j;
        }
        int32_t key = array[Min];
        for (size_t k = Min; k > i; k--)
        {
            array[k] = array[k - 1];
            array[i] = key;
        }
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
    std::cout << "Selection Sort: ";
    selectionSort(array, size);
    printArray(array, size);
    std::cout << "\nStable Selection Sort: ";
    stableSelectionSort(array, size);
    printArray(array, size);
    return 0;
}