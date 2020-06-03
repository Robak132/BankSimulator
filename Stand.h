#ifndef STAND_H
#define STAND_H
#include "Operation.h"
#include "Client.h"
#include "Employeet.h"
#include "Error.h"
#include "OpEnum.h" 
#include <vector>
#include <queue>

class IStand
{// Interfejs okienka. Posiada metody pozwalaj¹ce na polimorfizm z klasami pochodnymi. (przyk³ad: perforOperation())
public:
	virtual bool isEmployeet() = 0;									// Czy jest pracownik?
	virtual ID getStandID() const = 0;				
	virtual Employeet* getEmployeet() = 0;			
	virtual string getSType() const = 0;							// Zwraca string mówi¹cy jakim typem okienka jest obiekt.
	virtual IClient* getClient() = 0;					
	virtual int getWorkTime() = 0;									// Zwraca pozosta³y czas pracy z obecnym klientem
	virtual void setWorkTime(int) = 0;								// I ustawia ten czas.
	virtual void decreaseWorkTime() = 0;							// Jak i obni¿a go o jednostkê (1)
	virtual bool isClient() = 0;									// Czy jest pracownik?
	virtual int getQueueLength() const = 0;			
	virtual void addClient(IClient*) = 0;							// Dodaje klienta na koniec kolejki.
	virtual void performOperation() = 0;							// Wykonuje operacjê któr¹ chce wykonaæ klient obecnie siedz¹cy przy stanowisku.
	virtual void nextClient() = 0;									// Klient obecny od stanowiska odchodzi jeœli skoñczy³, i przychodzi nastêpny z kolejki.
	virtual vector<numt::PossibleOperations> getOperations() = 0;	// Zwraca wektor operacji które mo¿emy wykonaæ przy stanowisku.
};

ostream& operator << (ostream& out, const IStand* _is);


class Stand : public IStand
{
protected:
	string s_type;									// Typ okienka
	int work_time{};								// Pozosta³y czas pracy z klientem
	ID self_ID;										// objekt klasy ID, sprecyzowany do okienek. Dla ka¿dego okienka inny.
	IClient* client;								// Klient siedz¹cy przy stanowisku
	queue<IClient*> client_queue{};					// Kolejka klientów
	vector<numt::PossibleOperations> operations;	// Operacje do wykonania przy okienku
public:
	Stand();
	ID getStandID() const;
	Employeet* getEmployeet();
	bool isEmployeet();
	IClient* getClient();
	int getWorkTime();
	string getSType() const;
	void setWorkTime(int);
	void decreaseWorkTime();
	bool isClient();
	int getQueueLength() const;
	void addClient(IClient*);
	void performOperation();
	vector<numt::PossibleOperations> getOperations();
	void nextClient();

	
};


class EStand : public Stand
{	// Rozszerza stanowisko o pracownika. 
protected:
	Employeet* employeet;
public:
	EStand(Employeet* = nullptr);
	void setEmployeet(Employeet*);
	Employeet* getEmployeet();
	bool isEmployeet();

};

// Poni¿ej znajduj¹ siê najmniejsze mo¿liwe stanowiska:
// - Bankomat
// - Wp³atomat
// - Informacja
// - Okienko Kasowe
// - Okienko do Kont
// W ka¿dym z tych stanowisk zosta³y podane operacje które mo¿na przy nich wykonaæ.
// Opis metody performOperation() jest w pliku SmallStands.cpp


class ATMout : public Stand
{
public:
	ATMout();
	void performOperation();
	
};

class ATMin : public Stand
{
public:
	ATMin();
	void performOperation();
};

class InfoStand : public EStand
{
public:
	InfoStand(Employeet* = nullptr);
	void performOperation();
};

class CashStand : public EStand
{
public:
	CashStand(Employeet* = nullptr);
	void performOperation();
};

class AccountStand : public EStand
{
public:
	AccountStand(Employeet* = nullptr);
	void performOperation();
};
#endif