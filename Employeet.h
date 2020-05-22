#ifndef EMPLOYEET_H
#define EMPLOYEET_H
#include "ID.h"

class Employeet
{
	ID self_ID;
	int productivity;
public:
	Employeet();
	ID getSelfID();
};
#endif