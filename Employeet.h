#ifndef EMPLOYEET_H
#define EMPLOYEET_H
#include "ID.h"

class Employeet
{ // Prosta klasa symuluj�ca pracownika.
	ID self_ID;
	int productivity;
public:
	Employeet();
	ID getSelfID();
};
#endif