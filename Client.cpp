#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Client.h"
#include "OpEnum.h"
#include "Tools.h"

using namespace std;

Client::Client(string _name, string _surname, string _document_id, numt::PossibleOperations _reason, int _money, Account _account) {
    name = _name;
    surname = _surname;
    if (!checkDocID(_document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = _document_id;
    client_reason = _reason;
    money = _money;
    account = _account;

    type = "NoType";
    id_number = ID('C');
    in_bank = true;
}

bool Client::inBank()
{
    return in_bank;
}
void Client::setInBank(bool b)
{
    in_bank = b;
}

//IStand* Client::getCurrentStand()
//{
//    return current_stand;
//}
//
//void Client::setCurrentStand(IStand* cs)
//{  
//    current_stand = cs;
//}

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

        file.open("name.txt");

        while (getline(file, line))
            namelist.push_back(line);
        file.close();
    }
    return namelist[Tools::randomInt() % namelist.size()];
}
string Client::randomSurname() {
    static vector<string>surnamelist;
    if (surnamelist.size() == 0) {
        ifstream file;
        string line;

        file.open("surname.txt");
        while (getline(file, line))
            surnamelist.push_back(line);
        file.close();
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

// Getter
string Client::getType() {
    return type;
}
ID Client::getID() {
    return id_number;
}
string Client::getIDNumber(){
    return id_number.getID();
}
string Client::getName(){
    return name;
}
string Client::getSurname(){
    return surname;
}
string Client::getNameSurname(){
    return name + " " + surname;
}
string Client::getDocumentID(){
    return document_id;
}
numt::PossibleOperations Client::getReason(){
    return client_reason;
}
int Client::getMoney(){
    return money;
}
Account* Client::getAccount(){
    return &account;
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