#include<iostream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;

//Struct to represent a matrix with members: pointer of a pointer of int and number of rows and columns.
struct matrix {
    int** pointer;
    int rows;
    int columns;
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
//In this function, we insert elements of an integer matrix. In this case, it is fundamental to enter with the matrix and its size (i.e., the number of rows and columns).
void insert_matrix (int** arg, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j =0; j < columns; j++){
            cout << "Insert the element " << i << " " << j <<" of the matrix:" << endl;
            //Calling the user_receive function to receive the elements of the matrix of its type (i.e., type = int).
            user_receive<int>(arg[i][j]);
        }
    }
}
//In this function, we print the elements of an matrix, each row by row and each element separated by space in the columns.
//In this case, it is fundamental to enter with the same argument of the last function (i.e., the insert_matrix function).
void print_matrix(int** arg, int rows, int columns){
     for (int i = 0; i < rows; i++){
        for (int j =0; j < columns; j++){
            cout << arg [i][j] << " ";
        }
        cout << "\n";
    }
}
//In this function, we allocate memory for an integer matrix. In this case, we should enter with the size of the matrix (i.e., the number of rows and columns).
int** allocate_matrix (int rows,int columns){ 
    //Declarating a pointer of pointer of type int. 
    int** p_matrix;
    //Allocating memory to a pointer array "of int" of the specified size, it represents the rows of the matrix.
    p_matrix = new int*[rows];
    //Allocating memory to each row of the specified size.
    for (int i = 0; i < columns; i++){
        p_matrix[i] = new int[columns];
    }
    //Returning the pointer of pointer.
    return p_matrix;
}

//In this function, the user initializes a matrix.
void matrix_inicialization (int** &p_matrix, int &rows, int &columns, string order_matrix){
    //Displaying the user should insert the number of rows of the matrix.
    cout << "Insert the number of rows of the " + order_matrix + " matrix:" << endl;
    //Calling the user_receive function to receive the number of rows of the matrix.
    user_receive<int>(rows);
    //Displaying the user should insert the number of columns of the matrix.
    cout << "Insert the number of columns of the " + order_matrix + " matrix:" << endl;
    //Calling the user_receive function to receive the number of columns of the matrix.
    user_receive<int>(columns);
    //Allocating memory for the mattrix.
    p_matrix = allocate_matrix(rows, columns);
    //Calling the insert_array function to get user input for each element of the matrix.
    insert_matrix(p_matrix, rows, columns);
}
//In this function, we check if the number of row (or column) of matrices are equals. If they are for both (i.e., the number rows and columns), then the sum is possible.
bool sum_possibility (int length_st, int length_nd){return (length_st == length_nd) ? true : false;}
//In this function, it performs element-wise sum of two matrices.
void operation_sum_matrix (int** matrix_st, int** matrix_nd,int** matrix_sum, int rows, int columns){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix_sum[i][j] = matrix_st[i][j]+matrix_nd[i][j];
        }
        }
}
//Main function.
int main(){
    //Declaring matrix to represent the first, second, and sum matrices.
   matrix matrix_st, matrix_nd, matrix_sum;
    //Initializing the first matrix, and after, the second one.
    matrix_inicialization(matrix_st.pointer, matrix_st.rows, matrix_st.columns, "first");
    matrix_inicialization(matrix_nd.pointer, matrix_nd.rows, matrix_nd.columns, "second");
    //Checking if the memory allocation was sucessfully, in case of failed, return 1 indicating failed in the program.
    if (matrix_st.pointer == nullptr || matrix_nd.pointer == nullptr){
            cout << "Memory Allocation Failed !" << endl;
            return 1;
        }
    //Output indicates sucess of memory allocation.
    cout << "Arrays/Matrices initialized sucessfully." << endl;
    //Checking if the sum of matrices is possible, in case of failed, it shows the sum isn't possible, also, returning 1 indicating failed in the program.
    if (sum_possibility(matrix_st.rows, matrix_nd.rows) == false || sum_possibility(matrix_st.columns, matrix_nd.columns) == false){
        cout << "Error!\nThe matrices have different sizes.\nIt isn't possible to use the sum operation between these matrices." << endl;
        return 1;
    }
    //Allocating memory for the sum matrix.
    matrix_sum.rows = matrix_st.rows;
    matrix_sum.columns = matrix_st.columns;
    matrix_sum.pointer = allocate_matrix(matrix_sum.rows, matrix_sum.columns);
    //Performing the element-wise sum of the two matrices.
    operation_sum_matrix(matrix_st.pointer, matrix_nd.pointer, matrix_sum.pointer, matrix_sum.rows, matrix_sum.columns);
    //Output indicates sucess of the sum operation.
    cout << "Operation sum performed successfully!\nThe result of sum operation is" << endl;
    //Calling the print_array function to display the elements of the sum matrix.
    print_matrix(matrix_sum.pointer, matrix_sum.rows, matrix_sum.columns);
    //Deallocating the memory allocated for the matrices.
    delete[] matrix_st.pointer;
    delete[] matrix_nd.pointer;
    delete[] matrix_sum.pointer;
    //Returning 0 indicating sucessful completion of the program.
    return 0;
}