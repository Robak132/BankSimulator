#include <iostream>
#include "Stand.h"


using namespace std;

Stand::Stand()
{
    self_ID = 0;
    client = nullptr;
    employeet = nullptr;
}

//Stand::Stand(ID stand_id)
//{
//    self_ID = stand_id;
//    client = nullptr;
//    employeet = nullptr;
//}

Client* Stand::getClient()
{
    return client;
}

int Stand::getStandID()
{
    return self_ID;
}

Employeet* Stand::getEmployeet()
{
    return employeet;
}

bool Stand::isEmployeet()
{
    if (employeet == nullptr) return false;
    else return true;
}

bool Stand::isCustomer()
{
    if (employeet == nullptr) return false;
    else return true;
}

int Stand::getQueueLength()
{
    return client_queue.size();
}

void Stand::performOperation(int op)
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



