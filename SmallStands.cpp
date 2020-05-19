#include "Stand.h"
#include "Stand.h"

using namespace std;

ATMout::ATMout(ID id) : Stand(id)
{
	operations = { numt::accountToClient };
}

void ATMout::performOperation(numt::PossibleOperations e)
{
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (e)
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

ATMin::ATMin(ID id) : Stand(id)
{
	operations = { numt::clientToAccount };
}

void ATMin::performOperation(numt::PossibleOperations e)
{
	
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (e)
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

InfoStand::InfoStand(ID id) : EStand(id)
{
	operations = { numt::infoAccount, numt::infoLoan };
}

void InfoStand::performOperation(numt::PossibleOperations e)
{
	if (client != nullptr)
	{
		AccountO acc(client);
		LoanO loa(client);
		switch (e)
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

CashStand::CashStand(ID id) : EStand(id)
{
	operations = { numt::takeLoan, numt::repayLoan, numt::clientToAccount, numt::accountToClient };
}

void CashStand::performOperation(numt::PossibleOperations e)
{
	if (client != nullptr)
	{
		TransferO trans(client);
		LoanO loa(client);
		switch (e)
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

AccountStand::AccountStand(ID id) : EStand(id)
{
	operations = { numt::createAccount, numt::deleteAccount, numt::infoAccount };
}

void AccountStand::performOperation(numt::PossibleOperations e)
{
	if (client != nullptr)
	{
		AccountO acc(client);
		switch (e)
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