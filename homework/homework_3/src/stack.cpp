#include "../include/stack.hpp"

Stack::Stack(int length)
{
    int m_length = length;
    m_p_elements = new int[m_length];
    m_top_element = -1;
}

bool Stack::stackEmpty()
{
    return m_top_element == -1 ? true : false;
}

int Stack::push(int pushed_numb)
{
    if (m_top_element<m_length-1)
    {
        m_top_element += 1;
        m_p_elements[m_top_element] = pushed_numb;
        cout << pushed_numb << " pushed to the stack." << endl;
        return 1;
    }
    else if (m_top_element == m_length-1)
    {
    
        cout << "The stack is full" << endl;
        return 0;
    }
}

int Stack::pop()
{
    if (stackEmpty())
    {
        cout<<"Empty stack"<<endl;
        return 0;
    }
    else
    {
        cout << m_p_elements[m_top_element] << " is popped from the stack." << endl;
        m_top_element -= 1;
        return 1;
    }
}

void Stack::displayElements()
{
    if (stackEmpty())
    {
        cout << "Try to print an Empty Stack" << endl;
    }
    else
    {
        cout << "The elements of the stack are" << endl;
        for (int i = 0; i < m_top_element+1; i++)
        {
            cout << m_p_elements[i] << ' ';
        }
        cout << endl;
    }
}