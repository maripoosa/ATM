#pragma once
#include "Tester.h"

class ATM : IATester {
protected:
	bool isLocked;
	int pin;
	int accountBalance;
	int limit;
public:
	ATM(int Pin, int AccountBalance);

	result_en unlock(int pin);
	virtual result_en withdraw(int amount);
	virtual void serviceInfo(atmInfo &info, string &address);
};