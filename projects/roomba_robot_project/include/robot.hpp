#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "../include/map.hpp"
#include "../include/battery.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

struct BotConfig{
    string bot_name;
    int battery_current_level;
    int battery_max_level;
};

class Robot
{
    protected:
        BotConfig my_bot_config;
        Map bot_map;
        vector<int> current_position;
        vector<vector<int>> free_local_positions;
        string bot_orientation;
        Battery bot_battery;
        mt19937 gen;
        bool bot_error;

    public:
        Robot(string, Map);
        void loadConfigFromFile(string);
        virtual void detectFreeLocalPositions(){};
        vector<int> selectRandomPosition();
        virtual void move(vector<int>){};
        void checkBatteryStatus();
        bool stopMotion();
        virtual void cleanRoom(){};
        void printRobotStatus();
};

#endif