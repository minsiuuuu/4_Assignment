#include <iostream>
#include "Library.h"

using namespace std;

string Library::getStringInput(const string& prompt)
{
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

int Library::getIntInput(const string& prompt)
{
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail()) {  // ���� �Է��� �ƴ� ���
            cin.clear();  // ��Ʈ�� ���� �÷��׸� �ʱ�ȭ
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // �߸��� �Է� ����
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // �߰� �Է� ����
            return input;  // ��ȿ�� ���� �Է� ��ȯ
        }
    }
}

void Library::run()
{
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. å ã��(����)" << endl;
        cout << "4. å ã��(����)" << endl;
        cout << "5. å �뿩" << endl;
        cout << "6. å �ݳ�" << endl;
        cout << "7. ��� ����" << endl;
        cout << "8. ����" << endl;
        cout << "����: ";

        int choice = getIntInput("");
        switch (choice)
        {
        case 1:
        {
            string title = getStringInput("å ����: ");
            string author = getStringInput("å ����: ");
            int quantity = getIntInput("���: ");
            bookManager.addBook(title, author);
            borrowManager.initializeStock(Book(title, author), quantity);
            break;
        }
        case 2:
        {
            bookManager.displayAllBooks();
            break;
        }
        case 3:
        {
            string title = getStringInput("ã�� å ������ �Է��ϼ���: ");
            bookManager.searchBookByTitle(title);
            break;
        }
        case 4:
        {
            string author = getStringInput("ã�� å ���ڸ� �Է��ϼ���: ");
            bookManager.searchBookByAuthor(author);
            break;
        }
        case 5:
        {
            string title = getStringInput("�뿩�� å ������ �Է��ϼ���: ");
            borrowManager.borrowBook(title);
            break;
        }
        case 6:
        {
            string title = getStringInput("�ݳ��� å ������ �Է��ϼ���: ");
            borrowManager.returnBook(title);
            break;
        }
        case 7:
        {
            borrowManager.displayStocks();
            break;
        }
        case 8:
        {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }
}
