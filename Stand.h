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
	virtual int getStandID() = 0;
	virtual Client* getClient() = 0;
	virtual Employeet* getEmployeet() = 0;
	virtual bool isEmployeet() = 0;
	virtual bool isCustomer() = 0;
	virtual int getQueueLength() = 0;
	virtual void performOperation(int) = 0;
	virtual void nextClient() = 0;
};

class Stand : public IStand
{
	int work_time{};
	int self_ID;
	Client* client;
	Employeet* employeet;
	queue<Client*> client_queue{};
	const vector<Operation> possible_operations;

public:
	Stand();
	//Stand(ID = ID());
	int getStandID();
	Client* getClient();
	Employeet* getEmployeet();
	bool isEmployeet();
	bool isCustomer();
	int getQueueLength();
	void performOperation(int);
	void nextClient();
};
#endif