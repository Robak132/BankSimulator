#include <iostream>
using namespace std;

struct StandError : public exception
{	// Odrbny error ktry jest apany podczas testowania
	string message;
	StandError(string);
};
ostream& operator<<(ostream& os, const StandError& e);

struct BadOperation : public StandError
{
	BadOperation(string);
};

struct NoClient : public StandError
{
	NoClient(string);
};
