#pragma once
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;

    Book(string title, string author) : title(title), author(author) {}
};

