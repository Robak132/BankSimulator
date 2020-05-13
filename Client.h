#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "ID.h"
#include "Account.h"
#include "Client.h"

using namespace std;

class IClient {
public:
    virtual bool isRealClient() = 0;

    virtual ID getIDNumber() = 0;
    virtual string getName() = 0;
    virtual string getSurname() = 0;
    virtual string getNameSurname() = 0;
    virtual string getDocumentID() = 0;
    virtual string getReason() = 0;
    virtual int getMoney() = 0;
    virtual Account getAccount() = 0;

    virtual void setIDNumber(ID _id_number) = 0;
    virtual void setName(string _name) = 0;
    virtual void setSurname(string _surname) = 0;
    virtual void setDocumentID(string _document_id) = 0;
    virtual void setReason(string _reason) = 0;
    virtual void setMoney(int _money) = 0;
    virtual void setAccount(Account _account) = 0;
};

class Client : public IClient {
private:
    ID id_number;   // 000000 - Not a client (Don't have account) [6-digit]

    string name;
    string surname;
    string document_id; // [3 - letters upersize, 3- digits]
    string reason;
    int money;

    Account account;
    bool checkDocID(string _document_id);
public:
    Client(string _name, string _surname, string _document_id, string reason, int money = 0, ID _id_number = ID(), Account _account = Account());
    Client(const Client& c);
    Client& operator = (const Client& c);

    bool isRealClient();

    ID getIDNumber();
    string getName();
    string getSurname();
    string getNameSurname();
    string getDocumentID();
    string getReason();
    int getMoney();
    Account getAccount();

    void setIDNumber(ID _id_number);
    void setName(string _name);
    void setSurname(string _surname);
    void setDocumentID(string _document_id);
    void setReason(string _reason);
    void setMoney(int _money);
    void setAccount(Account _account);
};

bool operator == (Client a, Client b);
bool operator != (Client a, Client b);

class BusinessClient : public Client {
private:
	string type;
public:
    BusinessClient(string _name, string _surname, string _document_id, string reason, int money = 0, ID _id_number = ID(), Account _account = Account()) : Client(_name, _surname, _document_id, reason, money, _id_number, _account) { }
};
class IndividualClient : public Client {
private:
    string type;
public:
    IndividualClient(string _name, string _surname, string _document_id, string reason, int money = 0, ID _id_number = ID(), Account _account = Account()) : Client(_name, _surname, _document_id, reason, money, _id_number, _account) { }
};
#endif