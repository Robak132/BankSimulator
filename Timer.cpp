#include "Timer.h"
#include "Tools.h"

using namespace std;

Timer::Timer(int _time_per_tick, string _log, BankSetup _bs) {
	time_per_tick = _time_per_tick;
	bank = new Bank(_bs);
	actual_time = bank->getOpenTime();

	try {
		log.open(_log);
	}
	catch (exception ex) {
		throw FileNotFound("Log file not found");
	}
}
Timer::~Timer() {
	delete bank;
	log.close();
}

void Timer::runSimulation() {
	log << "Simulation started" << endl;
	while (bank->getCloseTime() >= actual_time) {
		if (Tools::randomInt() % 20 == 0) {
			IClient* temp_client = bank->randomClient();
			if (!temp_client->inBank()) {
				log << getFormatedTime() << endl;
				log << "A wild client appeared: " << temp_client << endl;
				bank->addClientToList(temp_client);
				log << "Client chose: " << temp_client->getCurrentStand() << endl;
			}
		}
		actual_time += time_per_tick;
	}
	log << "Simulation ended" << endl;
}


int Timer::getTimePerTick() {
	return time_per_tick;
}
int Timer::getActualTime() {
	return actual_time;
}
string Timer::getFormatedTime() {
	string minutes = to_string(actual_time % 60);
	if (minutes.size() == 1)
		minutes = "0" + minutes;
	string hours = to_string(actual_time / 60);
	if (hours.size() == 1)
		hours = "0" + hours;
	string time = hours + ":" + minutes;
	return time;
}

void Timer::setTimePerTick(int _time_per_tick) {
	time_per_tick = _time_per_tick;
}