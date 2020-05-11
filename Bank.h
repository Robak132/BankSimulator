#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Timer.h"

using namespace std;

class Bank {
private:
    int n_workers;
    Timer timer;
    ofstream log;
    vector<Client>clients;
    
public:
    Bank(int _time_per_tick = 60, int _open_time = 8, int _close_time = 16, int _n_workers = 10);
    ~Bank();

    void start_simulation();
    string get_formated_time(int time) const;
};
#endif