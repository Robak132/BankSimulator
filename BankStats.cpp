#include "BankStats.h"
#include "Client.h"

using namespace std;

BankStats::BankStats()
{
	try {
		stats_file.open("BankStatistics.txt");
	}
	catch (exception ex) {
		throw "Log file not found";
	}
	stats_data = { 0,0,0 };
}

BankStats::~BankStats()
{
	stats_file.close();
}

void BankStats::lookOnClient(IClient* cl)
{
	stats_data.clients_passed++;
	switch (cl->getReason())
	{
	case numt::PossibleOperations::createAccount:
		if (!cl->getAccount()->getCreated())
			stats_data.accounts_created++;
		break;
	case numt::PossibleOperations::deleteAccount:
		if(cl->getAccount()->getCreated())
			stats_data.accounts_deleted++;
		break;
	default:
		break;
	}
}

void BankStats::saveIt()
{
	stats_file << "---BANK STATISTICS---" << endl
		<< "Accounts_created: " << stats_data.accounts_created << endl
		<< "Accounts_deleted: " << stats_data.accounts_deleted << endl
		<< "All clients passed through bank: " << stats_data.clients_passed << endl;
}