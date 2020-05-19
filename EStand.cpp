#include <iostream>
#include "Stand.h"

using namespace std;

EStand::EStand(ID id): Stand(id)
{
	employeet = nullptr;
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