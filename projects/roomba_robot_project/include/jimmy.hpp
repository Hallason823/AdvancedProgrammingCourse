#ifndef JIMMY_HPP
#define JIMMY_HPP
#include "../include/robot.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class Jimmy : public Robot
{
    bool m_completed_motion_flag;
    public:
        Jimmy(string, Map);
        void detectFreeLocalPositions();
        bool checkForAroundCollision(vector<int>);
        void move(vector<int>);
        void cleanRoom();
};

#endif