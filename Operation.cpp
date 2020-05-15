#include "Operation.h"
using namespace std;



WithdrawMoney::WithdrawMoney()
{
	execution_time = 3;
}

void WithdrawMoney::doOperation(Client client)
{
	cout << "WithdrawMoney\n";
}

DepositMoney::DepositMoney()
{
	execution_time = 4;
}

void DepositMoney::doOperation(Client client)
{
	cout << "DepositMoney\n"
}

TransferMoney::TransferMoney()
{
	execution_time = 3;
}

void TransferMoney::doOperation(Client client)
{
	cout << "TransferMoney\n";
}

CreateAccount::CreateAccount()
{
	execution_time = 20;
}

void CreateAccount::doOperation(Client client)
{
	cout << "CreateAccount\n";
}

AccountInfo::AccountInfo()
{
	execution_time = 7;
}

void AccountInfo::doOperation(Client client)
{
	cout << "AccountInfo\n";
}

DeleteAccount::DeleteAccount()
{
	execution_time = "25";
}

void DeleteAccount::doOperation(Client)
{
	cout << "DeleteAccount\n";
}

TakeLoan::TakeLoan();
{
	execution_time = "8";
}

void TakeLoan::doOperation(Client client)
{
	cout << "TakeLoan\n";
}

RepayLoan::RepayLoan()
{
	execution_time = "5"
}

voi RepayLoan::doOperation(Client client)
{
	cout << "RepayLoan\n;"
}






