#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Client.h"
#include "OpEnum.h"
#include "Tools.h"
#include "Stand.h"

using namespace std;

Client::Client(string _name, string _surname, string _document_id, numt::PossibleOperations _reason, int _money, Account _account) {
    name = _name;
    surname = _surname;
    if (!checkDocID(_document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = _document_id;
    account = _account;
    client_reason = _reason;
    money = _money;

    type = "NoType";
    id_number = ID('C');
    setInBank();
    setCurrentStand(nullptr);
}

bool Client::inBank() {
    return in_bank;
}

void Client::setInBank(bool _b)
{
    in_bank = _b;
}



bool Client::checkDocID(string _document_id) {
    if (_document_id.length() != 6)
        return false;
    for (int i = 0; i < 6; i++) {
        if (i < 3) {
            if (_document_id[i] < 65 || _document_id[i] > 90)
                return false;
        }
        else {
            if (_document_id[i] < 48 || _document_id[i] > 57)
                return false;
        }
    }
    return true;
}

string Client::randomName() {
    static vector<string>namelist;
    if (namelist.size() == 0) {
        ifstream file;
        string line;

        try {
		    file.open("name.txt");
            if (!file.good())
                throw FileNotFound("Name generator not found");

            while (getline(file, line))
                namelist.push_back(line);
            file.close();
	    }
    	catch (FileNotFound ex) {
            cout << "Name generator not found" << endl;
            exit(1);
	    }
    }
    return namelist[Tools::randomInt() % namelist.size()];
}
string Client::randomSurname() {
    static vector<string>surnamelist;
    if (surnamelist.size() == 0) {
        ifstream file;
        string line;

        try {
            file.open("surname.txt");
            if (!file.good())
                throw FileNotFound("Surname generator not found");

            while (getline(file, line))
                surnamelist.push_back(line);
            file.close();
        }
        catch (FileNotFound ex) {
            cout << "Surname generator not found" << endl;
            exit(1);
        }
    }
    return surnamelist[Tools::randomInt() % surnamelist.size()];
}
string Client::randomDocumentID() {
    string _document_id = "";
    for (int i = 0; i < 3; i++) {
        int rand = Tools::randomInt() % 26 + 65;
        _document_id += char(rand);
    }
    for (int i = 0; i < 3; i++) {
        int rand = Tools::randomInt() % 10 + 48;
        _document_id += char(rand);
    }
    return _document_id;
}
numt::PossibleOperations Client::randomOperation() {
    int rand = Tools::randomInt() % 8;
    return static_cast<numt::PossibleOperations>(rand);
}
int Client::randomMoney() {
    return (Tools::randomInt() % 10 + 1) * 1000;
}
int BusinessClient::randomMoney() {
    return (Tools::randomInt() % 10 + 1) * 10000;
}
int IndividualClient::randomMoney() {
    return (Tools::randomInt() % 10 + 1) * 1000;
}
Account Client::randomAccount() {
    int temp_money = 0;
    int temp_credit = 0;
    switch (Tools::randomInt() % 7) {
    case 0:
        return Account(0, 0, false);
        break;
    case 1:
    case 2:
    case 3:
        temp_money = (Tools::randomInt() % 10 + 1) * 100;
        return Account(temp_money, 0, true);
        break;
    case 4:
    case 5:
    case 6:
        temp_money = (Tools::randomInt() % 10 + 1) * 100;
        temp_credit = (Tools::randomInt() % 10 + 1) * 100;
        return Account(temp_money, temp_credit, true);
    }
}

ostream& operator << (ostream& out, const IClient* client) {
    return out << client->getNameSurname() << " (" << client->getDocumentID() << ") with reason: " << client->getFormatedReason();
}

// Getter
ID Client::getID() const {
    return id_number;
}
string Client::getType() const{
    return type;
}
string Client::getIDNumber() const {
    return id_number.getID();
}
string Client::getName() const {
    return name;
}
string Client::getSurname() const {
    return surname;
}
string Client::getNameSurname() const {
    return name + " " + surname;
}
string Client::getDocumentID() const {
    return document_id;
}
string Client::getFormatedReason() const {
    switch (client_reason) {
    case numt::PossibleOperations::accountToClient:
        return "Withdraw";
        break;
    case numt::PossibleOperations::clientToAccount:
        return "Payment";
        break;
    case numt::PossibleOperations::createAccount:
        return "Create account";
        break;
    case numt::PossibleOperations::deleteAccount:
        return "Delete account";
        break;
    case numt::PossibleOperations::infoAccount:
        return "Get info about account";
        break;
    case numt::PossibleOperations::takeLoan:
        return "Take loan";
        break;
    case numt::PossibleOperations::repayLoan:
        return "Repay loan";
        break;
    case numt::PossibleOperations::infoLoan:
        return "Get info about loan";
        break;
    }
}
numt::PossibleOperations Client::getReason() const {
    return client_reason;
}
int Client::getMoney() const {
    return money;
}
Account* Client::getAccount() {
    return &account;
}
IStand* Client::getCurrentStand() {
    return current_stand;
}

// Setter
void Client::setType(string _type) {
    type = _type;
}
void Client::setName(string _name) {
    name = _name;
}
void Client::setSurname(string _surname) {
    surname = _surname;
}
void Client::setDocumentID(string _document_id) {
    if (!checkDocID(_document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = _document_id;
}
void Client::setReason(numt::PossibleOperations _reason) {
    client_reason = _reason;
}
void Client::setMoney(int _money) {
    money = _money;
}
void Client::setAccount(Account _account) {
    account = _account;
}
void Client::setCurrentStand(IStand* cs) {
    current_stand = cs;
}
