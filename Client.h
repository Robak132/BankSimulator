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
    virtual ID getID() const = 0;
    virtual string getIDNumber() const = 0;
    virtual string getName() const = 0;
    virtual string getSurname() const= 0;
    virtual string getNameSurname() const = 0;
    virtual string getDocumentID() const = 0;
    virtual bool inBank() = 0;
    virtual void setInBank(bool) = 0;
    virtual numt::PossibleOperations getReason() const = 0;
    virtual string getFormatedReason() const = 0;
    virtual int getMoney() const = 0;
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
    bool checkReason(numt::PossibleOperations _reason);
public:
    Client(string _name, string _surname, string _document_id, numt::PossibleOperations reason, int money, Account _account);

    bool inBank();

    ID getID() const;
    string getType() const;
    string getIDNumber() const;
    string getName() const;
    string getSurname() const;
    string getNameSurname() const;
    string getDocumentID() const;
    string getFormatedReason() const;
    numt::PossibleOperations getReason() const;
    int getMoney() const;
    Account* getAccount();
    IStand* getCurrentStand();

    void setInBank(bool = false);
    //void setCurrentStand(IStand*);
    void setType(string _type);
    void setName(string _name);
    void setSurname(string _surname);
    void setDocumentID(string _document_id);
    void setReason(numt::PossibleOperations _reason);
    void setMoney(int _money);
    void setAccount(Account _account);
    void setCurrentStand(IStand*);
protected:
    static string randomName();
    static string randomSurname();
    static string randomDocumentID();
    static numt::PossibleOperations randomOperation();
    static int randomMoney();
    static Account randomAccount();
};

ostream& operator << (ostream& out, const IClient* client);

class BusinessClient : public Client {
public:
    BusinessClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account=randomAccount())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Business");
    }
protected:
    static int randomMoney();
};

class IndividualClient : public Client {
public:
    IndividualClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account=randomAccount())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Individual");
    }
protected:
    static int randomMoney();
};
#endif