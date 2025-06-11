#include "../include/auxiliarytools.hpp"

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int getNearestLargerPrime(int number)
{
    int next_prime = number++;
    while (isPrime(next_prime) == false)
    {
        next_prime += 1;
    }
    return next_prime;
}

vector<vector<int>> loadDatasFromFile(string file_path)
{
    ifstream file(file_path);
    string line;
    int value;
    vector<int> datas_by_line;
    vector<vector<int>> all_datas;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            istringstream stream(line);
            while(stream >> value){datas_by_line.push_back(value);}
            all_datas.push_back(datas_by_line);
            datas_by_line.clear();
        }
    }
    else
    {
        cout<< "Fail opening the file." << endl;
    }
    return all_datas;
}

void receiveUserInput(int& data)
{
    std::string inputStr;
    do 
    {
        getline(std::cin, inputStr);
        stringstream dataExtraction(inputStr);

        if (!(dataExtraction >> data) || !dataExtraction.eof() || (data < 1 || data > 2))
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << endl << "Invalid input!" << endl << "Try again (enter 1 or 2): " << endl << endl;
        } 
        else
        {
            break;
        }
    } while (true);
}