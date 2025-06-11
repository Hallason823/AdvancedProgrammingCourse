#include "../include/graph.hpp"

GNode::GNode()
{
    color = "White";
    distance = numeric_limits<int>::max();
    prev = -1;
}

Graph::Graph(string file_path)
{
    vector<vector<int>> all_datas = loadDatasFromFile(file_path);
    m_table = (all_datas.empty()) ? vector<vector<int>>() : all_datas;
    m_nodes_numb = m_table.size();
    m_p_nodes_list = new GNode[m_nodes_numb];
}

void Graph::initialize_single_source(int base_node_identifier)
{
    for (int node = 0; node < m_nodes_numb; node++)
    {
        m_p_nodes_list[node].color = "White";
        m_p_nodes_list[node].distance = numeric_limits<int>::max();
        m_p_nodes_list[node].prev = -1;
    }
    m_p_nodes_list[base_node_identifier].color = "Gray";
    m_p_nodes_list[base_node_identifier].distance = 0;
}

void Graph::relax(int u_node_identifier, int v_node_identifier)
{
    if (m_p_nodes_list[v_node_identifier].distance > m_p_nodes_list[u_node_identifier].distance + m_table[u_node_identifier][v_node_identifier])
    {
        m_p_nodes_list[v_node_identifier].distance = m_p_nodes_list[u_node_identifier].distance + m_table[u_node_identifier][v_node_identifier];
        m_p_nodes_list[v_node_identifier].prev = u_node_identifier;
        if (m_p_nodes_list[v_node_identifier].color != "Black")
            {
                m_p_nodes_list[v_node_identifier].color = "Gray";
            }
    }
}

int Graph::extractTheMinimum()
{
    int min_node = -1;
    int min_distance = numeric_limits<int>::max();
    for (int v = 0; v < m_nodes_numb; v++)
    {
        if(m_p_nodes_list[v].color != "Black" && m_p_nodes_list[v].distance < min_distance)
        {
            min_node = v;
            min_distance = m_p_nodes_list[v].distance;
        }
    }
    return min_node;
}

void Graph::dijkstra(int base_node_identifier)
{
    initialize_single_source(base_node_identifier);
    int u = extractTheMinimum();
    while (u != -1)
    {
        for (int v = 0; v < m_nodes_numb; v++)
        {
            if (m_table[u][v] != 0)
            {
                relax(u, v);
            }
        }
        m_p_nodes_list[u].color = "Black";
        u = extractTheMinimum();
    }
}

void Graph::printPath(int starting_node, int arrival_node)
{
    dijkstra(starting_node);
    cout << endl << "Path from " << starting_node << " to " << arrival_node << endl;
    vector<int> path;
    int v = arrival_node;
    while (m_p_nodes_list[v].distance != 0)
    {
        path.push_back(v);
        v = m_p_nodes_list[v].prev;
    }
    path.push_back(starting_node);
    for (int i = path.size()-1; i >-1; i--)
    {
        cout << path[i] << ' ';
    }
}

ostream& operator<< (ostream& os, const Graph& param)
{
    if (param.m_table != vector<vector<int>>())
        {
            os << "The graph is" << endl << endl;
            for (int i = 0; i < param.m_nodes_numb; i++)
            {
                for (int j = 0; j < param.m_nodes_numb; j++)
                {
                    os << param.m_table[i][j] << ' ';
                }
                    os << endl;
            }
            os << endl; 
        }
        else {os << "The graph initialized as NULL." << endl;}
}