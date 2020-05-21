#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
private:
	bool created;
	int money;
	int credit;

public:
	Account(int _money=500, int _credit=0, bool _created = true);

	bool getCreated() const;
	int getMoney() const;
	int getCredit() const;
	
	void setCreated(bool status);
	void setMoney(int _money);
	void setCredit(int _credit);
};
bool operator == (Account a, Account b);
bool operator != (Account a, Account b);
#endif