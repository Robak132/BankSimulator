#include <iostream>
#include <vector>
#include "Client.h"
#include "Bank.h"

using namespace std;

int main() {
	IndividualClient client("name", "surname", "DID123", ID('C'));
	cout << client.getIDNumber().getID() << endl;
	IndividualClient client2("name", "surname", "DID123", ID('C'));
	cout << client2.getIDNumber().getID() << endl;
}