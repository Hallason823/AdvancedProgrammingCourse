#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include <iostream>
#include "./auxiliarytools.hpp"
#include "./hashtable.hpp"
using namespace std;

struct Node 
{
    float data;
    Node *p_next;
    Node *p_prev;
    Node(float);
};

class List
{
    Node *m_p_head;
    int m_size; 
    public:
        List();
        void insertNode(float);
        void deleteNode(Node*);
        void displayList();
        void removeDuplicates();
};

#endif