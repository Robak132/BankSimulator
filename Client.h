#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>

#include "ID.h"
#include "Account.h"
#include "OpEnum.h"

using namespace std;

class IStand;

class IClient {
public:
    virtual ID getID() = 0;
    virtual string getIDNumber() = 0;
    virtual string getName() = 0;
    virtual string getSurname() = 0;
    virtual string getNameSurname() = 0;
    virtual string getDocumentID() = 0;
    virtual bool inBank() = 0;
    virtual void setInBank(bool) = 0;
    virtual numt::PossibleOperations getReason() = 0;
    virtual int getMoney() = 0;
    virtual Account* getAccount() = 0;

    virtual void setType(string _type) = 0;
    virtual void setName(string _name) = 0;
    virtual void setSurname(string _surname) = 0;   
    virtual void setDocumentID(string _document_id) = 0;
    virtual void setReason(numt::PossibleOperations _reason) = 0;
    virtual void setMoney(int _money) = 0;
    virtual void setAccount(Account _account) = 0;
    virtual IStand* getCurrentStand() = 0;
    virtual void setCurrentStand(IStand*) = 0;
};

class Client : public IClient {
private:
    ID id_number;

    bool in_bank;
    IStand* current_stand;
    string type;
    string name;
    string surname;
    string document_id; // [3 - letters upersize, 3- digits]
    numt::PossibleOperations client_reason;
    int money;

    Account account;
    bool checkDocID(string _document_id);
public:
    Client(string _name, string _surname, string _document_id, numt::PossibleOperations reason, int money, Account _account);

    bool inBank();
    void setInBank(bool = false);
    IStand* getCurrentStand();
    void setCurrentStand(IStand*);
    string getType();
    ID getID();
    string getIDNumber();
    string getName();
    string getSurname();
    string getNameSurname();
    string getDocumentID();
    numt::PossibleOperations getReason();
    int getMoney();
    Account* getAccount();

    void setType(string _type);
    void setName(string _name);
    void setSurname(string _surname);
    void setDocumentID(string _document_id);
    void setReason(numt::PossibleOperations _reason);
    void setMoney(int _money);
    void setAccount(Account _account);
protected:
    static string randomName();
    static string randomSurname();
    static string randomDocumentID();
    static numt::PossibleOperations randomOperation();
    static int randomMoney();
};

class BusinessClient : public Client {
public:
    BusinessClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account = Account())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Business");
    }
protected:
    static int randomMoney();
};

class IndividualClient : public Client {
public:
    IndividualClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account = Account())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Individual");
    }
protected:
    static int randomMoney();
};
#endif