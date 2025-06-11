#include "../include/quicksort.hpp"

int partition(int arr[], int p, int r)
{
    int partition_element = arr[r];
    int i = p-1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= partition_element)
        {
            i += 1;
            switchElementsbyIndexes(arr, i, j);
        }
    }
    switchElementsbyIndexes(arr, i+1, r);
    return ++i;
}

void quickSort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}