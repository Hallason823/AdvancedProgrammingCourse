#include<iostream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;

//Struct to represent a vector with members: pointer of int and its length.
struct vector{
    int* pointer;
    int length;
};
//In this function, we receive the user input of any data type, working with the adress of data. When defining the type, it's checking if the type is right. 
//If not, it's indicating the extration failed, because the input is invalid. It goes into a loop until the user insert a valid input.
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
//In this function, the user initializes a vector.
void vector_inicialization (int* &p_vector, int &length, string order_vector){
    //Displaying the user should insert the size of the vector.
    cout << "Insert the size of the " + order_vector + " vector:" << endl;
    //Calling the user_receive function to receive the length of the vector.
    user_receive<int>(length);
    //Allocating memory for the vector.
    p_vector = allocate_array(length);
    //Calling the insert_array function to get user input for each element of the vector.
    insert_array(p_vector, length);
}
//In this function, we check if the sum of two vectors is possible.
bool sum_possibility (int length_st, int length_nd){return (length_st == length_nd) ? true : false;}
//In this function, it performs element-wise sum of two vectors.
void operation_sum_vectors (int vector_st[], int vector_nd[], int* &p_vector_sum, int length){

    for (int i = 0; i < length; i++){
        p_vector_sum[i] = vector_st[i] + vector_nd[i];
    }
}
//Main function.
int main(){
    //Declaring vectors to represent the first, second, and sum vectors.
    vector vector_st, vector_nd, vector_sum;
    //Initializing the first vector, and after, the second one.
    vector_inicialization(vector_st.pointer, vector_st.length, "first");
    vector_inicialization(vector_nd.pointer, vector_nd.length, "second");
    //Checking if the memory allocation was sucessfully, in case of failed, return 1 indicating failed in the program.
    if (vector_st.pointer == nullptr || vector_nd.pointer == nullptr){
            cout << "Memory Allocation Failed !" << endl;
            return 1;
        }
    //Output indicates sucess of memory allocation.
    cout << "Arrays/Vectors initialized sucessfully." << endl;
    //Checking if the sum of vectors is possible, in case of failed, it shows: the sum isn't possible, also, returning 1 indicating failed in the program.
    if (sum_possibility(vector_st.length, vector_nd.length) == false){
        cout << "Error!\nThe sizes of vectors are differents.\nIt isn't possible to use the sum operation between these vectors." << endl;
        return 1;
    }
    //Allocating memory for the sum vector.
    vector_sum.length = vector_st.length;
    vector_sum.pointer = allocate_array(vector_sum.length);
    //Performing the element-wise sum of the two vectors.
    operation_sum_vectors(vector_st.pointer, vector_nd.pointer, vector_sum.pointer, vector_sum.length);
    //Output indicates sucess of the sum operation.
    cout << "Operation sum performed successfully!" << endl;
    //Calling the print_array function to display the elements of the sum vector.
    print_array(vector_sum.pointer, vector_sum.length);
    //Deallocating the memory allocated for the vectors.
    delete[] vector_st.pointer;
    delete[] vector_nd.pointer;
    delete[] vector_sum.pointer;
    //Returning 0 indicating sucessful completion of the program.
    return 0;
}