#ifndef EMPLOYEET_H
#define EMPLOYEET_H
#include "ID.h"

class Employeet
{ // Prosta klasa symulująca pracownika.
	ID self_ID;
	int productivity;
public:
	Employeet();
	ID getSelfID();
};
#endif