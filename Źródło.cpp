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

    //cout << P(numt::infoLoan);
    Timer time;
    time.runSimulation();
    Bank bank;
    vector<vector<IStand*>> vec = bank.get_stands();
    IStand* atm = vec[0][0];
    cout << atm << endl;
    show2D(vec);
    cout<< vec[0][0]->isClient() << endl;
    cout<< vec[0][0]->getSType() << endl;
    IClient* kuba = bank.randomClient();
    cout << kuba << endl;
    atm->addClient(kuba);
    cout << atm << endl;
    atm->nextClient();
}

