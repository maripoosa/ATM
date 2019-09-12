/**
* \brief èrÛd≥o klasy testujπcej
* \file Tester.cpp
* \author Pawel Iwaneczko
* \copyright Copyright 2017 HTeam. All rights reserved.
*/
#include <cassert>
#include <iostream>
#define private public
#define protected public
#include "SuperATM.h"
using namespace std;


#ifndef TESTER

#define USERNAME USER_NAME " " USER_SURNAME
void * TesterConstructor(uint8_t type, int pin, int accountBalance)
{
	void *ptr = 0;
	switch (type) {
	case atmType: ptr = new ATM(pin, accountBalance); break;
	case regularAtmType: ptr = new RegularATM(pin, accountBalance); break;
	case cashInAtmType: ptr = new CashInATM(pin, accountBalance); break;
	case superAtmType: ptr = new SuperATM(pin, accountBalance); break;
	}
	return ptr;
}
size_t TesterUserName(char *username, size_t usernameSize, uint8_t *group)
{
	size_t length = sizeof(USERNAME);
	memcpy_s(username, usernameSize, USERNAME, length);
	*group = USER_GROUP;
	return length;
}

namespace statistics {
	Stats::Stats() : initialized(), id(this_thread::get_id()), stats() {
		id = thread::id();
		initialized = true;
	}
	Stats::~Stats() {
		id = this_thread::get_id();
	}
	size_t Stats::Count() const {
		size_t count = 0;
		for (auto &s : stats) count += s.second;
		return count;
	}
	void Stats::AddPtr(void* ptr, size_t count)
	{
		if (initialized) {
			thread::id id = this_thread::get_id();
			if ((this->id == thread::id() || this->id != id) && locker.try_lock()) {
				this->id = id;
				stats.insert(make_pair(ptr, count));
				this->id = thread::id();
				locker.unlock();
			}
		}
	}
	void Stats::RemovePtr(void* ptr)
	{
		if (initialized) {
			thread::id id = this_thread::get_id();
			if ((this->id == thread::id() || this->id != id) && locker.try_lock()) {
				auto it = stats.find(ptr);
				if (it != stats.end()) {
					this->id = id;
					stats.erase(it);
					this->id = thread::id();
				}
				locker.unlock();
			}
		}
	}
};

static statistics::Stats stats;
void* operator new (size_t count) {
	void* ptr = malloc(count);
	stats.AddPtr(ptr, count);
	return ptr;
}
void operator delete (void* ptr) {
	stats.RemovePtr(ptr);
	free(ptr);
}
void operator delete[](void* ptr) {
	stats.RemovePtr(ptr);
	free(ptr);
}
size_t TesterDestructor(uint8_t type, void *ptr)
{
	switch (type)
	{
	case atmType: delete (ATM*)ptr; break;
	case regularAtmType: delete (RegularATM*)ptr; break;
	case cashInAtmType: delete (CashInATM*)ptr; break;
	case superAtmType: delete (SuperATM*)ptr; break;
	default: break;
	}
	return stats.Count();
}

size_t TesterHelper(uint8_t type, uint8_t func, void *ptr, void *data, size_t *dlen)
{
	ATM *atm = (ATM *)ptr;
	if (func == 0 && (data != 0) && (dlen != 0) && ((*dlen) > sizeof(atmInfo)) && dynamic_cast<ATM *>(atm) != 0) {
		atmInfo info;
		string address;
		atm->serviceInfo(info, address);
		memcpy(data, &info, sizeof(atmInfo));
		memcpy_s((uint8_t *)data + sizeof(atmInfo), size_t(*dlen - sizeof(atmInfo)), address.data(), address.size());
		return (sizeof(atmInfo) + address.size());
	}
	return 0;
}
#endif /* !TESTER */