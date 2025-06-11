#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
using namespace std;

class Stack
{
    int m_length;
    int m_top_element;
    int *m_p_elements;
    public:
        Stack(int);
        bool stackEmpty();
        int push(int);
        int pop();
        void displayElements();
};

#endif