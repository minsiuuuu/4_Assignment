#pragma once
#include <unordered_map>
#include "Book.h"

using namespace std;

class BorrowManager
{
private:
    unordered_map<string, int> stock;
    unordered_map<string, int> borrowed;

public:
    void initializeStock(Book book, int quantity);
    void borrowBook(string title);
    void returnBook(string title);
    void displayStocks();
    void displayStock(string title);
};

