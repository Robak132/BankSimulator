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

using namespace std;

Bank::Bank(int _n_clients, int _n_workers, int _n_ATMin, int _n_ATMout, int _n_CashStand, int _n_InfoStand, int _n_AccountStand) {
    if(_n_workers < _n_CashStand + _n_InfoStand + _n_AccountStand)
    {
        throw BadOperation("Not enough employees.");
    }

    b_setup.n_workers = _n_workers;
    b_setup.n_clients = _n_clients;
    b_setup.n_ATMin = _n_ATMin;
    b_setup.n_ATMout = _n_ATMout;
    b_setup.n_CashStand = _n_CashStand;
    b_setup.n_InfoStand = _n_InfoStand;
    b_setup.n_AccountStand = _n_AccountStand;
    

    for(int i = 0; i<b_setup.n_workers; i++)
    {
        employees.push_back(new Employeet);
    }


    initializeStands();
    initializeClients();

}
Bank::~Bank() {
}



vector<vector<IStand*>> Bank::get_stands()
{
    return stands;
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

void Bank::initializeClients()
{
    namefile.open("name.txt");
    surnamefile.open("surname.txt");

    string line;
    while (getline(namefile, line)) {
        namelist.push_back(line);
    }
    while (getline(surnamefile, line)) {
        surnamelist.push_back(line);
    }
    for (int i = 0; i < b_setup.n_clients; i++) {
        clients.push_back(createClient());
    }

    namefile.close();
    surnamefile.close();
}

IClient* Bank::createClient() {
    IClient* client = nullptr;
    if (randomInt() % 2 == 0)
        client = new BusinessClient(randomName(), randomSurname(), "DID123");
    else
        client = new IndividualClient(randomName(), randomSurname(), "DID123");
    return client;
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
        best_stand->addClient(client);
}

int Bank::randomInt() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    return generator();
}
IClient* Bank::randomClient() {
    return clients[randomInt() % clients.size()];
}
string Bank::randomName() {
    return "Jakub";//namelist[randomInt() % namelist.size()];
}
string Bank::randomSurname() {
    return "Mazur";//surnamelist[randomInt() % surnamelist.size()];
}

//numt::PossibleOperations Bank::randomReason()
//{
//
//}