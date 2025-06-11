#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>
using namespace std;

struct TNode 
{
    int key;
    TNode *p_father, *p_left_son, *p_right_son;
    TNode(int);
};

class BinaryTree
{
    TNode *m_p_root;
    public:
        BinaryTree();
        TNode* findMinByNode(TNode*);
        TNode* findMaxByNode(TNode*);
        TNode* findSuccessorByNode(TNode*);
        TNode* findPredecesssorByNode(TNode*);
        void insertNode(int);
        void transplant(TNode*, TNode*);
        void deleteNode(int);
        TNode* searchKey(TNode*, int);
        TNode* getRoot();
        void displayBinaryTreeInOrder(TNode*);
};

#endif