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

class Bank {
private:
    int n_workers;
    ofstream log;
    
    ifstream namefile;
    vector<string>namelist;
    ifstream surnamefile;
    vector<string>surnamelist;

    list<Stand>stands;
    list<Client*>clients;
public:
    Bank(int _n_workers, string filename="log.txt");
    ~Bank();

    int randomInt();
    Client* createClient();
    string randomName();
    string randomSurname();
};
#endif