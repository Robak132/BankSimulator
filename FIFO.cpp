#include <iostream>
#include "FIFO.h"

using namespace std;

MyError::MyError(string something)
{
	message = something;
}

ostream& operator<<(ostream& os, const MyError& e)
{
	return os << e.message;
}

Vehicle::Vehicle()
{	
	wheels = 0;
	colour = "red";
	price = 99.99;
}

Vehicle::Vehicle(const Vehicle& v)
{
	colour = v.colour;
	price = v.price;
	wheels = v.wheels;
}

Vehicle::Vehicle(string c, double p, unsigned int w)
{
	colour = c;
	price = p;
	wheels = w;
}

ostream& operator << (ostream& os, const Vehicle obj)
{
	return os << "Vehicle(colour = " << obj.colour << ", number of wheels = " << obj.wheels << ", price = " << obj.price << ")";
}