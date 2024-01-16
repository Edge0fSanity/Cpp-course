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

fstream file; //��������� ��� ������ � ������

//����������� ������� ����� ������� file.seekg(0, std::ios_base::end);// ������ � �����
//������� ������� �������� �����, ������������ ��������� �� ������ � �������� ������
//������� ������, ������������� ������ ������� � ��������� ������ ��������
//������� ��������, ��������� ������ �������� � ���������������� ����
//������� ����������, ������ � ����� � << ��������

vector<Product> find(string);
vector<Product> del(string);
void add(string, string, string, string);


int main() {
	setlocale(0, "RU");
	char ch;
	cout << "��� ����." << endl;
	cout << "��� ����������� �������� ���� �� �������" << endl;
	cout << "1.��������" << endl;
	cout << "2.�������" << endl;
	cout << "3.�����" << endl;
	cin >> ch;
	switch (ch) {
	case '1': {
		string name;
		string type;
		string q;
		string date;
		cout << "������� ������ ������: ���, ���, ���-��, ����" << endl;
		getline(cin, name);
		getline(cin, type);
		getline(cin, q); //��� ��� ����, �� ���� ������
		getline(cin, date);
		add(name, type, q, date);
		break;
	}
	case '2':
	{
		string name;
		cout << "������� �������� ������ ��� ��������" << endl;
		getline(cin, name);

		if (!del(name).empty()) {
			cout << "����� ������" << endl;
		}

		break;
	}
	case '3':
	{
		string name;
		cout << "������� ������ ������������ ��� �����, ������� ��� ��������" << endl;
		getline(cin, name);

		vector<Product> finded = find(name);

		cout << "��������� ������: " << endl;
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

	if (!file.is_open()) { cout << "���� �� ������" << endl; return products; }
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

	if (!file.is_open()) { cout << "���� �� ������" << endl; return products; }
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
	file.seekg(0, ios_base::beg); //���������� ������ ������
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


	if (!file.is_open()) { cout << "���� �� ������" << endl;}
	else {
		file << "n:" << name << endl;
		file << "t:" << type << endl;
		file << "q:" << q << endl;
		file << "d:" << date << endl;
		file << endl;
		cout << "������ ������� ���������" << endl;
	}
	file.close();
}