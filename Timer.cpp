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
		bool not_timed = true;
		if (Tools::randomInt() % 5 == 0) {
			IClient* temp_client = bank->randomClient();
			if (!temp_client->inBank()) {
				clients_in.push_back(temp_client);
				if (not_timed)
				{
					log << endl;
					log << getFormatedTime() << endl;
					not_timed = false;
				}
				log << "A wild client appeared: " << temp_client << "." << endl;
				bank->addClientToList(temp_client);
				log << temp_client->getNameSurname() << " [" << temp_client->getIDNumber() << "] chose " << temp_client->getCurrentStand() << "." << endl;
			}
		}
		bank->iterateThrough();
		for (int i = clients_in.size()-1 ; i>=0; i--)
		{
			if (!clients_in[i]->inBank())
			{
				if (not_timed)
				{
					log << endl;
					log << getFormatedTime() << endl;
					not_timed = false;
				}
				if (clients_in[i]->getCurrentStand()->isEmployeet())
					log << "Employee [" << clients_in[i]->getCurrentStand()->getEmployeet()->getSelfID().getID() << "] just helped customer [" << clients_in[i]->getIDNumber() << "] with " << clients_in[i]->getFormatedReason() << " in " << clients_in[i]->getCurrentStand()->getSType() << "." << endl;
				else
					log << clients_in[i] << " finished doing it with " << clients_in[i]->getCurrentStand()->getSType() << " [" << clients_in[i]->getCurrentStand()->getStandID().getID() << "]." << endl;
				clients_in.erase(clients_in.begin()+i);
			}

		}
		actual_time += time_per_tick;
		not_timed = true;
	}
	actual_time -= time_per_tick;

	log << endl << getFormatedTime() << endl;
	for (int i = clients_in.size() - 1; i >= 0; i--) {
		log << clients_in[i] << " failed doing do it because simulation ended." << endl;
		clients_in.erase(clients_in.begin() + i);
	}
	log << "Simulation ended" << endl;
	bank->getStats().saveIt();
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