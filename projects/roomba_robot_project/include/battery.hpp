#ifndef BATTERY_HPP
#define BATTERY_HPP
#include <iostream>
using namespace std;

class Battery
{
    int m_current_level;
    int m_max_level;
    public:
        Battery();
        Battery(int, int);
        void chargeBattery();
        void dischargeBattery();
        void updateAtributes(int, int);
        int getCurrentLevel();
};

#endif