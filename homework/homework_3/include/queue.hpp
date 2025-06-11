#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

struct QNode
{
    int data;
    QNode *p_next;
    QNode(int);
};

class Queue
{
    QNode *m_p_rear;
    QNode *m_p_front;
    public:
        Queue();
        void enQueue(int);
        int deQueue();
        bool getStatus();
        void displayQueue();
};

#endif