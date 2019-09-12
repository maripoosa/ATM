#include "SuperATM.h"

SuperATM::SuperATM(int Pin, int AccountBalance) :CashInATM(Pin, AccountBalance)
{
	pin = Pin;
	accountBalance = AccountBalance;
	limit =10000;

	if (pin = Pin)
		isLocked = true;
}

result_en SuperATM::rfidWithdraw()
{
	
		if (accountBalance >= 50)
		{

			accountBalance -= 50;

			isLocked = true;
			return result_en::res_ok;
		}
		else
		{
			isLocked = true;
			return result_en::res_no_funds;
		}
		
}

result_en SuperATM::withdraw(int amount)
{
	if (amount == 50)
	{
		if (accountBalance < 50)
		{
			isLocked = true;
			return result_en::res_no_funds;

		}
		else if (amount < 0)
		{
			isLocked = true;
			return result_en::res_error;

		}
		else
		{
			accountBalance -= 50;
			isLocked = true;
			return result_en::res_ok;
		}
	}
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

void SuperATM::serviceInfo(atmInfo & info, string & address)
{
	info.accountBalance = accountBalance;
	info.limit = limit;
	info.isLocked = isLocked;
	address = "SuperATM";
	
}