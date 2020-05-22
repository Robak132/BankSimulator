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
	virtual ID getStandID() const = 0;
	virtual string getSType() const = 0;
	virtual IClient* getClient() = 0;
	virtual int getWorkTime() = 0;
	virtual void setWorkTime(int) = 0;
	virtual void decreaseWorkTime() = 0;
	virtual bool isClient() = 0;
	virtual int getQueueLength() const = 0;
	virtual void addClient(IClient*) = 0;
	virtual void performOperation() = 0;
	virtual void nextClient() = 0;
	virtual vector<numt::PossibleOperations> getOperations() = 0;
};

ostream& operator << (ostream& out, const IStand* _is);


class Stand : public IStand
{
protected:
	string s_type;
	int work_time{};
	ID self_ID;
	IClient* client;
	queue<IClient*> client_queue{};
	vector<numt::PossibleOperations> operations;
public:
	Stand();
	ID getStandID() const;
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
{
protected:
	Employeet* employeet;
public:
	EStand(Employeet* = nullptr);
	void setEmployeet(Employeet*);
	Employeet* getEmployeet();
	bool isEmployeet();

};

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