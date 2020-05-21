#include "Error.h"
#include <iostream>

using namespace std;

StandError::StandError(string something)
{
	message = something;
}
FileNotFound::FileNotFound(string something)
{
	message = something;
}

ostream& operator<<(ostream& os, const StandError& e)
{
	return os << e.message;
}

BadOperation::BadOperation(string s) :StandError(s){}

NoClient::NoClient(string s) : StandError(s){}