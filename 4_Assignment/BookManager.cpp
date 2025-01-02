#include "BookManager.h"

void BookManager::search(const string& query, bool IsTitle)
{
    bool found = false;
    for (const auto& book : books)
    {
        if ((IsTitle && book.title == query) || (!IsTitle && book.author == query))
        {
            cout << "����: " << book.title << " ����: " << book.author << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << (IsTitle ? "�ش� ����" : "�ش� ����") << "�� å�� ã�� �� �����ϴ�." << endl;
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
        cout << "���� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }
    for (const auto& book : books)
    {
        cout << "����: " << book.title << " ����: " << book.author << endl;
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
