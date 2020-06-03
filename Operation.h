#ifndef OPERATION_H
#define OPERATION_H

#include "Client.h"
using namespace std;

class Operation
{   // klasa dokonuj¹ca dla jakiegoœ klienta operacji.
protected:
	IClient* client;
public:
	Operation(IClient*);
};


class TransferO : public Operation
{   // Przelewy
public:
	TransferO(IClient*);
	int accountToClient();
	int clientToAccount();
};

class AccountO : public Operation 
{	// Konto
public:
	AccountO(IClient*);
	int createAccount();
	int deleteAccount();
	int infoAccount();
};

class LoanO : public Operation
{	// Po¿yczki
public:
	LoanO(IClient*);
	int takeLoan();
	int repayLoan();
	int infoLoan();
};
#endif
