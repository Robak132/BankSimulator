#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

class ID {
private:
	char category;
	string value;
	string extendID(string _id);
public:
	ID(char _category='C');
	ID(const ID& id);
	ID& operator= (const ID& id);
	string getID();
	void setNextID();
};
ostream& operator << (ostream& out, ID& id);
bool operator == (ID a, ID b);
bool operator == (ID a, string b);
bool operator != (ID a, ID b);
bool operator != (ID a, string b);
#endif