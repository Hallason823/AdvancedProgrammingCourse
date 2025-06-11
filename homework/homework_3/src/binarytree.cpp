#include "../include/binarytree.hpp"

TNode::TNode(int key_value)
{
    key = key_value;
    p_father = nullptr;
    p_left_son = nullptr;
    p_right_son = nullptr;
}

BinaryTree::BinaryTree()
{
    m_p_root = nullptr;
    //cout << "The Binary Tree created." << endl; 
}

TNode* BinaryTree::findMinByNode(TNode* node)
{
    while (node->p_left_son != nullptr)
    {
        node = node->p_left_son;
    }
    return node;
}

TNode* BinaryTree::findMaxByNode(TNode* node)
{
    while (node->p_right_son != nullptr)
    {
        node = node->p_right_son;
    }
    return node;
}

TNode* BinaryTree::findSuccessorByNode(TNode* node)
{
    if (node->p_right_son != nullptr)
    {
        return findMinByNode(node->p_right_son);
    }
    TNode *aux_node = node->p_father;
    while (aux_node != nullptr && node == aux_node->p_right_son)
    {
        node = aux_node;
        aux_node = aux_node->p_father;
    }
    return aux_node;
}

TNode* BinaryTree::findPredecesssorByNode(TNode* node)
{
    if (node->p_left_son != nullptr)
    {
        return findMaxByNode(node->p_left_son);
    }
    TNode *aux_node = node->p_father; 
    while (aux_node != nullptr && node == aux_node->p_left_son)
    {
        node = aux_node;
        aux_node = aux_node->p_father;
    }
    return aux_node;
}

void BinaryTree::insertNode(int value)
{
    TNode *node_z = new TNode(value);
    TNode *aux_node_y = nullptr;
    TNode *aux_node_x = m_p_root;
    while (aux_node_x != nullptr)
    {
        aux_node_y = aux_node_x;
        aux_node_x = (node_z->key < aux_node_x->key) ? aux_node_x->p_left_son : aux_node_x->p_right_son;
    }
    node_z->p_father = aux_node_y;
    if (aux_node_y == nullptr)
    {
        m_p_root = node_z;
    }
    else if (node_z->key < aux_node_y->key)
    {
        aux_node_y->p_left_son = node_z;
    }
    else
    {
        aux_node_y->p_right_son = node_z;
    }
}

void BinaryTree::transplant(TNode* node, TNode* moved_node)
{
    if (node->p_father == nullptr)
    {
        m_p_root = moved_node;
    }
    else if (node == node->p_father->p_left_son)
    {
        node->p_father->p_left_son = moved_node;
    }
    else
    {
        node->p_father->p_right_son = moved_node;
    }
    if (moved_node != nullptr)
    {
        moved_node->p_father = node->p_father;
    }
}

void BinaryTree::deleteNode(int value)
{
    TNode *node = searchKey(m_p_root, value);
    if (node->p_left_son == nullptr)
    {
        transplant(node, node->p_right_son);
    }
    else if (node->p_right_son == nullptr)
    {
        transplant(node, node->p_left_son);
    }
    else
    {
        TNode *aux_node = findMinByNode(node->p_right_son);
        if (aux_node->p_father != node)
        {
            transplant(aux_node, aux_node->p_right_son);
            aux_node->p_right_son = node->p_right_son;
            aux_node->p_right_son->p_father = aux_node;
        }
        transplant(node, aux_node);
        aux_node->p_left_son = node->p_left_son;
        aux_node->p_left_son->p_father = aux_node;
    }
}

TNode* BinaryTree::searchKey(TNode* node, int key)
{
    while (node != nullptr && key != node->key)
    {
        node = (key < node->key) ? node->p_left_son : node->p_right_son;
    }
    return node;
}

TNode* BinaryTree::getRoot()
{
    return m_p_root;
}

void BinaryTree::displayBinaryTreeInOrder(TNode* node)
{
    if (node != nullptr )
    {
        displayBinaryTreeInOrder(node->p_left_son);
        cout << node->key << ' ';
        displayBinaryTreeInOrder(node->p_right_son);
    }
}