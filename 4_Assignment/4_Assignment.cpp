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
                cout << "����: " << book.title << " ����: " << book.author << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << (IsTitle ? "�ش� ����" : "�ش� ����") << "�� å�� ã�� �� �����ϴ�." << endl;
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
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }
        for (const auto &book : books)
        {
            cout << "����: " << book.title << " ����: " << book.author << endl;
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
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. å ã��(����)" << endl;
        cout << "4. å ã��(����)" << endl;
        cout << "5. ����" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        cin.ignore();

        if (choice == 1)
        {
            string title, author;
            cout << "å ����: ";
            getline(cin, title);
            cout << "å ����: ";
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
            cout << "ã�� å ������ �Է��ϼ���: ";
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4)
        {
            string author;
            cout << "ã�� å ���ڸ� �Է��ϼ���: ";
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5)
        {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}
