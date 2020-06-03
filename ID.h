#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

class ID {
private:
	char category;
	string value;
	string extendID(string _id);		// wyd�u�a string do d�ugo�ci 6, dodaj�c na pocz�tku "0"
	string nextID(char _category);		// generuje nast�pny nieu�ywany numer w danej kategorii
public:
	ID(char _category='N');				// Wywo�anie bez parametr�w tworzy pusty obiekt, ale konstruktor domy�lny jest wymagany w innych miejscach programu
	string getID() const;
};
ostream& operator << (ostream& out, ID& id);
bool operator == (ID a, ID b);
bool operator == (ID a, string b);
bool operator != (ID a, ID b);
bool operator != (ID a, string b);
#endif