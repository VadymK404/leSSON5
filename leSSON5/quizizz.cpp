#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "file_chas_h.h"

using namespace std;

int quizizz() {
	system("chcp 1251>null");
	cout << "\n\t\tVictorina\n\n";
	ifstream file("qui.txt");
	if (!file) {
		cout << "file not exist";
		return 1;
	}
	short kol = 1,right=0;
	string line,user;

	while (getline (file ,line)) {
		cout << "Question #"<<kol<<endl;
		cout << line << endl;
		for (int i = 1; i <=3; i++) {
			getline(file, line);
			cout << i << ") " << line<<endl;
		}
		
		cout << "your answer is:";
		cin >> user;
		file >> line;
		file.ignore();

		
		if (user == line) {
			cout << "\n\033[33mCorrect\033[0m"<<endl;
			right++;
		}
		else cout << "\n\033[32mIncorrect answer\033[0m\n"<<endl;

		kol++;
	}
	file.close();
	cout << "На " << kol << " питан правильно відповіли";

	cout << "\n\t1) back menu\n2) exit\nYour choice: ";
	short choice, res;
	cin >> choice;
	if (choice == 1)res = main();
	else if (choice == 2) exit;
	else cout << "incorrect num\n";


	return 0;
}