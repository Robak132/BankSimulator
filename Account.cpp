#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(int _money, int _credit, bool _created) {
	if (_created) {
		money = _money;
		credit = _credit;
	}
	else
	{
		money = 0;
		credit = 0;
	}
	created = _created;
}

bool Account::getCreated() const {
	return created;
}
int Account::getMoney() const {
	return money;
}
int Account::getCredit() const {
	return credit;
}
void Account::setCreated(bool _const) {
	created = _const;
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
