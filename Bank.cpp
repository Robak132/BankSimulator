#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <string>

#include "Bank.h"
#include "Client.h"
#include "Stand.h"
#include "Tools.h"

using namespace std;

//Bank::Bank(int _n_clients, int _n_workers, int _n_ATMin, int _n_ATMout, int _n_CashStand, int _n_InfoStand, int _n_AccountStand, int _open_time, int _close_time ) {
Bank::Bank(BankSetup _bs ) {
    if(_bs.n_workers < _bs.n_CashStand + _bs.n_InfoStand + _bs.n_AccountStand) {
        throw BadOperation("Not enough employees.");
    }

    b_setup = _bs;

    for(int i = 0; i<b_setup.n_workers; i++)
    {
        employees.push_back(new Employeet);
    }

    initializeStands();
    initializeClients();
}
Bank::~Bank() {
    for (int i = clients.size() - 1; i > 0; i--)
        delete clients[i];

    for (int i = employees.size() - 1; i > 0; i--)
        delete employees[i];

    for (int i=0;i<stands.size();i++)
        for (int j = stands[i].size() - 1; j > 0; j--)
            delete stands[i][j];
}

vector<vector<IStand*>> Bank::get_stands()
{
    return stands;
}

int Bank::getCloseTime()
{
    return  b_setup.close_time;
}

int Bank::getOpenTime()
{
    return  b_setup.open_time;
}

void Bank::initializeStands()
{
    int emp_iterator = 0;
    vector<IStand*>temp;
    for (int i = 0; i < b_setup.n_ATMin; i++)
    {
        temp.push_back(new ATMin());
    }
    stands.push_back(temp);

    temp.clear();
    for (int i = 0; i < b_setup.n_ATMout; i++)
    {
        temp.push_back(new ATMout());

    }
    stands.push_back(temp);

    temp.clear();
    for (int i = 0; i < b_setup.n_CashStand; i++)
    {
        EStand* hash = new CashStand;
        hash->setEmployeet(employees[emp_iterator++]);
        temp.push_back(hash);
    }
    stands.push_back(temp);

    temp.clear();
    for (int i = 0; i < b_setup.n_InfoStand; i++)
    {
        EStand* hash = new InfoStand;
        hash->setEmployeet(employees[emp_iterator++]);
        temp.push_back(hash);
    }
    stands.push_back(temp);

    temp.clear();
    for (int i = 0; i < b_setup.n_AccountStand; i++)
    {
        EStand* hash = new AccountStand;
        hash->setEmployeet(employees[emp_iterator++]);
        temp.push_back(hash);
    }
    stands.push_back(temp);
}

void Bank::initializeClients() {
    for (int i = 0; i < b_setup.n_clients; i++) {
        clients.push_back(createClient());
    }
}

IClient* Bank::createClient() {
    IClient* client = nullptr;
    if (Tools::randomInt() % 2 == 0)
        client = new BusinessClient();
    else
        client = new IndividualClient();
    return client;
}
IClient* Bank::randomClient() {
    return clients[Tools::randomInt() % clients.size()];
}

void Bank::addClientToList(IClient* client) {
    IStand* best_stand = nullptr;
    for (unsigned int i = 0; i < stands.size(); i++) {
        bool isGood = false;
        for (unsigned int j = 0; j < stands[i][0]->getOperations().size(); j++)
            if (stands[i][0]->getOperations()[j] == client->getReason())
                isGood = true;

        if (!isGood)
            continue;

        for (unsigned int j = 0; j < stands[i].size(); j++) {
            if (best_stand == nullptr || stands[i][j]->getQueueLength() < best_stand->getQueueLength())
                best_stand = stands[i][j];
        }
    }
    if (best_stand != nullptr)
    {
        client->setInBank(true);
        best_stand->addClient(client);
    }
}