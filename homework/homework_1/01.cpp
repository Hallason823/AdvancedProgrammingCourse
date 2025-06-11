#include<iostream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;

//In this function, we receive the user input of any data type, working with the adress of data. When defining the type, it's checking if the type is right. 
//If not, it's indicating the extration failed, because the input is invalid. It goes into a loop until the user to insert a valid input.
template <class Type>
void user_receive (Type& data){
    string data_str;
    do {
        getline(cin, data_str);
        stringstream data_extraction (data_str);
    if (!(data_extraction >> data) || !data_extraction.eof()){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!\nTry again." << endl;
    }
    else {
        break;
    }
    } while(true);
}

//In this function, we insert elements of an integer array. In this case, it is fundamental to enter with the array and its size.
void insert_array (int arg[], int length){
    for (int i = 0; i < length; i++){
        cout << "Insert the element " << i << " of the array:" << endl;
        //Calling the user_receive function to receive the elements of the array of its type (i.e., type = int).
        user_receive<int>(arg[i]);
        }
}
//In this function, we print the elements of an array, each element separated by space and spot in the last element of the array.
//In this case, it is fundamental to enter with the same argument of the last function (i.e., the insert_array function).
void print_array(int arg[], int length){
    cout << "The elements of the array are" << " ";
    for (int i = 0; i < length-1; i ++){
        cout << arg[i] << " ";
        }
        cout << arg[length-1] << ".";
}
//In this function, we allocate memory for an integer array. In this case, we should enter with the size of the array.
int* allocate_array (int array_size){
    //Declarating a pointer of type int.
    int *p_array;
    //Allocating memory to an array of the specified size.
    p_array = new int[array_size];
    //Returning the pointer to the allocated array.
    return p_array;
}
//Main function
int main(){
//Declating variables, i.e., the size of the array and the pointer "of int".
    int array_size;
    int *pointer_array;
    //Displaying the user should insert the size of the array.
    cout << "Insert the size of the array:" << endl;
    //Calling the user_receive function to receive the size of the array.
    user_receive<int>(array_size);
    //Calling the allocate_array function to allocate memory for the array.
    pointer_array = allocate_array(array_size);
    //Checking if the memory allocation was sucessfully, in case of failed, return 1 indicating failed in the program.
    if (pointer_array == nullptr){
            cout << "Memory Allocation Failed !" << endl;
            return 1;
        }
    //Output indicates sucess of memory allocation.
    cout << "Array initialized sucessfully." << endl;
    //Calling the insert_array function to receive the elements of the array by the user.
    insert_array(pointer_array, array_size);
    //Calling the print_array function to display the elements of the array.
    print_array(pointer_array, array_size);
    //Deallocating the memory allocated to the array.
    delete[] pointer_array;
    //Returning 0 indicating sucessful completion of the program.
    return 0;
}