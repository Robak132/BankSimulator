#ifndef OPERATION_H
#define OPERATION_H

#include "Client.h"
using namespace std;

class Operation
{
protected:
	Client* client;
public:
	Operation(Client*);
};


class TransferO : public Operation
{
public:
	TransferO(Client*);
	int accountToClient();
	int clientToAccount();
};

class AccountO : public Operation  // Øeby dzia≥a≥a jak potrzeba potrzebny wskaünik na Account
{
public:
	AccountO(Client*);
	int createAccount();
	int deleteAccount();
	int infoAccount();
};

class LoanO : public Operation
{
public:
	LoanO(Client*);
	int takeLoan();
	int repayLoan();
	int infoLoan();
};
#endif
