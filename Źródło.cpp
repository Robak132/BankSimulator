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

int main()
{
    Timer time;
    time.runSimulation();
    //Bank bank;
    //vector<vector<IStand*>> vec = bank.get_stands();
    //IClient* kuba = bank.randomClient();
    //IClient* oskar = bank.randomClient();
    //IStand* atm = vec[1][0];
    //cout << atm << endl;
    //cout<< vec[0][0]->isClient() << endl;
    //cout<< vec[0][0]->getSType() << endl;
    //cout << kuba << endl;
    //atm->addClient(kuba);
    //cout << atm << endl;
    ////cout<< atm->getClient() << endl;
    //atm->nextClient();
    //cout << "TU\n";
    //cout << atm->getClient() << endl;
    //atm->performOperation();
    //cout << atm->getWorkTime() << endl;
    //atm->addClient(oskar);
    //cout << atm << endl;
    //atm->nextClient();
    //cout << atm->getClient() << endl;
    //cout << atm->getWorkTime() << endl;
}

