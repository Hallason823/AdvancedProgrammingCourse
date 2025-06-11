#include "../include/robot.hpp"

Robot::Robot(string file, Map bot_map_param) : gen(mt19937(chrono::high_resolution_clock::now().time_since_epoch().count())), bot_map (bot_map_param), bot_error(false)
{
    loadConfigFromFile(file);
    bot_battery.updateAtributes(my_bot_config.battery_current_level, my_bot_config.battery_max_level);
}

void Robot::loadConfigFromFile(string config_file_adress)
{
    ifstream file (config_file_adress);

    if (file.is_open())
    {
        int current_position_param[2];
        file >> my_bot_config.bot_name;
        file >> current_position_param[0] >> current_position_param[1];
        file >> my_bot_config.battery_current_level >> my_bot_config.battery_max_level;
        if (!file.eof()){file >> bot_orientation;}
        else {bot_orientation = "None";}
        current_position.push_back(current_position_param[0]);
        current_position.push_back(current_position_param[1]);
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

vector<int> Robot::selectRandomPosition()
{
    if (free_local_positions.empty()) {
        bot_error = true;
        throw std::out_of_range("It doesn't existe any free local positions.");
    }
    uniform_int_distribution<> distribution(0, free_local_positions.size()-1);
    int ramdon_index = distribution(gen);
    return free_local_positions[ramdon_index];
}

void Robot::checkBatteryStatus()
{
    cout << "The battery status is " << bot_battery.getCurrentLevel() << "%." << endl;
}

bool Robot::stopMotion()
{
    if(bot_battery.getCurrentLevel() == 0)
    {
        cout << "The robot stopped, it is discharged." << endl << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Robot::printRobotStatus()
{
    cout << "The robot name is " << my_bot_config.bot_name << "." << endl;
    cout << "The robot current position is " << current_position[0] << " " << current_position[1] << "." << endl;
    cout << "The robot orientation is " << bot_orientation << "." << endl;
    checkBatteryStatus();
}