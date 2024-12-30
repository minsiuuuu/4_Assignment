#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book
{
public:
    string title;
    string author;

    Book(string title, string author) : title(title), author(author) {}
};

class BookManager
{
private:
    vector<Book> books;

    void search(const string& query, bool IsTitle)
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

public:
    void addBook(string title, string author)
    {
        books.push_back(Book(title, author));
    }
    void displayAllBooks()
    {
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }
        for (const auto &book : books)
        {
            cout << "제목: " << book.title << " 저자: " << book.author << endl;
        }
    }
    void searchByTitle(string title)
    {
        search(title, true);
    }
    void searchByAuthor(string author)
    {
        search(author, false);
    }
};

int main()
{
    BookManager manager;

    while (true)
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 찾기(제목)" << endl;
        cout << "4. 책 찾기(저자)" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        cin.ignore();

        if (choice == 1)
        {
            string title, author;
            cout << "책 제목: ";
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2)
        {
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            string title;
            cout << "찾을 책 제목을 입력하세요: ";
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4)
        {
            string author;
            cout << "찾을 책 저자를 입력하세요: ";
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
