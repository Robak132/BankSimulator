#include "ID.h"
#include <iostream>
#include <string>

using namespace std;

ID::ID(char _category) {
	if (_category == 'C' || _category == 'E' || _category == 'S') {
		category = _category;
		value = category + "000000";
	}
	else
		throw invalid_argument("Unknown category");
}
ID::ID(const ID& id) {
	category = id.category;
	value = id.value;
}

ID& ID::operator= (const ID& id) {
	if (this == &id)
		return *this;
	category = id.category;
	value = id.value;
	return *this;
}
string ID::extendID(string _id) {
	while (_id.length() != 6)
		_id = "0" + _id;
	return _id;
}
string ID::getID() {
	return value;
}
void ID::setNextID() {
	static int last_id_c = 0;
	static int last_id_e = 0;
	static int last_id_s = 0;
	string newid = "";
	switch (category) {
	case 'C':
		newid = 'C' + extendID(to_string(last_id_c));
		last_id_c++;
		break;
	case 'E':
		newid = 'E' + extendID(to_string(last_id_e));
		last_id_e++;
		break;
	case 'S':
		newid = 'S' + extendID(to_string(last_id_s));
		last_id_s++;
		break;
	}
	value = newid;
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