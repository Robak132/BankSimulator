#include <iostream>
#include "Stand.h"

using namespace std;

Stand::Stand()
{
    self_ID = ID('S');
    client = nullptr;
    s_type = "MainStand";
}

IClient* Stand::getClient()
{
    return client;
}

int Stand::getWorkTime()
{
    return work_time;
}

void Stand::setWorkTime(int i)
{
    if (!work_time)
    {
        work_time = i;
    }
}

string Stand::getSType()
{
    return s_type;
}

ID Stand::getStandID()
{
    return self_ID;
}

bool Stand::isClient()
{
    if (client == nullptr) return false;
    else return true;
}

int Stand::getQueueLength()
{
    return client_queue.size();
}

void Stand::addClient(IClient* c)
{
    client_queue.push(c);
}

void Stand::performOperation()
{
    cout << client->getReason() << endl;
}

vector<numt::PossibleOperations> Stand::getOperations()
{
    return operations;
}

void Stand::nextClient()
{
    if (getQueueLength() && !work_time) 
    { 
        if(client)
            client->setInBank(false);
        client = client_queue.front();
        client_queue.pop();
    }
    else if (!getQueueLength() && !work_time)
    {
        client = nullptr;
    }
}


