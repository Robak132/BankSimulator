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
#include "Stand.h"

using namespace std;

Bank::Bank(int _n_workers, int _n_stands, string filename) {
    n_workers = _n_workers;
    n_stands = _n_stands;
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
    
    for (int i = 0; i < n_stands; i++) {
        stands.push_back(new Stand());
    }
}
Bank::~Bank() {
    log.close();
    namefile.close();
}

Client* Bank::createClient() {
    Client* client = nullptr;
    if (randomInt() % 2 == 0)
        client = new BusinessClient(randomName(), randomSurname(), "DID123");
    else
        client = new IndividualClient(randomName(), randomSurname(), "DID123");
    return client;
}

int Bank::randomInt() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    return generator();
}
string Bank::randomName() {
    return namelist[randomInt() % namelist.size()];
}
string Bank::randomSurname() {
    return surnamelist[randomInt() % surnamelist.size()];
}