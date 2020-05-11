#ifndef INDIVIDUALCLIENT_H
#define INDIVIDUALCLIENT_H

#include <iostream>
#include "Client.h"

using namespace std;

// Nie wiem do czego to ale jest
class IndividualClient : protected Client {
private:
	string type;
public:
	IndividualClient();
};
#endif