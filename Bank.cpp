/*
Symulacja banku

Jakub Robaczewski, Oskar Bartosz
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Bank.h"
#include "Timer.h"
#include "Client.h"

using namespace std;

Bank::Bank(int _time_per_tick, int _open_time, int _close_time, int _n_workers) {
    n_workers = _n_workers;
    timer = Timer(_time_per_tick, _open_time * 60, _close_time * 60);
    log.open("log.txt");
}
Bank::~Bank() {
    log.close();
}

void Bank::start_simulation() {
    cout << "Simulation started!\n";
    log << "Simulation started!\n";
    while (time_now <= close_time) {
        cout << get_formated_time(time_now) << endl;
        log << get_formated_time(time_now) << endl;

        time_now += time_per_tick;
    }
    cout << "Simulation ended!\n";
    log << "Simulation ended!\n";
}
string Bank::get_formated_time(int time) const {
    int hours = time / 60;
    int minutes = time % 60;
    string ftime = "";

    if (hours < 10)
        ftime += "0" + to_string(hours) + ":";
    else
        ftime += to_string(hours) + ":";
    if (minutes < 10)
        ftime += "0" + to_string(minutes);
    else
        ftime += to_string(minutes);
    return ftime;
}

int main() {
   // Client cl("Name", "Surname", "CIA667", "Pay");
   // Simulation sim(15);
   // sim.start_simulation();
}
