#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Client.h"
#include "Stand.h"

using namespace std;

struct BankSetup
{
    int n_workers;
    int n_clients;
    int n_ATMin;
    int n_ATMout;
    int n_CashStand;
    int n_InfoStand;
    int n_AccountStand;
};

class Bank {
private:
    BankSetup b_setup;
    vector<vector<IStand*>>stands;
    
    ifstream namefile;
    vector<string>namelist;
    ifstream surnamefile;
    vector<string>surnamelist;

    vector<IClient*>clients;
    vector<Employeet*> employees;

    int randomInt();
    string randomName();
    string randomSurname();
    //numt::PossibleOperations randomReason();
    IClient* createClient();
    void initializeClients();
    void initializeStands();
public:
    vector<vector<IStand*>> get_stands();
    Bank(int _n_clients, int _n_workers=5, int _n_ATMin = 1, int _nATMout = 2, int _n_CashStand = 2, int _n_InfoStand = 1, int _n_AccountStand = 2);
    ~Bank();
    IClient* randomClient();
    void addClientToList(IClient* client);
};
#endif