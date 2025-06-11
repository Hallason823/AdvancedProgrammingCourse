#include "../include/alfred.hpp"

Alfred::Alfred(string file, Map bot_map_param):Robot(file, bot_map_param){}

void Alfred::detectFreeLocalPositions()
{
    free_local_positions.clear();
    
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if  (bot_map.checkTheExistenceLocal({current_position[0]+i, current_position[1]+j}) && !(i == 0 && j == 0))
            {
                if (bot_map.getValueMap({current_position[0]+i, current_position[1]+j}) != 1)
                {
                    free_local_positions.push_back({current_position[0]+i, current_position[1]+j});
                }
            }
        }
    }
}

string Alfred::convertToWindRose(vector<int> ref_position)
{
    map<vector<int>, string> wind_rose_dictionary = {
        {{0,-1}, "North"},
        {{-1,-1}, "NorthWest"},
        {{-1,0}, "West"},
        {{-1,1}, "SouthWest"},
        {{0,1}, "South"},
        {{1,1}, "Southeast"},
        {{1,0}, "East"},
        {{1,-1}, "Northeast"}
    };

    return wind_rose_dictionary[{ref_position[0],ref_position[1]}];
}

void Alfred::turn(vector<int> ref_position)
{
    string destined_orientation = convertToWindRose(ref_position);

    if (bot_orientation != destined_orientation)
    {
        bot_orientation = destined_orientation;
        bot_battery.dischargeBattery();
    }
}

//The destined_position argument must be a vector of size 2, the first element represents the horizontal position
//and other one represents the vertical position
void Alfred::move(vector<int> destined_position)
{
    if (bot_error == false)
    {
        turn({destined_position[0]-current_position[0], destined_position[1]-current_position[1]});
        cout << endl << "Moving to " << destined_position[0] << " " << destined_position[1] << "." << endl << endl;
        if (bot_battery.getCurrentLevel() > 0)
        {
            current_position = destined_position;
            bot_battery.dischargeBattery();
        }
        else
        {
            cout << "Operation did not complete." << endl;
        }
    }
}

void Alfred::cleanRoom()
{
    while(bot_error == false && stopMotion() == false)
    {
        printRobotStatus();
        detectFreeLocalPositions();
        move(selectRandomPosition());
    }
}