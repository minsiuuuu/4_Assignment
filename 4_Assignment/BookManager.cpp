#include "BookManager.h"

void BookManager::search(const string& query, bool IsTitle)
{
    bool found = false;
    for (const auto& book : books)
    {
        if ((IsTitle && book.title == query) || (!IsTitle && book.author == query))
        {
            cout << "제목: " << book.title << " 저자: " << book.author << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << (IsTitle ? "해당 제목" : "해당 저자") << "의 책을 찾을 수 없습니다." << endl;
    }
}

void BookManager::addBook(string title, string author)
{
    books.push_back(Book(title, author));
}

void BookManager::displayAllBooks()
{
    if (books.empty())
    {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }
    for (const auto& book : books)
    {
        cout << "제목: " << book.title << " 저자: " << book.author << endl;
    }
}

void BookManager::searchBookByTitle(string title)
{
    search(title, true);
}

void BookManager::searchBookByAuthor(string author)
{
    search(author, false);
}
