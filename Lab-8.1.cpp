#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //библиотека, чтобы подчищать консоль



using namespace std;

bool cin_check(string, string);



int main() {
	setlocale(0, "RU");

	string login, pass;

	cout << "Введите логин и пароль" << endl;
	do {
		cin >> login;
		cin >> pass;
	} while (!cin_check(login, pass));

	cout << "Добро пожаловать, " << login << endl;
	cout << "Вы ввели пароль: " << pass << endl;

	return 0;
}


bool cin_check(string login, string pass) { //проверка ввода
	for (int i = 0; i < login.length(); ++i) {
		if (login[i] == '\\') {
			cout << "Логин и пароль не могут содержать символы \\ и кодирующиеся с его содержанием, повторите ввод" << endl;
			return false;
		}
	}
	return true;
}