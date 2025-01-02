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
        cout << title << "�� ��ϵ��� ���� å�Դϴ�!" << endl;
        return;
    }

    if (stock[title] == 0) {
        cout << title << "�� ���� �� �ִ� ��� �����ϴ�!" << endl;
        return;
    }

    stock[title]--;
    borrowed[title]++;
    cout << "å�� �뿩�߽��ϴ�: " << title << endl;
    displayStock(title);
}

void BorrowManager::returnBook(string title)
{
    if (borrowed.find(title) == borrowed.end()) {
        cout << title << "�� ��ϵ��� ���� å�Դϴ�!" << endl;
        return;
    }

    if (borrowed[title] == 0) {
        cout << title << "�� �뿩���� �ʾұ� ������ �ݳ��� �� �����ϴ�!" << endl;
        return;
    }

    borrowed[title]--;
    stock[title]++;
    cout << "å�� �ݳ��߽��ϴ�: " << title << endl;
    displayStock(title);
}

void BorrowManager::displayStocks()
{
    cout << "���� ��� ����:" << endl;
    for (const auto& item : stock)
    {
        cout << "å ����: " << item.first 
            << ", ���: " << item.second 
            << ", �뿩 ��: " << (borrowed.find(item.first) != borrowed.end() ? borrowed.at(item.first) : 0)
            << endl;
    }
}

void BorrowManager::displayStock(string title)
{
    if (stock.find(title) != stock.end())
    {
        int borrowedCount = borrowed.find(title) != borrowed.end() ? borrowed.at(title) : 0;
        cout << "å ����: " << title 
            << ", ���� ���: " << stock.at(title) 
            << ", �뿩 ��: " << borrowedCount << endl;
    }
    else
    {
        cout << title << "�� ��� ������ �����ϴ�." << endl;
    }
}
