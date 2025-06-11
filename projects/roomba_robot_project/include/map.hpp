#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Config
{
    int rows_numb;
    int columns_numb;
    int base_row;
    int base_column;
    vector<vector<int>> obstacles_positions;
};

class Map
{
    Config m_my_config;
    int **m_p_map;

    public:
        Map();
        Map(string);
        Map (Config);
        void loadAttributesFromFile(string);
        void allocateMemoryForMap();
        void insertCellObstacle(vector<int>);
        void insertRectangleObstacle(vector<int>);
        void insertObstacles();
        void updateAllAttributes(Config);
        vector<int> getMapDimension();
        int getValueMap(vector<int>);
        bool checkTheExistenceLocal(vector<int>);
        Config getSelectedAttributes();
        friend ostream& operator<< (ostream&, const Map&);

};
#endif