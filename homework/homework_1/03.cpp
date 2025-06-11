#include <iostream>
using namespace std;

//In this fuction, we operate in two integer pointers.
int do_something (int* x, int* y){

    //Saving the value pointed to by x in an auxiliary variable called temp.
    int temp = *x;
    //Multiplying (by 10) the value pointed to by y in and assign it to x.
    *x = *y * 10;
    //Multiplying (by 10) the value in the auxiliary variable temp and assign it to y.
    *y = temp * 10;
    //Returning the sum the values pointed by x and y.
    return *x + *y;
}
//Main function.
int main(){
    //It declares and initializes two integers called a and b with the aim of to test the fuction do_something.
    int a = 1, b = 2;
    //Output (with cout) of the result of calls the do_something function with the adresses of two last initialized variables.
    cout << "The result is " << do_something(&a, &b) << "." << endl;
    //It returns 0 indicating sucessful completion of the program.
    return 0;
}
