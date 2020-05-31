#include "OpEnum.h"
using namespace std;

string numt::getFormatedReason(numt::PossibleOperations po) {
    switch (po) {
    case numt::PossibleOperations::accountToClient:
        return "Withdraw";
        break;
    case numt::PossibleOperations::clientToAccount:
        return "Payment";
        break;
    case numt::PossibleOperations::createAccount:
        return "Create account";
        break;
    case numt::PossibleOperations::deleteAccount:
        return "Delete account";
        break;
    case numt::PossibleOperations::infoAccount:
        return "Get info about account";
        break;
    case numt::PossibleOperations::takeLoan:
        return "Take loan";
        break;
    case numt::PossibleOperations::repayLoan:
        return "Repay loan";
        break;
    case numt::PossibleOperations::infoLoan:
        return "Get info about loan";
        break;
    default:
        return "Some operation";
    }
}