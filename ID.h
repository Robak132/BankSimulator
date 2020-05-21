#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

class ID {
private:
	char category;
	string value;
	string extendID(string _id);
	string nextID(char _category);
public:
	ID(char _category=NULL);
	string getID() const;
};
ostream& operator << (ostream& out, ID& id);
bool operator == (ID a, ID b);
bool operator == (ID a, string b);
bool operator != (ID a, ID b);
bool operator != (ID a, string b);
#endif