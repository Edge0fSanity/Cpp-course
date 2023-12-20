#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //библиотека, чтобы подчищать консоль



using namespace std;

int cin_err() {
	if (cin.fail())
	{
		cout << "Вы ввели неверное значение" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		return 1;
	}
	return 0;
}
bool check_preferences(string login, string pass, string base);

struct users {
	string login;
	string pass;
	string name;
};

void users_write(users user[], fstream& file) {
	int f = 0, l, i = 0;
	string line;
	l = sizeof(user) / sizeof(user[0]);

	while (getline(file, line) && (i < l)) {
		if (f == 0) {
			user[i].login = line.substr(3);
		}
		else if (f == 1) {
			user[i].pass = line.substr(3);
		}
		else if (f == 2) {
			user[i].name = line.substr(3);
		}
		++f;
		++i;
		if (f == 4) { f = 0; }
	}
}


int main() {
	string path;
	string line, base = "", login, pass;
	fstream file;
	users user[3];

	file.open("Users.txt");

	if (!file.is_open()) { cout << "Файл пользователей не найден" << endl;  return 1; } //открытие файла + обработчик ошибок	

	users_write(user, file);


	while (true) {
		cout << "Введите логин и пароль" << endl;
		cin >> login;
		cin >> pass;
		if (check_preferences(login, pass, base)) {
			cout << "Да, такого знаю, добро пожаловать" << endl;
			break;
		}
		else {
			system("cls");
			cout << "Таких не знаем, давай еще раз" << endl;
		}
	}




	file.close();

	return 0;
}


bool check_preferences(string login, string pass, string base) {
	string maylogin = "", maypass = "";
	for (int i = 1; i < base.length(); ++i) {
		if (base[i - 1] == 'l' && base[i] == ':') {
			++i;
			while (base[i] != '\n') {
				maylogin += base[i];
				++i;
			}
			i += 3;
			while (base[i] != '\n') {
				maypass += base[i];
				++i;
			}
		}
		if (maylogin == login && maypass == pass) {
			return true;
		}
	}
	return false;
}