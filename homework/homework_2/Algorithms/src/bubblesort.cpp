#include "../include/bubblesort.hpp"

void bubbleSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = length-1; j >= i; j--)
        {
            if (arr[j] < arr[j-1])
            {
                switchElementsbyIndexes(arr, j-1, j);
            }
        }
    }
}