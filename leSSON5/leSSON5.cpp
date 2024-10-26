#include <iostream>
#include "quizizz.h"
#include "phonebook.h"
using namespace std;

int main() {
    system("chcp 1251>null");
    cout << "Розподіл файлу на декілька частин\n";
    cout << "\t\033[41mМеню\n1) Вікторина\n2) Телефонна книга\033[0m\n";
    short choice, res;
    cin >> choice;
    switch (choice) {
    case 1:
        res = quizizz(); 
            break;
    case 2:
        res= phonebook();
    default: cout << "Невірний вибір"; break;
    }
    return 0;
}