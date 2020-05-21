#ifndef TIMER_H
#define TIMER_H

#include <fstream>
#include <iostream>
#include "Bank.h"

using namespace std;

class Timer {
private:
	int time_per_tick;
	int actual_time;
	Bank* bank;

	ofstream log;
public:
	Timer(int _time_per_tick = 1, string _log = "log.txt", BankSetup = {20,20,1,2,2,1,2,420,1320});
	~Timer();
	void runSimulation();

	int getTimePerTick();
	int getActualTime();
	string getFormatedTime();

	void setTimePerTick(int _time_per_tick);


};

#endif