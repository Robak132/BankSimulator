#ifndef STAND_H
#define STAND_H
//#include "Operation.h"
#include "Client.h"
#include "Employeet.h"
#include "OpEnum.h" 
#include <vector>
#include <queue>

class Operation { public: int m; };

class IStand
{
public:
	virtual ID getStandID() = 0;
	virtual Client* getClient() = 0;
	virtual int getWorkTime() = 0;
	virtual bool isClient() = 0;
	virtual int getQueueLength() = 0;
	virtual void addClient(Client*)= 0;
	virtual void performOperation(int) = 0;
	virtual void nextClient() = 0;
};

class Stand : public IStand
{
	int work_time{};
	ID self_ID;
	Client* client;
	queue<Client*> client_queue{};
	const vector<Operation> operations;

public:
	Stand();
	ID getStandID();
	Client* getClient();
	int getWorkTime();
	bool isClient();
	int getQueueLength();
	void addClient(Client*);
	void performOperation(int);
	void nextClient();
};

class EStand : public Stand
{
	Employeet* employeet;
public:
	EStand();
	Employeet* getEmployeet();
	bool isEmployeet();
};
#endif