#include <iostream>
#include <vector>
#include "Client.h"

using namespace std;

Client::Client(string _name, string _surname, string _document_id, string _reason, int _money, ID _id_number, Account _account) {
    name = _name;
    surname = _surname;
    if (!checkDocID(_document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = _document_id;
    reason = _reason;
    money = _money;
    id_number = _id_number;
    account = _account;
}
Client::Client(const Client& c) {
    name = c.name;
    surname = c.surname;
    if (!checkDocID(c.document_id))
        throw invalid_argument("Invalid argument");
    else
        document_id = c.document_id;
    reason = c.reason;
    money = c.money;
    id_number = c.id_number;
    account = c.account;
}
Client& Client::operator = (const Client& c) {
    if (this != &c) {
        name = c.name;
        surname = c.surname;
        if (!checkDocID(c.document_id))
            throw invalid_argument("Invalid argument");
        else
            document_id = c.document_id;
        reason = c.reason;
        money = c.money;
        id_number = c.id_number;
        account = c.account;
    }
    return *this;
}

bool operator == (Client a, Client b) {
    return a.getIDNumber() == b.getIDNumber() &&
           a.getName() == b.getName() &&
           a.getSurname() == b.getSurname() &&
           a.getDocumentID() == b.getDocumentID() &&
           a.getReason() == b.getReason() &&
           a.getMoney() == b.getMoney() &&
           a.getAccount() == b.getAccount();
}
bool operator != (Client a, Client b) {
    return !(a == b);
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
bool Client::isRealClient() {
    if (id_number == "000000")
        return false;
    return true;
}

// Getter
ID Client::getIDNumber(){
    return id_number;
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
string Client::getReason(){
    return reason;
}
int Client::getMoney(){
    return money;
}
Account Client::getAccount(){
    return account;
}

// Setter
void Client::setIDNumber(ID _id_number) {
    id_number = _id_number;
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
void Client::setReason(string _reason) {
    reason = _reason;
}
void Client::setMoney(int _money) {
    money = _money;
}
void Client::setAccount(Account _account) {
    account = _account;
}