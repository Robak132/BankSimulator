#include <iostream>
#include "Stand.h"


using namespace std;

Stand::Stand(ID id)
{
    self_ID = id;
    client = nullptr;
}

Client* Stand::getClient()
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

void Stand::addClient(Client* c)
{
    client_queue.push(c);
}

void Stand::performOperation(numt::PossibleOperations op)
{
    cout << op << endl;
}

void Stand::nextClient()
{
    if (getQueueLength() && !work_time) 
    { 
        client = client_queue.front();
        client_queue.pop();
    }
    else if (!getQueueLength() && !work_time)
    {
        client = nullptr;
    }
}


