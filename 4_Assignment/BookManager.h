#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class BookManager
{
private:
    vector<Book> books;

    void search(const string& query, bool IsTitle);

public:
    void addBook(string title, string author);
    void displayAllBooks();
    void searchBookByTitle(string title);
    void searchBookByAuthor(string author);
};

