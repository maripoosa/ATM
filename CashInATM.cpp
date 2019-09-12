#include "CashInATM.h"

CashInATM::CashInATM(int Pin, int AccountBalance) :RegularATM(Pin, AccountBalance)
{
	pin = Pin;
	accountBalance = AccountBalance;
	limit = 10000;

	if (pin = Pin)
		isLocked = true;
}

result_en CashInATM::deposit(int amount)
{
	if (isLocked == false)
	{
		if (amount <= accountBalance)
		{
			if (amount <= 0)
			{
				isLocked = true;
				return result_en::res_error;
			}

			else
			{
				if (limit < amount)
				{
					isLocked = true;
					return result_en::res_withdraw_limit;
				}

				else
				{

					accountBalance = accountBalance + amount;
					isLocked = true;
					return result_en::res_ok;
				}
			}

		}
		else
		{
			isLocked = true;
			return result_en::res_no_funds;
		}

	}
	else
		return result_en::res_atm_blocked;

}

void CashInATM::serviceInfo(atmInfo & info, string & address)
{
	info.accountBalance = accountBalance;
	info.limit = limit;
	info.isLocked = isLocked;
	address = "CashInATM";
}
