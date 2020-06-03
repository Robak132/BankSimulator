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
    cout << "operation " << endl;
}

void Stand::decreaseWorkTime()
{
    if (work_time) work_time--;
}

vector<numt::PossibleOperations> Stand::getOperations()
{
    return operations;
}

Employeet* Stand::getEmployeet()
{
    return nullptr;
}

bool Stand::isEmployeet() {
    return false;
}

void Stand::nextClient()
{   // Następny klient podejdzie do okienka tylk wtedy gdy poprzedni zakończył swoją wizytę.
    if (getQueueLength() && !work_time)     
    { // Jeśli ktoś stał w kolejce, podejdzie do niej.
        if(client)
            client->setInBank(false);   // Klient wychodzi z banku.
        client = client_queue.front();
        client_queue.pop();
    }
    else if (!getQueueLength() && !work_time)
    { // Jeśli nikogo w kolejce nie ma, nikt nie podejdzie.
        if (client)
            client->setInBank(false);
        client = nullptr;
    }
}

ostream& operator << (ostream& out, const IStand* _is) {
    if (_is)
        out << _is->getSType() << " [" << _is->getStandID().getID() << "] and now queue length is " << _is->getQueueLength();
    else
        out << "Stand hasn't been builded yet.";
    return out;
}


