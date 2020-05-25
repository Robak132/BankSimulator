#ifndef TIMER_H
#define TIMER_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Bank.h"

using namespace std;

class Timer {
private:
	int time_per_tick;
	int actual_time;
	Bank* bank;
	vector<IClient*> clients_in;

	ofstream log;
public:
	Timer(int _time_per_tick = 1, string _log = "log.txt", BankSetup = {1000,10000,1,1,1,1,1,420,1320});
	~Timer();
	void runSimulation();
	int getTimePerTick();
	int getActualTime();
	string getFormatedTime();

	void setTimePerTick(int _time_per_tick);
};

#endif