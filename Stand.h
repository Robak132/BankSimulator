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
{
public:
	virtual ID getStandID() = 0;
	virtual Client* getClient() = 0;
	virtual int getWorkTime() = 0;
	virtual void setWorkTime(int) = 0;
	virtual bool isClient() = 0;
	virtual int getQueueLength() = 0;
	virtual void addClient(Client*) = 0;
	virtual void performOperation(numt::PossibleOperations) = 0;
	virtual void nextClient() = 0;
};

class Stand : public IStand
{
protected:
	int work_time{};
	ID self_ID;
	Client* client;
	queue<Client*> client_queue{};
	vector<numt::PossibleOperations> operations;

public:
	Stand(ID = ID());
	ID getStandID();
	Client* getClient();
	int getWorkTime();
	void setWorkTime(int);
	bool isClient();
	int getQueueLength();
	void addClient(Client*);
	void performOperation(numt::PossibleOperations);
	void nextClient();
};

class EStand : public Stand
{
protected:
	Employeet* employeet;
public:
	EStand(ID= ID());
	void setEmployeet(Employeet*);
	Employeet* getEmployeet();
	bool isEmployeet();

};

class ATMout : public Stand
{
public:
	ATMout(ID = ID());
	void performOperation(numt::PossibleOperations);
};

class ATMin : public Stand
{
public:
	ATMin(ID = ID());
	void performOperation(numt::PossibleOperations);
};

class InfoStand : public EStand
{
public:
	InfoStand(ID = ID());
	void performOperation(numt::PossibleOperations);
};

class CashStand : public EStand
{
public:
	CashStand(ID = ID());
	void performOperation(numt::PossibleOperations);
};

class AccountStand : public EStand
{
public:
	AccountStand(ID = ID());
	void performOperation(numt::PossibleOperations);
};

#endif

