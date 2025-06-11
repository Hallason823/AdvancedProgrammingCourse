#include "../include/map.hpp"

Map::Map()
{
    m_my_config.rows_numb = 0;
    m_my_config.columns_numb = 0;
    m_my_config.base_column = -1;
    m_my_config.base_row = -1;
    m_p_map = nullptr;
}

Map::Map(string map_config_file_adress)
{
   loadAttributesFromFile(map_config_file_adress);
   allocateMemoryForMap();
   insertObstacles();
}

Map::Map(Config initialized_attributes)
{  
    updateAllAttributes(initialized_attributes);
}

void Map::allocateMemoryForMap()
{
    m_p_map = new int* [m_my_config.rows_numb];
    for (int i = 0; i < m_my_config.rows_numb; i++){m_p_map[i] = new int[m_my_config.columns_numb]();}
}

void Map::loadAttributesFromFile(string config_file_adress)
{   
    string line;
    int value;
    vector<int> single_obstacle_position;
    ifstream file (config_file_adress);

    if (file.is_open())
    {   
        file >> m_my_config.rows_numb >> m_my_config.columns_numb >> m_my_config.base_row >> m_my_config.base_column;
        getline(file, line);
        while(getline(file, line))
        {
            istringstream stream(line);
            while(stream >> value){single_obstacle_position.push_back(value);}
            m_my_config.obstacles_positions.push_back(single_obstacle_position);
            single_obstacle_position.clear();
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void Map::insertCellObstacle(vector<int> single_obstacle_position)
{
    if (checkTheExistenceLocal(single_obstacle_position))
    {
        m_p_map[single_obstacle_position[0]][single_obstacle_position[1]] = 1;
    }
    else 
    {
        cout << endl << "The position does not exit on the map." << endl << endl;
    }
}

void Map::insertRectangleObstacle(vector<int> single_obstacle_position)
{
    for (int i = single_obstacle_position[0]; i <= single_obstacle_position[2]; i++)
    {
        for (int j = single_obstacle_position[1]; j <= single_obstacle_position[3]; j++)
        {
            if (checkTheExistenceLocal({i, j}))
            {
                 m_p_map[i][j] = 1;
            }
            else 
            {
                cout << endl << "The position does not exit on the map." << endl << endl;
            }
        }
    }
}

void Map::insertObstacles()
{
    int obstacle_size;
        for(const auto single_obstacle_position : m_my_config.obstacles_positions){
            obstacle_size = single_obstacle_position.size();
            if (obstacle_size == 2){insertCellObstacle(single_obstacle_position);}
            else if (obstacle_size == 4){insertRectangleObstacle(single_obstacle_position);}
            else {cout << "Error!" << endl << "Invalidy entry." << endl;}
        }
}

void Map::updateAllAttributes(Config initialized_attributes)
{
    m_my_config = initialized_attributes;
    allocateMemoryForMap();
    insertObstacles();
}

vector <int> Map::getMapDimension()
{
    return {m_my_config.rows_numb, m_my_config.columns_numb};
}

int Map::getValueMap(vector<int> position)
{
    return m_p_map[position[0]][position[1]];
}

bool Map::checkTheExistenceLocal (vector<int> local){

    return local[0] >= 0 && local[0] < m_my_config.rows_numb 
    && local[1] >= 0 && local[1] < m_my_config.columns_numb ? true : false;

}

Config Map::getSelectedAttributes()
{
    return m_my_config;
}


ostream& operator<< (ostream& os, const Map& param)
{
    if (param.m_p_map != nullptr)
        {
            os << "The map is" << endl << endl;
            for (int i = 0; i < param.m_my_config.rows_numb; i++)
            {
                for (int j = 0; j < param.m_my_config.columns_numb; j++)
                {
                    os << param.m_p_map[i][j] << ' ';
                }
                    os << endl;
            }
            os << endl; 
        }
        else {os << "The map initialized as nullptr." << endl;}
}