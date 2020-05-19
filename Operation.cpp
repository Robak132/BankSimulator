#include "Operation.h"
#include <iostream>
using namespace std;
#define MONEY 100

Operation::Operation(Client* c)
{
	client = c;
}

TransferO::TransferO(Client* c):Operation(c)
{

}

int TransferO::accountToClient()
{
	if (client->getAccount()->getMoney() >= 100)
	{
		client->setMoney(client->getMoney() + 100);
	}
	return 5;
}

int TransferO::clientToAccount()
{
	if (client->getMoney() >= 100)
	{
		client->setMoney(client->getMoney() - 100);
		
	}
	return 4;
}

AccountO::AccountO(Client* c) :Operation(c)
{

}

int AccountO::createAccount()
{
	return 30;
}

int AccountO::deleteAccount()
{
	return 20;
}

int AccountO::infoAccount()
{
	return 3;
}

LoanO::LoanO(Client* c) : Operation(c)
{

}

int LoanO::takeLoan()
{
	if (client->getAccount()->getCredit() <= 1000)
	{
		//Tutaj ustalanie kredytu
	}
	return 10;
}

int LoanO::repayLoan()
{
	if (client->getAccount()->getCredit() <= client->getAccount()->getMoney())
	{
		//Tutaj sp³acañsko kredytu
	}
	return 5;
}

int LoanO::infoLoan()
{
	return 3;
}









