#ifndef OPERATION_H
#define OPERATION_H

#include "Client.h"
using namespace std;

class Operation
{
	int execution_time;
public:
	virtual void doOperation(Client) = 0;
};

//
//class Transfer : public Operation
//{
//public:
	/*void accountToClient();
	void clientToAccount();
	void accountToAccount();*/
//	void doOperation(Client);
//};
//
//class Account : public Operation
//{
//public:
//	void createAccount();
//	void deleteAccount();
//	void infoAccount();
//	void doOperation(Client);
//};
//
//class Loan : public Operation
//{
//	void takeLoan();
//	void repayLoan();
//	void infoLoan();
//};
#endif
