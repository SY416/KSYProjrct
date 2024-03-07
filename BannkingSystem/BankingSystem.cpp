// BankingSystem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int NAME_LEN = 20;

void ShowMenu(void);        // 메뉴출력
void MakeAccount(void);     // 계좌개설을 위한 함수
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccInfo(void);  // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
    int accID;                  // 계좌번호
    int balance;                // 잔액
    char cusName[NAME_LEN];     // 고객이름T
} Account;

Account accArr[100];    // Account 저장을 위한 배열
int accNum = 0;         // 저장된 Account 수

int main()
{
    int choice;

    while (1)
    {
        ShowMenu();
        std::cout << "선택: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            std::cout << "올바른 접근이 아닙니다." << std::endl;
        }
    }
    return 0;
}

void ShowMenu(void)
{
    std::cout << "-----Menu-----" << std::endl;
    std::cout << "1. 계좌개설" << std::endl;
    std::cout << "2. 입 금" << std::endl;
    std::cout << "3. 츨 금" << std::endl;
    std::cout << "4. 계좌겅보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    std::cout << "[계좌개셜]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "이 름";
    std::cin >> name;
    std::cout << "입금액: ";
    std::cin >> balance;
    std::cout << std::endl;
    accArr[accNum].accID = id;
    accArr[accNum].accID = balance;
    strcpy_s(accArr[accNum].cusName, name);// 문자열을 복사하는 함수
    accNum++;
}

void DepositMoney(void)
{
    int money;
    int id;
    std::cout << "[입 금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "입금액: ";
    std::cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accID == id)
        {
            accArr[i].balance += money;
            std::cout << "입금완료" << std::endl << std::endl;
            return;
        }
    }
    std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    std::cout << "[출 금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    std::cout << "출금액: ";
    std::cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accID == id)
        {
            if (accArr[i].balance < money)
            {
                std::cout << "잔액부족" << std::endl << std::endl;
                return;
            }
            accArr[i].balance -= money;
            std::cout << "출금완료" << std::endl << std::endl;
            return;
        }
    }
    std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        std::cout << "계좌ID: " << accArr[i].accID << std::endl;
        std::cout << "이 름: " << accArr[i].cusName << std::endl;
        std::cout << "잔 액: " << accArr[i].balance << std::endl << std::endl;
    }
}
