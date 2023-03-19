#include <iostream>

// Time Complexity: O(nlogn)
// Space Complexity: O(logn)

int32_t partition(int32_t *array, int32_t lowerArr, int32_t upperArr)
{
    int32_t pivot = array[lowerArr];
    int32_t start = lowerArr;
    int32_t end = upperArr;

    while (start < end)
    {
        while (array[start] <= pivot)
            start++;
        while (array[end] > pivot)
            end--;
        if (start < end)
            std::swap(array[start], array[end]);
    }
    std::swap(array[lowerArr], array[end]);
    return end;
}

void quickSort(int32_t *array, int32_t lowerArr, int32_t upperArr)
{
    if (lowerArr < upperArr)
    {
        int32_t pos = partition(array, lowerArr, upperArr);
        quickSort(array, lowerArr, pos - 1);
        quickSort(array, pos + 1, upperArr);
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
    std::cout << "Quick Sort: ";
    int32_t size = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, size - 1);
    printArray(array, size);

    return 0;
}