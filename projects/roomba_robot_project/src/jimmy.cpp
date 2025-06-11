#include "../include/jimmy.hpp"

Jimmy::Jimmy(string file, Map bot_map_param):Robot(file, bot_map_param){m_completed_motion_flag = true;}

void Jimmy::detectFreeLocalPositions()
{
    int relative_positions[][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    free_local_positions.clear();
    for (int i = 0; i < 4; i ++)
    {
        if (bot_map.checkTheExistenceLocal({current_position[0]+relative_positions[i][0], current_position[1]+relative_positions[i][1]}))
            {
                free_local_positions.push_back({current_position[0]+relative_positions[i][0], current_position[1]+relative_positions[i][1]});
            }
    }
}

bool Jimmy::checkForAroundCollision(vector<int> destined_position)
{
    return bot_map.getValueMap(destined_position) == 1 ? true : false;
}

void Jimmy::move(vector<int> destined_position)
{
    if (bot_error == false)
    {
        cout << endl << "Moving to " << destined_position[0] << " " << destined_position[1] << "." << endl << endl;
        bot_battery.dischargeBattery();
        if (checkForAroundCollision(destined_position) == false)
        {
            current_position = destined_position;
            m_completed_motion_flag = true;
        }
        else
        {
            cout  << "The operation failed, the location is occupied." << endl;
            auto it = find(free_local_positions.begin(), free_local_positions.end(), destined_position);
            free_local_positions.erase(it);
        }
    }
}

void Jimmy::cleanRoom()
{
    while(bot_error == false && stopMotion() == false)
    {
        if (m_completed_motion_flag == true)
        {
            detectFreeLocalPositions();
            m_completed_motion_flag = false;
            printRobotStatus();
        }
        move(selectRandomPosition());
    }
}