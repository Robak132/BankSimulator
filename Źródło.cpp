#include "Bank.h"
#include "ID.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
template<typename typ>
void show2D(vector<vector<typ>> vec)
{
    for (auto row : vec)
    {
        cout << "Row length " << row.size() << "----> |";
        for (auto elem : row)
        {
            cout << setw(4)<< elem << "|";
        }
        cout << endl;
    }
}

int main()
{
    //Bank bank(10, 7);
    //vector<vector<IStand*>> vec = bank.get_stands();
    //IStand* atm = vec[0][0];
    //show2D(vec);
    //cout<< vec[0][0]->isClient() << endl;
    //IClient* kuba = bank.randomClient();
    //atm->addClient(kuba);
    //atm->nextClient();
    //cout << vec[0][0]->isClient() << endl;
    //atm->performOperation();
    //cout << (kuba == atm->getClient()) << endl;
    //cout << kuba ->getAccount()->getMoney() << endl;
    //cout << kuba ->getMoney() << endl;
}

