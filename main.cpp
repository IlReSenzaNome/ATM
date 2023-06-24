/*Simulation for ATM Banking System*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include "rlutil.h"

int mainMenu();
int createAccount();
void loginAccount();
void exitAccount();
int startMenu();
void bankDeposit();
int checkPassword();

int main(int argc, char const *argv[])
{
  rlutil::setColor(rlutil::RED);
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

// Create Account
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

void loginAccount()
{
  checkPassword();
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
  int password;
  for (int i = 0; i < 4; i++)
  {
  }
}
// Login menu for ATM
int startMenu()
{
  do
  {
    int option;
    rlutil::setBackgroundColor(rlutil::BLACK);
    std::cout << "\t\t+----------------------------+" << std::endl;
    std::cout << "\t\t|> 1 Bank-Deposit:           |" << std::endl;
    std::cout << "\t\t|> 2 Cash=Out:               |" << std::endl;
    std::cout << "\t\t|> 3 Query:                  |" << std::endl;
    std::cout << "\t\t+----------------------------+" << std::endl;
    std::cout << "\t\t|>";
    std::cin >> option;
    return option;
  } while (true);
} // end startMenu()

void bankDeposit()
{
  int amount;
  rlutil::cls();
  std::cout << "Bank Deposit" << std::endl;
  std::cout << "Enter Amount: ";
  std::cin >> amount;
}