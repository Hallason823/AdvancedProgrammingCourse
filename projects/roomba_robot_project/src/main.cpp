#include <iostream>
#include "../include/map.hpp"
#include "../include/jimmy.hpp"
#include "../include/alfred.hpp"

int main()
{   
    Map my_map("../config/mapConfig.txt");
    Jimmy my_Jimmy("../config/JimmyConfig.txt", my_map.getSelectedAttributes());
    Alfred my_Alfred("../config/AlfredConfig.txt", my_map.getSelectedAttributes());
    
    cout << my_map;
    my_Jimmy.cleanRoom();
    my_Alfred.cleanRoom();

    return 0;
}