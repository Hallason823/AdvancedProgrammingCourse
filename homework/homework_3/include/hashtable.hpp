#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <limits>
using namespace std;

class HashTable
{
    int m_length;
    int *m_p_keys;
    public:
        HashTable(int);
        void fillTable();
        int calculateINdexByHashFunction(int, int);
        int insertKey(int);
        int searchKey(int);
        void removeKey(int);

};

#endif