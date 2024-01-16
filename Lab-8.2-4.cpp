#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //библиотека, чтобы подчищать консоль

#define lenus 3



using namespace std;

struct User {
	string login, pass, name;
};


void register_data_load(User[]); //загрузка регистрационных данных(по логину)
string check_preferences(string, string, User[]); //проверка соответсвия логин-пароль + бд
bool cin_check(string login, string pass); //проверка ввода
void registration(User[]);

int last = 0;

int main() {
	setlocale(0, "RU");


	string login, pass, check;
	User users[100];

	register_data_load(users);

	cout << "Сразу войти(1) или сначала зарегистрироваться(2)?" << endl;
	cin >> check;
	if (check == "2") {
		registration(users);
	}


	do {
		cout << "Введите верные логин и пароль" << endl;
		cin >> login;
		cin >> pass;
		check = check_preferences(login, pass, users);
	} while (!cin_check(login, pass) or check == "");
	
	cout << "Добро пожаловать, " << check << endl;


	return 0;
}


bool cin_check(string login, string pass) { //проверка ввода
	for (int i = 0; i < login.length(); ++i) {
		if (login[i] == '\\' or pass[i] == '\\') {
			cout << "Логин и пароль не могут содержать символы \\ и кодирующиеся с его содержанием, повторите ввод" << endl;
			return false;
		}
		if (login == "" or pass == "") {
			cout << "Вы ничего не ввели, переделывай" << endl;
		}
	}
	return true;
}

void register_data_load(User users[]) {
	fstream file;
	string line = "", pass = "", login = "", name = "";
	
	file.open("Users.txt");
	for (last; users[last].name != ""; ++last) {}

	int count = lenus + last;
	if (!file.is_open()) { cout << "Файл пользователей не найден" << endl;  cout << "error opening file"; return; } //открытие файла + обработчик ошибок	
	while (getline(file, line)) {
		if (line[0] == 'l' && line[1] == ':') {
			for (int i = 2; i < line.length(); ++i) {
				login += line[i];
			}
			users[count].login = login;
			getline(file, line);
			if (not(line[0] == 'p' && line[1] == ':')) {
				cout << "Неверная структура файла" << endl; cout << "error file structure"; break; return;
			}
			for (int i = 2; i < line.length(); ++i) {
				pass += line[i];
			}
			users[count].pass = pass;
			getline(file, line);
			if (not(line[0] == 'n' && line[1] == ':')) {
				cout << "Неверная структура файла" << endl; cout << "error file structure"; break; return;
			}
			for (int i = 2; i < line.length(); ++i) {
				name += line[i];
			}
			users[count].name = name;
			login = "";
			pass = "";
			name = "";
			--count;

		}
	}
	file.close();
}

string check_preferences(string login, string pass, User users[]) {
	int count = lenus + last;
	for (int i = 0; i < count; ++i) {
		if (users[i].login == login && users[i].pass == pass) {
			return users[i].name;
		}
	}
	system("cls");
	cout << "Логин или пароль неверны, повторите ввод" << endl;
	return "";
}

void registration(User users[]) {
	fstream file;
	file.open("Users.txt");
	if (!file.is_open()) { cout << "Файл пользователей не найден" << endl;  cout << "error opening file"; return; } //открытие файла + обработчик ошибок	
	string login, pass1, pass2, name;
	cout << endl << "Добро пожаловать в форму регистрации" << endl;
	do {
		cout << "Введите верные логин и пароль" << endl;
		cin >> login;
		cin >> pass1;
		cout << "Повторите пароль" << endl;
		cin >> pass2;
		if (pass1 != pass2) {
			cout << "Пароли не совпадают" << endl;
			system("cls");
			continue;
		}
	} while (!cin_check(login, pass1));

	cout << "Отлично, теперь введите имя пользователя" << endl;
	cin >> name;

	for (last; users[last].name != ""; ++last) {
		file << "l:" << users[last].login << endl;
		file << "p:" << users[last].pass << endl;
		file << "n:" << users[last].name << endl;
		file << endl;

	} //находим последнюю запись и параллельно записываем структуру в файл
	users[last].login = login;
	users[last].pass = pass1;
	users[last].name = name;
	file << "l:" << users[last].login << endl; //дописываем файл
	file << "p:" << users[last].pass << endl;
	file << "n:" << users[last].name << endl;
	file << endl;
	last -= lenus - 1;
	cout << "Пользователь добвлен" << endl;
	file.close();
}