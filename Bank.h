#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Client.h"
#include "Stand.h"
#include "BankStats.h"

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
    int open_time;
    int close_time;
};

class Bank {
private:
    BankStats statistics;
    BankSetup b_setup;
    vector<vector<IStand*>>stands;

    vector<IClient*>clients;
    vector<Employeet*> employees;

    IClient* createClient();
    void initializeClients();
    void initializeStands();
public:
    vector<vector<IStand*>> get_stands();
    int getOpenTime();
    int getCloseTime();
    BankStats& getStats();
    //Bank(int _n_clients=20, int _n_workers=5, int _n_ATMin = 1, int _nATMout = 2, int _n_CashStand = 2, int _n_InfoStand = 1, int _n_AccountStand = 2, int _open_time = 420, int _close_time = 1320);
    Bank(BankSetup = { 20,20,1,2,2,1,2,420,1320 });
    ~Bank();
    IClient* randomClient();
    void iterateThrough();
    void addClientToList(IClient* client);
};
#endif