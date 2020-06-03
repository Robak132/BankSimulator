#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

class ID {
private:
	char category;
	string value;
	string extendID(string _id);		// wyd³u¿a string do d³ugoœci 6, dodaj¹c na pocz¹tku "0"
	string nextID(char _category);		// generuje nastêpny nieu¿ywany numer w danej kategorii
public:
	ID(char _category='N');				// Wywo³anie bez parametrów tworzy pusty obiekt, ale konstruktor domyœlny jest wymagany w innych miejscach programu
	string getID() const;
};
ostream& operator << (ostream& out, ID& id);
bool operator == (ID a, ID b);
bool operator == (ID a, string b);
bool operator != (ID a, ID b);
bool operator != (ID a, string b);
#endif