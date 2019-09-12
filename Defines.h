#pragma once
#define USER_NAME    "Daria"         //Proszê wpisaæ swoje Imiê
#define USER_SURNAME "Sojka"     //Proszê wpisaæ swoje Nazwizko
#define USER_GROUP   5 				//Proszê wpisac numer grupy

struct atmInfo {
	int accountBalance;
	bool isLocked;
	int limit;
};

enum result_en {
	res_ok,
	res_wrong_pin,				/*!< niepoprawny pin                */
	res_atm_blocked,            /*!< Bankomat jest zablokowany      */
	res_no_funds,				/*!< brak srodków na koncie         */
	res_withdraw_limit,         /*!< Przekroczono limit wyp³aty     */
	res_error,                  /*!< Inny b³¹d                      */
};