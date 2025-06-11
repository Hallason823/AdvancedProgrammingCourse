#include "../include/mergesortedarrays.hpp"


bool isDecreasing(int arr[], int arr_filled_length)
{
    for (int i = 1; i < arr_filled_length; i++)
    {
        if(arr[i] > arr[i-1])
        {
            return false;
        }
    }
    return true;
}

void sortIncreasing(int arr[], int arr_filled_length)
{
    for (int i = 0; i < arr_filled_length/2; i++)
    {
        switchElementsbyIndexes(arr, i, arr_filled_length-i-1);
    }
}

void mergeSortedArrays(int A[], int A_filled_length, int B[], int B_filled_length)
{
    if (isDecreasing(A, A_filled_length)){sortIncreasing(A, A_filled_length);}
    if (isDecreasing(B, B_filled_length)){sortIncreasing(B, B_filled_length);}

    int i = --A_filled_length;
    int j = --B_filled_length;
    
    while(j >= 0)
    {
        if (A[i] < B[j])
        {
            A[i+j+1] = B[j];
            j -= 1;
        }
        else
        {
            A[i+j+1] = A[i];
            i -= 1;
        }
    }
}
