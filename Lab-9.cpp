#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct Product {
	string name;
	string type;
	string quantity;
	string date;
};

fstream file; //контейнер для работы с файлом

//перемещение курсора через функцию file.seekg(0, std::ios_base::end);// Курсор в конец
//создаем функцию открытия файла, возвращающую указатель на обьект с открытым файлом
//функцию поиска, передвиагющую курсор вначало и создающую массив структур
//функцию удаления, создающую массив структур и перезаписывающую файл
//функция добавления, курсор в конец и << элемента

vector<Product> find(string);
vector<Product> del(string);
void add(string, string, string, string);


int main() {
	setlocale(0, "RU");
	char ch;
	cout << "Это БАЗА." << endl;
	cout << "Для продолжения выберите один из пунктов" << endl;
	cout << "1.Добавить" << endl;
	cout << "2.Удалить" << endl;
	cout << "3.Найти" << endl;
	cin >> ch;
	switch (ch) {
	case '1': {
		string name;
		string type;
		string q;
		string date;
		cout << "Введите данные товара: имя, тип, кол-во, дату" << endl;
		getline(cin, name);
		getline(cin, type);
		getline(cin, q); //вот тут беда, не дает ввести
		getline(cin, date);
		add(name, type, q, date);
		break;
	}
	case '2':
	{
		string name;
		cout << "Введите название товара для удаления" << endl;
		getline(cin, name);

		if (!del(name).empty()) {
			cout << "Товар удален" << endl;
		}

		break;
	}
	case '3':
	{
		string name;
		cout << "Давайте найдем инетресующий вас товар, введите его название" << endl;
		getline(cin, name);

		vector<Product> finded = find(name);

		cout << "Найденные товары: " << endl;
		for (Product i : finded) {
			cout << "n: " << i.name << endl;
			cout << "t: " << i.type << endl;
			cout << "q: " << i.quantity << endl;
			cout << "d: " << i.date << endl;
			cout << endl;
		}

		break;
	}
	}
	return 0;
}


vector<Product> find(string name) {
	file.open("Base.txt");

	vector<Product> products;
	Product temp;
	string line;

	if (!file.is_open()) { cout << "Файл не найден" << endl; return products; }
	while (getline(file, line)) {
		if (line[0] == 'n' && line[1] == ':' && line.erase(0, 2) == name) {
			temp.name = line.erase(0, 2);

			getline(file, line);
			temp.type = line.erase(0, 2);

			getline(file, line);
			temp.quantity = line.erase(0, 2);

			getline(file, line);
			temp.date = line.erase(0, 2);

		}
		products.push_back(temp);
	}
	file.close();
	return products;

}

vector<Product> del(string name) {
	file.open("Base.txt");


	vector<Product> products;
	Product temp;
	string line;

	if (!file.is_open()) { cout << "Файл не найден" << endl; return products; }
	while (getline(file, line)) {
		if (line[0] == 'n' && line[1] == ':' && line.erase(0, 2) != name) {
			temp.name = line.erase(0, 2);

			getline(file, line);
			temp.type = line.erase(0, 2);

			getline(file, line);
			temp.quantity = line.erase(0, 2);

			getline(file, line);
			temp.date = line.erase(0, 2);

		}
		products.push_back(temp);
	} 
	file.seekg(0, ios_base::beg); //перемещаем курсор наверх
	for (Product temp : products) {
		file << "n:" << temp.name << endl;
		file << "t:" << temp.type << endl;
		file << "q:" << temp.quantity << endl;
		file << "d:" << temp.date << endl;
		file << endl;
	}
	file.close();

	return products;

}

void add(string name, string type, string q, string date) {
	file.open("Base.txt", ios::app);


	if (!file.is_open()) { cout << "Файл не найден" << endl;}
	else {
		file << "n:" << name << endl;
		file << "t:" << type << endl;
		file << "q:" << q << endl;
		file << "d:" << date << endl;
		file << endl;
		cout << "Запись успешно добавлена" << endl;
	}
	file.close();
}