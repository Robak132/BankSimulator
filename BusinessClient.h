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
	BusinessClient(string _name, string _surname, string _document_id, string reason, int money = 0, ID _id_number = ID(), Account _account = Account());
};
#endif