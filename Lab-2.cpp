#include <iostream>
#include <string> 

using namespace std;


int def() {
	int res;
	string text;
	int p;
	cout << "Выберите пункт" << endl;
	cout << "1.Ввести текст" << endl;
	cout << "2.Проверить текст" << endl;
	cout << "3.Вывод результата" << endl;
	cout << "4.Выход" << endl;
	cin >> p;
	switch (p) {
	case 1:
		getline(cin, text);
		break;
	case 2:
		res = check(text);
	}
	return 0;
}

int check(text) {
	int res;
	
}




int main() {
	int n;
	cout << "Номер задания ?" << endl;
	cin >> n;
	switch (n)
	{
	case 1: {
		float y, x;
		cin >> x;
		y = -2.7 * x * x * x + 0.23 * x * x - 1.4;
		cout << y;
		break;
	}
	case 2: {
		float r1, r2;
		cout << "Введите сопротивления 1 и 2 элементов\n";
		cin >> r1 >> r2;
		cout << "Сопротивление цепи равно: " << r1 + r2 << endl;
		break;
	}
	case 3: {
		
		def();
	}

	default:
		break;
	}

	return 0;
}