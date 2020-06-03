#ifndef OPENUM_H
#define OPENUM_H
#include <iostream>

namespace numt
{
	enum class PossibleOperations
	{   // Enum s³u¿¹cy wbieraniu operacji które mo¿na wykonaæ w banku.
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
