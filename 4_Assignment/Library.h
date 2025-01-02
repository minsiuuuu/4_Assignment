#pragma once
#include "BookManager.h"
#include "BorrowManager.h"

class Library
{
private:
	BookManager bookManager;
	BorrowManager borrowManager;

	string getStringInput(const string& prompt);
	int getIntInput(const string& prompt);

public:
	void run();
};

