#ifndef BUSINESSCLIENT_H
#define BUSINESSCLIENT_H

#include <iostream>
#include "Client.h"

using namespace std;

// Nie wiem do czego to ale jest
class BusinessClient : protected Client {
private:
	string type;
public:
	BusinessClient();
};
#endif