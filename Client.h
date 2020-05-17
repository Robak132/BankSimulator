#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "ID.h"
#include "Account.h"
#include "Client.h"

using namespace std;

enum class reason {
    pay_in,
    pay_out,
    create_account,
    delete_account,
    take_loan,
    pay_loan
};

class IClient {
public:
    virtual ID getIDNumber() = 0;
    virtual string getName() = 0;
    virtual string getSurname() = 0;
    virtual string getNameSurname() = 0;
    virtual string getDocumentID() = 0;
    virtual reason getReason() = 0;
    virtual int getMoney() = 0;
    virtual Account getAccount() = 0;

    virtual void setIDNumber(ID _id_number) = 0;
    virtual void setName(string _name) = 0;
    virtual void setSurname(string _surname) = 0;
    virtual void setDocumentID(string _document_id) = 0;
    virtual void setReason(reason _reason) = 0;
    virtual void setMoney(int _money) = 0;
    virtual void setAccount(Account _account) = 0;
};

class Client : public IClient {
private:
    ID id_number;   // 000000 - Not a client (Don't have account) [6-digit]

    string type;
    string name;
    string surname;
    string document_id; // [3 - letters upersize, 3- digits]
    reason client_reason;
    int money;

    Account account;
    bool checkDocID(string _document_id);
public:
    Client(string _name, string _surname, string _document_id, ID _id_number, reason reason = static_cast<reason>(0), int money = 0, Account _account = Account());

    string getType();
    ID getIDNumber();
    string getName();
    string getSurname();
    string getNameSurname();
    string getDocumentID();
    reason getReason();
    int getMoney();
    Account getAccount();

    void setType(string _type);
    void setIDNumber(ID _id_number);
    void setName(string _name);
    void setSurname(string _surname);
    void setDocumentID(string _document_id);
    void setReason(reason _reason);
    void setMoney(int _money);
    void setAccount(Account _account);
};

class BusinessClient : public Client {
public:
    BusinessClient(string _name, string _surname, string _document_id, ID _id_number, reason _reason=static_cast<reason>(0), int _money = 0, Account _account = Account())
        : Client(_name, _surname, _document_id, _id_number, _reason, _money, _account) {
        setType("Business");
    }
};

class IndividualClient : public Client {
public:
    IndividualClient(string _name, string _surname, string _document_id, ID _id_number, reason _reason=static_cast<reason>(0), int _money = 0, Account _account = Account())
        : Client(_name, _surname, _document_id, _id_number, _reason, _money, _account) {
        setType("Individual");
    }
};
#endif