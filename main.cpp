/*Simulation for ATM Banking System*/
#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>
#include <cstdlib>
#include "src/rlutil.h"
#include "src/checkoutATM.h"

int mainMenu();
void loginAccount();
int startMenu();
int bankDeposit();

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
    std::cout << "\t\t\t|>                                            |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    rlutil::locate(28, 8);
    std::cin >> option;

    return option;
  } while (true);
}

void loginAccount()
{
  const int npassword = 1234;
  int option;
  if (checkPassword() == npassword)
  {
    rlutil::cls();
    rlutil::setColor(rlutil::BROWN);
    option = startMenu();
    switch (option)
    {
    case 1:
      bankDeposit();
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
    int object;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|                   Process                   |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|> 1. Bank-Deposit:                           |" << std::endl;
    std::cout << "\t\t\t|> 2. Cash-Out:                               |" << std::endl;
    std::cout << "\t\t\t|> 3. Query:                                  |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|>                                            |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    rlutil::locate(28, 8);
    std::cin >> object;
    return object;
  } while (true);
} // end startMenu()

int bankDeposit()
{
  // Bank deposit
  rlutil::cls();
  double mount;
  std::string check;
  int amount, option;
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  std::cout << "\t\t\t|              Bank Deposit                   |" << std::endl;
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  std::cout << "\t\t\t|> 1. Cash                                    |" << std::endl;
  std::cout << "\t\t\t|> 2. Check                                   |" << std::endl;
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  std::cout << "\t\t\t|>                                            |" << std::endl;
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  rlutil::locate(28, 7);
  std::cin >> option;
  switch (option)
  {
  case 1:
    rlutil::cls();
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|Enter amount:                                |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    rlutil::locate(40, 2);
    std::cin >> mount;
    if (mount == static_cast<int>(mount) && mount >= 10 && static_cast<int>(mount) % 2 != 0 && static_cast<int>(mount) % 5 != 0 || static_cast<int>(mount) % 10 == 0)
    {
      rlutil::cls();
      amount = static_cast<int>(mount);
      std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
      std::cout << "\t\t\t|Amount: " << amount << "\t\t\t              |" << std::endl;
      std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    }
    else
    {
      error();
    }
    break;
  case 2:
    rlutil::cls();
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|Enter number of checks:                      |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    rlutil::locate(50, 2);
    std::cin >> check;
    if (check.length() > 10 || check.length() < 10)
    {
      rlutil::cls();
      error();
    }
    else
    {
      rlutil::cls();
      std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
      std::cout << "\t\t\t|             Successful                      |" << std::endl;
      std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    }

    break;
  default:
    error();
    break;
  }
}
