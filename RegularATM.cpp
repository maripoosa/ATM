#include "RegularATM.h"




RegularATM::RegularATM(int Pin, int AccountBalance) :ATM(Pin, AccountBalance)
{
	pin = Pin;
	accountBalance = AccountBalance;
	limit = 10000;

	if (pin = Pin)
		isLocked = true;

}

result_en RegularATM::checkBalance(int & balance)
{

	if (isLocked==false) 
	{
		balance = accountBalance;
		isLocked = true;
		return result_en::res_ok;
	}
	else {
		return result_en::res_atm_blocked;
	}
	isLocked = true;
	return result_en::res_error;

}

void RegularATM::serviceInfo(atmInfo & info, string & address)
{
	info.accountBalance = accountBalance;
	info.limit = limit;
	info.isLocked = isLocked;
	address = "Regular ATM";
}
