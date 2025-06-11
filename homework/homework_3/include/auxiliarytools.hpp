#ifndef AUXILIARYTOOLS_HPP
#define AUXILIARYTOOLS_HPP
#include <iostream>
#include <vector>
#include<string>
#include<sstream>
#include<limits>
#include <fstream>
using namespace std;

bool isPrime(int);
int getNearestLargerPrime(int);
vector<vector<int>> loadDatasFromFile(string);
void receiveUserInput(int&);

#endif