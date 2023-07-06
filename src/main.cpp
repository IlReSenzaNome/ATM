/*Simulation for ATM Banking System*/
#include <iostream>
#include <conio.h>
#include <string>
#include "lib/rlutil.h"
#include "lib/checkoutATM.h"

// prototypes fuction
int mainMenu();
void loginAccount();
int startMenu();
void bankDeposit(int &);
void cashOut(int &);

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
// Main Menu
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
// Create Account
void loginAccount()
{
  const int npassword = 1234;
  int option, consultation = 1000;
  if (checkPassword() == npassword)
  {
    rlutil::cls();
    rlutil::setColor(rlutil::COLOR::BROWN);
    option = startMenu();
    switch (option)
    {
    case 1:
      bankDeposit(consultation);
      break;
    case 2:
      cashOut(consultation);
      break;
    case 3:
      query(consultation);
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
// bank deposit
void bankDeposit(int &consultation)
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
      std::cout << "\t\t\t|The money has been deposited                 |" << std::endl;
      successful();
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
      successful();
    }
    break;
  default:
    error();
    break;
  }
}
// Cash out
void cashOut(int &consultation)
{
  // Cash out
  int option, amount = 0;
  rlutil::cls();
  rlutil::setColor(rlutil::COLOR::MAGENTA);
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  std::cout << "\t\t\t|              Cash Out                       |" << std::endl;
  std::cout << "\t\t\t+------------------------+--------------------+" << std::endl;
  std::cout << "\t\t\t|> 1. 10                 |            2. 20  <|" << std::endl;
  std::cout << "\t\t\t|> 3. 40                 |            4. 60  <|" << std::endl;
  std::cout << "\t\t\t|> 5. 80                 |           6. 100  <|" << std::endl;
  std::cout << "\t\t\t|> 7. 200                |   8. Other Amount <|" << std::endl;
  std::cout << "\t\t\t+------------------------+--------------------+" << std::endl;
  std::cout << "\t\t\t|>                                            |" << std::endl;
  std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
  rlutil::locate(28, 9);
  std::cin >> option;
  switch (option)
  {
  case 1:
    checkcashout(consultation, 10);
    break;
  case 2:
    checkcashout(consultation, 20);
    break;
  case 3:
    checkcashout(consultation, 40);
    break;
  case 4:
    checkcashout(consultation, 60);
    break;
  case 5:
    checkcashout(consultation, 80);
    break;
  case 6:
    checkcashout(consultation, 100);
    break;
  case 7:
    checkcashout(consultation, 200);
    break;
  case 8:
    rlutil::cls();
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    std::cout << "\t\t\t|Enter amount:                                |" << std::endl;
    std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
    rlutil::locate(40, 2);
    std::cin >> amount;
    if (amount == static_cast<int>(amount) && amount >= 10 && static_cast<int>(amount) % 2 != 0 && static_cast<int>(amount) % 5 != 0 || static_cast<int>(amount) % 10 == 0)
    {
      rlutil::cls();
      std::cout << "\t\t\t+---------------------------------------------+" << std::endl;
      std::cout << "\t\t\t|> Money Withdrawn                            |" << std::endl;
      animate();
      successful();
    }
    else
    {
      error();
    }
    break;
  default:
    error();
    break;
  }
}
