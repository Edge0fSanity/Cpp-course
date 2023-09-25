#include <iostream>
#include <string> 

using namespace std;





int check(string txt) {
	int i, count=1, mcount = 0;
	for (i = 0; i <= txt.length() - 1; i++) {
		if (txt[i] == txt[i + 1]) {
			count++;
		}
		else {
			if (count > mcount) {
				mcount = count;
			}
			count = 1;
		}
	}
	return mcount;
}

int def() {
	int res=0;
	string text = {};
	int p;
	while (true) {
		cout << "Выберите пункт" << endl;
		cout << "1.Ввести текст" << endl;
		cout << "2.Проверить текст" << endl;
		cout << "3.Вывод результата" << endl;
		cout << "4.Выход" << endl;
		cin >> p;
		switch (p) {
		case 1:
			getline(cin, text);
			getline(cin, text);
			cout << text;
			break;
		case 2:
			if (text != "") {
				res = check(text);
			}
			else {
				cout << "Для начала введите текст" << endl;
			}
			break;
		case 3:
			if (res > 0) {
				cout << res << endl;;
			}
			else{
				cout << "Выводить нечего" << endl;;
			}
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "Введите верный номер пункта" << endl;
			break;
		}
	}
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
	case 3: 
		def();
		break;
	
	default:
		break;
	}

	return 0;
}