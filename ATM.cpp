
#include "ATM.h"

ATM::ATM(int Pin, int AccountBalance)
{

	pin = Pin;
	accountBalance = AccountBalance;
	limit = 1000;

	if (pin = Pin)
		isLocked = true;
}

result_en ATM::unlock(int Pin)
{
	if (pin == Pin)
	{
		isLocked = false;
		return result_en::res_ok;
	}
	else
	{

		return result_en::res_wrong_pin;
	}
}

result_en ATM::withdraw(int amount)
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

					accountBalance = accountBalance - amount;
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

void ATM::serviceInfo(atmInfo & info, string & address)
{
	info.accountBalance = accountBalance;
	info.limit = limit;
	info.isLocked = isLocked;
	address = "ATM";
	
}
