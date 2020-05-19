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
    int n_stands;
    list<Stand*>stands;

    ofstream log;
    
    ifstream namefile;
    vector<string>namelist;
    ifstream surnamefile;
    vector<string>surnamelist;

    list<Client*>clients;
public:
    Bank(int _n_workers, int _n_stands, string filename="log.txt");
    ~Bank();

    Client* createClient();

    int randomInt();
    string randomName();
    string randomSurname();
};
#endif