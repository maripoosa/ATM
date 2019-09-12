/**
* \brief Nag³ówek klasy testuj¹cej
* \file Tester.h
* \author Pawel Iwaneczko
* \copyright Copyright 2017 HTeam. All rights reserved.
*/
#pragma once
#ifndef IG_TESTER_H
#define IG_TESTER_H
#include <cstdint>
#include <string>
#include "Defines.h"
using namespace std;

enum classType {
	atmType,
	regularAtmType,
	cashInAtmType,
	superAtmType,
};

class IATester {
public:
	virtual result_en unlock(int pin) = 0;
	virtual result_en withdraw(int amount) = 0;
	virtual void serviceInfo(atmInfo &info, string &address) = 0;
};

class IRTester {
public:
	virtual result_en checkBalance(int& balance) = 0;
	virtual void serviceInfo(atmInfo &info, string &address) = 0;
};

class ICTester {
public:
	virtual result_en deposit(int amount) = 0;
	virtual void serviceInfo(atmInfo &info, string &address) = 0;
};

class ISTester {
public:
	virtual result_en rfidWithdraw() = 0;
	virtual result_en withdraw(int amount) = 0;
	virtual void serviceInfo(atmInfo &info, string &address) = 0;
};

#pragma region Statistics
#ifndef TESTER
#define DLL_EXPORT __declspec(dllexport)
extern "C" {
	DLL_EXPORT void * TesterConstructor(uint8_t type, int pin, int accountBalance);
	DLL_EXPORT size_t TesterDestructor(uint8_t type, void *ptr);
	DLL_EXPORT size_t TesterHelper(uint8_t type, uint8_t func, void *ptr, void *data, size_t *dlen);
	DLL_EXPORT size_t TesterUserName(char *username, size_t usernameSize, uint8_t *group);
}


#include <Windows.h>
#include <thread>
#include <mutex>
#include <map>
#include <string>
namespace statistics {
	using namespace std;
	class Stats {
	private:
		bool initialized;
		mutex locker;
		thread::id id;
		map<void *, size_t> stats;
	public:
		Stats();
		~Stats();
		size_t Count() const;
		void AddPtr(void* ptr, size_t count);
		void RemovePtr(void* ptr);
	};
};

void* operator new (size_t count);
void operator delete (void* ptr);
void operator delete[](void* ptr);
#endif /* !TESTER */
#pragma endregion
#endif /* IG_TESTER_H */