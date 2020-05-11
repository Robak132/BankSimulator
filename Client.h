#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include "Account.h"
#include "ID.h"

using namespace std;

class Client {
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
    Client(string _name, string _surname, string _document_id, string reason, int money=0, ID _id_number = ID(), Account _account = Account());
    Client(const Client& c);
    Client& operator = (const Client& c);
    
    bool isRealClient();

    // Getter
    ID getIDNumber() const;
    string getName() const;
    string getSurname() const;
    string getNameSurname() const;
    string getDocumentID() const;
    string getReason() const;
    int getMoney() const;
    Account getAccount() const;

    // Setter
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
#endif