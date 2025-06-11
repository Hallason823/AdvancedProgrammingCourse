#include "../include/auxiliarytools.hpp"

void displayIntArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

void switchElementsbyIndexes(int arr[], int origin_index, int destination_index)
{
    int temp = arr[origin_index];
    arr[origin_index] = arr[destination_index];
    arr[destination_index] = temp;
}

void receiveUserInput(int& data)
{
    std::string inputStr;
    do 
    {
        getline(std::cin, inputStr);
        stringstream dataExtraction(inputStr);

        if (!(dataExtraction >> data) || !dataExtraction.eof() || (data < 1 || data > 3))
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << endl << "Invalid input!" << endl << "Try again (enter 1, 2, or 3): " << endl;
        } 
        else
        {
            break;
        }
    } while (true);
}