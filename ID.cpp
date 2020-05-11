#include "ID.h"
#include <iostream>
#include <string>

using namespace std;

ID::ID(string _id_number) {
	if (!CheckID(_id_number))
		throw invalid_argument("ID invalid");
	id_number = _id_number;
}
bool ID::CheckID(string _ID) {
	if (_ID.length() != 6)
		return false;
	for (int i = 0; i < 6; i++) {
		if (_ID[i] < 48 || _ID[i] > 57)
			return false;
	}
	return true;
}

string ID::getID() {
	return id_number;
}
void ID::setID(string _ID) {
	if (!CheckID(_ID))
		throw invalid_argument("ID invalid");
	id_number = _ID;
}

bool operator == (ID a, ID b) {
	return a.getID() == b.getID();
}
bool operator == (ID a, string b) {
	return a.getID() == b;
}
bool operator != (ID a, ID b) {
	return !(a == b);
}
bool operator != (ID a, string b) {
	return !(a == b);
}