#include "../include/hashtable.hpp"

HashTable::HashTable(int length)
{
    m_length = length;
    m_p_keys = new int[m_length];
    fillTable();
}

void HashTable::fillTable()
{
    for (int i = 0; i < m_length; i++)
    {
        m_p_keys[i] = numeric_limits<int>::min();
    }
}

int HashTable::calculateINdexByHashFunction(int key, int i)
{
    return (key+i)%m_length;
}

int HashTable::insertKey(int key)
{
    int i = 0;
    int j;
    while (i < m_length)
    {
        j = calculateINdexByHashFunction(key, i);
        if (m_p_keys[j] == numeric_limits<int>::min() || m_p_keys[j] == numeric_limits<int>::max())
        {
            m_p_keys[j] = key;
            return j;
        }
        i += 1;
    }
    cout << "Error: The table has overflowed" << endl;
    return -1;
}

int HashTable::searchKey(int key)
{
    int i = 0;
    int j;
    do
    {
        j = calculateINdexByHashFunction(key, i);
        if (m_p_keys[j] == key)
        {
            return j;
        }
        i += 1;
    } 
    while (i < m_length && m_p_keys[j] != numeric_limits<int>::min());
    return -1;
}

void HashTable::removeKey(int key)
{
    int key_index = searchKey(key);
    if (key_index == -1)
    {
        cout << endl << "The Key does not exist in the table." << endl;
    }
    else
    {
        m_p_keys[key_index] = numeric_limits<int>::max();
        cout << endl << "The key " << key << "With index" << key_index << "has removed in the table." << endl;
    }
}