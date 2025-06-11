#include<iostream>
using namespace std;

//In this function, we print the elements of an array, each element separated by space and spot in the last element of the array.
//In this case, it is fundamental to enter with the array and its size.
void print_array(int arg[], int length){
    cout << "The elements of the array are" << " ";
    for (int i = 0; i < length-1; i ++){
        cout << arg[i] << " ";
        }
        cout << arg[length-1] << ".";
}

//In this function, we extend any array of type int by adding the element 0 in the beginning. The input are analogous the last function (i.e., the print_array function).
int* array_extension (int array_data[], int length){
    //Declarating a pointer of type int.
    int *p_array;
    //Allocating memory to an array with one extra element.
    p_array = new int[length+1];
    //It sets the value 0 the first element of the new array.
    p_array[0] = 0;
    //Copying the array input in the new array with the following formulation new_array [i+1] = original_array[i] for i in (0, ... , length the original array -1).
    for (int i = 1; i <= length; i++){
        p_array[i] = array_data[i-1]; 
    }
    //Returning the pointer to the new array.
    return p_array;
}

//Main function
int main(){
    //Declarating and initializing an array as in the class witth the aim of test.
    int my_array [] = {2, 4, 6, 8, 10};
    //Calculating the lenght of the array above.
    int length = sizeof(my_array)/sizeof(my_array[0]);
    //Declarating a point of type int.
    int *pointer_array;
    //Calling the array_extension function with the aim of extend the my_array.
    pointer_array = array_extension(my_array, length);
    //Checking if the memory allocation was sucessfully, in case of failed, return 1 indicating failed in the program.
    if (pointer_array == nullptr){
            cout << "Memory Allocation Failed !" << endl;
            return 1;
        }
    //Output indicates sucess of memory allocation.
    cout << "Array initialized sucessfully." << endl;
    //Calling the print_array function to display the elements of the extended array.
    print_array(pointer_array, length+1);
    //Deallocating the memory allocated to the extend array.
    delete[] pointer_array;
    //Returning 0 indicating sucessful completion of the program.
    return 0;
}