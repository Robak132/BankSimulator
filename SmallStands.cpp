#include "Stand.h"

using namespace std;

ATMout::ATMout() : Stand()
{
	operations = { numt::PossibleOperations::accountToClient };
	s_type = "ATMout";
}

void ATMout::performOperation()
{
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (client->getReason())
		{
		case numt::PossibleOperations::accountToClient:
		{
			int tim = trans.accountToClient();
			setWorkTime(tim);
			break;
		}
		default:
		{
		}
		}
	}

}

ATMin::ATMin() : Stand()
{
	operations = { numt::PossibleOperations::clientToAccount };
	s_type = "ATMin";
}

void ATMin::performOperation()
{
	
	if (client != nullptr)
	{
		TransferO trans(client);
		switch (client->getReason())
		{
		case numt::PossibleOperations::clientToAccount:
		{
			int tim = trans.clientToAccount();
			setWorkTime(tim);
			break;
		}
		default:
		{
		}
		}
	}
}

InfoStand::InfoStand(Employeet* e) : EStand(e)
{
	operations = { numt::PossibleOperations::infoAccount, numt::PossibleOperations::infoLoan };
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
		case numt::PossibleOperations::infoAccount:
		{
			int tim = acc.infoAccount();
			setWorkTime(tim);
			break;
		}
		case numt::PossibleOperations::infoLoan:
		{
			int tim = loa.infoLoan();
			setWorkTime(tim);
			break;
		}
		default:
		{
		}
		}
	}

	
}

CashStand::CashStand(Employeet* e) : EStand(e)
{
	operations = { numt::PossibleOperations::takeLoan, numt::PossibleOperations::repayLoan, numt::PossibleOperations::clientToAccount, numt::PossibleOperations::accountToClient };
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
		case numt::PossibleOperations::takeLoan:
		{
			int tim = loa.takeLoan();
			setWorkTime(tim);
			break;
		}
		case numt::PossibleOperations::repayLoan:
		{
			int tim = loa.repayLoan();
			setWorkTime(tim);
			break;
		}
		case numt::PossibleOperations::clientToAccount:
		{
			int tim = trans.clientToAccount();
			setWorkTime(tim);
			break;
		}
		case numt::PossibleOperations::accountToClient:
		{
			int tim = trans.accountToClient();
			setWorkTime(tim);
			break;
		}
		default:
		{
		}
		}
	}

	
}

AccountStand::AccountStand(Employeet* e) : EStand(e)
{
	operations = { numt::PossibleOperations::createAccount, numt::PossibleOperations::deleteAccount, numt::PossibleOperations::infoAccount };
	s_type = "Account Stand";
}

void AccountStand::performOperation()
{
	if (client != nullptr)
	{
		AccountO acc(client);
		switch (client->getReason())
		{
		case  numt::PossibleOperations::createAccount:
		{
			int tim = acc.createAccount();
			setWorkTime(tim);
			break;
		}
		case  numt::PossibleOperations::deleteAccount:
		{
			int tim = acc.deleteAccount();
			setWorkTime(tim);
			break;
		}
		case  numt::PossibleOperations::infoAccount:
		{
			int tim = acc.infoAccount();
			setWorkTime(tim);
			break;
		}
		default:
		{
		}
		}
	}
}