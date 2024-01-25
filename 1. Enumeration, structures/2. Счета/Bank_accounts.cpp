#include <iostream>

struct account
{
    std::string name;
    int acc_num;
    float balance;
};

void balance_changer(account& acc, float new_balance)
{
    acc.balance = new_balance;
}


int main()
{
   setlocale(LC_ALL, "Russian");

   int new_balance = 0;
   account acc1;

   std::cout << "Введите номер счёта: ";
   std::cin >> acc1.acc_num;

   std::cout << "Введите имя владельца: ";
   std::cin >> acc1.name;

   std::cout << "Введите баланс: ";
   std::cin >> acc1.balance;

   std::cout << "Введите новый баланс: ";
   std::cin >> new_balance;

   balance_changer(acc1, new_balance);

   std::cout << "Ваш счёт: " << acc1.name << ", " << acc1.acc_num << ", " << acc1.balance << "\n";

   return 0;
}
