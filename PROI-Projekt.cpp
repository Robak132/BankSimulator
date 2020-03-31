/*
Symulacja banku

Jakub Robaczewski, Oskar Bartosz
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

class Simulation {
private:
    int n_workers;
    int time_per_tick;  // Minutes
    int open_time;      // Hours in 24h format
    int close_time;     // Hours in 24h format
    int time_now;

    ofstream log;
public:
    Simulation(int _time_per_tick = 60, int _open_time = 8, int _close_time = 16, int _n_workers = 10) {
        n_workers = _n_workers;
        time_per_tick = _time_per_tick;
        open_time = _open_time * 60;
        close_time = _close_time * 60;
        time_now = _open_time * 60;

        log.open("log.txt");
    }
    ~Simulation() {
        log.close();
    }

    void start_simulation() {
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
    string get_formated_time(int time) {
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
};

int main() {
    Simulation sim(15);
    sim.start_simulation();
}
