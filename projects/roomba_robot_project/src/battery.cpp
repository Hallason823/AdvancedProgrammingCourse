#include "../include/battery.hpp"

Battery::Battery()
{
    m_current_level = 100;
    m_max_level = 100;
}

Battery::Battery(int current_level_param, int max_level_param)
{
    updateAtributes(current_level_param, max_level_param);
}

void Battery::chargeBattery()
{
    if (m_current_level < m_max_level){m_current_level = m_max_level;}
    else {cout << "The battery is already charged." << endl;}
}

void Battery::dischargeBattery()
{
    m_current_level-=1;
}

void Battery::updateAtributes(int current_level_param, int max_level_param)
{
    m_current_level = current_level_param;
    m_max_level = max_level_param;
}

int Battery::getCurrentLevel()
{
    return m_current_level;
}