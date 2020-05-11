#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

class ID {
private:
	string id_number;
	bool CheckID(string _ID);
public:
	ID(string _id_number="000000");
	string getID();
	void setID(string _ID);
};

bool operator == (ID a, ID b);
bool operator == (ID a, string b);
bool operator != (ID a, ID b);
bool operator != (ID a, string b);
#endif