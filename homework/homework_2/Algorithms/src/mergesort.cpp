#include "../include/mergesort.hpp"

void merge(int arr[], int p, int q, int r)
{
    int length_st = q-p+1;
    int length_nd = r-q;

    int *L = new int[length_st+1];
    int *R = new int[length_nd+1];

    for (int i = 0; i < length_st; i++){L[i] = arr[p+i];}
    for (int j = 0; j < length_nd; j++){R[j] = arr[q+j+1];}

    L[length_st] = numeric_limits<int>::max();
    R[length_nd] = numeric_limits<int>::max();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i += 1;
        }
        else
        {
            arr[k] = R[j];
            j += 1;
        }
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = floor((p+r)/2);
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}