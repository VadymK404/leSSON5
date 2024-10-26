#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "quizizz.h"
#include "file_chas_h.h"

using namespace std;

struct telbook {
    string name;
    int phone;
};

void beginContact(telbook tb[], int& count) {
    ifstream file("contact.txt");
    if (!file) {
        cout << "Файл не знайдено!\n";
        return;
    }
    else {
        while (file >> tb[count].name >> tb[count].phone) {
            count++;
        }
        file.close();
    }
}

void showContact(telbook tb[], int count) {
    for (int i = 0; i < count; i++) {
        cout << tb[i].name << ' ' << tb[i].phone << endl;
    }
}

void addContact(telbook tb[], int& count) {
    if (count >= 10) {
        cout << "Телефонна книга заповнена!\n";
        return;
    }
    cout << "Введіть ім'я: ";
    cin >> tb[count].name;
    cout << "Введіть номер телефону: ";
    cin >> tb[count].phone;
    count++;
    ofstream file("contact.txt", ios::app);
    if (file) {
        file << tb[count - 1].name << " " << tb[count - 1].phone << endl;
        file.close();
    }
    else {
        cout << "Помилка збереження контакту у файл.\n";
    }
}

void editContact(telbook tb[], int count) {
    string name;
    cout << "Введіть ім'я контакту, який хочете змінити: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == name) {
            cout << "Введіть нове ім'я: ";
            cin >> tb[i].name;
            cout << "Введіть новий номер телефону: ";
            cin >> tb[i].phone;

            
            ofstream file("contact.txt");
            if (file) {
                for (int j = 0; j < count; j++) {
                    file << tb[j].name << " " << tb[j].phone << endl;
                }
                file.close();
            }
            else {
                cout << "Помилка збереження змін у файл.\n";
            }
            return;
        }
    }
    cout << "Контакт не знайдено.\n";
}

void findContact(telbook tb[], int count) {
    string name;
    cout << "Введіть ім'я для пошуку: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == name) {
            cout << "Контакт знайдено: " << tb[i].name << " " << tb[i].phone << endl;
            return;
        }
    }
    cout << "Контакт не знайдено.\n";
}

int phonebook() {
    system("chcp 1251>null");
    telbook tb[10];
    int size = 0;
    int contact;

    beginContact(tb, size);

    cout << "\t\n\tТелефона книга\n\n";
    cout << "1 = показати контакти\n2 = додати контакт\n3 = редагувати контакт\n4 = знайти контакт\n0 = вихід\n";

    while (true) {
        cout << "\nВаш вибір: ";
        cin >> contact;

        switch (contact) {
        case 0:
            cout << "Вихід з програми.\n";
            return 0;

        case 1:
            cout << "Збережені контакти:\n";
            showContact(tb, size);
            break;

        case 2:
            addContact(tb, size);
            break;

        case 3:
            editContact(tb, size);
            break;

        case 4:
            findContact(tb, size);
            break;

        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }
}


