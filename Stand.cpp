// Stand.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Stand.h"

using namespace std;

Stand::Stand(ID stand_id)
{
    self_ID = stand_id;
    /*static vector<string> names{ "WithdrawMoney", "DepositMoney", "TransferMoney",
        "CreateAccount", "AccountInfo", "DeleteAccount()", "TakeLoan", "RepayLoan" };
    static vector<Operation> operations{ WithdrawMoney obj1, };*/
}

ID Stand::getClientID()
{
    return client_ID;
}

ID Stand::getStandID()
{
    return self_ID;
}

ID Stand::getEmployeetID()
{
    return employeet_ID;
}

int main()
{
    std::cout << "Hello World!\n";
}

