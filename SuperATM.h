#pragma once
#include "CashInATM.h"

class SuperATM : public CashInATM, ISTester {
public:
	SuperATM(int Pin, int AccountBalance);

	result_en rfidWithdraw();
	result_en withdraw(int amount);
	void serviceInfo(atmInfo &info, string &address);
};