#ifndef OPENUM_H
#define OPENUM_H
#include <iostream>

namespace numt
{
	enum class PossibleOperations
	{
		accountToClient,
		clientToAccount,
		createAccount,
		deleteAccount,
		infoAccount,
		takeLoan,
		repayLoan,
		infoLoan,
	};

	std::string getFormatedReason(PossibleOperations po);
}
#endif
