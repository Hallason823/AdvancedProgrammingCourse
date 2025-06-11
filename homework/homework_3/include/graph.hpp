#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "./auxiliarytools.hpp"
#include "./queue.hpp"
using namespace std;

struct GNode
{
    string color;
    int distance;
    int prev;
    GNode();
};

class Graph
{
    int m_nodes_numb;
    vector<vector<int>> m_table;
    GNode *m_p_nodes_list;
    public:
        Graph(string);
        void initialize_single_source(int);
        void relax(int, int);
        int extractTheMinimum();
        void dijkstra(int);
        void printPath(int, int);
        friend ostream& operator<< (ostream&, const Graph&);
};

#endif