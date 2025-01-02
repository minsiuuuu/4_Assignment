#include <iostream>
#include "BorrowManager.h"

using namespace std;

void BorrowManager::initializeStock(Book book, int quantity)
{
	stock[book.title] += quantity;
}

void BorrowManager::borrowBook(string title)
{
    if (stock.find(title) == stock.end()) {
        cout << title << "은 등록되지 않은 책입니다!" << endl;
        return;
    }

    if (stock[title] == 0) {
        cout << title << "은 빌릴 수 있는 재고가 없습니다!" << endl;
        return;
    }

    stock[title]--;
    borrowed[title]++;
    cout << "책을 대여했습니다: " << title << endl;
    displayStock(title);
}

void BorrowManager::returnBook(string title)
{
    if (borrowed.find(title) == borrowed.end()) {
        cout << title << "은 등록되지 않은 책입니다!" << endl;
        return;
    }

    if (borrowed[title] == 0) {
        cout << title << "은 대여되지 않았기 때문에 반납할 수 없습니다!" << endl;
        return;
    }

    borrowed[title]--;
    stock[title]++;
    cout << "책을 반납했습니다: " << title << endl;
    displayStock(title);
}

void BorrowManager::displayStocks()
{
    cout << "현재 재고 상태:" << endl;
    for (const auto& item : stock)
    {
        cout << "책 제목: " << item.first 
            << ", 재고: " << item.second 
            << ", 대여 중: " << (borrowed.find(item.first) != borrowed.end() ? borrowed.at(item.first) : 0)
            << endl;
    }
}

void BorrowManager::displayStock(string title)
{
    if (stock.find(title) != stock.end())
    {
        int borrowedCount = borrowed.find(title) != borrowed.end() ? borrowed.at(title) : 0;
        cout << "책 제목: " << title 
            << ", 현재 재고: " << stock.at(title) 
            << ", 대여 중: " << borrowedCount << endl;
    }
    else
    {
        cout << title << "은 재고 정보가 없습니다." << endl;
    }
}
