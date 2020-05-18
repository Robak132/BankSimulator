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
    namefile.open("name.txt");
    surnamefile.open("surname.txt");

    string line;
    while (getline(namefile, line)) {
        namelist.push_back(line);
    }
    while (getline(surnamefile, line)) {
        surnamelist.push_back(line);
    }
}
Bank::~Bank() {
    log.close();
    namefile.close();
}

int Bank::randomInt() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    return generator();
}
Client* Bank::createClient() {
    Client* client = nullptr;
    if (randomInt() % 2 == 0)
        client = new BusinessClient(randomName(), randomSurname(), "DID123");
    else
        client = new IndividualClient(randomName(), randomSurname(), "DID123");
    return client;
}
string Bank::randomName() {
    return namelist[randomInt() % namelist.size()];
}
string Bank::randomSurname() {
    return surnamelist[randomInt() % surnamelist.size()];
}