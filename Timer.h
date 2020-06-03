#ifndef TIMER_H
#define TIMER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>     
#include "Bank.h"

using namespace std;

class Timer {
private:
	int time_per_tick;
	int actual_time;
	int sleep_time;
	Bank* bank;
	vector<IClient*> clients_in;

	ofstream log;
public:
	Timer(int _time_per_tick = 1, string _log = "log.txt", BankSetup = {1000,10000,1,1,1,1,1,420,1320}, int st = 1);
	~Timer();
	void runSimulation();
	int getTimePerTick();
	int getActualTime();
	int getSleepTime();
	string getFormatedTime();

	void setTimePerTick(int _time_per_tick);
};

#endif