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

string Stand::getSType() const
{
    return s_type;
}

ID Stand::getStandID() const
{
    return self_ID;
}

bool Stand::isClient()
{
    if (client == nullptr) return false;
    else return true;
}

int Stand::getQueueLength() const
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

void Stand::decreaseWorkTime()
{
    if (work_time) work_time--;
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
            client->setCurrentStand(nullptr);
        client = client_queue.front();
        client_queue.pop();
    }
    else if (!getQueueLength() && !work_time)
    {
        client = nullptr;
    }
}

ostream& operator << (ostream& out, const IStand* _is) {
    if (_is)
        out << _is->getSType() << " with ID " << _is->getStandID().getID() << " and queue length " << _is->getQueueLength();
    else
        out << "Stand hasn't been builded yet.";
    return out;
}


