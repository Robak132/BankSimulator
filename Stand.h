#pragma once
#include "ID.h"
#include "Operation.h"
#include "FIFO.h"
#include "Client.h"
#include <vector>

class IStand
{
public:
	virtual ID getEmployeetID() = 0;
	virtual ID getStandID() = 0;
	virtual ID getClientID() = 0;
	virtual int getQueueLength() = 0;
	virtual void performOperation(string) = 0;
	virtual void nextClient() = 0;
	virtual void goOnBreak() = 0;
	virtual bool operator==(const Stand&) = 0;
	virtual bool operator++() = 0;
};

class Stand : public IStand
{
	int work_time;
	ID self_ID;
	ID client_ID;
	ID employeet_ID;
	Queue<Client> client_queue;
	const vector<Operation> possible_operations;
	bool coffe_break;

public:
	Stand(ID);
	ID getEmployeetID();
	ID getStandID();
	ID getClientID();
};