#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <exception>

using namespace std;

struct ValueNotFound : public exception {
	string message;
public:
	ValueNotFound(string _message);
};

struct DuplicatedKey : public exception {
	string message;
public:
	DuplicatedKey(string _message);
};
#endif