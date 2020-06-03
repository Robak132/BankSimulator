#include "Timer.h"
#include "Tools.h"

using namespace std;

Timer::Timer(int _time_per_tick, string _log, BankSetup _bs, int st) {
	sleep_time = st;
	time_per_tick = _time_per_tick;
	bank = new Bank(_bs);
	actual_time = bank->getOpenTime();

	try {
		log.open(_log);	// Otwarcie logu
	}
	catch (exception ex) {
		throw FileNotFound("Log file not found");
	}
}
Timer::~Timer() {
	delete bank;
	log.close();		// Zamkniêcie logu
}

void Timer::runSimulation() {
	log << "Simulation started" << endl;
	while (bank->getCloseTime() > actual_time) {
		bool not_timed = true;
		if (Tools::randomInt() % 5 == 0) {			// Losuje klienta - szansa = 20% * (iloœæ klientów poza bankiem/iloœæ zapisanych klientów)
			IClient* temp_client = bank->randomClient();
			if (!temp_client->inBank()) {
				clients_in.push_back(temp_client);	// Dodaje klienta do vektora klientów w banku
				if (not_timed)
				{
					log << endl;
					log << getFormatedTime() << endl;
					cout << endl << getFormatedTime() << endl;
					not_timed = false;
				}
				log << "A wild client appeared: " << temp_client << "." << endl;
				cout << "A wild client appeared: " << temp_client << "." << endl;
				bank->addClientToList(temp_client);	// Dodaje klienta do kolejki
				log << temp_client->getNameSurname() << " [" << temp_client->getIDNumber() << "] chose " << temp_client->getCurrentStand() << "." << endl;
				cout << temp_client->getNameSurname() << " [" << temp_client->getIDNumber() << "] chose " << temp_client->getCurrentStand() << "." << endl;
			}
		}
		bank->iterateThrough();						// Przechodzi przez wszystkie okienka, zmniejsza czasy i wpuszcza nowych klientów
		for (int i = clients_in.size()-1 ; i>=0; i--)
		{
			if (!clients_in[i]->inBank())			// Usuniêcie klienta, który wyszed³ z banku
			{
				if (not_timed)
				{
					log << endl;
					log << getFormatedTime() << endl;
					cout << endl << getFormatedTime() << endl;
					not_timed = false;
				}
				if (clients_in[i]->getCurrentStand()->isEmployeet())
				{
					log << "Employee [" << clients_in[i]->getCurrentStand()->getEmployeet()->getSelfID().getID() << "] just helped customer [" << clients_in[i]->getIDNumber() << "] with " << clients_in[i]->getFormatedReason() << " in " << clients_in[i]->getCurrentStand()->getSType() << "." << endl;
					cout << "Employee [" << clients_in[i]->getCurrentStand()->getEmployeet()->getSelfID().getID() << "] just helped customer [" << clients_in[i]->getIDNumber() << "] with " << clients_in[i]->getFormatedReason() << " in " << clients_in[i]->getCurrentStand()->getSType() << "." << endl;
				}
				else
				{
					log << clients_in[i] << " finished doing it with " << clients_in[i]->getCurrentStand()->getSType() << " [" << clients_in[i]->getCurrentStand()->getStandID().getID() << "]." << endl;
					cout << clients_in[i] << " finished doing it with " << clients_in[i]->getCurrentStand()->getSType() << " [" << clients_in[i]->getCurrentStand()->getStandID().getID() << "]." << endl;
				}
				clients_in.erase(clients_in.begin()+i);
			}

		}
		actual_time += time_per_tick;
		if (!not_timed)
		{
			this_thread::sleep_for(chrono::seconds(sleep_time));
			not_timed = true;
		}
	}

	log << endl << getFormatedTime() << endl;
	cout << endl << getFormatedTime() << endl;
	for (int i = clients_in.size() - 1; i >= 0; i--) { // Wypisanie klientów, którym nie uda³o siê ukoñczyæ operacji
		log << clients_in[i] << " failed doing do it because simulation ended." << endl;
		cout << clients_in[i] << " failed doing do it because simulation ended." << endl;
		clients_in.erase(clients_in.begin() + i);
	}
	log << "Simulation ended" << endl;
	cout << "Simulation ended" << endl;
	bank->getStats().saveIt();	// Zapisanie statystyk
}


int Timer::getTimePerTick() {
	return time_per_tick;
}
int Timer::getActualTime() {
	return actual_time;
}
int Timer::getSleepTime() {
	return sleep_time;
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