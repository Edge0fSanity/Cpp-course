#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //����������, ����� ��������� �������

#define lenus 3



using namespace std;

struct User {
	string login, pass, name;
};


void register_data_load(User[]); //�������� ��������������� ������(�� ������)
string check_preferences(string, string, User[]); //�������� ����������� �����-������ + ��
bool cin_check(string login, string pass); //�������� �����
void registration(User[]);

int last = 0;

int main() {
	setlocale(0, "RU");


	string login, pass, check;
	User users[100];

	register_data_load(users);

	cout << "����� �����(1) ��� ������� ������������������(2)?" << endl;
	cin >> check;
	if (check == "2") {
		registration(users);
	}


	do {
		cout << "������� ������ ����� � ������" << endl;
		cin >> login;
		cin >> pass;
		check = check_preferences(login, pass, users);
	} while (!cin_check(login, pass) or check == "");
	
	cout << "����� ����������, " << check << endl;


	return 0;
}


bool cin_check(string login, string pass) { //�������� �����
	for (int i = 0; i < login.length(); ++i) {
		if (login[i] == '\\' or pass[i] == '\\') {
			cout << "����� � ������ �� ����� ��������� ������� \\ � ������������ � ��� �����������, ��������� ����" << endl;
			return false;
		}
		if (login == "" or pass == "") {
			cout << "�� ������ �� �����, �����������" << endl;
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
	if (!file.is_open()) { cout << "���� ������������� �� ������" << endl;  cout << "error opening file"; return; } //�������� ����� + ���������� ������	
	while (getline(file, line)) {
		if (line[0] == 'l' && line[1] == ':') {
			for (int i = 2; i < line.length(); ++i) {
				login += line[i];
			}
			users[count].login = login;
			getline(file, line);
			if (not(line[0] == 'p' && line[1] == ':')) {
				cout << "�������� ��������� �����" << endl; cout << "error file structure"; break; return;
			}
			for (int i = 2; i < line.length(); ++i) {
				pass += line[i];
			}
			users[count].pass = pass;
			getline(file, line);
			if (not(line[0] == 'n' && line[1] == ':')) {
				cout << "�������� ��������� �����" << endl; cout << "error file structure"; break; return;
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
	cout << "����� ��� ������ �������, ��������� ����" << endl;
	return "";
}

void registration(User users[]) {
	fstream file;
	file.open("Users.txt");
	if (!file.is_open()) { cout << "���� ������������� �� ������" << endl;  cout << "error opening file"; return; } //�������� ����� + ���������� ������	
	string login, pass1, pass2, name;
	cout << endl << "����� ���������� � ����� �����������" << endl;
	do {
		cout << "������� ������ ����� � ������" << endl;
		cin >> login;
		cin >> pass1;
		cout << "��������� ������" << endl;
		cin >> pass2;
		if (pass1 != pass2) {
			cout << "������ �� ���������" << endl;
			system("cls");
			continue;
		}
	} while (!cin_check(login, pass1));

	cout << "�������, ������ ������� ��� ������������" << endl;
	cin >> name;

	for (last; users[last].name != ""; ++last) {
		file << "l:" << users[last].login << endl;
		file << "p:" << users[last].pass << endl;
		file << "n:" << users[last].name << endl;
		file << endl;

	} //������� ��������� ������ � ����������� ���������� ��������� � ����
	users[last].login = login;
	users[last].pass = pass1;
	users[last].name = name;
	file << "l:" << users[last].login << endl; //���������� ����
	file << "p:" << users[last].pass << endl;
	file << "n:" << users[last].name << endl;
	file << endl;
	last -= lenus - 1;
	cout << "������������ �������" << endl;
	file.close();
}