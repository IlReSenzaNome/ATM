#include "rlutil.h"
#include <string>

void error()
{
    rlutil::cls();
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                Error Process                |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
}

int createAccount()
{
    int age, phone, password;
    char name[10], address[50];
    rlutil::cls();
    rlutil::setColor(rlutil::BLUE);
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                Create Account               |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> Enter your name: ";
    std::cin >> name;
    std::cout << "\t\t\t|> Enter your age: ";
    std::cin >> age;
    std::cout << "\t\t\t|> Enter your address: ";
    std::cin >> address;
    std::cout << "\t\t\t|> Enter your phone number: ";
    std::cin >> phone;
    std::cout << "\t\t\t|> Enter your password: ";
    std::cin >> password;
    if (age < 18)
    {
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t| You are not old enough to create an account |" << std::endl;
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t";
        getch();
    }
    else
    {
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t| Account Created                             |" << std::endl;
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t";
        getch();
    }
    return password;
}

void exitAccount()
{
    rlutil::cls();
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                  Thank You                  |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    getch();
    exit(0);
}

int checkPassword()
{
    rlutil::cls();
    int password, g = 2;
    for (int i = 1; i < 4; i++)
    {
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t|> Enter your password: ";
        password = 0;
        char ch;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (password != 0)
                {
                    password /= 10;
                    std::cout << "\b \b";
                }
            }
            else if (isdigit(ch))
            {
                int digit = ch - '0';
                password = password * 10 + digit;
                std::cout << "*";
            }
        }
        std::cout << std::endl;
        if (password == 1234)
        {
            return password;
        }
        else
        {
            rlutil::cls();
            rlutil::setColor(rlutil::RED);
            std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
            std::cout << "\t\t\t|> Wrong Password  " << g << "\t\t              |" << std::endl;
            g--;
            std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
            if (i == 3)
            {
                rlutil::cls();
                std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
                std::cout << "\t\t\t|> You have no more attempts                  |" << std::endl;
                std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
                return 0;
            }
            std::cout << "\t\t\t";
            getch();
        }
    }
}
