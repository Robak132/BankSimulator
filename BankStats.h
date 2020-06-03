#ifndef BANKSTATS_H
#define BANKSTATS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "OpEnum.h"

class IClient;

struct StatisticsData
{   // Dane które przechowuj¹ statystyki
	int accounts_created;
	int accounts_deleted;
	int clients_passed;
};

using namespace std;

class BankStats
{
	ofstream stats_file;
	StatisticsData stats_data;
public:
	BankStats();
	~BankStats();
	void lookOnClient(IClient*);	// Patrzy na klienta który za³atwia swoj¹ potrzebê i odpowiednio zmienia statystyki.
	void saveIt();					// Zapisuje do pliku.
};



#endif 
