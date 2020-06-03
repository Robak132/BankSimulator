#ifndef OPENUM_H
#define OPENUM_H
#include <iostream>

namespace numt
{
	enum class PossibleOperations
	{   // Enum s�u��cy wbieraniu operacji kt�re mo�na wykona� w banku.
		accountToClient,
		clientToAccount,
		createAccount,
		deleteAccount,
		infoAccount,
		takeLoan,
		repayLoan,
		infoLoan,
	};

	std::string getFormatedReason(PossibleOperations po); // Zwraca sformatowany string operacji. 
}
#endif
