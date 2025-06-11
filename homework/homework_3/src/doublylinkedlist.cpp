#include "../include/doublylinkedlist.hpp"

Node::Node(float value)
{
    data = value;
    p_next = nullptr;
    p_prev = nullptr;
    //cout << "Node created with the value " << data << endl;
}

List::List()
{
    m_p_head = nullptr;
    m_size = 0;
    //cout << "The list created successively." << endl;
}

void List::insertNode(float value)
{
    Node *node_added = new Node(value);
    if (m_p_head != nullptr)
    {
        node_added->p_next = m_p_head;
        m_p_head->p_prev = node_added;
    }
    m_p_head = node_added;
    m_size += 1;
    //cout << "The Node added with value " << m_p_head->data << " successively" << endl;
}

void List::deleteNode(Node* node_removed)
{
    if (node_removed->p_prev != nullptr)
    {
        node_removed->p_prev->p_next = node_removed->p_next;
    }
    else 
    {
        m_p_head = node_removed->p_next;
    }

    if (node_removed->p_next != nullptr)
    {
        node_removed->p_next->p_prev = node_removed->p_prev;
    }
    m_size -= 1;
}

void List::displayList()
{
    Node *actual_node = m_p_head;
    int count = 1;
    cout << "Nullptr" << endl;
    while (actual_node != nullptr)
    {
        cout << "Node " << count << " with value of " << actual_node->data << endl;
        actual_node = actual_node->p_next;
        count += 1;
    }
    cout << "Nullptr" << endl;
}

void List::removeDuplicates()
{
    if (m_size > 1)
    {
        HashTable table(getNearestLargerPrime(m_size));
        Node *actual_node = m_p_head;
        while (actual_node != nullptr)
        {
            if (table.searchKey(actual_node->data) == -1)
            {
                table.insertKey(actual_node->data);
            }
            else
            {
                deleteNode(actual_node);
            }
            actual_node = actual_node->p_next;
        }
    }
}