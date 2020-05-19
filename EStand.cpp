#include <iostream>
#include "Stand.h"

using namespace std;

EStand::EStand(ID id, Employeet* e): Stand(id)
{
	employeet = e;
}

void EStand::setEmployeet(Employeet* e)
{
	employeet = e;
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