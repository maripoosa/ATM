#pragma once
#include "RegularATM.h"

class CashInATM : public RegularATM, ICTester {
public:
	CashInATM(int Pin, int AccountBalance);

	result_en deposit(int amount);
	void serviceInfo(atmInfo &info, string &address);
};
