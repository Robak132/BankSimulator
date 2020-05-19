#ifndef OPERATION_H
#define OPERATION_H

#include "Client.h"
using namespace std;

class Operation
{
protected:
	IClient* client;
public:
	Operation(IClient*);
};


class TransferO : public Operation
{
public:
	TransferO(IClient*);
	int accountToClient();
	int clientToAccount();
};

class AccountO : public Operation  // Øeby dzia≥a≥a jak potrzeba potrzebny wskaünik na Account
{
public:
	AccountO(IClient*);
	int createAccount();
	int deleteAccount();
	int infoAccount();
};

class LoanO : public Operation
{
public:
	LoanO(IClient*);
	int takeLoan();
	int repayLoan();
	int infoLoan();
};
#endif
