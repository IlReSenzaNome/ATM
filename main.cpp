/*Simulation for ATM Banking System*/
#include <iostream>
#include <conio.h>
#include "src/rlutil.h"
#include "src/checkoutATM.h"

int mainMenu();
void loginAccount();
int startMenu();
void bankDeposit();

int main(int argc, char const *argv[])
{
  rlutil::setColor(rlutil::WHITE);
  switch (mainMenu())
  {
  case 1:
    // Create Account
    createAccount();
    break;
  case 2:
    // Login Account
    loginAccount();
    break;
  case 3:
    // Exit
    exitAccount();
    break;
  default:
    error();
    break;
  }
  getch();
  return 0;
}

int mainMenu()
{
  do
  {
    int option;
    std::cout << "\033]0;Banco\007";
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                  Main Menu                  |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> 1. Create Account                          |" << std::endl;
    std::cout << "\t\t\t|> 2. Login                                   |" << std::endl;
    std::cout << "\t\t\t|> 3. Exit                                    |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> ";
    std::cin >> option;
    return option;
  } while (true);
}

void loginAccount()
{
  const int npassword = 1234;
  if (checkPassword() == npassword)
  {
    rlutil::cls();
    rlutil::setColor(rlutil::BROWN);
    switch (startMenu())
    {
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    default:
      error();
      break;
    }
  }
}

// Login menu for ATM
int startMenu()
{
  do
  {
    int option;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                   Process                   |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> 1. Bank-Deposit:                           |" << std::endl;
    std::cout << "\t\t\t|> 2. Cash-Out:                               |" << std::endl;
    std::cout << "\t\t\t|> 3. Query:                                  |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> ";
    std::cin >> option;
    return option;
  } while (true);
} // end startMenu()