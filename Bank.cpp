#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <string>

#include "Bank.h"
#include "Timer.h"
#include "Client.h"

using namespace std;

Bank::Bank(int _n_workers, string filename) {
    n_workers = _n_workers;
    log.open(filename);
}
Bank::~Bank() {
    log.close();
}

int Bank::randomInt() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    return generator();
}
void Bank::createClient() {
    Client* client = nullptr;
    if (randomInt() % 2 == 0) {
        client = new BusinessClient("name", "surname", "DID123", ID('C'));
    }
    else {
        client = new IndividualClient("name", "surname", "DID123", ID('C'));
    }
    clients.push_back(client);
}
string Bank::randomName() {
    string line;
    ifstream namefile;
    namefile.open("namelist.txt");
    if (namefile.is_open()) {
        while (getline(namefile, line)) {
            cout << line << '\n';
        }
        namefile.close();
    }
    return "";
}
string Bank::randomSurname() {
    string line;
    ifstream namefile;
    namefile.open("surnamelist.txt");
    if (namefile.is_open()) {
        while (getline(namefile, line)) {
            cout << line << '\n';
        }
        namefile.close();
    }
    return "";
}