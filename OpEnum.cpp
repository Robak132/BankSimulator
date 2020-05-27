#include "OpEnum.h"
using namespace std;

string numt::getFormatedReason(numt::PossibleOperations po) {
    switch (po) {
    case numt::accountToClient:
        return "Withdraw";
        break;
    case numt::clientToAccount:
        return "Payment";
        break;
    case numt::createAccount:
        return "Create account";
        break;
    case numt::deleteAccount:
        return "Delete account";
        break;
    case numt::infoAccount:
        return "Get info about account";
        break;
    case numt::takeLoan:
        return "Take loan";
        break;
    case numt::repayLoan:
        return "Repay loan";
        break;
    case numt::infoLoan:
        return "Get info about loan";
        break;
    default:
        return "Some operation";
    }
}