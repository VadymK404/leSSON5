#include <iostream>
#include "quizizz.h"
#include "phonebook.h"
using namespace std;

int main() {
    system("chcp 1251>null");
    cout << "������� ����� �� ������� ������\n";
    cout << "\t\033[41m����\n1) ³�������\n2) ��������� �����\033[0m\n";
    short choice, res;
    cin >> choice;
    switch (choice) {
    case 1:
        res = quizizz(); 
            break;
    case 2:
        res= phonebook();
    default: cout << "������� ����"; break;
    }
    return 0;
}