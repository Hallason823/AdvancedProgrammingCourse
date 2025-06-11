#include "../include/queue.hpp"

QNode::QNode(int value)
{
    data = value;
    p_next = nullptr;
}

Queue::Queue()
{
    m_p_rear = nullptr;
    m_p_front = nullptr;
}

void Queue::enQueue(int value)
{
    QNode *node_added = new QNode(value);
    if (m_p_rear == nullptr)
    {
        m_p_front = node_added;
    }
    else
    {
        m_p_rear->p_next = node_added;
    }
    m_p_rear = node_added;
    cout << "Enqueue " << node_added->data << endl;
}

int Queue::deQueue()
{
    int removed_data = -1;
    if (m_p_rear == nullptr && m_p_front == nullptr)
    {
        cout << "Empty queue." << endl;
    }
    else if (m_p_rear == m_p_front)
    {
        cout << "Dequeue " << m_p_front->data << endl;
        removed_data = m_p_front->data;
        m_p_rear = nullptr;
        m_p_front = nullptr; 
    }
    else
    {
        cout << "Dequeue " << m_p_front->data << endl;
        removed_data = m_p_front->data ;
        m_p_front = m_p_front->p_next;
    }
    return removed_data;
}

bool Queue::getStatus()
{
    return m_p_front != nullptr ? true : false;
}

void Queue::displayQueue()
{
    QNode *actual_qnode = m_p_front;
    int count = 1;
    while (actual_qnode != nullptr)
    {
        cout << "Node " << count << " with value of " << actual_qnode->data << endl;
        actual_qnode = actual_qnode->p_next;
        count += 1;
    }
    cout << endl;
}