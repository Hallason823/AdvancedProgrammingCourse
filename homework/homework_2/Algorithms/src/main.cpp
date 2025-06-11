#include <iostream>
#include <algorithm>
#include "../include/auxiliarytools.hpp"
#include "../include/bubblesort.hpp"
#include "../include/quicksort.hpp"
#include "../include/mergesort.hpp"
#include "../include/mergesortedarrays.hpp"
using namespace std;

int main ()
{
    int test_array[] = {31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};
    int length_of_test_array = sizeof(test_array)/sizeof(test_array[0]);

    cout << endl << "Questions 1, 2 and 3." << endl << "Before to sort:" << endl;
    displayIntArray(test_array, length_of_test_array);

    cout << endl << endl << "Select a sorting algorithm:" << endl << "(1)Bubble Sort;" << endl << "(2)Quick Sort;" << endl << "(3)Merge Sort." << endl << endl;
    int user_input;
    receiveUserInput(user_input);

    if (user_input == 1)
    {
        bubbleSort(test_array, length_of_test_array);
    }
    else if (user_input == 2)
    {
        quickSort(test_array, 0, length_of_test_array-1);
    }
    else
    {
        mergeSort(test_array, 0, length_of_test_array-1);
    }

    cout << endl << "After to sort:" << endl;
    displayIntArray(test_array, length_of_test_array);

    int *A = new int[31]{0, 4, 9, 16, 25};
    int *B = new int[10]{19, 17, 13, 11, 7, 5, 3, 2};
    int A_filled_length = 5;
    int B_filled_length = 8;

    cout << endl << endl << "Question 4." << endl << "A is" << endl;
    displayIntArray(A, A_filled_length);
    cout << endl << endl << "B is" << endl;
    displayIntArray(B, B_filled_length);

    mergeSortedArrays(A, A_filled_length, B, B_filled_length);
    cout << endl << endl << "After the merge between A and B, we have:" << endl;
    displayIntArray(A, A_filled_length+B_filled_length);

    return 0;
}