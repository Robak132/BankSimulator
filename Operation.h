#pragma once
#include "Client.h"
using namespace std;

class Operation
{
	int execution_time;
public:
	virtual void doOperation(Client) = 0;
};

class WithdrawMoney : public Operation
{
public:
	WithdrawMoney();
	void doOperation(Client);
};

class DepositMoney : public Operation
{
public:
	DepositMoney();
	void doOperation(Client);
};

class TransferMoney : public Operation
{
public:
	TransferMoney();
	void doOperation(Client);
};

class CreateAccount : public Operation
{
public:
	CreateAccount();
	void doOperation(Client);
};

class AccountInfo : public Operation
{
public:
	AccountInfo();
	void doOperation(Client);
};

class DeleteAccount : public Operation
{
public:
	DeleteAccount();
	void doOperation(Client);
};

class TakeLoan : public Operation
{
public:
	TakeLoan();
	void doOperation(Client);
};

class RepayLoan : public Operation
{
public:
	RepayLoan();
	void doOperation(Client);
};

