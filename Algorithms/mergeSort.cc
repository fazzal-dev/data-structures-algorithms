#include <iostream>

// Time Complexity: O(N log(N))
// Space Complexity: O(n)

void merge(int32_t *array, int32_t lowerArr, int32_t mid, int32_t upperArr)
{
    int32_t i = lowerArr;
    int32_t j = mid + 1;
    int32_t k = lowerArr;
    int32_t *t_array = new int32_t[upperArr - lowerArr + 1];

    while (i <= mid and j <= upperArr)
    {
        if (array[i] <= array[j])
        {
            t_array[k - lowerArr] = array[i];
            i++;
        }
        else
        {

            t_array[k - lowerArr] = array[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= upperArr)
        {
            t_array[k - lowerArr] = array[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            t_array[k - lowerArr] = array[i];
            i++;
            k++;
        }
    }
    for (size_t i = lowerArr; i <= upperArr; i++)
    {
        array[i] = t_array[i - lowerArr];
    }
    delete[] t_array;
}

void mergeSort(int32_t *array, int32_t lowerArr, int32_t upperArr)
{
    if (lowerArr < upperArr)
    {
        int32_t mid = (lowerArr + upperArr) / 2;
        mergeSort(array, lowerArr, mid);
        mergeSort(array, mid + 1, upperArr);
        merge(array, lowerArr, mid, upperArr);
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
    std::cout << "Merge Sort: ";
    int32_t size = sizeof(array) / sizeof(array[0]);
    mergeSort(array, 0, size - 1);
    printArray(array, size);
    return 0;
}
