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
        cout << "���� �� ��������!\n";
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
        cout << "��������� ����� ���������!\n";
        return;
    }
    cout << "������ ��'�: ";
    cin >> tb[count].name;
    cout << "������ ����� ��������: ";
    cin >> tb[count].phone;
    count++;
    ofstream file("contact.txt", ios::app);
    if (file) {
        file << tb[count - 1].name << " " << tb[count - 1].phone << endl;
        file.close();
    }
    else {
        cout << "������� ���������� �������� � ����.\n";
    }
}

void editContact(telbook tb[], int count) {
    string name;
    cout << "������ ��'� ��������, ���� ������ ������: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == name) {
            cout << "������ ���� ��'�: ";
            cin >> tb[i].name;
            cout << "������ ����� ����� ��������: ";
            cin >> tb[i].phone;

            
            ofstream file("contact.txt");
            if (file) {
                for (int j = 0; j < count; j++) {
                    file << tb[j].name << " " << tb[j].phone << endl;
                }
                file.close();
            }
            else {
                cout << "������� ���������� ��� � ����.\n";
            }
            return;
        }
    }
    cout << "������� �� ��������.\n";
}

void findContact(telbook tb[], int count) {
    string name;
    cout << "������ ��'� ��� ������: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == name) {
            cout << "������� ��������: " << tb[i].name << " " << tb[i].phone << endl;
            return;
        }
    }
    cout << "������� �� ��������.\n";
}

int phonebook() {
    system("chcp 1251>null");
    telbook tb[10];
    int size = 0;
    int contact;

    beginContact(tb, size);

    cout << "\t\n\t�������� �����\n\n";
    cout << "1 = �������� ��������\n2 = ������ �������\n3 = ���������� �������\n4 = ������ �������\n0 = �����\n";

    while (true) {
        cout << "\n��� ����: ";
        cin >> contact;

        switch (contact) {
        case 0:
            cout << "����� � ��������.\n";
            return 0;

        case 1:
            cout << "�������� ��������:\n";
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
            cout << "������� ����. ��������� �� ���.\n";
            break;
        }
    }
}


