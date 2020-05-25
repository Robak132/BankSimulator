#include "Bank.h"
#include "Timer.h"
#include "ID.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
//#define P(x) #x;


using namespace std;
template<typename typ>
void show2D(vector<vector<typ>> vec)
{
    for (auto row : vec)
    {
        cout << "Row length " << row.size() << "----> |";
        for (auto elem : row)
        {
            cout << setw(4)<< elem->getStandID().getID() << "|";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    Timer time;
    time.runSimulation();

    for (int i = 1; i < argc; ++i)
        cout << argv[i] << endl;
    return 0;
}

