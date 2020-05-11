#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(int _money, int _credit) {
	money = _money;
	credit = _credit;
}

int Account::getMoney() const {
	return money;
}
int Account::getCredit() const {
	return credit;
}
void Account::setMoney(int _money) {
	money = _money;
}
void Account::setCredit(int _credit) {
	credit = _credit;
}

bool operator == (Account a, Account b) {
	return a.getMoney() == b.getMoney() && a.getCredit() == b.getCredit();
}
bool operator != (Account a, Account b) {
    return !(a == b);
}
