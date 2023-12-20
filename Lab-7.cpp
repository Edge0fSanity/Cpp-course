#include <iostream>
#include <fstream>
#include <string>

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

int count_words(string str) { //подсчет слов в строке
	if (str.length() == 0) {
		return 0;
	}
	int c = 0;  
	for (int i = 1; i < str.length() - 1; ++i) {
		if (((str[i] == ' ') || (str[i] == '\n')) && (str[i - 1] != ' ') && (str[i + 1] != ' ')) {
			++c;
		}
	}
	return c;
}

int main() {
	string path;
	string line, text = "";
	fstream file;
	cout << "Введите имя файла" << endl;
	do { cin >> path; } while (cin_err()); //ввод пути файла с защитой от дурака
	file.open("C:\\Users\\Nikita\\Documents\\Лабы_ост\\" + path + ".txt");

	if (!file.is_open()) { cout << "такого файла нет" << endl;  return 1; } //открытие файла + обработчик ошибок

	while (getline(file, line)) {
		text += line + "\n";
	}
	if (text != "") {
		cout << text << endl;
		cout << count_words(text) << endl;
	}
	else {
		cout << "Файл пуст";
	}




	file.close();

	return 0;
}