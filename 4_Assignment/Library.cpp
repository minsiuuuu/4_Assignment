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

        if (cin.fail()) {  // 숫자 입력이 아닌 경우
            cin.clear();  // 스트림 상태 플래그를 초기화
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 잘못된 입력 제거
            cout << "잘못된 입력입니다. 숫자를 입력해주세요: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 추가 입력 제거
            return input;  // 유효한 숫자 입력 반환
        }
    }
}

void Library::run()
{
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 찾기(제목)" << endl;
        cout << "4. 책 찾기(저자)" << endl;
        cout << "5. 책 대여" << endl;
        cout << "6. 책 반납" << endl;
        cout << "7. 재고 보기" << endl;
        cout << "8. 종료" << endl;
        cout << "선택: ";

        int choice = getIntInput("");
        switch (choice)
        {
        case 1:
        {
            string title = getStringInput("책 제목: ");
            string author = getStringInput("책 저자: ");
            int quantity = getIntInput("재고: ");
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
            string title = getStringInput("찾을 책 제목을 입력하세요: ");
            bookManager.searchBookByTitle(title);
            break;
        }
        case 4:
        {
            string author = getStringInput("찾을 책 저자를 입력하세요: ");
            bookManager.searchBookByAuthor(author);
            break;
        }
        case 5:
        {
            string title = getStringInput("대여할 책 제목을 입력하세요: ");
            borrowManager.borrowBook(title);
            break;
        }
        case 6:
        {
            string title = getStringInput("반납할 책 제목을 입력하세요: ");
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
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }
}
