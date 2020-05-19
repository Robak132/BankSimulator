#include <iostream>
#include <vector>
#include "Client.h"
#include "OpEnum.h"

using namespace std;

Client::Client(string _name, string _surname, string _document_id, ID _id_number, numt::PossibleOperations _reason, int _money, Account _account) {
    type = "NoType";
    name = _name;
    surname = _surname;
    if (!checkDocID(_document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = _document_id;
    client_reason = _reason;
    money = _money;
    id_number = _id_number;
    account = _account;
    setNextID();
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
void Client::setNextID() {
    id_number.setNextID();
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