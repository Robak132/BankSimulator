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
    bool in_bank;
    ID id_number;       // kategoria - du¿a litera, 6 cyfr indeksu
    string type;
    string name;
    string surname;
    string document_id; // 3 du¿e litery, 3 cyfry
    numt::PossibleOperations client_reason;
    int money;
    Account account;
    IStand* current_stand;

    bool checkDocID(string _document_id);
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
    void setType(string _type);
    void setName(string _name);
    void setSurname(string _surname);
    void setDocumentID(string _document_id);
    void setReason(numt::PossibleOperations _reason);
    void setMoney(int _money);
    void setAccount(Account _account);
    void setCurrentStand(IStand*);
protected:
    static string randomName();                         // Losuje imie z pliku name.txt
    static string randomSurname();                      // Losuje nazwisko z pliku name.txt
    static string randomDocumentID();                   // Losuje identyfikator dokumentu z liter A-Z i liczb 0-9
    static numt::PossibleOperations randomOperation();  // Losuje operacje 0-7
    static int randomMoney();                           // Losuje liczbê pieniêdzy (1000-10000)
    static Account randomAccount();                     // Losuje rodzaj konta (za³o¿one/nie) oraz liczbê pieniêdzy i/lub kredytu
};

ostream& operator << (ostream& out, const IClient* client);

class BusinessClient : public Client {
public:
    BusinessClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account=randomAccount())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Business");
    }
protected:
    static int randomMoney();                           // Klient biznesowy losuje w zakresie 1000-10000
};

class IndividualClient : public Client {
public:
    IndividualClient(string _name=randomName(), string _surname=randomSurname(), string _document_id=randomDocumentID(), numt::PossibleOperations _reason=randomOperation(), int _money=randomMoney(), Account _account=randomAccount())
        : Client(_name, _surname, _document_id, _reason, _money, _account) {
        setType("Individual");
    }
protected:
    static int randomMoney();                           // Klient indiwidualny losuje w zakresie 10000-100000
};
#endif