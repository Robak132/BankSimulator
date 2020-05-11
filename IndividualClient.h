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
	IndividualClient(string _name, string _surname, string _document_id, string reason, int money = 0, ID _id_number = ID(), Account _account = Account());
};
#endif