#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
private:
	int money;
	int credit;
public:
	Account(int _money=0, int _credit=0);

	int getMoney() const;
	int getCredit() const;
	
	void setMoney(int _money);
	void setCredit(int _credit);
};
bool operator == (Account a, Account b);
bool operator != (Account a, Account b);
#endif