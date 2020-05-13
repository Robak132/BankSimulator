#include "ID.h"
#include <iostream>
#include <string>

using namespace std;

ID::ID(string _id_number) {
	if (!checkID(_id_number))
		throw invalid_argument("ID invalid");
	id_number = _id_number;
}
bool ID::checkID(string _id) {
	if (_id.length() != 6)
		return false;
	for (int i = 0; i < 6; i++) {
		if (_id[i] < 48 || _id[i] > 57)
			return false;
	}
	return true;
}
string ID::extendID(string _id) {
	while (_id.length() != 6)
		_id = "0" + _id;
	return _id;
}

string ID::getID() {
	return id_number;
}
void ID::setID(string _id) {
	_id = extendID(_id);
	if (!checkID(_id))
		throw invalid_argument("ID invalid");
	id_number = _id;
}
void ID::setNewID() {
	static int last_id = 1;
	string _id = extendID(to_string(last_id));
	if (!checkID(_id))
		throw invalid_argument("ID invalid");
	id_number = _id;
	last_id++;
}

ostream& operator << (ostream& out, ID& id) {
	return out << id.getID();
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