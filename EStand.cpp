#include <iostream>
#include "Stand.h"

using namespace std;

EStand::EStand(): Stand()
{
	employeet = nullptr;
}

Employeet* EStand::getEmployeet()
{
	return employeet;
}

bool EStand::isEmployeet()
{
	if (employeet != nullptr) { return true; }
	else { return false; }
}