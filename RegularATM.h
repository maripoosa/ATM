#pragma once
#include "ATM.h"

class RegularATM : public ATM, IRTester {
public:
	RegularATM(int Pin, int AccountBalance);

	result_en checkBalance(int& balance);
	void serviceInfo(atmInfo &info, string &address);
};