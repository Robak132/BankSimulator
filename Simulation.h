#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Simulation {
private:
    int n_workers;
    int time_per_tick;
    int open_time;
    int close_time;
    int time_now;
    ofstream log;
public:
    Simulation(int _time_per_tick = 60, int _open_time = 8, int _close_time = 16, int _n_workers = 10);
    ~Simulation();

    void start_simulation();
    string get_formated_time(int time) const;
};
#endif