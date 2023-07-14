#include "rlutil.h"
#include <limits>

void animate()
{
    rlutil::locate(43, 2);
    int points = 0;

    while (true)
    {
        for (int i = 0; i <= points; i++)
        {
            std::cout << ".";
        }

        Sleep(1000);

        points++;
        if (points > 3)
        {
            break;
        }
    }
    std::cout << std::endl;
}

void error()
{
    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::RED);
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                Error Process                |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
}

void successful()
{
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|             Successful Process              |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
}

void query(int &consultation)
{
    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::YELLOW);
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                Query Process                |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> total account balance: " << consultation << "$\t\t      |" << std::endl;
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
    std::cout << "\t\t\t|> Enter your name:                           |" << std::endl;
    rlutil::locate(45, 4);
    std::cin >> name;
    std::cout << "\t\t\t|> Enter your age:                            |" << std::endl;
    rlutil::locate(45, 5);
    std::cin >> age;
    std::cout << "\t\t\t|> Enter your address:                        |" << std::endl;
    rlutil::locate(48, 6);
    std::cin >> address;
    std::cout << "\t\t\t|> Enter your phone number:                   |" << std::endl;
    rlutil::locate(54, 7);
    std::cin >> phone;
    std::cout << "\t\t\t|> Enter your password:                       |" << std::endl;
    rlutil::locate(49, 8);
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
    rlutil::setColor(rlutil::COLOR::LIGHTBLUE);
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
        rlutil::setColor(rlutil::COLOR::GREEN);
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t|> Enter your password:                       |" << std::endl;
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        rlutil::locate(49, 2);
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

void checkcashout(int &consultation, int n)
{
    if (consultation > 0)
    {
        rlutil::cls();
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
        std::cout << "\t\t\t|> Money Withdrawn: 10                        |" << std::endl;
        consultation -= n;
        std::cout << "\t\t\t|> Money Remaining: " << consultation << "    \t\t      |" << std::endl;
        std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    }
    else
    {
        error();
    }
}