#include "Stand.h"
#include "Stand.h"

using namespace std;

ATMout::ATMout() : Stand()
{
	operations = { numt::accountToClient };
	s_type = "ATMout";
}

void ATMout::performOperation()
{
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (client->getReason())
		{
		case numt::accountToClient:
		{
			int tim = trans.accountToClient();
			setWorkTime(tim);
			break;
		}
		default:
		{
			throw BadOperation("Can not perform that weird shit.");
		}
		}
	}
	else
	{
		throw NoClient("Without client? U dumb?");
	}
}

ATMin::ATMin() : Stand()
{
	operations = { numt::clientToAccount };
	s_type = "ATMin";
}

void ATMin::performOperation()
{
	
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (client->getReason())
		{
		case numt::clientToAccount:
		{
			int tim = trans.clientToAccount();
			setWorkTime(tim);
			break;
		}
		default:
		{
			throw BadOperation("Can not perform that weird shit.");
		}
		}
	}
	else
	{
		throw NoClient("Without client? U dumb?");
	}
}

InfoStand::InfoStand(Employeet* e) : EStand(e)
{
	operations = { numt::infoAccount, numt::infoLoan };
	s_type = "Information Stand";
}

void InfoStand::performOperation()
{
	if (client != nullptr)
	{
		AccountO acc(client);
		LoanO loa(client);
		switch (client->getReason())
		{
		case numt::infoAccount:
		{
			int tim = acc.infoAccount();
			setWorkTime(tim);
			break;
		}
		case numt::infoLoan:
		{
			int tim = loa.infoLoan();
			setWorkTime(tim);
			break;
		}
		default:
		{
			throw BadOperation("Can not perform that weird shit.");
		}
		}
	}
	else
	{
		throw NoClient("Without client? U dumb?");
	}
	
}

CashStand::CashStand(Employeet* e) : EStand(e)
{
	operations = { numt::takeLoan, numt::repayLoan, numt::clientToAccount, numt::accountToClient };
	s_type = "Cash Stand";
}

void CashStand::performOperation()
{
	if (client != nullptr)
	{
		TransferO trans(client);
		LoanO loa(client);
		switch (client->getReason())
		{
		case numt::takeLoan:
		{
			int tim = loa.takeLoan();
			setWorkTime(tim);
			break;
		}
		case numt::repayLoan:
		{
			int tim = loa.repayLoan();
			setWorkTime(tim);
			break;
		}
		case numt::clientToAccount:
		{
			int tim = trans.clientToAccount();
			setWorkTime(tim);
			break;
		}
		case numt::accountToClient:
		{
			int tim = trans.accountToClient();
			setWorkTime(tim);
			break;
		}
		default:
		{
			throw BadOperation("Can not perform that weird shit.");
		}
		}
	}
	else
	{
		throw NoClient("Without client? U dumb?");
	}
	
}

AccountStand::AccountStand(Employeet* e) : EStand(e)
{
	operations = { numt::createAccount, numt::deleteAccount, numt::infoAccount };
	s_type = "Account Stand";
}

void AccountStand::performOperation()
{
	if (client != nullptr)
	{
		AccountO acc(client);
		switch (client->getReason())
		{
		case  numt::createAccount:
		{
			int tim = acc.createAccount();
			setWorkTime(tim);
			break;
		}
		case  numt::deleteAccount:
		{
			int tim = acc.deleteAccount();
			setWorkTime(tim);
			break;
		}
		case  numt::infoAccount:
		{
			int tim = acc.infoAccount();
			setWorkTime(tim);
			break;
		}
		default:
		{
			throw BadOperation("Can not perform that weird shit.");
		}
		}
	}
	else
	{
		throw NoClient("Without client? U dumb?");
	}
}