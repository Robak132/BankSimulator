#include "Employeet.h"

Employeet::Employeet()
{
	self_ID = ID('E');
}

ID Employeet::getSelfID()
{
	return self_ID;
}