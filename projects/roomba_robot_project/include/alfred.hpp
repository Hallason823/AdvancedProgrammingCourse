#ifndef ALFRED_HPP
#define ALFRED_HPP
#include "../include/robot.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <map>
using namespace std;


class Alfred : public Robot
{
    public:
        Alfred(string, Map);
        void detectFreeLocalPositions();
        string convertToWindRose(vector<int>);
        void turn(vector<int>);
        void move(vector<int>);
        void cleanRoom();
        
};

#endif