#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Client.h"
#include "Stand.h"
#include "BankStats.h"

using namespace std;


struct BankSetup
{   // Struktura trzymaj¹ca parametry banku.
    int n_workers;
    int n_clients;
    int n_ATMin;
    int n_ATMout;
    int n_CashStand;
    int n_InfoStand;
    int n_AccountStand;
    int open_time;
    int close_time;
};

class Bank {
private:
    BankStats statistics;                   // Klasa statystyk banku. Przechowuje statystyki z konkretnego dnia.
    BankSetup b_setup;                      // Parametry zgrupowane w strukturê.
    vector<vector<IStand*>>stands;          // Wektor 2D Okienek w banku. Ka¿da kolumna reprezentuje inny typ okienka.

    vector<IClient*>clients;                // Wektor zarejestrowanych w banku klientów.
    vector<Employeet*> employees;           // Wektor zarejestrowanych w banku pracowników.

    IClient* createClient();                // Tworzy jednego klienta dla banku. Ma 50% szans ¿e jest indywidualny i 50% ¿e jest biznesowy.
    void initializeClients();               // Tworzy listê wszystkich klientów.
    void initializeStands();                // Tworzy wszystkie okienka.
public:
    vector<vector<IStand*>> get_stands();   // Zwraca wektr 2D Stanowisk
    int getOpenTime();                      
    int getCloseTime();
    BankStats& getStats();
    Bank(BankSetup = { 20,20,1,2,2,1,2,420,1320 }); // konstruktor domyœlny z domyœlnymi parametrami dla b_setup
    ~Bank();
    IClient* randomClient();                // Zwraca losowego klieta z listy wszystkich klientów
    void iterateThrough();                  // PrzejdŸ przez wszystkie okienka wykonuj¹c metody nextClient i performOperation.
    void addClientToList(IClient* client);  // Wybiera pracownikowi odpowiednie okienko gdzie za³atwi swoj¹ potrzebê.
};
#endif